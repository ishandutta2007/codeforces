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
  int last = -1;
  int ans = 0;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    int x;
    in >> x;
    if (x > last) {
      cur++;
    } else {
      cur = 1;
    }
    last = x;
    ans = std::max(ans, cur);
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}