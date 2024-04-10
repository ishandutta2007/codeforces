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

void run(std::istream& in, std::ostream& out) {
  int n, k;
  in >> n >> k;
  std::vector<int> beauty(n);
  for (int i = 0; i < n; i++) {
    in >> beauty[i];
  }
  int sum = std::accumulate(beauty.begin(), beauty.end(), 0);
  int64_t ans = 0;
  std::vector<bool> flags(n);
  int sumBeauty = 0;
  for (int i = 0; i < k; i++) {
    int city;
    in >> city;
    city--;
    flags[city] = true;
    ans += beauty[city] * int64_t(sum - beauty[city]);
    sumBeauty += beauty[city];
  }
  for (int i = 0; i < n; i++) {
    if (!flags[i]) {
      int all = sumBeauty;
      if (!flags[(i + 1) % n]) { all += beauty[(i + 1) % n]; }
      if (!flags[(i + n - 1) % n]) { all += beauty[(i + n - 1) % n]; }
      ans += all * int64_t(beauty[i]);
    }
  }
  ans /= 2;
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}