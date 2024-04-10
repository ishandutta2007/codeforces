// Old Floppy Drive  (https://codeforces.com/contest/1490/problem/G)
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
using u128 = unsigned __int128;
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
        int n, m; cin >> n >> m;
        vector a(n, 0);
        trav(ai, a) cin >> ai;

        ll sum = 0;
        vector<pair<ll, int>> f;
        rep(i, n) {
            sum += a[i];
            if (sum > 0 && (!sz(f) || f.back().first < sum))
                f.emplace_back(sum, i);
        }

        while (m--) {
            ll x; cin >> x;
            auto it = lower_bound(all(f), pair(x, 0));
            if (it != end(f)) {
                cout << it->second << ' ';
                continue;
            }
            if (!sz(f) || sum <= 0) { cout << "-1 "; continue; }

            ll rs = (x - f.back().first + sum - 1) / sum;
            it = lower_bound(all(f), pair(x - rs * sum, 0));
            cout << (it->second + rs * n) << ' ';
        }

        cout << '\n';
    }

    return 0;
}