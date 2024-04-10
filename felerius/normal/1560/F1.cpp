// Nearest Beautiful Number (hard version) (https://codeforces.com/contest/1560/problem/F2)
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

ll toint(string_view s) {
    ll i;
    from_chars(data(s), data(s) + sz(s), i);
    return i;
}

bool check(string_view s, int k) {
    array<bool, 10> have{};
    rep(i, sz(s))
        have[s[i] - '0'] = true;
    return accumulate(all(have), 0) <= k;
}

ll both(string s, int k, int p) {
    if (check(s, k))
        return toint(s);

    array<bool, 10> have{};
    rep(i, p + 1)
        have[s[i] - '0'] = true;
    char low = '0';
    while (!have[low - '0'])
        ++low;

    rep(i, p + 1, sz(s))
        s[i] = low;

    return (check(s, k) ? toint(s) : 2 * INF);
}

ll solve(string s, int k, int p) {
    if (s[p] == '9')
        return 2 * INF;

    array<bool, 10> have{};
    rep(i, p)
        have[s[i] - '0'] = true;

    s[p]++;
    rep(i, p + 1, sz(s))
        s[i] = '0';

    ll mn = both(s, k, p);

    char low = s[p];
    while (low <= '9' && !have[low - '0'])
        ++low;

    if (low <= '9') {
        s[p] = low;
        mn = min(mn, both(s, k, p));
    }

    return mn;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s = to_string(n);
        if (check(s, k)) { cout << n << '\n'; continue; }

        ll mn = 2 * INF;
        rep(p, sz(s))
            mn = min(mn, solve(s, k, p));

        cout << mn << '\n';
    }
}