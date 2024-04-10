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
    std::vector<std::vector<int>> lessons;
    std::vector<std::vector<int>> moves;
    std::vector<std::vector<int>> dyn;
    int n, m, k;

    void calcMoves() {
        moves.assign(n, std::vector<int>(k + 1, m));
        for (int i = 0; i < n; i++) {
            for (size_t j1 = 0; j1 < lessons[i].size(); j1++) {
                for (size_t j2 = j1; j2 < lessons[i].size(); j2++) {
                    int skip = lessons[i].size() - (j2 - j1 + 1);
                    if (skip <= k) {
                        moves[i][skip] = std::min(moves[i][skip], lessons[i][j2] - lessons[i][j1] + 1);
                    }
                }
            }
            if (lessons[i].size() <= k) {
                std::fill(moves[i].begin() + lessons[i].size(), moves[i].end(), 0);
            }
        }
    }

    void calcDyn() {
        dyn.assign(n + 1, std::vector<int>(k + 1));
        dyn[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                int res = 1'000'000'000;
                for (int s = 0; s <= j; s++) {
                    res = std::min(res, dyn[i - 1][s] + moves[i - 1][j - s]);
                }
                dyn[i][j] = res;
            }
        }
    }

    void run(std::istream& in, std::ostream& out) {
        in >> n >> m >> k;
        lessons.assign(n, std::vector<int>());
        for (int i = 0; i < n; i++) {
            std::string s;
            in >> s;
            for (size_t j = 0; j < s.length(); j++) {
                if (s[j] == '1') {
                    lessons[i].push_back(j);
                }
            }
        }
        calcMoves();
        calcDyn();
        out << dyn[n][k] << "\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}