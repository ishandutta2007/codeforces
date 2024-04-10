#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
    std::array<int, 4> lengths;
    for (int &length : lengths) in >> length;
    bool triangle = false;
    bool segment = false;
    for (int i = 0; i < 4; i++) {
        std::array<int, 3> sides;
        for (int j = 0; j < 3; j++) {
            sides[j] = lengths [(j < i) ? j : (j + 1)];
        }
        int sum = std::accumulate(sides.begin(), sides.end(), 0);
        triangle |= std::all_of(sides.begin(), sides.end(), [sum](int side) {
            return side < sum - side;
        });
        segment |= std::any_of(sides.begin(), sides.end(), [sum](int side) {
            return side == sum - side;
        });
    }
    if (triangle) {
        out << "TRIANGLE" << std::endl;
    } else if (segment) {
        out << "SEGMENT" << std::endl;
    } else {
        out << "IMPOSSIBLE" << std::endl;
    }
}

int main() {
    run(std::cin, std::cout);
    return 0;
}