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
    int n, m;
    std::vector<std::vector<bool>> field;
    std::vector<std::vector<int>> d1, d2, d3, d4;
    std::vector<std::vector<int>> dd;
    std::vector<std::vector<bool>> covered;

    void fillDs() {
        d1.assign(n, std::vector<int>(m));
        d2.assign(n, std::vector<int>(m));
        d3.assign(n, std::vector<int>(m));
        d4.assign(n, std::vector<int>(m));
        for (int i = 0; i < n; i++) {
            int cur = -1;
            for (int j = 0; j < m; j++) {
                if (field[i][j]) {
                    cur++;
                } else {
                    cur = -1;
                }
                d1[i][j] = cur;
            }
            cur = -1;
            for (int j = m - 1; j >= 0; j--) {
                if (field[i][j]) {
                    cur++;
                } else {
                    cur = -1;
                }
                d2[i][j] = cur;
            }
        }
        for (int j = 0; j < m; j++) {
            int cur = -1;
            for (int i = 0; i < n; i++) {
                if (field[i][j]) {
                    cur++;
                } else {
                    cur = -1;
                }
                d3[i][j] = cur;
            }
            cur = -1;
            for (int i = n - 1; i >= 0; i--) {
                if (field[i][j]) {
                    cur++;
                } else {
                    cur = -1;
                }
                d4[i][j] = cur;
            }
        }
        dd.assign(n, std::vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dd[i][j] = std::min(d1[i][j], std::min(d2[i][j], std::min(d3[i][j], d4[i][j])));
            }
        }
    }

    void fillCovered() {
        covered.assign(n, std::vector<bool>(m));
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < m; j++) {
                if (dd[i][j] > 0) {
                    cur = std::max(cur - 1, dd[i][j]);
                } else {
                    cur--;
                }
                covered[i][j] = covered[i][j] || (cur >= 0);
            }
            cur = 0;
            for (int j = m- 1; j >= 0; j--) {
                if (dd[i][j] > 0) {
                    cur = std::max(cur - 1, dd[i][j]);
                } else {
                    cur--;
                }
                covered[i][j] = covered[i][j] || (cur >= 0);
            }
        }
        for (int j = 0; j < m; j++) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                if (dd[i][j] > 0) {
                    cur = std::max(cur - 1, dd[i][j]);
                } else {
                    cur--;
                }
                covered[i][j] = covered[i][j] || (cur >= 0);
            }
            cur = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (dd[i][j] > 0) {
                    cur = std::max(cur - 1, dd[i][j]);
                } else {
                    cur--;
                }
                covered[i][j] = covered[i][j] || (cur >= 0);
            }
        }
    }


    void run(std::istream& in, std::ostream& out) {
        in >> n >> m;
        field.assign(n, std::vector<bool>(m));
        for (int i = 0; i < n; i++) {
            std::string s;
            in >> s;
            for (int j = 0; j < m; j++) {
                field[i][j] = s[j] == '*';
            }
        }
        fillDs();
        fillCovered();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] && !covered[i][j]) {
                    out << "-1\n";
                    return;
                }
            }
        }
        std::vector<std::vector<int>> answer;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dd[i][j] > 0) {
                    answer.push_back(std::vector<int>{i + 1, j + 1, dd[i][j]});
                }
            }
        }
        out << answer.size() << "\n";
        for (const std::vector<int>& star : answer) {
            out << star[0] << " " << star[1] << " " << star[2] << "\n";
        }
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}