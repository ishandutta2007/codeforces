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
  std::vector<int> p(n);
  std::vector<int> inv(n);
  for (int i = 0; i < n; i++) {
    in >> p[i];
    p[i]--;
  }
  for (int i = 0; i < n; i++) {
    inv[p[i]]=i;
  }
  int ans = 1;
  int cur = 1;
  for (int i = 1; i < n; i++) {
    if (inv[i] > inv[i - 1]) {
      cur++;
      ans = std::max(ans, cur);
    } else {
      cur = 1;
    }
  }
  out << n - ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}