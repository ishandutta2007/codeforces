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
#include <array>

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::array<int, 5001> amin, amax;
  std::fill(amin.begin(), amin.end(), n);
  std::fill(amax.begin(), amax.end(), -1);
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
    amin[as[i]] = std::min(amin[as[i]], i);
    amax[as[i]] = std::max(amax[as[i]], i);
  }
  std::vector<int> dyn(n + 1);
  std::array<int, 5001> flags = {};
  dyn[0] = 0;
  for (int i = 1; i <= n; i++) {
    dyn[i] = dyn[i - 1];
    int left = i;
    int xorV = 0;
    for (int j = i - 1 ; j >= 0; j--) {
      int a = as[j];
      if (flags[a] != i) {
        flags[a] = i;
        xorV ^= a;
      }
      if (amax[a] >= i) break;
      left = std::min(left, amin[a]);
      if (left == j) {
        dyn[i] = std::max(dyn[i], dyn[left] + xorV);
      }
    }
  }
  out << dyn[n] << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}