// Education (https://codeforces.com/contest/1512/problem/F)
// begin "cp-lib/boilerplate.hpp"
#include <bits/stdc++.h>

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep(i, l, r)     for (int i = l; i < r; ++i)
#define _rep0(i, r)       _rep(i, 0, r)
#define _repr(i, r, l)    for (int i = r; i >= l; --i)
#define _repr0(i, r)      _repr(i, r, 0)
#define rep(...)          _choose(__VA_ARGS__, _rep, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _repr, _repr0, suppress_warning)(__VA_ARGS__)
#define all(a)      ::begin(a),::end(a)
#define sz(c)       int(::size(c))
#define trav(a, b)  for(auto& a : b)

using namespace std;

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
[[maybe_unused]] static mt19937 rng(u32(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count()));

namespace cp_lib {}
// end "cp-lib/boilerplate.hpp"

using namespace cp_lib;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, c; cin >> n >> c;
        vector a(n, 0ll);
        trav(ai, a) cin >> ai;
        vector b(n - 1, 0ll);
        trav(bi, b) cin >> bi;

        ll ans = INFL, days = 0, rem = 0;
        rep(i, n) {
            ans = min(ans, (c - rem + a[i] - 1) / a[i] + days);
            if (i + 1 < n) {
                ll extra_days = (b[i] - rem + a[i] - 1) / a[i];
                days += extra_days + 1;
                rem = rem + extra_days * a[i] - b[i];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}