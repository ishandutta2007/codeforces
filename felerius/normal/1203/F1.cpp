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

// Contest: Codeforces Round #579 (Div. 3) (https://codeforces.com/contest/1203)
// Problem: F1: Complete the Projects (easy version) (https://codeforces.com/contest/1203/problem/F1)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    int r;
    cin >> n >> r;

    vector<pair<int, int>> pos;
    vector<tuple<int, int, int>> neg;
    for (size_t i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (b >= 0) {
            pos.emplace_back(a, b);
        } else {
            neg.emplace_back(a + b, a, b);
        }
    }

    sort(begin(pos), end(pos));
    size_t count = 0;
    for (auto [minr, change] : pos) {
        if (r >= minr) {
            r += change;
            ++count;
        }
    }

    sort(begin(neg), end(neg));
    vector<size_t> prev(r + 1, 0);
    vector<size_t> cur(r + 1, 0);
    for (size_t i = 0; i < neg.size(); ++i) {
        auto [_, minr, change] = neg[i];
        auto k = min(r + 1, max(minr, -change));
        for (size_t j = 0; j < k; ++j) {
            cur[j] = prev[j];
        }
        for (size_t j = k; j < r + 1; ++j) {
            cur[j] = max(prev[j], 1 + prev[j + change]);
        }

        swap(cur, prev);
    }

    cout << (prev[r] + count == n ? "YES" : "NO") << '\n';

    return 0;
}