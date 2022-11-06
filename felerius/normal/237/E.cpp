#pragma GCC optimize("fast-math")
// begin "cp-lib/boilerplate.hpp"
#include <bits/stdc++.h>
#ifdef LOCAL
#  include <dbg.h>
#else
#  define dbg(...) do {} while (0)
#endif

#define _choose(_1, _2, _3, x, ...)     x
#define _rep(i, l, r)                   for (int i = l; i < r; ++i)
#define _rep0(i, r)                     _rep(i, 0, r)
#define rep(...)                        _choose(__VA_ARGS__, _rep, _rep0, _)(__VA_ARGS__)
#define _repr(i, r, l, ...)             for (int i = r; i >= l; --i)
#define repr(...)                       _repr(__VA_ARGS__, 0)
#define all(a)                          ::begin(a),::end(a)
#define trav(a, b)                      for (auto&& a : b)

using namespace std;
namespace cp_lib {}

using ll = long long;
using ld = long double;
[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
template <class C> int sz(const C& c) { return int(::size(c)); }
// end "cp-lib/boilerplate.hpp"
// begin "cp-lib/graph/flow/cost-scaling.hpp"
// begin "_detail.hpp"
namespace cp_lib::_flow_detail {
    template <class Flow, class Edge>
    struct BaseFlowGraph {
        vector<vector<Edge>> adj;

        explicit BaseFlowGraph(int n) : adj(n) {}

        Flow calc_flow(int s, int t, Flow limit = numeric_limits<Flow>::max());
        vector<pair<Flow, vector<Edge*>>> decompose(int s, int t);
        vector<bool> calc_cut(int s);
    };
}
// end "_detail.hpp"

namespace cp_lib {
    template <class Flow, class Cost>
    struct CostScalingEdge {
        int to, rev;
        Flow flow{0}, cap;
        Cost cost;
    };

    template <class Flow = ll, class Cost = ll, int ALPHA = 16>
    struct CostScalingFlowGraph : _flow_detail::BaseFlowGraph<Flow, CostScalingEdge<Flow, Cost>> {
        static_assert(is_signed_v<Flow> && is_signed_v<Cost>);
        using Base = _flow_detail::BaseFlowGraph<Flow, CostScalingEdge<Flow, Cost>>;
        using Base::Base;

        Cost max_cost = 0;

        int add_edge(int s, int t, Flow cap, Cost cost) {
            int idx = sz(Base::adj[s]), idx_rev = (s == t ? idx + 1 : sz(Base::adj[t]));
            auto scaled_cost = cost * Cost(ALPHA) * Cost(sz(Base::adj));
            Base::adj[s].push_back(CostScalingEdge<Flow, Cost>{t, idx_rev, Flow(0), cap, scaled_cost});
            Base::adj[t].push_back(CostScalingEdge<Flow, Cost>{s, idx, Flow(0), Flow(0), -scaled_cost});
            max_cost = max(max_cost, abs(scaled_cost));
            return idx;
        }

        template <class TotalCost = ll>
        pair<TotalCost, vector<Cost>> minimize_circulation(vector<Flow> excess = {}) {
            vector<Cost> pi(sz(Base::adj));
            vector next(sz(Base::adj), 0);
            vector<uint8_t> inq(sz(Base::adj));
            queue<int> q;
            auto eps = max_cost;
            if (!sz(excess))
                excess.resize(sz(Base::adj));

            auto push = [&](CostScalingEdge<Flow, Cost>& e, Flow f) {
                auto& rev = Base::adj[e.to][e.rev];
                e.flow += f;
                rev.flow -= f;
                excess[e.to] += f;
                excess[rev.to] -= f;
            };
            auto relabel = [&](int v) {
                auto mx = numeric_limits<Cost>::min();
                trav(e, Base::adj[v])
                    if (e.flow < e.cap)
                        mx = max(mx, pi[e.to] - e.cost);
                pi[v] = mx - eps;
                next[v] = 0;
            };

            for (; eps; eps = (eps < ALPHA && eps != 1 ? 1 : eps / ALPHA)) {
                fill(all(next), 0);
                rep(v, sz(Base::adj))
                    trav(e, Base::adj[v])
                        if (pi[v] + e.cost - pi[e.to] < 0 && e.flow < e.cap)
                            push(e, e.cap - e.flow);
                rep(v, sz(Base::adj))
                    if (excess[v] > 0)
                        q.push(v), inq[v] = true;

                while (sz(q)) {
                    int v = q.front(); q.pop();
                    inq[v] = false;
                    while (excess[v] > 0) {
                        if (next[v] == sz(Base::adj[v]))
                            relabel(v);
                        for (int& i = next[v]; i < sz(Base::adj[v]); ++i) {
                            auto& e = Base::adj[v][i];
                            if (pi[v] + e.cost - pi[e.to] < 0 && e.flow < e.cap) {
                                push(e, min(excess[v], e.cap - e.flow));
                                if (excess[e.to] > 0 && !inq[e.to])
                                    q.push(e.to), inq[e.to] = true;
                                if (!excess[v])
                                    break;
                            }
                        }
                    }
                }
            }

            TotalCost cost{0};
            rep(v, sz(Base::adj))
                trav(e, Base::adj[v])
                    cost += TotalCost(e.cost / ALPHA / sz(Base::adj)) * TotalCost(e.flow);
            trav(i, pi)
                i /= ALPHA * sz(Base::adj);
            return {cost / 2, move(pi)};
        }
    };
}
// end "cp-lib/graph/flow/cost-scaling.hpp"
// begin "cp-lib/graph/flow/dinic.hpp"
namespace cp_lib::_flow_detail {
    template <class Flow, class Edge>
    Flow BaseFlowGraph<Flow, Edge>::calc_flow(int s, int t, Flow limit) {
        Flow flow{0};
        vector dist(sz(adj), 0), next(sz(adj), 0);
        queue<int> q;
        while (flow < limit) {
            fill(all(dist), INF);
            fill(all(next), 0);
            dist[s] = 0;
            q.push(s);

            while (sz(q)) {
                int v = q.front(); q.pop();
                trav(e, adj[v])
                    if (dist[e.to] == INF && e.flow < e.cap)
                        q.push(e.to), dist[e.to] = dist[v] + 1;
            }
            if (dist[t] == INF) break;

            auto dfs = [&](int v, Flow aug, auto&& self) -> Flow {
                if (v == t) return aug;
                for (int& i = next[v]; i < sz(adj[v]); ++i) {
                    auto& e = adj[v][i];
                    if (e.flow == e.cap || dist[e.to] != dist[v] + 1)
                        continue;
                    Flow pushed = self(e.to, min(aug, e.cap - e.flow), self);
                    if (!pushed)
                        continue;
                    e.flow += pushed;
                    adj[e.to][e.rev].flow -= pushed;
                    return pushed;
                }
                return Flow(0);
            };
            Flow aug;
            while ((aug = dfs(s, limit - flow, dfs)))
                flow += aug;
        }

        return flow;
    }
}
// end "cp-lib/graph/flow/dinic.hpp"

using namespace cp_lib;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    string t; int n; cin >> t >> n;
    vector<string> s(n);
    vector a(n, 0);
    int m = 0;
    rep(i, n)
        cin >> s[i] >> a[i], m += sz(s[i]);
    array<int, 26> tcnt{};
    trav(c, t)
        tcnt[c - 'a']++;

    CostScalingFlowGraph<int, int> g(27 * n + 26 + 2);
    int vs = 27 * n + 26, vt = vs + 1;
    rep(i, n) {
        g.add_edge(vs, 27 * i, a[i], i + 1);
        array<int, 26> cnt{};
        trav(c, s[i])
            cnt[c - 'a']++;
        rep(j, 26) {
            g.add_edge(27 * i, 27 * i + j + 1, cnt[j], 0);
            g.add_edge(27 * i + j + 1, 27 * n + j, cnt[j], 0);
        }
    }
    rep(i, 26)
        g.add_edge(27 * n + i, vt, tcnt[i], 0);

    auto flow = g.calc_flow(vs, vt);
    if (flow != sz(t))
        cout << "-1\n", exit(0);
    auto [cost, _] = g.minimize_circulation();
    cout << cost << '\n';
}