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
  int n, k;
  in >> n >> k;
  std::vector<int64_t> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  int64_t sum = std::accumulate(as.begin(), as.end(), int64_t(0));
  int64_t minDiff = (sum % n == 0) ? 0 : 1;
  std::sort(as.begin(), as.end());
  int64_t cur = as[0];
  int64_t left = k;
  for (int i = 1; i < n; i++) {
    if ((as[i] - cur) * i <= left) {
      left -= (as[i] - cur) * i;
      cur = as[i];
    } else {
      cur += left / i;
      break;
    }
  }
  int64_t cur2 = as[n - 1];
  int64_t left2 = k;
  for (int i = n - 2; i >= 0; i--) {
    if ((cur2 - as[i]) * (n - i - 1) <= left2) {
      left2 -= (cur2 - as[i]) * (n - i - 1);
      cur2 = as[i];
    } else {
      cur2 -= left2 / (n - i - 1);
      break;
    }
  }
  int64_t result = std::max(minDiff, cur2 - cur);
  out << result << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}