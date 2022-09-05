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
  int64_t res = 0;
  for (int i = 0 ;i < n; i++) {
    int64_t x, m;
    in >> x >> m;
    int64_t l = x;
    int64_t r = x + m;
    while (l < r && ((l & 3) != 0)) {
      res ^= l;
      l++;
    }
    while (l < r && ((r & 3) != 0)) {
      r--;
      res ^= r;
    }
  }
  if (res == 0) {
    out << "bolik" << std::endl;
  } else {
    out << "tolik" << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}