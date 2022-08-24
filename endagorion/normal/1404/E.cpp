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
    int S = n * m, T = n * m + 1;
    Dinic dinic(n * m + 2);
    vector<string> f(n);
    forn(i, n) cin >> f[i];

    int V = 0;

    fore(i, -1, n - 1) forn(j, m) {
        bool flip = false;
        bool badV = i == -1 || f[i][j] == '.';
        bool badU = i == n - 1 || f[i + 1][j] == '.';
        int v = i * m + j, u = v + m;
        if (badV && badU) continue;
        if (badV) dinic.add_edge(u, T, 1);
        else if (badU) dinic.add_edge(v, T, 1);
        else {
            dinic.add_edge(u, v, 1);
            dinic.add_edge(v, u, 1);
        }
    }
    forn(i, n) fore(j, -1, m - 1) {
        bool flip = false;
        bool badV = j == -1 || f[i][j] == '.';
        bool badU = j == m - 1 || f[i][j + 1] == '.';
        int v = i * m + j, u = v + 1;
        if (badV && badU) continue;
        if (badV) dinic.add_edge(S, u, 1);
        else if (badU) dinic.add_edge(S, v, 1);
        else {
            dinic.add_edge(u, v, 1);
            dinic.add_edge(v, u, 1);
        }
    }
    cout << dinic.max_flow(S, T) / 2 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}