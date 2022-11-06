// Cheap Dinner (https://codeforces.com/contest/1487/problem/E)
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

    int n1, n2, n3, n4; cin >> n1 >> n2 >> n3 >> n4;
    vector<ll> a(n1), b(n2), c(n3), d(n4);
    trav(ai, a) cin >> ai;
    trav(bi, b) cin >> bi;
    trav(ci, c) cin >> ci;
    trav(di, d) cin >> di;

    vector<vector<int>> adj1(n1), adj2(n2), adj3(n3);
    int m1, u, v; cin >> m1;
    rep(_, m1) cin >> u >> v, adj1[u-1].push_back(v-1);
    int m2; cin >> m2;
    rep(_, m2) cin >> u >> v, adj2[u-1].push_back(v-1);
    int m3; cin >> m3;
    rep(_, m3) cin >> u >> v, adj3[u-1].push_back(v-1);

    vector<int> p4(n4), i4(n4);
    iota(all(p4), 0);
    sort(all(p4), [&](int i, int j) { return d[i] < d[j]; });
    rep(i, n4) i4[p4[i]] = i;
    rep(i, n3) {
        trav(ai, adj3[i]) ai = i4[ai];
        sort(all(adj3[i]));
        int l = -1, r = sz(adj3[i]);
        while (r - l > 1) {
            int m = (l + r) / 2;
            (adj3[i][m] == m ? l : r) = m;
        }
        c[i] += (r == n4 ? INF : d[p4[r]]);
    }

    vector<int> p3(n3), i3(n3);
    iota(all(p3), 0);
    sort(all(p3), [&](int i, int j) { return c[i] < c[j]; });
    rep(i, n3) i3[p3[i]] = i;
    rep(i, n2) {
        trav(ai, adj2[i]) ai = i3[ai];
        sort(all(adj2[i]));
        int l = -1, r = sz(adj2[i]);
        while (r - l > 1) {
            int m = (l + r) / 2;
            (adj2[i][m] == m ? l : r) = m;
        }
        b[i] += (r == n3 ? INF : c[p3[r]]);
    }

    vector<int> p2(n2), i2(n2);
    iota(all(p2), 0);
    sort(all(p2), [&](int i, int j) { return b[i] < b[j]; });
    rep(i, n2) i2[p2[i]] = i;
    rep(i, n1) {
        trav(ai, adj1[i]) ai = i2[ai];
        sort(all(adj1[i]));
        int l = -1, r = sz(adj1[i]);
        while (r - l > 1) {
            int m = (l + r) / 2;
            (adj1[i][m] == m ? l : r) = m;
        }
        a[i] += (r == n2 ? INF : b[p2[r]]);
    }

    ll mn = *min_element(all(a));
    cout << (mn >= INF ? -1 : mn) << '\n';
    return 0;
}