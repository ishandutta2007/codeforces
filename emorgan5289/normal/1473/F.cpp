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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int edges = 0;
 
// N vertices, flow is measured with type T
template<int N, typename T>
struct flow {
 
    const bool SCALING = true;
    const T inf_T = numeric_limits<T>::max();
 
    struct flow_edge { int v, u; T f, w; };
    vector<flow_edge> adj[N];
    int l[N], p[N], s, t; T k;
 
    // add an edge from i to j with capacity w
    void edge(int i, int j, T w, bool directed = true) {
        edges++;
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

// returns a sorted list of all divisors of n in O(sqrt(n)) time.
template<typename T>
vector<T> divisors(T n) {
    vector<T> s, e;
    for (T i = 1; i <= (T)(sqrt(n)); i++)
        if (n%i == 0) {
            s.push_back(i);
            if (i*i != n) e.push_back(n/i);
        }
    for (int i = e.size()-1; i >= 0; i--)
        s.push_back(e[i]);
    return s;
}
 
const int N = 3005;
int a[N], b[N];
flow<2*N+N*105, int> f;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    ll ans = 0;
    int s = 2*N-1, t = 2*N-2;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> p(105, -1);
    for (int i = 0; i < n; i++) {
        for (auto& x : divisors(a[i])) {
            if (p[x] != -1) f.edge(2*N+x*N+i, 2*N+x*N+p[x], inf);
            p[x] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] > 0) {
            f.edge(s, i, b[i]);
            for (auto& x : divisors(a[i]))
                f.edge(i, 2*N+x*N+i, inf);
            ans += b[i];
        }
        if (b[i] < 0) {
            f.edge(2*N+a[i]*N+i, N+i, inf);
            f.edge(N+i, t, -b[i]);
        }
    }
    for (int i = 1; i <= 100; i++)
        for (int j = i; j <= 100; j += i)
            f.edge(2*N+j, 2*N+i, inf);
    ans -= f.solve(s, t);
    cout << ans << "\n";
}