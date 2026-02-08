int micPin = A0;
int ledPin = 4;

// -------- SETTINGS YOU CAN CHANGE --------
int threshold = 350;        // sound level trigger
int minGap = 200;           // minimum time between triggers (ms)
int ledOnTime = 120;        // LED ON duration (ms)
// ----------------------------------------

unsigned long lastTrigger = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int soundValue = analogRead(micPin);
  Serial.println(soundValue);

  unsigned long now = millis();

  // Detect sound event
  if (soundValue > threshold && (now - lastTrigger) > minGap) {
    digitalWrite(ledPin, HIGH);
    delay(ledOnTime);
    digitalWrite(ledPin, LOW);
    lastTrigger = now;
  }

  delay(10);
}
