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
  int n, t;
  in >> n >> t;
  int mult = 1 << n;
  std::vector<std::vector<int>> glasses(n+1);
  for (int i = 0; i <= n; i++) {
    glasses[i].resize(i + 1);
  }
  for (int i = 0; i < t; i++) {
    glasses[0][0] += mult;
    for (int j = 0; j < n; j++) {
      for (int k = 0; k <= j; k++) {
        if (glasses[j][k] >= mult) {
          glasses[j+1][k] += (glasses[j][k] - mult) / 2;
          glasses[j+1][k+1] += (glasses[j][k] - mult) / 2;
          glasses[j][k] = mult;
        }
      }
    }
  }
  int ans = 0;
  for (int j = 0; j < n; j++) {
    for (int k  = 0; k <= j; k++) {
      if (glasses[j][k] == mult) ans++;
    }
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}