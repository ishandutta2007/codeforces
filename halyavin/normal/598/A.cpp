#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>

void run(std::istream &in, std::ostream &out) {
  int t;
  in >> t;
  for (int k = 0; k < t; k++) {
    int64_t n;
    in >> n;
    int64_t sum = n * (n + 1) / 2;
    int64_t i = 1;
    while (i <= n) {
      sum -= 2 * i;
      i <<= 1;
    }
    out << sum << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}