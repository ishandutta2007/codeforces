#ifdef __GNUC__
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,bmi,fma,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
  int64_t p, k;
  in >> p >> k;
  if (k == 1) {
    int64_t res = 1;
    for (int i = 0; i < p; i++) {
      res = (res * p) % 1000000007;
    }
    out << res << std::endl;
    return;
  }
  if (k == 0) {
    int64_t res = 1;
    for (int i = 0; i < p - 1; i++) {
      res = (res * p) % 1000000007;
    }
    out << res << std::endl;
    return;
  }
  int s = 1;
  int64_t mul = k;
  for (; mul != 1; s++) {
    mul = (mul * k) % p;
  }
  int div = (p - 1) / s;
  int64_t res = 1;
  for (int i = 0; i < div; i++) {
    res = (res * p) % 1000000007;
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}