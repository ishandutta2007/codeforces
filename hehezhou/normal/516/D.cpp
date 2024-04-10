#include <bits/stdc++.h>
using namespace std;
struct edge {
    int v, w, nxt;
} e[200010];
int head[100010], tot;
inline void addedge(int u, int v, int w) {
    e[++tot] = edge{v, w, head[u]};
    head[u] = tot;
}
long long dis[100010];
int id;
inline void dfs(int now, int fa) {
    for (int i = head[now]; i; i = e[i].nxt) {
        if (e[i].v == fa) continue;
        dis[e[i].v] = dis[now] + e[i].w;
        dfs(e[i].v, now);
    }
    if (id == 0 || dis[id] < dis[now]) id = now;
}
int n;
int fa[100010], sze[100010];
inline int gf(int a) {
    return fa[a] == a ? fa[a] : fa[a] = gf(fa[a]);
}
long long maxdis[100010];
int tid[100010];
inline int cmp(int a, int b) {
    return maxdis[a] > maxdis[b];
}
int buc[100010];
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w);
        addedge(v, u, w);
    }
    dfs(1, 0);
    int rt = id;
    id = 0;
    dis[rt] = 0;
    dfs(rt, 0);
    for (int i = 1; i <= n; i++) maxdis[i] = dis[i];
    dis[id] = 0;
    dfs(id, 0);
    for (int i = 1; i <= n; i++) maxdis[i] = max(maxdis[i], dis[i]), tid[i] = i, cerr << maxdis[i] << " \n"[i == n];
    sort(tid + 1, tid + 1 + n, cmp);
    int q;
    scanf("%d", &q);
    while (q--) {
        long long L;
        int ans = 0;
        scanf("%lld", &L);
        for (int i = 1; i <= n; i++) fa[i] = 0, sze[i] = 0, buc[i] = 0;
        for (int l = 1, r = 1; r <= n; r++) {
            int now = tid[r];
            fa[now] = now, sze[now] = 1;
            for (int i = head[now]; i; i = e[i].nxt) {
                if (fa[e[i].v] == 0) continue;
                buc[sze[gf(e[i].v)]]--;
                sze[now] += sze[gf(e[i].v)];
                fa[gf(e[i].v)] = now;
            }
            buc[sze[now]]++;
            while (maxdis[tid[l]] > maxdis[now] + L) sze[gf(tid[l++])]--;
            ans = max(ans, sze[now]);
        }
        printf("%d\n", ans);
    }
}