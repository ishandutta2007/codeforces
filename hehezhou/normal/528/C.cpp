#include <bits/stdc++.h>
using namespace std;
int n, m;
struct edge {
    int v, nxt, vis;
} e[500010];
int head[100010], tot = 1;
inline void addedge(int u, int v) {
    e[++tot] = edge{v, head[u], 0};
    head[u] = tot;
}
int du[100010];
inline void dfs(int now) {
    static int dfsnow = 0;
    for (int &i = head[now]; i; i = e[i].nxt) {
        if (e[i].vis) continue;
        e[i].vis = e[i ^ 1].vis = 1;
        int v = e[i].v;
        dfs(v);
        ++dfsnow;
        if (dfsnow & 1) printf("%d %d\n", now, v);
        else printf("%d %d\n", v, now);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
        du[u] ^= 1, du[v] ^= 1;
    }
    for (int i = 1; i <= n; i++) {
        if (du[i] == 0) continue;
        int j;
        for (j = i + 1; du[j] == 0; j++);
        addedge(i, j);
        addedge(j, i);
        i = j;
    }
    if (tot / 2 % 2) addedge(1, 1);
    printf("%d\n", tot / 2);
    for (int i = 1; i <= n; i++) dfs(i);
}