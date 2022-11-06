// Bubble Strike (https://codeforces.com/contest/1599/problem/C)
#pragma GCC optimize("fast-math")
// begin "cp-lib/prelude.hpp"
#include <bits/stdc++.h>
#ifdef LOCAL
#  include <dbg.h>
#else
#  define dbg(...) do {} while (0)
#endif

#define cp_lib_4th(_1, _2, _3, x, ...)  x
#define cp_lib_rep(i, l, r)             for (int i = (l); (i) < (r); ++(i))
#define cp_lib_rep0(i, r)               cp_lib_rep(i, 0, r)
#define rep(...)                        cp_lib_4th(__VA_ARGS__, cp_lib_rep, cp_lib_rep0, _)(__VA_ARGS__)
#define cp_lib_repr(i, r, l, ...)       for (int i = (r); (i) >= (l); --(i))
#define repr(...)                       cp_lib_repr(__VA_ARGS__, 0)
#define all(a)                          ::begin(a),::end(a)
#define trav(a, b)                      for (auto&& a : (b))

using namespace std;
using ll = long long;
using ld = long double;
[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
template <class C> int sz(const C& c) { return int(::size(c)); }
// end "cp-lib/prelude.hpp"

int main() {
    int n; double p; cin >> n >> p;
    int tot = n * (n - 1) * (n - 2) / 6;
    int mn = int(ceil(2 * tot * p));
    int l = -1, r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int p3 = (m * (m - 1) * (m - 2)) / 6;
        int p2 = (m * (m - 1)) / 2 * (n - m);
        int p1 = m * ((n - m) * (n - m - 1)) / 2;
        int cnt = 2 * p3 + 2 * p2 + p1;
        (cnt >= mn ? r : l) = m;
    }

    cout << r << '\n';
}