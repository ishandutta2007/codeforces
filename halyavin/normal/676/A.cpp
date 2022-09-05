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
  int pos1 = 0;
  int posn = 0;
  for (int i = 0; i < n; i++) {
    int x;
    in >> x;
    if (x == 1) pos1 = i;
    if (x == n) posn = i;
  }
  int ans = std::max({posn, n - posn - 1, pos1, n - pos1 - 1});
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}