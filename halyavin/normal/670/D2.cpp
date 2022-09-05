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
  int n, k;
  in >> n >> k;
  std::vector<int64_t> as(n);
  std::vector<int64_t> bs(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  for (int i = 0; i < n; i++) {
    in >> bs[i];
  }
  int64_t left = 0;
  int64_t right = 2000000001;
  while (right - left > 1) {
    int64_t middle = (left + right) / 2;
    int64_t magic = 0;
    for (int i = 0; i < n; i++) {
      magic += std::max(int64_t(0), as[i] * middle - bs[i]);
      magic = std::min(magic, int64_t(1000000001));
    }
    if (magic <= k) {
      left = middle;
    } else {
      right = middle;
    }
  }
  out << left << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}