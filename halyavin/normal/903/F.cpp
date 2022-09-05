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
    std::array<std::string, 4> matrix;
    std::array<int, 4> cost;
    std::vector<std::array<int, 256>> dyn;
    int n;
    void run(std::istream& in, std::ostream& out) {
        in >> n;
        for (int i = 0; i < 4; i++) {
            in >> cost[i];
        }
        for (int i = 0; i < 4; i++) {
            in >> matrix[i];
        }
        dyn.clear();
        dyn.resize(n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 255; j >= 0; j--) {
                int cur = 1000000000;
                std::array<int, 4> mask;
                bool big = true;
                for (int k = 0; k < 4; k++) {
                    mask[k] = (j >> (2 * k)) & 3;
                    if (mask[k] == 0 && matrix[k][i] == '*') {
                        big = false;
                    }
                }
                if (big) {
                    int jj = 0;
                    for (int k = 0; k < 4; k++) {
                        jj += std::max(0, mask[k] - 1) << (2 * k);
                    }
                    cur = dyn[i][jj];
                }
                for (int size = 1; size < 4; size++) {
                    for (int start = 0; start + size <= 4; start++) {
                        std::array<int, 4> mask2 = mask;
                        for (int i = 0; i < size; i++) {
                            mask2[i + start] = std::max(mask2[i + start], size);
                        }
                        int jj = 0;
                        for (int k = 0; k < 4; k++) {
                            jj += mask2[k] << (2 * k);
                        }
                        if (jj > j) {
                            cur = std::min(cur, dyn[i + 1][jj] + cost[size - 1]);
                        }
                    }
                }
                cur = std::min(cur, dyn[i][255] + cost[3]);
                dyn[i + 1][j] = cur;
            }
        }
        out << dyn[n][0] << "\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}