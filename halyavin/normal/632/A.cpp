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
  int n, p;
  in >> n >> p;
  std::vector<int> buyers(n);
  for (int i = 0; i < n; i++) {
    std::string s;
    in >> s;
    if (s == "half") { buyers[i] = 0; } else {
      buyers[i] = 1;
    }
  }
  int64_t cur = 0;
  int64_t ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ans += 2 * cur + buyers[i];
    cur = 2 * cur + buyers[i];
  }
  out << ans * (p / 2) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}