#include <bits/stdc++.h>
using namespace std;
struct edge {
    int v, id, w, nxt;
} e[1000010];
int head[500010], tot;
inline void addedge(int u, int v, int w, int id) {
    e[++tot] = edge{v, id, w, head[u]};
    head[u] = tot;
}
int st[1000010][20], dfn[500010], dep[500010], dfn2[500010], dep2[500010];
int top[500010], id[500010], sze[500010];
int dfsnow1 = 0, dfsnow2 = 0;
void dfs(int u, int fa) {
    st[dfn[u] = ++dfsnow1][0] = dep[u] = dep[fa] + 1;
    sze[u] = 1;
    id[dfn2[u] = ++dfsnow2] = u;
    for (int i = head[u]; i; i = e[i].nxt) {
        if (e[i].v == fa) continue;
        top[e[i].id] = e[i].v;
        dep2[e[i].v] = dep2[u] ^ e[i].w;
        dfs(e[i].v, u);
        sze[u] += sze[e[i].v];
        st[++dfsnow1][0] = dep[u];
    }
}
int lg2[1000010];
inline void init() {
    lg2[0] = -1;
    for (int i = 1; i <= dfsnow1; i++) lg2[i] = lg2[i >> 1] + 1; 
    for (int i = dfsnow1; i > 0; i--) {
        for (int j = 1; i + (1 << j) - 1 <= dfsnow1; j++) st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
}
inline int dis(int u, int v) {
    int ans = dep[u] + dep[v];
    u = dfn[u], v = dfn[v];
    if (u > v) swap(u, v);
    int k = lg2[v - u + 1];
    return ans - 2 * min(st[u][k], st[v - (1 << k) + 1][k]);
}
struct node {
    int a, b, dis;
    node() {a = b = dis = 0;}
    node(int a, int b, int dis): a(a), b(b), dis(dis) {}
};
inline node operator + (const node &a, const node &b) {
    if (a.a == 0 || b.a == 0) return node(a.a + b.a, a.b + b.b, a.dis + b.dis);
    int dis00 = dis(a.a, b.a),
        dis01 = dis(a.a, b.b),
        dis10 = dis(a.b, b.a),
        dis11 = dis(a.b, b.b);
    int newdis = max(max(max(max(max(dis00, dis01), dis10), dis11), a.dis), b.dis);
    if (newdis == a.dis) return a;
    if (newdis == b.dis) return b;
    if (newdis == dis00) return node(a.a, b.a, newdis);
    if (newdis == dis01) return node(a.a, b.b, newdis);
    if (newdis == dis10) return node(a.b, b.a, newdis);
    if (newdis == dis11) return node(a.b, b.b, newdis);
}
node t1[2000010], t2[2000010];
int tag[2000010];
inline void down(int x) {
    if (tag[x]) {
        tag[x] = 0;
        swap(t1[x << 1], t2[x << 1]);
        swap(t1[x << 1 | 1], t2[x << 1 | 1]);
        tag[x << 1] ^= 1;
        tag[x << 1 | 1] ^= 1;
    }
}
inline void up(int x) {
    t1[x] = t1[x << 1] + t1[x << 1 | 1];
    t2[x] = t2[x << 1] + t2[x << 1 | 1];
}
void modify(int x, int l, int r, int L, int R) {
    if (l > R || L > r) return;
    if (L <= l && r <= R) {
        tag[x] ^= 1;
        swap(t1[x], t2[x]);
        return;
    }
    down(x);
    int mid = l + r >> 1;
    modify(x << 1, l, mid, L, R);
    modify(x << 1 | 1, mid + 1, r, L, R);
    up(x);
}
void build(int x, int l, int r) {
    if (l == r) {
        if (dep2[id[l]]) t1[x] = node(id[l], id[l], 0), t2[x] = node(0, 0, 0);
        else t2[x] = node(id[l], id[l], 0), t1[x] = node(0, 0, 0);
        return;
    }
    int mid = l + r >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    up(x);
}
int n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w, i);
        addedge(v, u, w, i);
    }
    dfs(1, 0);
    init();
    build(1, 1, n);
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        modify(1, 1, n, dfn2[top[x]], dfn2[top[x]] + sze[top[x]] - 1);
        printf("%d\n", max(t1[1].dis, t2[1].dis));
    }
}