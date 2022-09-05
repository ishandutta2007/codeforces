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

const uint32_t p = 1000000007;

void run(std::istream &in, std::ostream &out) {
  int a, b;
  size_t k, t;
  in >> a >> b >> k >> t;
  size_t shift = k * (2 * t + 1) + 100;
  std::vector<uint32_t> dyn(2 * shift + 1);
  std::vector<uint32_t> dyn2(2 * shift + 1);
  dyn[shift + (a - b)] = 1;
  for (size_t i = 0; i < 2 * t; i++) {
    uint32_t sum = 0;
    for (size_t j = 0; j <= 2 * k; j++) {
      sum = (sum + dyn[j]) % p;
    }
    dyn2[k] = sum;
    for (size_t j = k + 1; j + k < dyn.size(); j++) {
      sum = (sum + dyn[j + k] - dyn[j - k - 1] + p) % p;
      dyn2[j] = sum;
    }
    std::swap(dyn, dyn2);
  }
  uint32_t res = 0;
  for (size_t i = shift + 1; i < dyn.size(); i++) {
    res = (res + dyn[i]) % p;
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}