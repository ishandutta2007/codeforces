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
#include <array>

void run(std::istream &in, std::ostream &out) {
  int n, m;
  in >> n >> m;
  std::array<int64_t, 11> stat = {};
  for (int i = 0; i < m; i++) {
    int a, b;
    in >> a >> b;
    stat[b] += a;
  }
  int64_t res = 0;
  for (int i = 10; i >= 0; i--) {
    int64_t boxes = std::min(stat[i], int64_t(n));
    res += boxes * i;
    n -= boxes;
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}