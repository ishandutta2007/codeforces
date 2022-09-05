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

void run(std::istream& in, std::ostream& out) {
  int n, m;
  in >> n >> m;
  for (int i = 0; i < n; i++) {
    if (2 * i + 2 * n < m) {
      out << (2 * i + 2 * n + 1) << " ";
    }
    if (2 * i < m) {
      out << (2 * i + 1) << " ";
    }
    if (2 * i + 2 * n + 1 < m) {
      out << (2 * i + 2 * n + 2) << " ";
    }
    if (2 * i + 1 < m) {
      out << (2 * i + 2) << " ";
    }
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}