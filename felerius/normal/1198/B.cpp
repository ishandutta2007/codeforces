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

// Contest: Codeforces Round #576 (Div. 1) (https://codeforces.com/contest/1198)
// Problem: B: Welfare State
// Link:    https://codeforces.com/contest/1198/problem/B

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<pair<bool, uint32_t>> a(n);
    for (auto& ai : a) {
        cin >> ai.second;
        ai.first = false;
    }

    size_t q;
    cin >> q;

    vector<pair<size_t, uint32_t>> e(q);
    for (size_t i = 0; i < q; ++i) {
        int j;
        cin >> j;
        if (j == 1) {
            cin >> e[i].first >> e[i].second;
            e[i].first--;
        } else {
            e[i].first = n;
            cin >> e[i].second;
        }
    }

    uint32_t max_payout = 0;
    for (auto it = rbegin(e); it != rend(e); ++it) {
        auto [p, x] = *it;
        if (p == n) {
            max_payout = max(max_payout, x);
        } else {
            if (!a[p].first) {
                a[p].first = true;
                a[p].second = max(max_payout, x);
            }
        }
    }

    for (auto [b, ai] : a) {
        cout << (b ? ai : max(max_payout, ai)) << ' ';
    }

    cout << '\n';

    return 0;
}