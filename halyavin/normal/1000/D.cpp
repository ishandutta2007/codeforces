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

const int mod = 998244353;

int add32(int x, int y) {
    int res = x + y;
    if (res >= mod) res -= mod;
    return res;
}

int sub32(int x, int y) {
    int res = x - y;
    if (res < 0) res += mod;
    return res;
}

int mul32(int x, int y) {
    return int(int64_t(x) * y % mod);
}

struct Solution {
    int n;
    std::vector<int> as;
    std::vector<std::vector<int>> bins;
    void calcBin() {
        bins.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            bins[i].resize(i + 1);
        }
        bins[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            bins[i][0] = 1;
            bins[i][i] = 1;
            for (int j = 1; j < i; j++) {
                bins[i][j] = add32(bins[i - 1][j - 1], bins[i - 1][j]);
            }
        }
    }
    void run(std::istream& in, std::ostream& out) {
        in >> n;
        as.resize(n);
        for (int i = 0; i < n; i++) {
            in >> as[i];
            if (as[i] < 0) as[i] = 0;
        }
        calcBin();
        std::vector<int> dynA(n + 1);
        dynA[0] = 1;
        for (int i = 1; i <= n; i++) {
            int sum = 1;
            for (int j = 0; j < i; j++) {
                if (as[j] == 0) continue;
                int rest = i - j - 1;
                if (as[j] <= rest) {
                    sum = add32(sum, mul32(dynA[j], bins[rest][as[j]]));
                }
            }
            dynA[i] = sum;
        }
        out << sub32(dynA[n], 1) << "\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}