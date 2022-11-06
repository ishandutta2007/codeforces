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

vi bfs(int v0, vvi& adj) {
    int n = sz(adj);
    vi dist(n, INF);
    dist[v0] = 0;
    queue<int> q;
    q.push(v0);
    while (sz(q)) {
        int v = q.front(); q.pop();
        trav(v2, adj[v])
            if (dist[v2] == INF)
                dist[v2] = dist[v] + 1, q.push(v2);
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, a, b, da, db; cin >> n >> a >> b >> da >> db; --a, --b;
        vvi adj(n);
        rep(_, n-1) {
            int u, v; cin >> u >> v; --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto dista = bfs(a, adj);
        auto vmx = (int)(max_element(all(dista)) - begin(dista));
        auto distmx = bfs(vmx, adj);
        int dia = *max_element(all(distmx));

        if (2 * da >= dia || dista[b] <= da) {
            cout << "Alice\n";
            continue;
        }

        cout << (db > 2 * da ? "Bob\n" : "Alice\n");
    }

    return 0;
}