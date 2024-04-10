#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, m, q, tp, tim, tot, st[maxn], dfn[maxn], low[maxn];
int bel[maxn], sz[maxn], vis[maxn], vis2[maxn];
ll g[maxn], path[maxn];
vector<pair<int, int>> G[maxn], H[maxn], rH[maxn];

void tarjan(int v) {
    dfn[v] = low[v] = ++tim, st[++tp] = v;
    for (auto e : G[v]) {
        int u = e.first;
        if (!dfn[u]) tarjan(u), low[v] = min(low[v], low[u]);
        else if (!bel[u]) low[v] = min(low[v], dfn[u]);
    }
    if (dfn[v] == low[v]) {
        tot++;
        while (1) {
            int u = st[tp--]; bel[u] = tot, sz[tot]++;
            if (u == v) break;
        }
    }
}

void init(int v) {
    vis2[v] = 1;
    for (auto e : rH[v]) if (!vis2[e.first]) {
        path[e.first] = path[v] + e.second, init(e.first);
    }
}

void dfs(int v, ll len) {
    vis[v] = 1;
    for (auto e : H[v]) if (!vis[e.first]) {
        dfs(e.first, len + e.second);
    }
    for (auto e : H[v]) {
        g[bel[v]] = __gcd(g[bel[v]], len + e.second + path[e.first]);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        G[u].emplace_back(v, w);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        for (auto e : G[i]) if (bel[i] == bel[e.first]) {
            H[i].push_back(e), rH[e.first].emplace_back(i, e.second);
        }
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        init(i), dfs(i, 0);
    }
    scanf("%d", &q);
    while (q--) {
        int v, s, t; scanf("%d %d %d", &v, &s, &t);
        if (sz[bel[v]] == 1) {
            puts(s == 0 ? "YES" : "NO");
        } else {
            ll tmp = __gcd(g[bel[v]], (long long)t);
            puts(!((t - s) % tmp) ? "YES" : "NO");
        }
    }
    return 0;
}