#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, tot, K, id[maxn], w[maxn], mp[maxn], d[100][maxn];
bool vis[maxn];
set<int> G[maxn];
vector<int> H[maxn];
long long ans, s1[maxn], s2[maxn];

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].insert(v), G[v].insert(u);
    }
    fill(w + 1, w + n + 1, 1);
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (G[i].size() == 1) Q.push(i);
    }
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (int y : G[x]) {
            G[y].erase(x), w[y] += w[x];
            ans += 2LL * w[x] * (n - w[x]);
            if (G[y].size() == 1) Q.push(y);
        }
        G[x].clear();
    }
    for (int i = 1; i <= n; i++) {
        if (G[i].size() > 2) id[i] = ++tot;
    }
    K = tot;
    for (int i = 1; i <= n; i++) {
        if (G[i].size() == 2) id[i] = ++tot;
    }
    for (int i = 1; i <= n; i++) {
        mp[id[i]] = w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j : G[i]) H[id[i]].push_back(id[j]);
    }
    for (int i = 1; i <= tot; i++) {
        w[i] = mp[i];
    }
    if (!K) K = 2;
    auto bfs = [&](int s) {
        memset(d[s], 0x3f, sizeof(d[s]));
        Q.push(s), d[s][s] = 0;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int v : H[u]) if (d[s][v] > d[s][u] + 1) {
                Q.push(v), d[s][v] = d[s][u] + 1;
            }
        }
    };
    for (int i = 1; i <= K; i++) {
        bfs(i);
        for (int j = 1; j <= tot; j++) {
            ans += 1LL * w[i] * w[j] * d[i][j];
        }
    }
    auto solve = [&](int a, int b) {
        vector<int> V = {a, b};
        while (b > K) {
            for (int x : H[b]) if (x ^ V[V.size() - 2]) {
                V.push_back(b = x); break;
            }
        }
        for (int x : V) vis[x] = 1;
        int tot = d[a][b] + V.size() - 1;
        for (int i = 1; i + 1 < V.size(); i++) {
            s1[i] = s1[i - 1] + w[V[i]];
            s2[i] = s2[i - 1] + 1LL * i * w[V[i]];
        }
        // inside
        for (int i = 1; i + 1 < V.size(); i++) {
            int ed = min(i + tot / 2, (int)V.size() - 2);
            ans += 2 * w[V[i]] * (s2[ed] - s2[i] - i * (s1[ed] - s1[i]));
            ans += 2 * w[V[i]] * (s2[ed] - s2[V.size() - 2] + (tot + i) * (s1[V.size() - 2] - s1[ed]));
        }
        // outside
        vector<bool> mark(::tot + 1);
        for (int i = 1; i + 1 < V.size(); i++) {
            mark[V[i]] = 1;
        }
        for (int i = 1; i <= ::tot; i++) if (!mark[i]) {
            int d1 = d[a][i], d2 = d[b][i];
            int u = min((int)V.size() - 2, (d2 + (int)V.size() - 1 - d1) / 2);
            ans += w[i] * (s2[u] + d1 * s1[u]);
            ans += w[i] * (s2[u] - s2[V.size() - 2] + (d2 + V.size() - 1) * (s1[V.size() - 2] - s1[u]));
        }
    };
    for (int i = 1; i <= K; i++) {
        for (int j : H[i]) if (j > K && !vis[j]) solve(i, j);
    }
    printf("%lld\n", ans / 2);
    return 0;
}