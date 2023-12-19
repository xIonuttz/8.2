#include <iostream>
#include <cmath>

// Forward declaration for the template class
template <typename T>
class ComplexNumber;

// Template specialization for comparing a float and a complex number
template <>
class ComplexNumber<float> {
private:
    float real;
    float imaginary;

public:
    ComplexNumber(float r, float i) : real(r), imaginary(i) {}

    // Calculate the module (magnitude) of the complex number
    float module() const {
        return std::sqrt(real * real + imaginary * imaginary);
    }

    // Compare two numbers (either complex or float) based on their module
    bool operator<(const float& other) const {
        return module() < other;
    }

    bool operator>(const float& other) const {
        return module() > other;
    }

    // Display the complex number
    void display() const {
        std::cout << "(" << real << " + " << imaginary << "i)" << std::endl;
    }
};

// Template specialization for comparing two complex numbers
template <typename T>
class ComplexNumber {
private:
    T real;
    T imaginary;

public:
    ComplexNumber(T r, T i) : real(r), imaginary(i) {}

    // Calculate the module (magnitude) of the complex number
    T module() const {
        return std::sqrt(real * real + imaginary * imaginary);
    }

    // Compare two numbers (either complex or float) based on their module
    bool operator<(const ComplexNumber& other) const {
        return module() < other.module();
    }

    bool operator>(const ComplexNumber& other) const {
        return module() > other.module();
    }

    // Display the complex number
    void display() const {
        std::cout << "(" << real << " + " << imaginary << "i)" << std::endl;
    }
};

int main() {
    ComplexNumber<float> complexNumber(3.0f, 4.0f);
    float floatValue = 5.0f;

    // Compare a complex number with a float based on their module
    if (complexNumber < floatValue) {
        std::cout << "Complex number has a smaller module than the float.\n";
    }
    else {
        std::cout << "Complex number has a larger or equal module compared to the float.\n";
    }

    return 0;
}
