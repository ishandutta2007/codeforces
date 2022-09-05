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
  int n;
  in >> n;
  std::vector<int> load(n);
  for (int i = 0; i < n; i++) {
    in >> load[i];
  }
  int sum = std::accumulate(load.begin(), load.end(), 0);
  int base = sum / n;
  int mod = sum % n;
  std::sort(load.begin(), load.end());
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    int final = base + ((i >= n - mod) ? 1 : 0);
    ans += std::abs(final - load[i]);
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