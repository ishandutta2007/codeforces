// Air Conditioners (https://codeforces.com/contest/1547/problem/E)
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
        vector a(k, pair(0, 0));
        rep(i, k)
            cin >> a[i].first, --a[i].first;
        rep(i, k)
            cin >> a[i].second;
        sort(all(a));

        multiset<int> after;
        for (auto [i, ti] : a)
            after.emplace(i + ti);
        int mn_before = 2 * INF;

        vector ans(n, 0);
        auto it = begin(a);
        rep(i, n) {
            ans[i] = mn_before + i;
            if (sz(after))
                ans[i] = min(ans[i], *begin(after) - i);

            if (it != end(a) && it->first == i) {
                mn_before = min(mn_before, it->second - it->first);
                after.erase(after.find(it->first + it->second));
                ++it;
            }
        }

        trav(i, ans)
            cout << i << ' ';
        cout << '\n';
    }
}