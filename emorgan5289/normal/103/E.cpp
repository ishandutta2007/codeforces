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

template<int N, int M>
struct matching {

    vector<int> adj[N];
    int ord[N], vis[N], R[N], t;

    // add an edge between i on the left, and j on the right
    void edge(int i, int j) {
        adj[i].push_back(j);
    }

    bool dfs(int i) {
        vis[i] = t;
        for (int j : adj[i])
            if (R[j] == -1)
                return R[j] = i, 1;
        for (int j : adj[i])
            if (vis[R[j]] < t && dfs(R[j]))
                return R[j] = i, 1;
        return 0;
    }

    // returns a list of edges {left, right}. runs in O(E \sqrt V) time.
    vector<pair<int, int>> solve() {
        iota(ord, ord+N, 0);
        random_shuffle(ord, ord+N);
        fill(R, R+M, -1); t = 0;
        for (int i = 0; i < N; i++)
            if (!dfs(i)) break;
            else t++;
        vector<pair<int, int>> out;
        for (int i = 0; i < N; i++)
            if (R[i] != -1)
                out.emplace_back(R[i], i);
        return out;
    }
};

struct dsu {

    vector<int> p, sz;

    dsu(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int rep(int x) {
        while (x != p[x]) x = p[x] = p[p[x]];
        return x;
    }

    // returns true if a and b are in the same set, and then unites them.
    bool unite(int a, int b) {
        a = rep(a), b = rep(b);
        if (sz[a] < sz[b]) swap(a, b);
        if (a != b) p[b] = a, sz[a] += sz[b];
        return a == b;
    }

    // returns true if a and b are in the same set.
    bool query(int a, int b) {
        return rep(a) == rep(b);
    }

    // returns the size of the set containing x
    int size(int x) {
        return sz[rep(x)];
    }
};

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

const int N = 305;
matching<N, N> m;
ll p[N], c[N];
vector<vector<int>> adj;
dinic<N, ll> f;
int S = N-1, T = N-2;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        while (k--) {
            int j; cin >> j; j--;
            m.edge(i, j);
        }
    }
    for (auto& [i, j] : m.solve())
        p[j] = i;
    for (int i = 0; i < n; i++)
        for (int j : m.adj[i])
            if (i != p[j])
                f.edge(i, p[j], inf_ll);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        f.edge(S, i, max(0ll, -c[i]));
        f.edge(i, T, max(0ll, c[i]));
        ans += min(0ll, c[i]);
    }
    cout << ans+f.solve(S, T) << "\n";
}