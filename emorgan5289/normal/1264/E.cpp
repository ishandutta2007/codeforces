#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

// N vertices, flow and cost are measured with type T
template<int N, typename T>
struct mincostflow {

    const T inf_T = numeric_limits<T>::max(), eps = 0; // set epsilon for non-integral types
    const bool CYCLIC = false; // false will usually make it run faster, but requires a DAG

    struct flow_edge { int v, u; T f, w, c; };
    vector<flow_edge> adj[N];
    T l[N], pot[N];
    int p[N], vis[N], s, t;
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;

    // add an edge from i to j with capacity w and cost per unit flow c
    void edge(int i, int j, T w, T c, bool directed = true) {
        adj[i].push_back({j, int(adj[j].size()), 0, w, c});
        adj[j].push_back({i, int(adj[i].size())-1, 0, 0, -c});
        if (!directed) edge(j, i, w, c);
    }

    T dp(int v) {
        if (vis[v] || v == s) return pot[v];
        for (auto& e : adj[v])
            if (adj[e.v][e.u].w != 0)
                pot[v] = min(pot[v], dp(e.v)-e.c);
        return vis[v] = 1, pot[v]; 
    }

    bool dij() {
        fill(l, l+N, inf_T), pq.push({l[s] = 0, s});
        fill(vis, vis+N, 0);
        while (!pq.empty()) {
            auto [c, v] = pq.top(); pq.pop();
            if (vis[v]) continue; vis[v] = 1;
            for (auto& e : adj[v]) {
                T d = e.c+pot[v]-pot[e.v];
                if (l[v] != inf_T && e.f < e.w-eps && c+d < l[e.v]-eps)
                    p[e.v] = e.u, pq.push({l[e.v] = c+d, e.v});
            }
        }
        for (int i = 0; i < N; i++)
            if (l[i] != inf_T) pot[i] += l[i];
        return l[t] != inf_T;
    }

    bool spfa() {
        fill(l, l+N, inf_T), l[s] = 0;
        queue<int> q({s});
        while (!q.empty()) {
            int v = q.front(); q.pop();
            vis[v] = 0;
            for (auto& e : adj[v])
                if (l[v] != inf_T && e.f < e.w-eps && l[v]+e.c < l[e.v]-eps) {
                    l[e.v] = l[v]+e.c, p[e.v] = e.u;
                    if (!vis[e.v]) q.push(e.v), vis[e.v] = 1;
                }
        }
        return l[t] != inf_T;
    }

    // compute the maximum flow from s to t, and the minimum cost needed to do it, one-time use.
    // for cyclic graphs: SPFA + Edmonds-Karp, complexity is O(EV*min(V, flow))
    // for DAGS: Dijkstra's w/ Johnson potentials + Edmonds-Karp, complexity is O(EV*min(V, flow))
    // negative weight cycles will always break it
    pair<T, T> solve(int _s, int _t) {
        s = _s, t = _t; T f = 0, c = 0;
        fill(pot, pot+N, inf_T), pot[s] = 0;
        if (!CYCLIC) dp(t);
        while (CYCLIC ? spfa() : dij()) {
            T x = inf_T;
            for (int v = t; v != s; v = adj[v][p[v]].v) {
                auto& e = adj[v][p[v]];
                x = min(x, adj[e.v][e.u].w-adj[e.v][e.u].f);
            }
            for (int v = t; v != s; v = adj[v][p[v]].v) {
                auto& e = adj[v][p[v]];
                c -= e.c*x, e.f -= x, adj[e.v][e.u].f += x;
            }
            f += x;
        }
        return {f, c};
    }

    // after calling solve(), return a component vector C s.t. C[i] \in {0, 1}
    // and i is reachable from s iff C[i] = 1. any edge from a 1 to a 0 is in the min cut
    vector<bool> cut() {
        vector<bool> out(N, 0); out[s] = 1;
        queue<int> q({s});
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto& e : adj[v])
                if (e.f < e.w && !out[e.v])
                    out[e.v] = 1, q.push(e.v);
        }
        return out;
    }
};

const int N = 55, S = 10000;
int win[N][N], wt[N];
mincostflow<S, int> f;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int x, y; cin >> x >> y; x--, y--;
        win[x][y] = 1, win[y][x] = -1;
    }
    int s = S-1, t = S-2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int g = N*min(i, j)+max(i, j);
            if (i < j) f.edge(s, g, 1, 0);
            if (win[i][j] != -1) {
                f.edge(g, N*N+i, 1, 0);
                f.edge(N*N+i, t, 1, wt[i]++);
            }
            if (win[i][j] != 1) {
                f.edge(g, N*N+j, 1, 0);
                f.edge(N*N+j, t, 1, wt[j]++);
            }
        }
    auto [flow, cost] = f.solve(s, t);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool v = 0;
            int g = N*min(i, j)+max(i, j);
            for (auto& e : f.adj[g])
                if (e.v == N*N+i && e.f) v = 1;
            cout << (v ? '1' : '0');
        }
        cout << "\n";
    }
}