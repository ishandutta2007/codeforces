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
  int n, m, k;
  int res = 0;
  in >> n >> m >> k;
  std::vector<int> pos(k);
  for (int i = 0; i < k; i++) {
    in >> pos[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int item;
      in >> item;
      size_t p = 0;
      for (; p < pos.size(); p++) {
        if (pos[p] == item) break;
      }
      res += p + 1;
      std::rotate(pos.begin(), pos.begin() + p, pos.begin() + p + 1);
    }
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}