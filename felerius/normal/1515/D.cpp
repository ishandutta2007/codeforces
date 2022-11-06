// Phoenix and Socks (https://codeforces.com/contest/1515/problem/D)
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
        int n, l, r; cin >> n >> l >> r;
        map<int, pair<int, int>> m;
        rep(i, l) {
            int c; cin >> c; --c;
            m[c].first++;
        }
        rep(i, r) {
            int c; cin >> c; --c;
            m[c].second++;
        }

        for (auto& [c, p] : m) {
            int x = min(p.first, p.second);
            l -= x;
            r -= x;
            p.first -= x;
            p.second -= x;
        }

        if (r > l) {
            swap(l, r);
            for (auto& [c, p] : m)
                swap(p.first, p.second);
        }

        int ans = 0;
        for (auto& [c, p] : m) {
            int x = min((l - r) / 2, p.first / 2);
            p.first -= 2 * x;
            l -= 2 * x;
            ans += x;
        }

        ans += r + (l - r);
        cout << ans << '\n';
    }
}