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
// Problem: A: MP3
// Link:    https://codeforces.com/contest/1198/problem/A

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    uint32_t I;
    cin >> n >> I;

    uint32_t k = min((uint32_t)31, (uint32_t)(I * 8 / n));
    uint32_t width = 1u << k;

    vector<uint32_t> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    sort(begin(a), end(a));
    vector<pair<uint32_t, uint32_t>> b;
    b.emplace_back(a[0], 1);
    for (size_t i = 1; i < n; ++i) {
        if (b.back().first == a[i]) {
            b.back().second++;
        } else {
            b.emplace_back(a[i], 1);
        }
    }

    size_t min_changed = numeric_limits<size_t>::max();
    size_t before = 0;
    size_t after = n;
    auto l_it = begin(b);
    auto r_it = l_it;
    for (size_t i = 0; r_it != end(b) && i < width; ++i) {
        after -= (r_it++)->second;
    }
    while (r_it != end(b)) {
        min_changed = min(min_changed, after + before);
        before += (l_it++)->second;
        after -= (r_it++)->second;
    }

    min_changed = min(min_changed, before);

    cout << min_changed << '\n';

    return 0;
}