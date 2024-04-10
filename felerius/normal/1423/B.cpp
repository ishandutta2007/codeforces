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

template <class T>
struct FlowGraph {
    static_assert(is_signed_v<T>, "flow must be a signed integer type");

    struct Edge {
        int from, to;
        T flow, cap;
    };

    vector<Edge> edges;
    vvi adj;
    vi dist, ptr;
    queue<int> q;

    explicit FlowGraph(int n) : adj(n), dist(n), ptr(n) {}

    int n() { return sz(adj); }
    int m() { return sz(edges); }
    int rev(int e) { return e ^ 1; };
    int from(int e) { return e & 1 ? edges[e >> 1].to : edges[e >> 1].from; };
    int to(int e) { return from(rev(e)); }
    T flow(int e) { return (e & 1 ? -1 : 1) * edges[e >> 1].flow; }
    T cap(int e) { return (e & 1 ? 0 : 1) * edges[e >> 1].cap; }

    void augment(int e, T flow) { edges[e >> 1].flow += (e & 1 ? -flow : flow); }
    void reset() { trav(e, edges) e.flow = 0; }

    int add_edge(int from, int to, T cap) {
        int e = 2 * m();
        edges.push_back(Edge{from, to, 0, cap});
        adj[from].push_back(e);
        adj[to].push_back(rev(e));
        return e;
    }

    T dfs(int v, int t, T f) {
        if (!f || v == t)
            return f;
        for (int& i = ptr[v]; i < sz(adj[v]); ++i) {
            int e = adj[v][i];
            if (dist[v] + 1 != dist[to(e)] || flow(e) == cap(e))
                continue;
            auto pushed = dfs(to(e), t, min(f, cap(e) - flow(e)));
            if (!pushed)
                continue;
            augment(e, pushed);
            return pushed;
        }
        return 0;
    }

    T calc_flow(int s, int t) {
        T f = 0;
        while (1) {
            fill(all(dist), -1);
            dist[s] = 0;
            q.push(s);
            while (sz(q)) {
                int v = q.front(); q.pop();
                trav(e, adj[v])
                    if (flow(e) < cap(e) && dist[to(e)] == -1)
                        dist[to(e)] = dist[v] + 1, q.push(to(e));
            }

            if (dist[t] == -1)
                return f;

            fill(all(ptr), 0);
            while (auto pushed = dfs(s, t, numeric_limits<T>::max()))
                f += pushed;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<array<int, 3>> e(m);
    FlowGraph<int> g(2 * n + 2);
    for (auto& [u, v, d] : e) {
        cin >> u >> v >> d, --u, --v;
        g.add_edge(u, v + n, 1);
    }
    int s = 2 * n, t = s + 1;
    rep(i, n)
        g.add_edge(s, i, 1), g.add_edge(i + n, t, 1);

    int l = 0, r = INF;
    while (r - l > 1) {
        int mi = (l + r) / 2;
        g.reset();
        rep(i, m) {
            auto [u, v, d] = e[i];
            g.edges[i].cap = (d <= mi);
        }

        int flow = g.calc_flow(s, t);
        (flow == n ? r : l) = mi;
    }

    cout << (r == INF ? -1 : r) << '\n';
    return 0;
}