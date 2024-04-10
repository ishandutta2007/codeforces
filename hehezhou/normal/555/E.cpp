#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int cnt;
struct edge {
    int v, nxt;
} e[400010];
int head[200010], tot;
inline void addedge(int u, int v) {
    e[++tot] = edge{v, head[u]};
    head[u] = tot;
}
int low[200010], dfn[200010], dfsnow;
int sta[200010], top, id[200010];
inline void tarjan(int now, int fa) {
    dfn[now] = low[now] = ++dfsnow;
    sta[++top] = now;
    for (int i = head[now]; i; i = e[i].nxt) {
        if (e[i].v == fa) {
            fa = -1;
            continue;
        }
        if (!dfn[e[i].v]) tarjan(e[i].v, now);
        low[now] = min(low[now], low[e[i].v]);
    }
    if (dfn[now] == low[now]) {
        cnt++;
        do {
            id[sta[top]] = cnt;
        } while (sta[top--] != now);
    }
}
vector < int > son[200010];
int f[200010][20], dep[200010], vis[200010];
inline void dfs(int now, int fa) {
    dep[now] = dep[fa] + 1;
    vis[now] = 1;
    f[now][0] = fa;
    for (int i = 0; f[now][i]; i++) f[now][i + 1] = f[f[now][i]][i];
    for (auto i : son[now]) {
        if (i == fa) continue;
        dfs(i, now);
    }
}
int tag[200010][2];
inline void calc(int now, int fa) {
    vis[now] = 1;
    for (auto i : son[now]) {
        if (i == fa) continue;
        calc(i, now);
        tag[now][0] += tag[i][0];
        tag[now][1] += tag[i][1];
    }
}
inline int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = 18; i --> 0; ) if (dep[f[a][i]] >= dep[b]) a = f[a][i];
    if (a == b) return a;
    for (int i = 18; i --> 0; ) if (f[a][i] != f[b][i]) a = f[a][i], b = f[b][i];
    return f[a][0];
}
int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i, 0);
    }
    for (int i = 1; i <= n; i++)
        for (int j = head[i]; j; j = e[j].nxt) if (id[i] != id[e[j].v]) {
            son[id[i]].push_back(id[e[j].v]);
        }
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= cnt; i++) if (!vis[i]) dfs(i, 0);
    for (int i = 1; i <= q; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u = id[u], v = id[v];
        int l = lca(u, v);
        if (l == 0) return puts("No"), 0;
        tag[u][0]++, tag[v][1]++;
        tag[l][0]--, tag[l][1]--;
    }
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= cnt; i++) if (!vis[i]) calc(i, 0);
    for (int i = 1; i <= cnt; i++) if (tag[i][0] && tag[i][1]) return puts("No"), 0;
    return puts("Yes"), 0;
}