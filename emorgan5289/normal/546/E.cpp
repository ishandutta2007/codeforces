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

// computes maximum flow through a weighted directed graph
// N vertices, flow is measured with type T
template<int N, typename T>
struct flow {

    const bool SCALING = true;
    const T inf_T = numeric_limits<T>::max();

    struct flow_edge { int v, u; T f, w; };
    vector<flow_edge> adj[N];
    int l[N], p[N], s, t; T k;

    // add an edge from i to j with weight w
    void edge(int i, int j, T w, bool directed = true) {
        adj[i].push_back({j, int(adj[j].size()), 0, w});
        adj[j].push_back({i, int(adj[i].size())-1, 0, directed ? 0 : w});
    }

    bool bfs() {
        queue<int> q({s});
        fill(l, l+N, -1), l[s] = 0;
        while (!q.empty() && l[t] == -1) {
            int v = q.front(); q.pop();
            for (auto& e : adj[v])
                if (l[e.v] == -1 && e.f < e.w && (!SCALING || e.w - e.f >= k))
                    q.push(e.v), l[e.v] = l[v] + 1;
        }
        return l[t] != -1;
    }

    T dfs(int v, T f) {
        if (v == t || !f)
            return f;
        for (; p[v] < adj[v].size(); p[v]++) {
            auto& e = adj[v][p[v]];
            if (l[e.v] != l[v] + 1)
                continue;
            if (T x = dfs(e.v, min(f, e.w - e.f))) {
                e.f += x, adj[e.v][e.u].f -= x;
                return x;
            }
        }
        return 0;
    }

    // compute the maximum flow from s to t, one-time use
    // Dinic's algorithm, runs in O(V^2E) or O(VElogU)
    T solve(int _s, int _t) {
        s = _s, t = _t; T out = 0;
        for (k = SCALING ? 1<<30 : 1; k > 0; k /= 2)
            while (bfs()) {
                fill(p, p+N, 0);
                while (T x = dfs(s, inf_T)) out += x;
            }
        return out;
    }

    // after calling solve(), return a component vector C s.t. C[i] \in {0, 1}
    // and i is reachable from s iff C[i] = 1. any edge from a 1 to a 0 is in the min cut
    vector<bool> cut() {
        vector<bool> out(N, 0); out[s] = 1;
        queue<int> q({s});
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto& e : adj[v]) {
                debug(v, e.v, e.f, e.w);
                if (e.f < e.w && !out[e.v])
                    out[e.v] = 1, q.push(e.v);
            }
        }
        return out;
    }
};

const int N = 500;
flow<N, ll> f;
int a[N], b[N], g[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    ll ra = 0, rb = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        f.edge(2*n, i, x), ra += x;
        f.edge(i, n+i, inf);
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        f.edge(n+i, 2*n+1, x), rb += x;
    }
    while (m--) {
        int x, y; cin >> x >> y; x--, y--;
        f.edge(x, n+y, inf);
        f.edge(y, n+x, inf);
    }
    if (f.solve(2*n, 2*n+1) == ra && ra == rb) {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            for (auto& e : f.adj[i]) {
                debug(i, e.v, e.f);
                g[i][e.v-n] = e.f;
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cout << g[i][j] << " \n"[j==n-1];
    } else
        cout << "NO\n";
}