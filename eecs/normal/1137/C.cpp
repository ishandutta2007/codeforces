#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000010;
int n, m, d, tot, cnt, t, w[maxn], f[maxn], bel[maxn];
int tp, st[maxn], h[maxn], low[maxn], dfn[maxn];
bool chk[maxn]; char s[55];
vector<int> S[maxn]; queue<int> q;
int id(int x, int y) { return (x - 1) * d + y; }
struct edge { int to, nxt; } e[maxn];

void add(int u, int v) {
    e[++t] = (edge){v, h[u]}, h[u] = t;
}

void dfs(int v) {
    dfn[v] = low[v] = ++tot, st[++tp] = v;
    for (int i = h[v], u; i; i = e[i].nxt) {
        if (!dfn[u = e[i].to]) dfs(u), low[v] = min(low[v], low[u]);
        else if (!bel[u]) low[v] = min(low[v], dfn[u]);
    }
    if (dfn[v] == low[v]) {
        for (cnt++; ; ) {
            int x = st[tp--];
            bel[x] = cnt;
            if (chk[x]) S[cnt].push_back(x / d);
            if (x == v) break;
        }
    }
}

int dp(int v) {
    if (~f[v]) return f[v]; f[v] = w[v];
    for (int i = h[v]; i; i = e[i].nxt) {
        f[v] = max(f[v], dp(e[i].to) + w[v]);
    }
    return f[v];
}

int main() {
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v);
        for (int j = 0; j < d; j++) {
            add(id(u, j), id(v, (j + 1) % d));
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= d; j++) {
            chk[id(i, j % d)] = s[j] - '0';
        }
    }
    for (int i = 0; i < n * d; i++) {
        if (!dfn[i]) dfs(i);
    }
    memset(chk, 0, sizeof(chk));
    for (int i = 1; i <= cnt; i++) {
        for (int j : S[i]) {
            if (!chk[j]) w[i]++, chk[j] = 1;
        }
        for (int j : S[i]) {
            chk[j] = 0;
        }
    }
    tot = 0;
    for (int i = 0; i < n * d; i++) {
        for (int j = h[i], k; j; j = e[j].nxt) {
            if (bel[i] == bel[k = e[j].to]) continue;
            low[++tot] = bel[i], dfn[tot] = bel[k];
        }
    }
    t = 0, memset(h, 0, sizeof(h));
    for (int i = 1; i <= tot; i++) {
        add(low[i], dfn[i]);
    }
    memset(f, -1, sizeof(f));
    printf("%d\n", dp(bel[id(1, 1 % d)]));
    return 0;
}