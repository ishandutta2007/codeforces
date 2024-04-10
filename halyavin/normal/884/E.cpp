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

int fromHex(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return (c - 'A') + 10;
}

struct Solution {
    std::vector<int> dsu;
    std::vector<int> freeColors;
    std::vector<bool> flags;
    std::vector<int> prevRow;
    std::vector<int> curRow;
    std::vector<int> row;
    int n, m, colors;
    int root(int v) {
        if (dsu[v] == v) return v;
        dsu[v] = root(dsu[v]);
        return dsu[v];
    }
    void join(int c1, int c2) {
        int r1 = root(c1);
        int r2 = root(c2);
        if (r1 != r2) {
            dsu[r1] = r2;
        }
    }
    void run(std::istream& in, std::ostream& out) {
        in >> n >> m;
        colors = m + 1;
        dsu.resize(colors);
        std::iota(dsu.begin(), dsu.end(), 0);
        flags.resize(colors);
        prevRow.assign(m, -1);
        curRow.assign(m, -1);
        row.assign(m, -1);
        freeColors.resize(colors);
        std::iota(freeColors.begin(), freeColors.end(), 0);
        int answer = 0;
        for (int i = 0; i < n; i++) {
            std::string s;
            in >> s;
            for (int j = 0; j < m / 4; j++) {
                int value = fromHex(s[j]);
                for (int k = 0; k < 4; k++) {
                    row[4 * j + k] = (value >> (3 - k)) & 1;
                }
            }
            for (int j = 0; j < m; j++) {
                if (row[j] == 0) {
                    curRow[j] = -1;
                    continue;
                }
                int c;
                if (j > 0 && row[j - 1] > 0) {
                    c = curRow[j - 1];
                } else {
                    c = freeColors.back();
                    freeColors.resize(freeColors.size() - 1);
                }
                curRow[j] = c;
                if (prevRow[j] > 0) {
                    join(c, prevRow[j]);
                }
            }
            for (int j = 0; j < m; j++) {
                if (prevRow[j] != -1) {
                    prevRow[j] = root(prevRow[j]);
                }
                if (curRow[j] != -1) {
                    curRow[j] = root(curRow[j]);
                }
            }
            flags.assign(colors, false);
            for (int j = 0; j < m; j++) {
                if (prevRow[j] != -1) {
                    flags[prevRow[j]] = true;
                }
            }
            for (int j = 0; j < m; j++) {
                if (curRow[j] != -1) {
                    flags[curRow[j]] = false;
                }
            }
            answer += std::accumulate(flags.begin(), flags.end(), 0);
            flags.assign(colors, false);
            freeColors.clear();
            for (int j = 0; j < m; j++) {
                if (curRow[j] != -1) {
                    flags[curRow[j]] = true;
                }
            }
            for (int j = 0; j < colors; j++) {
                if (!flags[j]) {
                    freeColors.push_back(j);
                    dsu[j] = j;
                }
            }
            std::swap(prevRow, curRow);
        }
        flags.assign(colors, false);
        for (int j = 0; j < m; j++) {
            if (prevRow[j] != -1) {
                flags[prevRow[j]] = true;
            }
        }
        answer += std::accumulate(flags.begin(), flags.end(), 0);
        out << answer << std::endl;
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}