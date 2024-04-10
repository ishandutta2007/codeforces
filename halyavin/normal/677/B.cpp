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
  int n, h, k;
  in >> n >> h >> k;
  int space = h;
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    in >> x;
    if (space >= x) {
      space -= x;
      continue;
    }
    int diff = (x - space);
    int seconds = (diff + k - 1) / k;
    ans += seconds;
    space += seconds * k;
    space = std::min(space, h);
    space -= x;
  }
  ans += (h - space + k - 1) / k;
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}