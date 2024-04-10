#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, h, id, tot, t[maxn], sz[maxn], bel[maxn];
bool out[maxn], vis[maxn];
vector<int> V, G[maxn], H[maxn];

void add(int u, int v) {
    G[u].push_back(v), H[v].push_back(u);
}

void dfs1(int v) {
    if (vis[v]) return; vis[v] = 1;
    for (int u : G[v]) dfs1(u);
    V.push_back(v);
}

void dfs2(int v) {
    if (bel[v]) return; bel[v] = tot;
    for (int u : H[v]) dfs2(u);
}

int main() {
    scanf("%d %d %d", &n, &m, &h);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v);
        if ((t[u] + 1) % h == t[v]) add(u, v);
        if ((t[v] + 1) % h == t[u]) add(v, u);
    }
    for (int i = 1; i <= n; i++) {
        dfs1(i);
    }
    for (int i = n - 1; ~i; i--) {
        if (!bel[V[i]]) tot++, dfs2(V[i]);
    }
    for (int i = 1; i <= n; i++) {
        sz[bel[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j : G[i]) {
            if (bel[i] ^ bel[j]) out[bel[i]] = 1;
        }
    }
    sz[id] = INT_MAX;
    for (int i = 1; i <= tot; i++) {
        if (!out[i] && sz[i] < sz[id]) id = i;
    }
    printf("%d\n", sz[id]);
    for (int i = 1; i <= n; i++) {
        if (bel[i] == id) printf("%d ", i);
    }
    return 0;
}