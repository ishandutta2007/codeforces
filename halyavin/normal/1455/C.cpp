#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int t;
    in >> t;
    for (int test = 0; test < t; test++) {
        int x, y;
        in >> x >> y;
        out << (x - 1) << " " << y << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}