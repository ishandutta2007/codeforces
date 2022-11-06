// Nezzar and Nice Beatmap (https://codeforces.com/contest/1477/problem/C)
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

    int n; cin >> n;
    vector x(n, 0ll), y(n, 0ll);
    rep(i, n)
        cin >> x[i] >> y[i];

    vector<int> p = {0, 1};
    rep(i, 2, n) {
        p.push_back(i);
        repr(j, sz(p) - 3) {
            auto a = p[j], b = p[j + 1], c = p[j + 2];
            ll x1 = x[b] - x[a], y1 = y[b] - y[a], x2 = x[c] - x[b], y2 = y[c] - y[b];
            if (x1 * x2 + y1 * y2 < 0)
                break;
            swap(p[j + 1], p[j + 2]);
        }
    }

    trav(pi, p)
        cout << (pi + 1) << ' ';
    cout << '\n';

    return 0;
}