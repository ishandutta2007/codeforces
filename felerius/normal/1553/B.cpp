// Reverse String (https://codeforces.com/contest/1553/problem/B)
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

    int q; cin >> q;
    while (q--) {
        string s, t; cin >> s >> t;
        int n = sz(s);
        bool pos = false;
        rep(m, n) rep(r, m, n) {
            int rem = sz(t) - (r - m + 1);
            int l = r - rem;
            if (rem < 0 || l < 0) continue;

            bool valid = true;
            int i = 0;
            rep(j, m, r + 1)
                valid &= (s[j] == t[i++]);
            repr(j, r - 1, l)
                valid &= (s[j] == t[i++]);
            pos |= valid;
        }

        cout << (pos ? "YES\n" : "NO\n");
    }
}