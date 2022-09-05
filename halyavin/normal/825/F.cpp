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

std::vector<int> getSelfPi(const std::string& s, int pos) {
    size_t n = s.length() - pos;
    std::vector<int> res(n);
    size_t cur = 0;
    for (size_t i = 1; i < n; i++) {
        while (s[i + pos] != s[cur + pos] && cur > 0) {
            cur = res[cur - 1];
        }
        if (s[i + pos] == s[cur + pos]) cur++;
        res[i] = cur;
    }
    return res;
}

struct Solution {
  std::string s;
  std::vector<std::vector<int>> pis;
  void buildPi() {
      pis.resize(s.length());
      for (int i = 0; i < s.length(); i++) {
          pis[i] = getSelfPi(s, i);
      }
  }
  int log10(int diff) {
      int res = 0;
      while (diff > 0) {
          res++;
          diff /= 10;
      }
      return res;
  }

  void run(std::istream& in, std::ostream& out) {
      in >> s;
      buildPi();
      std::vector<int> dyn(s.length() + 1, 1000000);
      dyn[0] = 0;
      for (int i = 0; i < s.length(); i++) {
          int init = dyn[i];
          for (int j = i + 1; j <= s.length(); j++) {
              dyn[j] = std::min(dyn[j], init + j - i + 1);
              int len = pis[i][j - i - 1];
              int diff = j - i - len;
              if ((j - i) % diff == 0) {
                  dyn[j] = std::min(dyn[j], init + diff + log10((j - i) / diff));
              }

          }
      }
      out << dyn[s.length()] << std::endl;
  }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}