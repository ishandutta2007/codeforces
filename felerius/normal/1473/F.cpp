// Strange Set (https://codeforces.com/contest/1473/problem/F)

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if __cplusplus >= 201703L
#   include <optional>
#   include <string_view>
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#   define MAYBE_UNUSED
#endif

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep0(i, r)       for (int i = 0; i < r; ++i)
#define _repn(i, l, r)    for (int i = l; i < r; ++i)
#define _repr0(i, r)      for (int i = r; i >= 0; --i)
#define _reprn(i, r, l)   for (int i = r; i >= l; --i)
#define rep(...)          _choose(__VA_ARGS__, _repn, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _reprn, _repr0, suppress_warning)(__VA_ARGS__)
#define trav(a, b)        for(auto& a : b)

using namespace std;

using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using u64 = uint64_t;
using u32 = uint32_t;

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

namespace cp_lib {}



namespace cp_lib::_flow_detail {
    template <class F, class Edge>
    struct BaseFlowGraph {
        vector<vector<Edge>> adj;

        explicit BaseFlowGraph(int n) : adj(n) {}

        int n() const { return sz(adj); }
        Edge& inv(const Edge& e) { return adj[e.to][e.inv]; }

        // Reset all flow values
        void reset() { trav(row, adj) trav(e, row) e.flow = 0; }

        // Decompose flow into a set of s-t paths
        vector<pair<F, vector<Edge*>>> decompose(int s, int t) {
            F flow = 0;
            trav(e, adj[s]) flow += e.flow;

            vector next(n(), 0), inpath(n(), -1);
            vector<pair<F, vector<Edge*>>> paths;
            for (int i = 0; flow; ++i) {
                paths.emplace_back(numeric_limits<F>::max(), vector<Edge*>());
                auto& [pflow, p] = paths.back();
                while (!sz(p) || p.back()->to != t) {
                    auto v = sz(p) ? p.back()->to : s;
                    if (inpath[v] == i) {
                        F bottleneck = p.back()->flow;
                        int rem_size = sz(p) - 1;
                        while (rem_size && p[rem_size - 1]->to != v)
                            bottleneck = min(bottleneck, p[--rem_size]->flow);
                        while (sz(p) > rem_size)
                            p.back()->flow -= bottleneck, inpath[p.back()->to] = -1, p.pop_back();
                    }
                    inpath[v] = i;
                    while (adj[v][next[v]].flow <= 0)
                        ++next[v];
                    p.push_back(&adj[v][next[v]]);
                }

                trav(e, p) pflow = min(pflow, e->flow);
                trav(e, p) e->flow -= pflow;
                flow -= pflow;
            }

            return paths;
        }

        // Determine for each vertex whether it is on the s side of an s-t cut
        vector<bool> cut(int s) {
            queue<int> q{{s}};
            vector<bool> res(sz(adj));
            res[s] = true;
            while (sz(q)) {
                int v = q.front(); q.pop();
                trav(e, adj[v])
                    if (e.flow < e.cap && !res[e.to])
                        res[e.to] = true, q.push(e.to);
            }
            return res;
        }
    };
}

namespace cp_lib {
    template <class F>
    struct FlowEdge {
        int to, inv;
        F flow = 0, cap;
        FlowEdge(int to_, int inv_, F cap_) : to(to_), inv(inv_), cap(cap_) {}
    };

    template <class F = int, bool Directed = true>
    struct FlowGraph : _flow_detail::BaseFlowGraph<F, FlowEdge<F>> {
        using Base = _flow_detail::BaseFlowGraph<F, FlowEdge<F>>;
        vector<int> next, dist;

        explicit FlowGraph(int n) : Base::BaseFlowGraph(n), next(n), dist(n) {}

        int add_edge(int from, int to, F cap) {
            Base::adj[from].emplace_back(to, sz(Base::adj[to]), cap);
            Base::adj[to].emplace_back(from, sz(Base::adj[from]) - 1, Directed ? (F)0 : cap);
            return sz(Base::adj[from]) - 1;
        }

        F dinic_dfs(int v, int t, F aug) {
            if (v == t) return aug;
            for (; next[v] < sz(Base::adj[v]); ++next[v]) {
                auto& e = Base::adj[v][next[v]];
                if (e.flow == e.cap || dist[e.to] != dist[v] + 1) continue;
                F pushed = dinic_dfs(e.to, t, min(aug, e.cap - e.flow));
                if (pushed == 0) continue;
                e.flow += pushed;
                Base::inv(e).flow -= pushed;
                return pushed;
            }
            return 0;
        }

        F flow(int s, int t) {
            F flow = 0;
            queue<int> q;
            while (1) {
                fill(all(dist), INF);
                fill(all(next), 0);
                dist[s] = 0;
                q.push(s);

                while (sz(q)) {
                    int v = q.front(); q.pop();
                    trav(e, Base::adj[v])
                        if (dist[e.to] == INF && e.flow < e.cap)
                            q.push(e.to), dist[e.to] = dist[v] + 1;
                }

                if (dist[t] == INF) break;
                F aug;
                while((aug = dinic_dfs(s, t, numeric_limits<F>::max()))) flow += aug;
            }

            return flow;
        }
    };
}

using namespace cp_lib;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector a(n, 0), b(n, 0);
    trav(ai, a) cin >> ai, --ai;
    trav(bi, b) cin >> bi;

    array<int, 100> rightmost{};
    rightmost.fill(-1);

    FlowGraph<int> g(n + 2);
    int s = n, t = s + 1, best = 0;
    rep(i, n) {
        if (b[i] >= 0)
            g.add_edge(s, i, b[i]);
        else
            g.add_edge(i, t, -b[i]);
        best += max(0, b[i]);
        rep(j, 100)
            if ((a[i] + 1) % (j + 1) == 0 && rightmost[j] != -1)
                g.add_edge(i, rightmost[j], INF);
        rightmost[a[i]] = i;
    }

    cout << (best - g.flow(s, t)) << '\n';
    return 0;
}