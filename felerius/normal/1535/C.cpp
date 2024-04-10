// Unstable String (https://codeforces.com/contest/1535/problem/C)
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
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = sz(s);
        vector dp(n, array<int, 2>{0, 0});
        ll cnt = 0;
        int quest = 0;
        repr(i, n - 1) {
            dp[i][0] = 1 + (i + 1 == n ? 0 : dp[i + 1][1]);
            dp[i][1] = 1 + (i + 1 == n ? 0 : dp[i + 1][0]);
            if (s[i] == '0')
                dp[i][1] = 0;
            else if (s[i] == '1')
                dp[i][0] = 0;
            quest = (s[i] == '?' ? quest + 1 : 0);
            cnt += dp[i][0] + dp[i][1] - quest;
        }

        cout << cnt << '\n';
    }

    return 0;
}