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

const int levels = 40;

void run(std::istream &in, std::ostream &out) {
  int n;
  int64_t k;
  in >> n >> k;
  std::vector<std::vector<int>> next(levels, std::vector<int>(n));
  std::vector<std::vector<int64_t>> sumW(levels, std::vector<int64_t>(n));
  std::vector<std::vector<int>> minW(levels, std::vector<int>(n));
  for (int i = 0 ; i < n; i++) {
    in >> next[0][i];
  }
  for (int i = 0; i < n; i++) {
    in >> sumW[0][i];
    minW[0][i] = sumW[0][i];
  }
  for (int level = 1; level < levels; level++) {
    for (int i = 0; i < n; i++) {
      int ni = next[level - 1][i];
      next[level][i] = next[level - 1][ni];
      sumW[level][i] = sumW[level - 1][i] + sumW[level - 1][ni];
      minW[level][i] = std::min(minW[level - 1][i], minW[level - 1][ni]);
    }
  }
  std::vector<int> ansNext(n);
  std::vector<int64_t> ansSumW(n);
  std::vector<int> ansMinW(n, 1000000000);
  std::iota(ansNext.begin(), ansNext.end(), 0);

  for (int level = 0; level < levels; level++) {
    if ((k >> level) & 1) {
      for (int i = 0; i < n; i++) {
        int ni = ansNext[i];
        ansNext[i] = next[level][ni];
        ansSumW[i] += sumW[level][ni];
        ansMinW[i] = std::min(ansMinW[i], minW[level][ni]);
      }
    }
  }
  for (int i =0; i < n; i++) {
    out << ansSumW[i] << " " << ansMinW[i] << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}