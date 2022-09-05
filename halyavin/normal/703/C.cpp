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
  int n, w, v, u;
  in >> n >> w >> v >> u;
  std::vector<std::pair<int, int>> poly(n);
  for (int i = 0; i < n; i++) {
    in >> poly[i].first >> poly[i].second;
  }
  int64_t maxDiff = -(1LL << 60);
  int64_t minDiff = (1LL << 60);
  for (int i = 0; i < n; i++) {
    int64_t diff = poly[i].first * int64_t(u) - poly[i].second * int64_t(v);
    maxDiff = std::max(maxDiff, diff);
    minDiff = std::min(minDiff, diff);
  }
  out.precision(12);
  if (minDiff >= 0 || maxDiff <= 0) {
    out << w / (double) u << std::endl;
    return;
  }
  out << (maxDiff + w * int64_t(v)) / (double) (int64_t(u) * v) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}