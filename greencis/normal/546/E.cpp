#include <bits/stdc++.h>
using namespace std;

struct dinic {
    static const int INF = 1e9;

    struct edge { int to, cap, flow; };
    vector<edge> edges;
    vector<vector<int>> g;
    vector<int> d, q, ptr;
    int n, st, fi;

    dinic(int n, int st, int fi) : n(n), st(st), fi(fi) { g.resize(n); q.resize(n); }

    void add_edge(int from, int to, int cap = INF) {
        g[from].push_back((int)edges.size());
        edges.push_back({to, cap, 0});
        g[to].push_back((int)edges.size());
        edges.push_back({from, 0, 0});
    }

    bool bfs() {
        d.assign(n, -1);
        int qh = 0, qt = 0;
        q[qt++] = st;
        d[st] = 0;
        while (d[fi] == -1 && qh < qt) {
            int v = q[qh++];
            for (int ed : g[v]) {
                int to = edges[ed].to;
                if (d[to] == -1 && edges[ed].flow < edges[ed].cap) {
                    d[to] = d[v] + 1;
                    q[qt++] = to;
                }
            }
        }
        return d[fi] != -1;
    }

    int dfs(int v, int add = INF) {
        if (add == 0) return 0;
        if (v == fi) return add;
        for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
            int ed = g[v][ptr[v]];
            int to = edges[ed].to;
            if (d[to] != d[v] + 1) continue;
            int pushed = dfs(to, min(add, edges[ed].cap - edges[ed].flow));
            if (pushed) {
                edges[ed].flow += pushed;
                edges[ed ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    int flow() {
        int ans = 0;
        while (bfs()) {
            ptr.assign(n, 0);
            while (int pushed = dfs(st))
                ans += pushed;
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    int n, m, x, y, suma = 0, sumb = 0;
    cin >> n >> m;
    dinic solver(2 * n + 2, 0, 2 * n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        suma += x;
        solver.add_edge(0, i + 1, x);
        solver.add_edge(i + 1, i + n + 1);
    }
    for (int i = 0; i < n; ++i) {
        cin >> x;
        sumb += x;
        solver.add_edge(i + n + 1, 2 * n + 1, x);
    }
    while (m--) {
        cin >> x >> y;
        solver.add_edge(x, y + n);
        solver.add_edge(y, x + n);
    }

    int flow = solver.flow();
    if (flow != suma || flow != sumb) {
        cout << "NO\n";
        exit(0);
    }

    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int ed : solver.g[i + 1]) {
            int to = solver.edges[ed].to;
            if (to >= n + 1 && to <= n + n)
                ans[i][to - n - 1] += solver.edges[ed].flow;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << (j ? " " : "") << ans[i][j];
        cout << "\n";
    }
}