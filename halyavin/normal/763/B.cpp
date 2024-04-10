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
  int n;
  in >> n;
  out << "YES\n";
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    in >> x1 >> y1 >> x2 >> y2;
    out << (x1 & 1) * 2 + (y1 & 1) + 1<< "\n";
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}