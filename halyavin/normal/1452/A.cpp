#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int t;
    in >> t;
    for (int i = 0; i < t; i++) {
        int x, y;
        in >> x >> y;
        if (x > y) {
            std::swap(x, y);
        }
        out << (x + y + std::max(0, y - x - 1)) << "\n";
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}