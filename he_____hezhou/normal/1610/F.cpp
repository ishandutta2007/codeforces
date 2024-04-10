#include <bits/stdc++.h>
using namespace std;
int n, m;
int ans[300010];
struct graph {
    vector < int > buf[300010];
    int son[300010], eid[300010], tag[300010], buftag[300010];
    inline int merge(int a, int b) {
        if (buf[a].size() < buf[b].size()) swap(a, b);
        for (auto i : buf[b]) buf[a].push_back(buftag[a] == buftag[b] ? i : -i);
        return a;
    }
    inline void calc(int id) {
        for (auto i : buf[id]) ans[abs(i)] = 1 + ((i < 0) ^ buftag[id]);
    }
    inline void addedge(int u, int v, int id) {
        buf[id].push_back(id);
        if (son[u] == v) {
            son[u] = 0, son[v] = 0;
            int id2 = eid[u];
            buftag[id2] ^= tag[u];
            buftag[id2] ^= 1;
            calc(id);
            calc(id2);
            return;
        }
        if (son[u]) {
            int v2 = son[u];
            son[u] = 0, son[v2] = 0;
            int id2 = eid[u];
            buftag[id2] ^= tag[u];
            buftag[id2] ^= 1;
            id = merge(id2, id);
            u = v2;
        }
        if (son[v]) {
            int v2 = son[v];
            son[v] = 0, son[v2] = 0;
            int id2 = eid[v];
            buftag[id2] ^= tag[v];
            id = merge(id, id2);
            v = v2;
        }
        son[u] = v, son[v] = u;
        tag[u] = 0, tag[v] = 1;
        eid[u] = eid[v] = id;
    }
    inline int operator[] (int x) { return son[x]; }
} g1, g2;
int vis[300010];
inline void dfs(int cur, int col) {
    if (vis[cur]) return;
    vis[cur] = 1;
    graph &g = (col == 1 ? g1 : g2);
    if (g[cur] == 0) return;
    g.buftag[g.eid[cur]] ^= g.tag[cur];
    g.calc(g.eid[cur]);
    dfs(g[cur], 3 - col);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        (w == 1 ? g1 : g2).addedge(u, v, i);
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += !!g1[i];
    // for (int i = 1; i <= n; i++) cerr << g1[i] << ' ' << g2[i] << endl;
    printf("%d\n", sum);
    for (int i = 1; i <= n; i++) if (g1[i] == 0 && g2[i] == 0) vis[i] = 1;
    for (int i = 1; i <= n; i++) if (g1[i] == 0 || g2[i] == 0) if (vis[i] == 0) {
        dfs(i, g1[i] == 0 ? 2 : 1);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, 1);
    for (int i = 1; i <= m; i++) putchar(ans[i] + '0');
    puts("");
}