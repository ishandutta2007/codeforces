// Explorer Space (https://codeforces.com/contest/1517/problem/D)
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

    int n, m, k; cin >> n >> m >> k;
    vector adj(n * m, vector<pair<int, int>>());
    rep(i, n) rep(j, m - 1) {
        int w; cin >> w;
        int v1 = i * m + j;
        int v2 = i * m + j + 1;
        adj[v1].emplace_back(v2, w);
        adj[v2].emplace_back(v1, w);
    }

    rep(i, n - 1) rep(j, m) {
        int w; cin >> w;
        int v1 = i * m + j;
        int v2 = (i + 1) * m + j;
        adj[v1].emplace_back(v2, w);
        adj[v2].emplace_back(v1, w);
    }

    array<int, 21> init{};
    init.fill(INF);
    init[0] = 0;
    vector dp(n * m, init);

    rep(i, 2, k + 1)
        rep(v, n * m)
            for (auto& [v2, w] : adj[v])
                dp[v][i] = min(dp[v][i], dp[v2][i - 2] + 2 * w);

    rep(v, n * m)
        cout << (dp[v][k] == INF ? -1 : dp[v][k]) << " \n"[v % m == m - 1];

    return 0;
}