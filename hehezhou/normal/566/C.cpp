#include <bits/stdc++.h>
using namespace std;
struct edge {
    int v, w, nxt;
} e[400010];
int w[200010];
int n;
int head[200010], tot;
inline void addedge(int u, int v, int w) {
    e[++tot] = edge{v, w, head[u]};
    head[u] = tot;
}
typedef double db;
db nowans;
inline db dfs(int now, int f, db nowdis) {
    db tmp = w[now] * sqrt(nowdis);
    nowans += nowdis * tmp;
    for(int i = head[now]; i; i = e[i].nxt) {
        if(e[i].v == f) continue;
        tmp += dfs(e[i].v, now, nowdis + e[i].w);
    }
    return tmp;
}
db ans = 1e20;
int p;
int tag[200010];
int sze[200010], rt, SIZE;
inline void getRoot(int now, int f) {
    sze[now] = 1;
    int flag = 1;
    for(int i = head[now]; i; i = e[i].nxt) {
        if(e[i].v == f || tag[e[i].v]) continue;
        getRoot(e[i].v, now);
        if(sze[e[i].v] * 2 > SIZE) flag = 0;
        sze[now] += sze[e[i].v];
    }
    if(flag && sze[now] * 2 >= SIZE) rt = now;
}
inline void solve(int now) {
    if(tag[now]) return;
    getRoot(now, 0);
    db _max = -1;
    int son = 0;
    nowans = 0;
    for(int i = head[now]; i; i = e[i].nxt) {
        db tmp = dfs(e[i].v, now, e[i].w);
        if(tmp > _max) _max = tmp, son = e[i].v;
    }
    SIZE = sze[son];
    if(ans > nowans) ans = nowans, p = now;
    tag[now] = 1;
    getRoot(son, now);
    solve(rt);
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", w + i);
    for(int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w);
        addedge(v, u, w);
    }
    SIZE = n;
    solve(1);
    printf("%d %.12lf\n", p, ans);
    return 0;
}