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
  int n;
  std::vector<int> nums;
  std::vector<int> ps;
  std::vector<int> nums2;
  int t;
  void getPrimeDivisors() {
      ps.clear();
      int copyn = n;
      for (int i = 2; i * i <= copyn; i++) {
          if (copyn % i == 0) {
              ps.push_back(i);
              do {
                  copyn /= i;
              } while (copyn % i == 0);
          }
      }
      if (copyn > 1) {
          ps.push_back(copyn);
      }
  }

  bool check() {
      for (int p : ps) {
          int shift = t / p;
          for (int i = 0; i < t; i += p) {
              int v = nums2[i];
              for (int j = 0; j < p; j++) {
                  nums2[(i + j * shift) % t] -= v;
              }
          }
      }
      for (int i = 0; i < t; i++) {
          if (nums2[i] != 0) {
              return false;
          }
      }
      return true;
  }

  void run(std::istream& in, std::ostream& out) {
      in >> n;
      std::string s;
      in >> s;
      nums.resize(n);
      for (int i = 0; i < n; i++) {
          nums[i] = s[i] - '0';
      }
      getPrimeDivisors();
      t = 1;
      for (int p : ps) {
          t *= p;
      }
      nums2.resize(t);
      int problems = n / t;
      for (int i = 0; i < problems; i++) {
          for (int j = 0; j < t; j++) {
              nums2[j] = nums[j * problems + i];
          }
          if (!check()) {
              out << "NO\n";
              return;
          }
      }
      out << "YES\n";
  }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}