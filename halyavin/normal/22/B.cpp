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
  std::vector<std::string> space(n);
  for (int i = 0; i < n; i++) {
    in >> space[i];
  }
  int maxAns = 0;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      if (space[x][y] == '1') continue;
      int maxy = m - 1;
      for (int nx = x; nx < n; nx++) {
        for (int i = y; i <= maxy; i++) {
          if (space[nx][i] == '1') {
            maxy = i - 1;
            break;
          }
        }
        if (maxy < y) break;
        maxAns = std::max(maxAns, maxy - y + 2 + nx - x);
      }
    }
  }
  out << 2 * maxAns << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}