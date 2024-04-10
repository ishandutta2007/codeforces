#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010;
int n, K, r, q, bel[maxn], fa[maxn][20], dep[maxn], dist[maxn];
vector<int> G[maxn];

int find(int x) {
    return x == bel[x] ? x : bel[x] = find(bel[x]);
}

int main() {
    scanf("%d %d %d", &n, &K, &r);
    for (int i = 1, $ = n, u, v; i < $; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(++n), G[n].push_back(u);
        G[v].push_back(n), G[n].push_back(v);
    }
    function<void(int)> dfs = [&](int v) {
        dep[v] = dep[fa[v][0]] + 1;
        for (int i = 1; 1 << i < dep[v]; i++) {
            fa[v][i] = fa[fa[v][i - 1]][i - 1];
        }
        for (int u : G[v]) if (u ^ fa[v][0]) {
            fa[u][0] = v, dfs(u);
        }
    };
    dfs(1);
    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 19; ~i; i--) {
            if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
        }
        if (u == v) return u;
        for (int i = 19; ~i; i--) {
            if (fa[u][i] ^ fa[v][i]) u = fa[u][i], v = fa[v][i];
        }
        return fa[u][0];
    };
    auto jump = [&](int v, int k) {
        while (k) {
            int t = __builtin_ctz(k);
            v = fa[v][t], k ^= 1 << t;
        }
        return v;
    };
    iota(bel + 1, bel + n + 1, 1);
    memset(dist, -1, sizeof(dist));
    queue<int> Q;
    while (r--) {
        int v; scanf("%d", &v);
        Q.push(v), dist[v] = 0;
    }
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        if (dist[v] == K) continue;
        for (int u : G[v]) {
            bel[find(u)] = find(v);
            if (!~dist[u]) Q.push(u), dist[u] = dist[v] + 1;
        }
    }
    scanf("%d", &q);
    while (q--) {
        int u, v; scanf("%d %d", &u, &v);
        int l = lca(u, v), len = dep[u] + dep[v] - (dep[l] << 1);
        if (len < K << 1) { puts("YES"); continue; }
        int x = K <= dep[u] - dep[l] ? jump(u, K) : jump(v, len - K);
        int y = K <= dep[v] - dep[l] ? jump(v, K) : jump(u, len - K);
        puts(find(x) == find(y) ? "YES" : "NO");
    }
    return 0;
}