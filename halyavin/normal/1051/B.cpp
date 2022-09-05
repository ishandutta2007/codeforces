#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
    int64_t l, r;
    in >> l >> r;
    out << "YES\n";
    while (l < r) {
        out << l << " " << l + 1 << "\n";
        l += 2;
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}