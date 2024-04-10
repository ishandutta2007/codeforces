#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct Edge {
    int from, to, cap, flow;
};

const int INF = (int)2e9;

struct Dinic {
    int n;
    vector<Edge> edges;
    vector<vector<int>> g;

    Dinic(int n) : n(n) {
        g.resize(n);
    }

    void add_edge(int from, int to, int cap) {
        assert(from < n);
        assert(to < n);
        assert(cap >= 0);
        Edge e = {from, to, cap, 0};
        g[from].push_back(edges.size());
        edges.push_back(e);
        e = {to, from, 0, 0};
        g[to].push_back(edges.size());
        edges.push_back(e);
    }

    vector<int> d;

    bool bfs(int s, int t) {
        d.assign(n, INF);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto id : g[v]) {
                auto e = edges[id];
                if (e.cap > e.flow && d[e.to] == INF) {
                    d[e.to] = d[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return d[t] != INF;
    }

    vector<int> pointer;

    int dfs(int v, int t, int flow_add) {
        if (!flow_add) {
            return 0;
        }
        if (v == t) {
            return flow_add;
        }
        int added_flow = 0;
        for (int& i = pointer[v]; i < g[v].size(); ++i) {
            int id = g[v][i];
            int to = edges[id].to;
            if (d[to] != d[v] + 1) {
                continue;
            }
            int pushed = dfs(to, t, min(flow_add, edges[id].cap - edges[id].flow));
            if (pushed) {
                edges[id].flow += pushed;
                edges[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            pointer.assign(n, 0);
            while (int pushed = dfs(s, t, INF)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    vi a(n), b(n), c(n), l(n), r(n);
    vi u(m), v(m), d(m);
    forn(i, n) cin >> a[i] >> b[i] >> c[i];
    forn(i, n) cin >> l[i] >> r[i];
    forn(i, m) cin >> u[i] >> v[i] >> d[i], --u[i], --v[i];

    vi off(n + 1);
    int S = 0, T = 1;
    off[0] = 2;
    forn(i, n) off[i + 1] = off[i] + r[i] - l[i] + 1;
    Dinic dinic(off[n]);
    i64 ans = 0;
    forn(i, n) {
        forn(j, r[i] - l[i]) dinic.add_edge(off[i] + j + 1, off[i] + j, 1e9);
        vi val(r[i] - l[i] + 1);
        forn(j, r[i] - l[i] + 1) {
            int x = j + l[i];
            val[j] = c[i] + x * (b[i] + x * a[i]);
//            cerr << val[j] << ' ';
        }
        dinic.add_edge(S, off[i], 1e9);
        ans += val[0];
        forn(j, r[i] - l[i]) {
            int d = val[j + 1] - val[j];
            if (d > 0) {
                ans += d;
                dinic.add_edge(S, off[i] + j + 1, d);
            } else {
                dinic.add_edge(off[i] + j + 1, T, -d);
            }
        }
    }

    forn(k, m) {
        int U = u[k], V = v[k], D = -d[k];
        fore(x, -300, 300) {
            int ju = x - l[U];
            int y = x + D;
            int jv = y - l[V];
            if (ju > r[U] - l[U] || jv < 0) continue;
            uax(ju, 0);
            if (jv > r[V] - l[V]) dinic.add_edge(off[U] + ju, T, 1e9);
            else dinic.add_edge(off[U] + ju, off[V] + jv, 1e9);
        }
    }

    int F = dinic.max_flow(S, T);
    cout << ans - F << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}