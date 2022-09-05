#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, tp, st[maxn], d[maxn];
int cnt, tim, dfn[maxn], low[maxn], bel[maxn];
vector<int> G[maxn], C[maxn];

void tarjan(int v) {
    dfn[v] = low[v] = ++tim, st[++tp] = v;
    for (int u : G[v]) {
        if (!dfn[u]) tarjan(u), low[v] = min(low[v], low[u]);
        else if (!bel[u]) low[v] = min(low[v], dfn[u]);
    }
    if (dfn[v] == low[v]) {
        cnt++;
        for (int u = 0; u ^ v; ) u = st[tp--], C[bel[u] = cnt].push_back(u);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v; scanf("%d %d", &u, &v);
        G[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j : G[i]) {
            if (bel[i] ^ bel[j]) d[bel[j]]++;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        if (!d[i]) st[++tp] = i;
    }
    while (tp > 1) {
        int &u = st[tp - 1], &v = st[tp];
        int x = C[u].back(), y = C[v].back(), z;
        printf("? %d %d\n", x, y);
        fflush(stdout), scanf("%d", &z);
        if (!z) swap(u, v), swap(x, y);
        C[v].pop_back();
        if (C[v].empty()) tp--;
        for (int i : G[y]) {
            if (!--d[bel[i]]) st[++tp] = bel[i];
        }
    }
    printf("! %d\n", C[st[1]].back());
    return 0;
}