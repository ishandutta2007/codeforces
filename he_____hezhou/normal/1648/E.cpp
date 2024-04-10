#include <bits/stdc++.h>
using namespace std;
int T;
int n, m;
struct node {
    int u, v, w, id;
} e[200010];
int ans[200010];
int fa[200010], id[200010];
vector < int > v[200010], ids[200010];
vector < pair < int, int > > faids[200010];
int gf(int a) { return fa[a] == a ? a : fa[a] = gf(fa[a]); }
vector < pair < int, int > > son[200010];
int d[200010];
void merge(int x, int y, int w) {
    if (ids[y].size() > ids[x].size()) swap(x, y);
    for (auto i : ids[y]) {
        int cur = gf(i);
        for (auto i : faids[x]) d[i.first] = 0;
        for (auto j : v[i]) if (id[j] == x) d[gf(j)]++;
        vector < pair < int, int > > tmp;
        int sze = 0;
        for (auto j : faids[x]) {
            if (d[j.first] != j.second || cur == j.first) {
                if (j.first != cur) {
                    son[j.first].push_back({cur, w});
                    son[cur].push_back({j.first, w});
                }
                fa[j.first] = cur;
                sze += j.second;
            }
            else tmp.push_back(j);
        }
        tmp.push_back({cur, sze});
        faids[x].swap(tmp);
    }
    for (auto i : ids[y]) {
        id[i] = x;
        ids[x].push_back(i);
        faids[x].push_back({gf(i), 1});
    }
    sort(faids[x].begin(), faids[x].end());
    vector < pair < int, int > > tmp;
    for (int l = 0, r = 0; l < faids[x].size(); l = r) {
        int sze = 0;
        while (r < faids[x].size() && faids[x][r].first == faids[x][l].first) sze += faids[x][r++].second;
        tmp.push_back({faids[x][l].first, sze});
    }
    faids[x].swap(tmp);
}
int dep[200010], f[200010][20], g[200010][20];
void dfs(int x, int fa) {
    dep[x] = dep[fa] + 1;
    for (auto i : son[x]) {
        if (i.first == fa) continue;
        f[i.first][0] = x;
        g[i.first][0] = i.second;
        dfs(i.first, x);
    }
}
void rmain() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        e[i].id = i;
    }
    sort(e + 1, e + 1 + m, [](node &a, node &b) {
        return a.w < b.w;
    });
    for (int i = 1; i <= n; i++) {
        v[i].clear(), son[i].clear();
        id[i] = i, fa[i] = i;
        ids[i].clear(), faids[i].clear();
        ids[i].push_back(i);
        faids[i].push_back({i, 1});
    }
    for (int i = 1; i <= m; i++) {
        ::v[e[i].u].push_back(e[i].v);
        ::v[e[i].v].push_back(e[i].u);
    }
    for (int i = 1; i <= m; i++) {
        int u = id[e[i].u], v = id[e[i].v];
        if (u == v) continue;
        merge(id[e[i].u], id[e[i].v], e[i].w);
    }
    dfs(1, 0);
    for (int i = 1; i < 20; i++)
        for (int j = 1; j <= n; j++) f[j][i] = f[f[j][i - 1]][i - 1], g[j][i] = max(g[j][i - 1], g[f[j][i - 1]][i - 1]);
    for (int i = 1; i <= m; i++) {
        int cur = 0;
        int u = e[i].u, v = e[i].v;
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 20; i --> 0; ) if (dep[f[u][i]] >= dep[v]) cur = max(cur, g[u][i]), u = f[u][i];
        if (u == v) ans[e[i].id] = cur;
        else {
            for (int i = 20; i --> 0; ) if (f[u][i] != f[v][i]) cur = max(cur, max(g[u][i], g[v][i])), u = f[u][i], v = f[v][i];
            cur = max(cur, max(g[u][0], g[v][0]));
        }
        ans[e[i].id] = cur;
    }
    for (int i = 1; i <= m; i++) printf("%d%c", ans[i], " \n"[i == m]);
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}