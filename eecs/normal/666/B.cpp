#include <bits/stdc++.h>
using namespace std;

const int maxn = 3010;
int n, m, d[maxn][maxn], ord[maxn][maxn];
vector<int> G[maxn], pre[maxn], nxt[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        memset(d[i], -0x3f, sizeof(d[i]));
        queue<int> Q; Q.push(i), d[i][i] = 0;
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            for (int u : G[v]) if (d[i][u] < 0) {
                Q.push(u), d[i][u] = d[i][v] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1, k = 0; j <= n; j++) if (i ^ j) {
            ord[i][++k] = j;
        }
        sort(ord[i] + 1, ord[i] + n, [&](int x, int y) { return d[x][i] > d[y][i]; });
        for (int j = 1; j <= 3; j++) if (d[ord[i][j]][i] > 0) pre[i].push_back(ord[i][j]);
        sort(ord[i] + 1, ord[i] + n, [&](int x, int y) { return d[i][x] > d[i][y]; });
        for (int j = 1; j <= 3; j++) if (d[i][ord[i][j]] > 0) nxt[i].push_back(ord[i][j]);
    }
    long long ans = 0;
    int v1, v2, v3, v4;
    for (int s = 1; s <= n; s++) {
        for (int t = 1; t <= n; t++) if (s ^ t && d[s][t] > 0) {
            for (int u : pre[s]) for (int v : nxt[t]) {
                if (u == v || u == t || v == s) continue;
                long long dist = d[u][s] + d[s][t] + d[t][v];
                if (dist > ans) ans = dist, v1 = u, v2 = s, v3 = t, v4 = v;
            }
        }
    }
    printf("%d %d %d %d\n", v1, v2, v3, v4);
    return 0;
}