// Colors and Intervals (https://codeforces.com/contest/1552/problem/E)
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

    int n, k; cin >> n >> k;
    vector c(n * k, 0);
    trav(ci, c) cin >> ci, --ci;

    vector ans(n, pair(-1, -1));
    vector idx(n, vector<int>());
    rep(i, n * k)
        idx[c[i]].push_back(i);
    trav(row, idx)
        reverse(all(row));

    vector cov(n * k, 0);
    int l = 0, lim = (n + k - 2) / (k - 1);
    rep(_, n) {
        auto mn = pair(INF, 0);
        rep(i, n)
            if (ans[i].first == -1)
                mn = min(mn, pair(idx[i][sz(idx[i]) - 2], i));
        auto x = mn.second;
        ans[x] = {idx[x].back(), idx[x][sz(idx[x]) - 2]};

        int new_l = l;
        rep(i, ans[x].first, ans[x].second + 1)
            if (++cov[i] == lim)
                new_l = max(new_l, i + 1);

        rep(i, n)
            while (sz(idx[i]) && idx[i].back() < new_l)
                idx[i].pop_back();
        l = new_l;
    }

    for (auto [a, b] : ans)
        cout << (a + 1) << ' ' << (b + 1) << '\n';
}