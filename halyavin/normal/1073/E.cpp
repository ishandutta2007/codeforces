#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>

const int mod = 998244353;

int add32(int x, int y) {
  int res = x + y;
  if (res >= mod) res -= mod;
  return res;
}

int mul32(int x, int y) {
  return int(int64_t(x) * y % mod);
}

int sub32(int x, int y) {
  int res = x - y;
  if (res < 0) res += mod;
  return res;
}

struct Solution {
    int64_t l, r;
    int k;
    std::array<std::array<std::pair<int, int>, 1024>, 19> dyn;
    std::array<int, 19> pow10;
    std::array<int, 19> dynAll;

    void init() {
        pow10[0] = 1;
        for (int i = 1; i <= 18; i++) {
            pow10[i] = mul32(pow10[i - 1], 10);
        }
        for (size_t i = 0; i < 1024; i++) {
            if (__builtin_popcount(i) <= k) {
                dyn[0][i] = {1,0};
            } else {
                dyn[0][i] = {0,0};
            }
        }
        for (size_t len = 1; len <= 18; len++) {
            for (size_t i = 0; i < 1024; i++) {
                int count = __builtin_popcount(i);
                if (count > k) {
                    dyn[len][i] = {0, 0};
                    continue;
                }
                int res1 = 0;
                int res2 = 0;
                for (int j = 0; j < 10; j++) {
                    if ((i & (1 << j)) != 0) {
                        res1 = add32(res1, dyn[len - 1][i].first);
                        res2 = add32(res2, dyn[len - 1][i].second);
                        res2 = add32(res2, mul32(dyn[len - 1][i].first, mul32(j, pow10[len - 1])));
                    } else if (count < k) {
                        size_t nexti = i + (1 << j);
                        res1 = add32(res1, dyn[len-1][nexti].first);
                        res2 = add32(res2, dyn[len - 1][nexti].second);
                        res2 = add32(res2, mul32(dyn[len -1][nexti].first, mul32(j, pow10[len - 1])));
                    }
                }
                dyn[len][i] = {res1, res2};
            }
        }
        dynAll[0] = 0;
        for (size_t len = 1; len <= 18; len++) {
            dynAll[len] = dynAll[len - 1];
            for (int j = 1; j <= 9; j++) {
                dynAll[len] = add32(dynAll[len], dyn[len - 1][(1 << j)].second);
                dynAll[len] = add32(dynAll[len], mul32(dyn[len - 1][(1 << j)].first, mul32(j, pow10[len - 1])));
            }
        }
    }

    int64_t f(int64_t x) {
        if (x < 10) {
            return (x - 1) * x / 2;
        }
        int64_t sub = 1;
        int64_t mul = 10;
        int last = 1;
        int64_t ans = 0;
        while (true) {
            while (x > sub && x % mul != 0) {
                x -= sub;
                int mask = 0;
                int64_t y = x / sub;
                while (y > 0) {
                    mask |= (1 << (y % 10));
                    y /= 10;
                }
                ans = add32(ans, dyn[last - 1][mask].second);
                ans = add32(ans, mul32(x % mod, dyn[last -1][mask].first));
            }
            if (x == sub) {
                ans = add32(ans, dynAll[last - 1]);
                return ans;
            }
            sub = mul;
            mul *= 10;
            last++;
        }
    }

    int64_t g(int64_t x) {
        int res = 0;
        for (int i = 1; i < x; i++) {
            int mask = 0;
            int j = i;
            while (j > 0) {
                mask |= (1 << (j % 10));
                j /= 10;
            }
            if (__builtin_popcount(mask) <= k) {
                res = add32(res, i);
            }
        }
        return res;
    }

    void run(std::istream& in, std::ostream& out) {
//        for (k = 1; k <= 10; k++) {
//            init();
//            for (int test = 1; test <= 1000000; test++) {
//                if (f(test) != g(test)) {
//                    out << k << " " << test << " " << f(test) << " " << g(test) << "\n";
//                    return;
//                }
//            }
//        }
        in >> l >> r >> k;
        init();
        out << sub32(f(r + 1), f(l)) << "\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}