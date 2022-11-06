// Two Tables (https://codeforces.com/contest/1555/problem/B)
#pragma GCC optimize("fast-math")
// begin "cp-lib/boilerplate.hpp"
#include <bits/stdc++.h>
#ifdef LOCAL
#  include <dbg.h>
#else
#  define dbg(...) do {} while (0)
#endif

#define _choose(_1, _2, _3, x, ...)     x
#define _rep(i, l, r)                   for (int i = l; i < r; ++i)
#define _rep0(i, r)                     _rep(i, 0, r)
#define rep(...)                        _choose(__VA_ARGS__, _rep, _rep0, _)(__VA_ARGS__)
#define _repr(i, r, l, ...)             for (int i = r; i >= l; --i)
#define repr(...)                       _repr(__VA_ARGS__, 0)
#define all(a)                          ::begin(a),::end(a)
#define trav(a, b)                      for (auto&& a : b)

using namespace std;
namespace cp_lib {}

using ll = long long;
using ld = long double;
[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
template <class C> int sz(const C& c) { return int(::size(c)); }
// end "cp-lib/boilerplate.hpp"

using namespace cp_lib;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        ll W, H; cin >> W >> H;
        ll x1, y1, x2, y2, w, h; cin >> x1 >> y1 >> x2 >> y2 >> w >> h;

        ll above = H - y2, below = y1, left = x1, right = W - x2;
        ll dist = INFL;
        if (x2 - x1 + w <= W)
            dist = min(dist, w - max(left, right));
        if (y2 - y1 + h <= H)
            dist = min(dist, h - max(above, below));
        dist = max(0ll, dist);
        cout << (dist == INFL ? -1 : dist) << '\n';
    }
}