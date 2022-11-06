// Christmas Game (https://codeforces.com/contest/1498/problem/F)
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

    int n, k; cin >> n >> k;
    vector adj(n, vector<int>());
    rep(_, n - 1) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector a(n, 0);
    trav(ai, a) cin >> ai;

    vector vals(n, vector<int>(2 * k));
    auto dfs = [&](int v, int p, auto&& self) -> void {
        vals[v][0] = a[v];
        trav(v2, adj[v]) {
            if (v2 == p) continue;
            self(v2, v, self);
            rep(i, 2 * k)
                vals[v][(i + 1) % (2 * k)] ^= vals[v2][i];
        }
    };
    dfs(0, -1, dfs);

    vector ans(n, 0);
    auto dfs2 = [&](int v, int p, auto&& self) -> void {
        rep(i, k, 2 * k)
            ans[v] ^= vals[v][i];
        trav(v2, adj[v]) {
            if (v2 == p) continue;
            vector above_child = vals[v];
            rep(i, 2 * k)
                above_child[(i + 1) % (2 * k)] ^= vals[v2][i];
            rep(i, 2 * k)
                vals[v2][(i + 1) % (2 * k)] ^= above_child[i];
            self(v2, v, self);
        }
    };
    dfs2(0, -1, dfs2);

    rep(i, n)
        cout << (ans[i] ? 1 : 0) << ' ';
    cout << '\n';

    return 0;
}