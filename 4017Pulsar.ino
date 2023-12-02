const int pulsePin[] = {3, 4, 5};  // Digital pins for pulses
const int buttonPin = 2;           // Digital pin for the button
const int incrementPulsePin = 9;   // Digital pin for the single pulse
const int pulseDelay = 200;        // Delay between pulses in milliseconds

int numberBuffer = 0;              // Buffer to store the 3-digit number

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);  // Set the button pin as INPUT_PULLUP
  pinMode(incrementPulsePin, OUTPUT);
}

void loop() {
  // Check if the button is pressed
  if (digitalRead(buttonPin) == LOW) {
    // Send a single pulse on D9
    digitalWrite(incrementPulsePin, HIGH);
    delay(10);  // Adjust this delay if needed
    digitalWrite(incrementPulsePin, LOW);

    // Increment the number buffer
    numberBuffer = (numberBuffer + 1) % 1000;

    // Wait for 200ms
    delay(200);

    // Output pulses based on the incremented number
    separateAndGeneratePulses(numberBuffer);
  }
  else{
    delay(1);
  }
}

void separateAndGeneratePulses(int number) {
  // Separate digits
  int digit1 = number / 100;
  int digit2 = (number / 10) % 10;
  int digit3 = number % 10;

  // Output pulses based on digits
  generatePulses(pulsePin[0], digit1);
  generatePulses(pulsePin[1], digit2);
  generatePulses(pulsePin[2], digit3);
}

void generatePulses(int pin, int count) {
  for (int i = 0; i < count; ++i) {
    digitalWrite(pin, HIGH);
    delay(pulseDelay);
    digitalWrite(pin, LOW);
    delay(pulseDelay);
  }
}
