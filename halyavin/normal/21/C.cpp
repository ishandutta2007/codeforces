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
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  int sum = std::accumulate(as.begin(), as.end(), 0);
  if (sum % 3 != 0) {
    out << "0" << std::endl;
    return;
  }
  int sum3 = sum / 3;
  std::vector<bool> flags1(n);
  std::vector<bool> flags2(n);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cur += as[i];
    flags1[i] = cur == sum3;
  }
  cur = 0;
  int all = 0;
  for (int i = n - 1; i > 0; i--) {
    cur += as[i];
    flags2[i] = cur == sum3;
    all += (cur == sum3);
  }
  int64_t ans = 0;
  for (int i = 0; i < n - 2; i++) {
    all -= flags2[i + 1];
    if (flags1[i]) {
      ans += all;
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