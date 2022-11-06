// notepad.exe (https://codeforces.com/contest/1672/problem/E)
#pragma GCC optimize("fast-math")

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

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    int l = 0, r = int(2005 * n);
    while (r - l > 1) {
        int m = (l + r) / 2;
        cout << "? " << m << '\n' << flush;
        int a; cin >> a;
        (a == 1 ? r : l) = m;
    }

    int ans = r;
    rep(h, 2, n + 1) {
        int mn = r - (h - 1);
        int w = (mn + h - 1) / h;
        cout << "? " << w << '\n' << flush;
        int a; cin >> a;
        if (a == h)
            ans = min(ans, w * h);
    }

    cout << "! " << ans << '\n';
}