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
  int n, m;
  in >> n >> m;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cur = 1000000001;
    for (int j = 0; j < m; j++) {
      int c;
      in >> c;
      cur = std::min(cur, c);
    }
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