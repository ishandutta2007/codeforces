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

void addAnswer(const std::vector<int>& row, size_t k, int& score, int& changed) {
    int opt = 0;
    int optChanged = 0;
    int ones = 0;
    int sum = std::accumulate(row.begin(), row.begin() + k, 0);
    for (size_t i = 0; i < row.size(); i++) {
        if (sum > opt && row[i] == 1) {
            opt = sum;
            optChanged = ones;
        }
        if (i + k < row.size()) {
            sum += row[i + k];
        }
        sum -= row[i];
        ones += row[i];
    }
    score += opt;
    changed += optChanged;
}

void run(std::istream& in, std::ostream& out) {
    size_t n, m, k;
    in >> n >> m >> k;
    std::vector<std::vector<int>> field(m, std::vector<int>(n));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            in >> field[j][i];
        }
    }
    int score = 0;
    int changed = 0;
    for (const auto& row : field) {
        addAnswer(row, k, score, changed);
    }
    out << score << " " << changed << std::endl;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}