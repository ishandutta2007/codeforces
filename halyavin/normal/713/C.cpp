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
#include <cmath>

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
    as[i] -= i;
  }
  std::vector<int> bs = as;
  std::sort(bs.begin(), bs.end());
  std::vector<std::vector<int64_t>> dyn(n, std::vector<int64_t>(n));
  for (int i = 0; i < n; i++) {
    dyn[0][i] = std::abs(bs[i] - as[0]);
  }
  for (int j = 1; j < n; j++) {
    int64_t minV = dyn[j - 1][0];
    for (int k = 0; k < n; k++) {
      minV = std::min(minV, dyn[j-1][k]);
      dyn[j][k] = minV + std::abs(bs[k] - as[j]);
    }
  }
  int64_t opt = dyn[n - 1][0];
  for (int k = 1; k < n; k++) {
    opt = std::min(opt, dyn[n - 1][k]);
  }
  out << opt << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}