// Stringforces (https://codeforces.com/contest/1550/problem/E)
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
    string s; cin >> s;

    auto check = [&](int w) {
        array<int, 17> init{};
            init.fill(n + 1);
        vector next(n, init);
        rep(c, k) {
            int next_diff = n;
            repr(i, n - 1) {
                if (i + 1 < n)
                    next[i][c] = next[i + 1][c];
                if (s[i] != '?' && s[i] - 'a' != c)
                    next_diff = i;
                if (i + w <= next_diff)
                    next[i][c] = i + w;
            }
        }

        vector dp(1 << k, n + 1);
        dp[0] = 0;
        rep(i, 1 << k) {
            if (dp[i] >= n)
                continue;
            rep(c, k)
                if (!((i >> c) & 1))
                    dp[i | (1 << c)] = min(dp[i | (1 << c)], next[dp[i]][c]);
        }

        return dp[(1 << k) - 1] <= n;
    };

    int l = 0, r = (n / k) + 1;
    while (r - l > 1)
        (check((l + r) / 2) ? l : r) = (l + r) / 2;

    cout << l << '\n';
}