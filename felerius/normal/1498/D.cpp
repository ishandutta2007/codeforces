// Bananas in a Microwave (https://codeforces.com/contest/1498/problem/D)
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

    int n, m; cin >> n >> m;
    vector first(m + 1, INF);
    first[0] = 0;

    rep(iter, n) {
        ll t, x, y; cin >> t >> x >> y;
        auto apply = [&](ll k) {
            if (t == 1)
                return (100000ll * k + x + 99999) / 100000;
            else
                return (k * x + 99999) / 100000;
        };

        rep(i, m + 1) {
            if (first[i] > iter) continue;
            ll k = i;
            rep(_, y) {
                k = apply(k);
                if (k > m || first[k] != INF) break;
                first[k] = iter + 1;
            }
        }
    }

    rep(i, 1, m + 1)
        cout << (first[i] == INF ? -1 : first[i]) << ' ';
    cout << '\n';

    return 0;
}