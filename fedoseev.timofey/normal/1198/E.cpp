#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

const ll Inf = 1e18;

struct Dinic {
    struct Edge {
        int u, v, c, f;
        Edge() : u(0), v(0), c(0), f(0) {}
        Edge(int u, int v, int c, int f) : u(u), v(v), c(c), f(f) {}
    };
    int n;
    int s, t;
    ll ans = 0;
    vector <Edge> e;
    vector <vector <int>> g;
    vector <int> d;
    vector <int> first;
    Dinic(int nn) {
        g.resize(nn);
        d.resize(nn);
        first.resize(nn);
        n = nn;
        s = 0, t = 0;
    }
    void add(int u, int v, int c) {
        e.emplace_back(u, v, c, 0);
        g[u].push_back(e.size() - 1);
        e.emplace_back(v, u, 0, 0);
        g[v].push_back(e.size() - 1);
    }
    int bfs(int s, int t, int b) {
        for (int i = 0; i < n; ++i) first[i] = 0;
        for (int i = 0; i < n; ++i) {
            d[i] = -1;
        }
        d[s] = 0;
        queue <int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto x : g[u]) {
                int v = e[x].v;
                if (d[v] != -1 || e[x].c - e[x].f < b) continue;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        if (d[t] == -1) return false;
        else return true;
    }
    int dfs(int u, int t, int b, int cmin = Inf) {
        if (u == t) return cmin;
        for (; first[u] < g[u].size(); first[u]++) {
            int x = g[u][first[u]];
            if (e[x].c - e[x].f >= b && d[e[x].v] == d[e[x].u] + 1) {
                int d = dfs(e[x].v, t, b, min(cmin, e[x].c - e[x].f));
                if (d > 0) {
                    e[x].f += d;
                    e[x ^ 1].f -= d;
                    if (s == u) ans += d;
                    return d;
                }
            }
        }
        return 0;
    }
    void findMaxFlow() {
        for (int b = ((1ll) << 60); b > 0; b >>= 1) {
            while (bfs(s, t, b)) {
                while (dfs(s, t, b));
            }
        }
    }
};

struct Rect {
    int x1, y1, x2, y2; 
};

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << "0\n";
        return 0;
    }
    vector <Rect> R;
    vector <int> xs, ys;
    for (int i = 0; i < m; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1;
        R.push_back({x1, y1, x2, y2});
        xs.push_back(x1), xs.push_back(x2), ys.push_back(y1), ys.push_back(y2);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    int a = xs.size();
    int b = ys.size();
    Dinic f(a + b);
    f.s = 0;
    f.t = a + b - 1;
    for (int i = 0; i + 1 < a; ++i) {
        f.add(0, i + 1, xs[i + 1] - xs[i]);
    }
    for (int i = 0; i + 1 < b; ++i) {
        f.add(a + i, f.t, ys[i + 1] - ys[i]);
    }
    for (int i = 0; i + 1 < a; ++i) {
        for (int j = 0; j + 1 < b; ++j) {
            for (int k = 0; k < m; ++k) {
                if (R[k].x1 <= xs[i] && xs[i + 1] <= R[k].x2 && R[k].y1 <= ys[j] && ys[j + 1] <= R[k].y2) {
                    f.add(i + 1, a + j, (ll)(xs[i + 1] - xs[i]) * (ys[j + 1] - ys[j]));
                }
            }
        }
    }
    f.findMaxFlow();
    cout << f.ans << '\n';
}