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
// Problem: (18) Towers (Difficulty: 4) (http://codeforces.com/problemset/problem/479/B)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    vector<pair<size_t, size_t>> moves;
    size_t last_improv = 0;
    for (size_t i = 0; i < k; ++i) {
        auto [min_it, max_it] = minmax_element(begin(a), end(a));
        if (*min_it == *max_it) {
            break;
        }

        int diff_before = *max_it - *min_it;
        ++*min_it;
        --*max_it;
        moves.emplace_back(max_it - begin(a), min_it - begin(a));

        auto [min_it2, max_it2] = minmax_element(begin(a), end(a));
        if (*max_it2 - *min_it2 < diff_before) {
            last_improv = moves.size();
        }
    }

    auto [min_it, max_it] = minmax_element(begin(a), end(a));
    cout << (*max_it - *min_it) << ' ' << last_improv << '\n';
    for (size_t i = 0; i < last_improv; ++i) {
        auto [a, b] = moves[i];
        cout << (a + 1) << ' ' << (b + 1) << '\n';
    }

    return 0;
}