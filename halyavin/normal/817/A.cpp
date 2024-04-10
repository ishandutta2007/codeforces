#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
  int x1, y1, x2, y2;
  int x, y;
  in >> x1 >> y1 >> x2 >> y2;
  int dx = x2 - x1;
  int dy = y2 - y1;
  in >> x >> y;
  if (std::abs(dx) % x != 0 || std::abs(dy) % y != 0) {
    out << "NO" << std::endl;
    return;
  }
  int d1 = dx / x;
  int d2 = dy / y;
  if (((d1 + d2) & 1) == 0) {
    out << "YES" << std::endl;
  } else {
    out << "NO" << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}