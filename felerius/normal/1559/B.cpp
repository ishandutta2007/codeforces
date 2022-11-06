// Mocha and Red and Blue (https://codeforces.com/contest/1559/problem/B)
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
        int n; cin >> n;
        string s; cin >> s;
        vector dp(n + 1, array<pair<int, int>, 2>{pair(INF, 0), pair(INF, 0)});
        dp[0] = {pair(0, 0), pair(0, 0)};
        rep(i, n) {
            if (s[i] != 'B')
                dp[i + 1][0] = min(pair(dp[i][1].first, 1), pair(dp[i][0].first + 1, 0));
            if (s[i] != 'R')
                dp[i + 1][1] = min(pair(dp[i][0].first, 0), pair(dp[i][1].first + 1, 1));
        }

        int x = int(dp[n][1].first < dp[n][0].first);
        int i = n;
        string ans;
        while (i) {
            ans.push_back(x ? 'B' : 'R');
            x = dp[i][x].second;
            --i;
        }
        reverse(all(ans));
        cout << ans << '\n';
    }
}