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
#include <array>


struct Solution {
  std::array<std::array<std::array<std::array<int64_t, 2>, 17>, 16>, 16> dyn;

  void fillDyn() {
    for (int i = 0; i < 16; i++) {
      for (int j = 0; j <= 16; j++) {
        for (int k = 0; k < 2; k++) {
          dyn[0][i][j][k] = k == 0 ? 1 : 0;
        }
      }
    }
    for (int digits = 1; digits < 16; digits++) {
      for (int s = 0; s < 16; s++) {
        for (int bit = 0; bit <= 16; bit++) {
          int mask = bit > 0 && bit <= 4 ? (1 << (bit - 1)) : 0;
          for (int needMax = 0; needMax < 2; needMax++) {
            int64_t res = 0;
            for (int d = 0; d <= s; d++) {
              if ((d & mask) != mask) {
                continue;
              }
              int needMaxPrev = d == s ? 0 : needMax;
              res += dyn[digits - 1][s][std::max(0, bit - 4)][needMaxPrev];
            }
            dyn[digits][s][bit][needMax] = res;
          }
        }
      }
    }
  }

  void inc(std::vector<int>& num) {
    for (size_t i = 0; i < 16; i++) {
      if (num[i] < 15) {
        num[i]++;
        return;
      }
      num[i] = 0;
    }
  }

  std::vector<int> toVec(const std::string& r) {
    std::vector<int> res(16);
    for (size_t i = 0; i < r.length(); i++) {
      if (r[i] >= '0' && r[i] <= '9') {
        res[i] = r[i] - '0';
      } else {
        res[i] = r[i] - 'a' + 10;
      }
    }
    return res;
  }

  int64_t get(std::vector<int>& num) {
    int64_t res = 0;
    for (int digits = 0; digits < 16; digits++) {
      while (num[digits] > 0) {
        num[digits]--;
        for (int s = 0; s < 16; s++) {
          int needMax = 1;
          bool good = true;
          for (int i = digits; i < 16; i++) {
            if (num[i] > s) {
              good = false;
              break;
            }
            if (num[i] == s) {
              needMax = 0;
            }
          }
          if (!good) {
            continue;
          }
          if (s >= digits * 4) {
            if ((num[s / 4] & (1 << (s % 4))) == 0) {
              continue;
            }
          }
          res += dyn[digits][s][s + 1][needMax];
        }
      }
    }
    return res;
  }

  void run(std::istream& in, std::ostream& out) {
    fillDyn();
    int q;
    in >> q;
    for (int test = 0; test < q; test++) {
      std::string l, r;
      in >> l >> r;
      std::reverse(l.begin(), l.end());
      std::reverse(r.begin(), r.end());
      std::vector<int> vl = toVec(l);
      std::vector<int> vr = toVec(r);
      inc(vr);
      int64_t answer = get(vr) - get(vl);
      out << answer << "\n";
    }
    out.flush();
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}