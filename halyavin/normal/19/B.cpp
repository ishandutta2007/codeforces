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
  int n;
  in >> n;
  const int64_t inf = 1LL << 62;
  std::vector<int64_t> dyn(n + 1, inf);
  dyn[0] = 0;
  for (int i = 0; i < n; i++) {
    int t, c;
    in >> t >> c;
    for (int j = n; j > 0; j--) {
      dyn[j] = std::min(dyn[j], dyn[std::max(0, j - t - 1)] + c);
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