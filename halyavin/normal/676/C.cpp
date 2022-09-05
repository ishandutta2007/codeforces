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
  size_t k;
  in >> n >> k;
  std::string s;
  in >> s;
  std::vector<int> as = {-1};
  std::vector<int> bs = {-1};
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      as.push_back(i);
    } else {
      bs.push_back(i);
    }
  }
  as.push_back(n);
  bs.push_back(n);
  if (as.size() < k + 2 || bs.size() < k + 2) {
    out << n << std::endl;
    return;
  }
  int ans = 0;
  for (size_t i = 0; i + k + 1 < as.size(); i++) {
    ans = std::max(ans, as[i + k + 1] - as[i] - 1);
  }
  for (size_t i = 0; i + k + 1 < bs.size(); i++) {
    ans = std::max(ans, bs[i + k + 1] - bs[i] - 1);
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}