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
    std::string s;
    int n, x;
    std::vector<std::vector<std::vector<int>>> dyn;
    std::vector<int> fibPow;
    void run(std::istream& in, std::ostream& out) {
        in >> n >> x;
        in >> s;

        dyn.assign(std::max(2, x + 1), std::vector<std::vector<int>>(n, std::vector<int>(n)));
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                dyn[0][i][i] = 1;
            } else {
                dyn[1][i][i] = 1;
            }
        }
        fibPow.resize(dyn.size());
        fibPow[0] = 2;
        fibPow[1] = 2;
        for (size_t i = 2; i < fibPow.size(); i++) {
            fibPow[i] = mul32(fibPow[i - 1], fibPow[i - 2]);
        }
        for (int f = 2; f < dyn.size(); f++) {
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    int res = 0;
                    res = add32(res, mul32(dyn[f - 1][i][j], (j == n - 1) ? fibPow[f - 2] : 1));
                    res = add32(res, mul32(dyn[f - 2][i][j], (i == 0) ? fibPow[f - 1] : 1));
                    for (int k = i; k < j; k++) {
                        res = add32(res, mul32(dyn[f - 1][i][k], dyn[f - 2][k + 1][j]));
                    }
                    dyn[f][i][j] = res;
                }
            }
        }
        out << dyn[x][0][n - 1] << "\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}