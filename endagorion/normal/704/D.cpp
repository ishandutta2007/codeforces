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
    int from, to, cap, flow, id;
};

const int INF = (int)2e9;

struct Dinic {
    int n;
    vector<Edge> edges;
    vector<vector<int>> g;

    Dinic(int n) : n(n) {
        g.resize(n);
    }

    void add_edge(int from, int to, int cap, int id = -1) {
        Edge e = {from, to, cap, 0, id};
        g[from].push_back(edges.size());
        edges.push_back(e);
        e = {to, from, 0, 0, -1};
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
    i64 r, b;
    cin >> r >> b;
    bool sw = r > b;
    if (sw) swap(r, b);
    b -= r;
    i64 ans = r * n;
    map<int, vector<pii>> ps, rps;
    vi xs, ys;
    forn(i, n) {
        int x, y;
        cin >> x >> y;
        ps[x].pb({y, i});
        rps[y].pb({x, -1});
        xs.pb(x);
        ys.pb(y);
    }

    auto reduce = [](vi &v) {
        sort(all(v));
        v.erase(unique(all(v)), v.end());
    };
    reduce(xs);
    reduce(ys);
    map<int, int> xl, yl;
    forn(i, m) {
        int t, c, d;
        cin >> t >> c >> d;
        auto &m = t == 1 ? xl : yl;
        if (!m.count(c)) m[c] = 1e9;
        uin(m[c], d);
    }

    auto index = [](vi &v, int x) {
        return lower_bound(all(v), x) - v.begin();
    };

    int S0 = (int)(xs.size() + ys.size()), T0 = S0 + 1;
    int S1 = T0 + 1, T1 = S1 + 1;
    Dinic dinic(T1 + 1);
    dinic.add_edge(T1, S1, INF);
    int SL1 = 0, SL2 = 0;
    bool ok = true;
    forn(i, xs.size()) {
        for (auto [y, id]: ps[xs[i]]) dinic.add_edge(i, xs.size() + index(ys, y), 1, id);
        int S = ps[xs[i]].size();
        int D = S;
        if (xl.count(xs[i])) uin(D, xl[xs[i]]);
        int L = (S - D + 1) / 2, R = (D + S) / 2;
//        cerr << "X " << xs[i] << ' ' << S << ' ' << D << ' ' << L << ' ' << R << '\n';
        ok &= L <= R;
        dinic.add_edge(S1, i, R - L);
        dinic.add_edge(S0, i, L);
        SL1 += L;
    }

    forn(i, ys.size()) {
        int S = rps[ys[i]].size();
        int D = S;
        if (yl.count(ys[i])) uin(D, yl[ys[i]]);
        int L = (S - D + 1) / 2, R = (D + S) / 2;
//        cerr << "Y " << ys[i] << ' ' << S << ' ' << D << ' ' << L << ' ' << R << '\n';
        ok &= L <= R;
        int ii = i + xs.size();
        dinic.add_edge(ii, T1, R - L);
        dinic.add_edge(ii, T0, L);
        SL2 += L;
    }
    dinic.add_edge(S1, T0, SL1);
    dinic.add_edge(S0, T1, SL2);

    int FF = dinic.max_flow(S0, T0);
//    cerr << SL1 << ' ' << SL2 << ' ' << FF << '\n';
    ok &= FF == SL1 + SL2;
    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }

    int F = -1;
    for (auto &e: dinic.edges) {
        if (e.from == T1 && e.to == S1) {
            F = e.flow;
            e.flow = 0;
            e.cap = 0;
        }
    }

//    cerr << F << '\n';

    F -= dinic.max_flow(T1, S1);
    cerr << F << '\n';
    cout << ans + F * b << '\n';
    string res(n, '.');
    for (auto &e: dinic.edges) {
        if (e.id != -1) res[e.id] = "rb"[e.flow ^ sw];
    }
    cout << res << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}