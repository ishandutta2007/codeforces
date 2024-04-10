#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (24) DZY Loves Sequences (Difficulty: 4) (http://codeforces.com/problemset/problem/446/A)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a) cin >> ai;

    vector<pair<size_t, size_t>> seqs;
    size_t begin = 0;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] <= a[i - 1]) {
            if (i > begin + 1) {
                seqs.emplace_back(begin, i);
            }

            begin = i;
        }
    }

    if (begin < n - 1) {
        seqs.emplace_back(begin, n);
    }

    size_t res = min(size_t{2}, n);
    for (auto [begin, end] : seqs) {
        res = max(res, min(end - begin + 1, n));
    }

    for (size_t i = 1; i < seqs.size(); ++i) {
        auto [prev_beg, prev_end] = seqs[i - 1];
        auto [cur_beg, cur_end] = seqs[i];
        if (prev_end != cur_beg) {
            continue;
        }

        if (a[prev_end - 1] + 1 < a[cur_beg + 1] || a[prev_end - 2] + 1 < a[cur_beg]) {
            res = max(res, cur_end - prev_beg);
        }
    }

    cout << res << '\n';

    return 0;
}