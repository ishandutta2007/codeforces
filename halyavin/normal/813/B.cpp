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

std::vector<int64_t> getAll(int64_t a, int64_t max) {
  std::vector<int64_t> result{1};
  int64_t cur = 1;
  int64_t limit = (max - 1) / a;
  while (cur <= limit) {
    cur *= a;
    result.push_back(cur);
  }
  return result;
}

void run(std::istream &in, std::ostream &out) {
  int64_t x, y, l, r;
  in >> x >> y >> l >> r;
  r++;
  std::vector<int64_t> xs = getAll(x, r);
  std::vector<int64_t> ys = getAll(y, r);
  std::vector<int64_t> bad;
  for (int64_t a : xs) {
    for (int64_t b : ys) {
      if (a + b >= l && a + b < r) {
        bad.push_back(a + b);
      }
    }
  }
  bad.push_back(l - 1);
  bad.push_back(r);
  std::sort(bad.begin(), bad.end());
  int64_t maxLen = 0;
  for (size_t i = 0; i + 1 < bad.size(); i++) {
    maxLen = std::max(maxLen, bad[i + 1] - bad[i] - 1);
  }
  out << maxLen << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}