// Make a Power of Two (https://codeforces.com/contest/1560/problem/D)
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

    vector<string> pows;
    rep(i, 60)
        pows.push_back(to_string(1ll << i));

    int t; cin >> t;
    while (t--) {
        string n; cin >> n;
        int mn = INF;
        trav(p, pows) {
            int i = 0, keep = 0;
            trav(c, p) {
                while (i < sz(n) && n[i] != c)
                    ++i;
                if (i < sz(n) && n[i] == c)
                    ++keep, ++i;
                mn = min(mn, sz(p) + sz(n) - 2 * keep);
            }
        }

        cout << mn << '\n';
    }
}