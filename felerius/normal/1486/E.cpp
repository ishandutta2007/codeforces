// Paired Payment (https://codeforces.com/contest/1486/problem/E)
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
    vector<vector<pair<int, int>>> adj(n);
    rep(_, m) {
        int u, v, w; cin >> u >> v >> w; --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<array<ll, 51>> dist(n);
    trav(a, dist) a.fill(INFL);

    priority_queue<tuple<ll, int, int>> q;
    dist[0][0] = 0;
    q.emplace(0, 0, 0);
    while (sz(q)) {
        auto [d, v, x] = q.top(); q.pop(); d = -d;
        if (d > dist[v][x]) continue;
        for (auto& [v2, w] : adj[v]) {
            if (x) {
                if (d + ll(x + w) * (x + w) < dist[v2][0])
                    dist[v2][0] = d + ll(x + w) * (x + w), q.emplace(-dist[v2][0], v2, 0);
            } else {
                if (d < dist[v2][w])
                    dist[v2][w] = d, q.emplace(-dist[v2][w], v2, w);
            }
        }
    }

    rep(i, n)
        cout << (dist[i][0] == INFL ? -1 : dist[i][0]) << " \n"[i + 1 == n];

    return 0;
}