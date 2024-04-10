// Maximize the Intersections (https://codeforces.com/contest/1552/problem/C)
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
        int n, k; cin >> n >> k;
        set<int> rem;
        rep(i, 2 * n)
            rem.emplace(i);

        vector<pair<int, int>> chords(k);
        for (auto& [x, y] : chords)
            cin >> x >> y, --x, --y, rem.erase(x), rem.erase(y);

        vector remv(all(rem));
        rep(i, n - k)
            chords.emplace_back(remv[i], remv[i + n - k]);

        int ans = 0;
        rep(i, n) rep(j, i + 1, n) {
            auto [x1, y1] = chords[i];
            auto [x2, y2] = chords[j];
            array<int, 4> a{x1, y1, x2, y2};
            sort(all(a));
            array<bool, 4> ty{};
            rep(k, 4)
                ty[k] = (a[k] == x1 || a[k] == y1);
            ans += !((ty[0] && ty[1]) || (ty[1] && ty[2]) || (ty[2] && ty[3]) || (ty[3] && ty[0]));
        }

        cout << ans << '\n';
    }
}