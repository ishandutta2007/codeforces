#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

// N vertices, flow is measured with type T
template<int N, typename T>
struct dinic {

    const bool SCALING = true;
    const T inf_T = numeric_limits<T>::max();

    struct flow_edge { int v, u; T f, w; };
    vector<flow_edge> adj[N];
    int l[N], p[N], s, t; T k;

    // add an edge from i to j with capacity w
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
            for (auto& e : adj[v])
                if (e.f < e.w && !out[e.v])
                    out[e.v] = 1, q.push(e.v);
        }
        return out;
    }
};

const int N = 1005;
dinic<2*N+2, int> f;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    vector<ll> a, b;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        if (2*x >= m) {
            cout << "-1\n";
            return 0;
        } else if (3*x > m) {
            b.pb(x);
        } else {
            a.pb(x);
        }
    }
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            if (b[j]%a[i] == 0 && 2*b[j]+a[i] <= m)
                f.edge(i, N+j, 1);
    for (int i = 0; i < a.size(); i++)
        f.edge(2*N, i, 1);
    for (int i = 0; i < b.size(); i++)
        f.edge(N+i, 2*N+1, 1);
    int flow = f.solve(2*N, 2*N+1);
    if (flow != b.size()) {
        cout << "-1\n";
        return 0;
    }
    vector<array<int, 2>> e;
    for (int i = 0; i < a.size(); i++)
        for (auto& fe : f.adj[i])
            if (fe.f > 0) e.pb({i, fe.v-N});
    vector<bool> v(a.size());
    vector<array<ll, 2>> ans;
    for (auto& [i, j] : e) {
        v[i] = 1;
        ans.pb({a[i]+b[j], a[i]+2*b[j]});
    }
    for (int i = 0; i < a.size(); i++)
        if (!v[i]) ans.pb({2*a[i], 3*a[i]});
    cout << ans.size() << "\n";
    for (auto& [x, y] : ans)
        cout << x << " " << y << "\n";
}