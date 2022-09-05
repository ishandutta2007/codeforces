#include <bits/stdc++.h>
using namespace std;

const int maxn = 30010;
int n, m, s, t, u[maxn], v[maxn], w[maxn], par[maxn], sub[maxn];
int dfn[maxn], low[maxn];
vector<pair<int, int>> G[maxn];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d", &s, &t);
    iota(par + 1, par + n + 1, 1);
    vector<int> cand;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        if (find(u[i]) != find(v[i])) {
            cand.push_back(i);
            par[find(u[i])] = find(v[i]);
        }
    }
    if (find(s) != find(t)) {
        puts("0\n0\n"), exit(0);
    }
    int ans = INT_MAX;
    vector<int> way;
    for (int i : cand) {
        iota(par + 1, par + n + 1, 1);
        for (int j = 1; j <= n; j++) {
            G[j].clear();
        }
        for (int j = 1; j <= m; j++) if (i ^ j) {
            G[u[j]].emplace_back(v[j], j);
            G[v[j]].emplace_back(u[j], j);
            par[find(u[j])] = find(v[j]);
        }
        if (find(s) != find(t)) {
            if (ans > w[i]) ans = w[i], way = {i};
            continue;
        }
        memset(sub, 0, sizeof(sub)), sub[t]++;
        memset(dfn, 0, sizeof(dfn));
        int tim = 0;
        function<void(int, int)> dfs = [&](int v, int id) {
            dfn[v] = low[v] = ++tim;
            for (auto e : G[v]) if (e.second ^ id) {
                if (!dfn[e.first]) {
                    dfs(e.first, e.second);
                    sub[v] += sub[e.first];
                    low[v] = min(low[v], low[e.first]);
                } else {
                    low[v] = min(low[v], dfn[e.first]);
                }
            }
            if (dfn[v] == low[v] && v != s && sub[v] == 1) {
                if (ans > w[i] + w[id]) ans = w[i] + w[id], way = {i, id};
            }
        };
        dfs(s, 0);
    }
    if (ans == INT_MAX) puts("-1"), exit(0);
    printf("%d\n%d\n", ans, way.size());
    for (int x : way) printf("%d ", x);
    return 0;
}