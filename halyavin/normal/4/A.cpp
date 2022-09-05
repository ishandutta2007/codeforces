#include <iostream>

void run(std::istream& in, std::ostream& out) {
    int weight;
    in >> weight;
    if (weight % 2 != 0 || weight == 2) {
        out << "NO" << std::endl;
    } else {
        out << "YES" << std::endl;
    }
}

int main() {
    run(std::cin, std::cout);
    return 0;
}