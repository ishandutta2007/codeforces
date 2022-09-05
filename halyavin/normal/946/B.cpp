#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
  int64_t a, b;
  in >> a >> b;
  while (a > 0 && b > 0) {
    if (a >= 2 * b) {
      a = a % (2 * b);
    } else if (b >= 2 * a) {
      b = b % (2 * a);
    } else {
      break;
    }
  }
  out << a << " " << b << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}