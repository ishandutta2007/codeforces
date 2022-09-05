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
  int64_t sum = 0;
  for (int i = 0; i < n; i++) {
    int time;
    in >> time;
    sum += time;
  }
  int m;
  in >> m;
  for (int i = 0; i < m; i++) {
    int64_t left, right;
    in >> left >> right;
    if (sum <= right) {
      out << std::max(sum, left) << std::endl;
      return;
    }
  }
  out << -1 << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}