#include <bits/stdc++.h>
using namespace std;

const int maxn = 3010;
int n, m, q, f[13][maxn], ans[400010];
bool b[maxn][maxn];
vector<int> G[maxn], rG[maxn];
vector<array<int, 3>> Q[maxn];

int main() {
    scanf("%d %d %d", &n, &m, &q);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v), rG[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(G[i].begin(), G[i].end());
        queue<int> Q;
        Q.push(i), b[i][i] = 1;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int v : rG[u]) if (!b[i][v]) {
                Q.push(v), b[i][v] = 1;
            }
        }
    }
    for (int i = 1, s, t, k; i <= q; i++) {
        scanf("%d %d %d", &s, &t, &k);
        if (!b[t][s]) { ans[i] = -1; continue; }
        Q[t].push_back({s, k, i});
    }
    for (int t = 1; t <= n; t++) {
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++) if (b[t][i] && i ^ t) {
            for (int k : G[i]) if (b[t][k]) {
                f[0][i] = k; break;
            }
        }
        for (int k = 1; k <= 12; k++) {
            for (int i = 1; i <= n; i++) {
                if (i ^ t) f[k][i] = f[k - 1][f[k - 1][i]];
            }
        }
        for (auto &p : Q[t]) {
            int s = p[0], k = p[1];
            if (!b[t][s] || f[12][s]) { ans[p[2]] = -1; continue; }
            ans[p[2]] = s;
            if (!--k) continue;
            for (int i = 0; i <= 12; i++) {
                if (k >> i & 1) ans[p[2]] = f[i][ans[p[2]]];
            }
            if (!ans[p[2]]) ans[p[2]] = -1;
        }
    }
    for (int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}