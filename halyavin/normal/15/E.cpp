#ifdef __GNUC__
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,popcnt,fma4,lzcnt,avx")
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
  n /= 2;
  uint32_t p = 1000000009;
  uint32_t a = 1;
  uint32_t b = 0;
  uint32_t c = 1;
  for (size_t i = 1; i < n; i++) {
    uint32_t m1 = c;
    uint32_t m2 = (1 + 3 * c) % p;
    b = uint32_t((b + uint64_t(a)*m2) % p);
    a = uint32_t((uint64_t(a)*m1) % p);
    c = (3 + 2 * c) % p;
  }
  uint64_t res = (a + b) % p;
  res = (2 * res + res * res + 2) % p;
  res = (2 * res) % p;
  out << res << std::endl;

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}