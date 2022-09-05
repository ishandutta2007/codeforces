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

const int mod = 1'000'000'007;

int add32(int x, int y) {
  int res = x + y;
  if (res >= mod) res -= mod;
  return res;
}

int mul32(int x, int y) {
  return int(int64_t(x) * y % mod);
}

struct Solution {
    std::vector<int> pow2;
    std::array<std::vector<int>, 21> bins;
    std::vector<int> minp;
    void init() {
        pow2.resize(1000001);
        pow2[0] = 1;
        for (size_t i = 1; i < pow2.size(); i++) {
            pow2[i] = mul32(pow2[i - 1], 2);
        }
        const size_t MAX_BIN = 1000001;
        for (std::vector<int>& lin : bins) {
            lin.resize(MAX_BIN);
            lin[0] = 1;
        }
        for (size_t i = 1; i < MAX_BIN; i++) {
            bins[0][i] = 1;
            for (size_t j = 1; j < bins.size(); j++) {
                bins[j][i] = add32(bins[j - 1][i], bins[j][i - 1]);
            }
        }
        minp.resize(1000001);
        for (size_t i = 2; i < minp.size(); i++) {
            if (minp[i] != 0) continue;
            minp[i] = i;
            for (size_t j = 2 * i; j < minp.size(); j += i) {
                if (minp[j] == 0) {
                    minp[j] = i;
                }
            }
        }
    }
    void run(std::istream& in, std::ostream& out) {
        init();
        int q;
        in >> q;
        for (int i = 0; i < q; i++) {
            int x, y;
            in >> x >> y;
            int ans = pow2[y - 1];
            while (x > 1) {
                int p = minp[x];
                int a = 0;
                while (x % p == 0) {
                    a++;
                    x /= p;
                }
                ans = mul32(ans, bins[a][y - 1]);
            }
            out << ans << "\n";
        }
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}