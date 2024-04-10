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
  int n, t;
  in >> n >> t;
  std::vector<std::pair<int, int>> homes(n);
  for (int i = 0; i < n; i++) {
    int x, a;
    in >> x >> a;
    homes[i].first = 2 * x - a;
    homes[i].second = 2 * x + a;
  }
  std::sort(homes.begin(), homes.end());
  int ans = 2;
  for (int i = 1; i < n; i++) {
    if (homes[i].first - homes[i - 1].second > 2 * t) {
      ans += 2;
    } else if (homes[i].first - homes[i - 1].second == 2 * t) {
      ans++;
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