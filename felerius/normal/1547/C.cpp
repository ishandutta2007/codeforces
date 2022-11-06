// Pair Programming (https://codeforces.com/contest/1547/problem/C)
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
        int k, n, m; cin >> k >> n >> m;
        vector<int> a(n), b(m);
        trav(ai, a) cin >> ai;
        trav(bi, b) cin >> bi;

        vector al(n, 0), bl(m, 0);
        rep(i, n)
            al[i] = (i ? al[i-1] : 0) + (a[i] == 0);
        rep(i, m)
            bl[i] = (i ? bl[i-1] : 0) + (b[i] == 0);

        vector dp(n + 1, vector(m + 1, 0));
        dp[n][m] = 1;
        repr(i, n) repr(j, m) {
            int l = k + (i ? al[i-1] : 0) + (j ? bl[j-1] : 0);
            if (i < n && a[i] <= l && dp[i+1][j])
                dp[i][j] = 1;
            else if (j < m && b[j] <= l && dp[i][j+1])
                dp[i][j] = 2;
        }

        if (dp[0][0]) {
            int i = 0, j = 0;
            while (i < n || j < m) {
                if (dp[i][j] == 1)
                    cout << a[i++] << ' ';
                else
                    cout << b[j++] << ' ';
            }

            cout << '\n';
        } else
            cout << "-1\n";
    }
}