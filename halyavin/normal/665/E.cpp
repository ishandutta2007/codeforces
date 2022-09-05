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

struct Solution {
  std::vector<size_t> nums;
  size_t k;

  int64_t solve(size_t f1, size_t e1, size_t f2, size_t e2, int bit) {
    if (f1 == e1 || f2 == e2) {
      return 0;
    }
    if (bit == 0) {
      return int64_t(e1 - f1) * int64_t(e2 - f2);
    }
    bit--;
    size_t m1, m2;
    for (m1 = f1; m1 < e1; m1++) {
      if ((nums[m1] & (1 << bit)) != 0) {
        break;
      }
    }
    for (m2 = f2; m2 < e2; m2++) {
      if ((nums[m2] & (1 << bit)) != 0) {
        break;
      }
    }
    if ((k & (1 << bit)) == 0) {
      return int64_t(e1 - m1) * int64_t(m2 - f2) + int64_t(m1 - f1) * int64_t(e2 - m2) +
          solve(f1, m1, f2, m2, bit) + solve(m1, e1, m2, e2, bit);
    } else {
      return solve(f1, m1, m2, e2, bit) + solve(m1, e1, f2, m2, bit);
    }
  }
  void run(std::istream& in, std::ostream& out) {
    int n;
    in >> n >> k;
    std::vector<size_t> as(n);
    for (int i = 0; i < n; i++) {
      in >> as[i];
    }
    nums.resize(n + 1);
    nums[0] = 0;
    for (int i = 0; i < n; i++) {
      nums[i + 1] = nums[i] ^ as[i];
    }
    std::sort(nums.begin(), nums.end());
    int64_t res = solve(0, nums.size(), 0, nums.size(), 32) / 2;
    out << res << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}