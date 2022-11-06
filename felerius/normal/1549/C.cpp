// Web of Lies (https://codeforces.com/contest/1549/problem/C)
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

    int n, m; cin >> n >> m;
    vector<array<int, 3>> qs(m);
    rep(i, m) {
        int u, v; cin >> u >> v; --u, --v;
        qs[i] = {1, u, v};
    }
    int q; cin >> q;
    rep(_, q) {
        int ty; cin >> ty;
        if (ty == 3)
            qs.push_back({3, 0, 0});
        else {
            int u, v; cin >> u >> v; --u, --v;
            qs.push_back({ty, u, v});
        }
    }

    int ans = n;
    vector cnt(n, 0);
    for (auto [ty, u, v] : qs) {
        if (u > v)
            swap(u, v);

        if (ty == 3)
            cout << ans << '\n';
        else if (ty == 1 && !cnt[u]++)
            --ans;
        else if (ty == 2 && !--cnt[u])
            ++ans;
    }
}