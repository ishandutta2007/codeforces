#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <set>
#include <string>
#include <tuple>
#include <vector>

// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (31) Main Sequence (Difficulty: 5) (http://codeforces.com/problemset/problem/286/C)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n; cin >> n;
    vector<int32_t> p(n);
    for (auto& pi : p) cin >> pi;

    size_t t; cin >> t;
    vector<size_t> q(t);
    for (auto& qi : q) { cin >> qi; qi = n - qi; }
    sort(begin(q), end(q));

    reverse(begin(p), end(p));
    vector<int32_t> open;
    auto it = begin(q);
    vector<int32_t> res(n);
    for (size_t i = 0; i < n; ++i) {
        bool force_open = false;
        if (it != end(q) && *it == i) {
            ++it;
            force_open = true;
        }

        if (!force_open && !open.empty() && open.back() == p[i]) {
            open.pop_back();
            res[i] = -p[i];
        } else {
            open.emplace_back(p[i]);
            res[i] = p[i];
        }
    }

    if (open.empty()) {
        cout << "YES\n";
        for (auto rit = rbegin(res); rit != rend(res); ++rit) {
            cout << -*rit << ' ';
        }

        cout << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}