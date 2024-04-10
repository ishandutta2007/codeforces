// region boilerplate
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <deque>
#include <exception>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if __cplusplus >= 201703L
#   include <optional>
#   include <string_view>
#   include <variant>
#endif

using namespace std;

#if __cplusplus >= 201703L
#   define all(a)      begin(a),end(a)
#   define sz(x)       ((int)size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define trav(a, b)     for(auto& a : b)

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18 + 5;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion

const int N = 300'005, M = 300'005;
vpi adj[N];
bool bridge[M];
int d[N];

int dfs(int v, int ei) {
    int dp = 0;
    for (auto [v2, ei2] : adj[v]) {
        if (ei2 == ei)
            continue;
        if (d[v2]) {
            dp += d[v2] > d[v] ? -1 : 1;
            continue;
        }
        d[v2] = d[v] + 1;
        dp += dfs(v2, ei2);
    }
    if (ei != -1)
        bridge[ei] = !dp;
    return dp;
}

pi dijkstra(int n, int v0) {
    vi dist(n, INF);
    deque<int> q;
    dist[v0] = 0;
    q.push_back(v0);
    while (sz(q)) {
        auto v = q.front(); q.pop_front();
        for (auto [v2, ei] : adj[v]) {
            if (dist[v2] != INF)
                continue;
            dist[v2] = dist[v] + bridge[ei];
            if (bridge[ei])
                q.push_back(v2);
            else
                q.push_front(v2);
        }
    }
    auto it = max_element(all(dist));
    return {(int)(it - begin(dist)), *it};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    rep(i, m) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    d[0] = 1;
    dfs(0, -1);

    auto [v1, _] = dijkstra(n, 0);
    cout << dijkstra(n, v1).second << '\n';

    return 0;
}