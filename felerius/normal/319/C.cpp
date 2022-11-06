#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>

// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (49) Kalila and Dimna in the Logging Industry (Difficulty: 5) (http://codeforces.com/problemset/problem/319/C)

using namespace std;

using ll = int64_t;
using Point = pair<ll, ll>;

ll dot(Point a, Point b) { return a.first * b.first + a.second * b.second; }
long double dot_approx(Point a, Point b) { return (long double)a.first * (long double)b.first + (long double)a.second * (long double)b.second; }
ll cross(Point a, Point b) { return a.first * b.second - a.second * b.first; }
Point sub(Point a, Point b) { return {a.first - b.first, a.second - b.second}; }

int main() {
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& ai : a) cin >> ai;
    for (auto& bi : b) cin >> bi;

    vector<Point> hull, vecs;
    hull.emplace_back(b[0], 0);

    vector<ll> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        Point query = {a[i], 1};
        auto it = lower_bound(rbegin(vecs), rend(vecs), query, [](Point a, Point b) {
            return cross(a, b) > 0;
        });
        auto from_back = it - rbegin(vecs);
        dp[i] = dot(query, hull[hull.size() - 1 - from_back]);

        Point new_line = {b[i], dp[i]};
        // This can overflow int64_t with exact calculation, lets just use long
        // double and hope it is enough to get the correct sign...
        while (!vecs.empty() && dot_approx(vecs.back(), sub(new_line, hull.back())) < 0) {
            hull.pop_back();
            vecs.pop_back();
        }
        if (!hull.empty()) {
            auto diff = sub(new_line, hull.back());
            vecs.emplace_back(diff.second, -diff.first);
        }
        hull.push_back(new_line);
    }

    cout << dp.back() << '\n';

    return 0;
}