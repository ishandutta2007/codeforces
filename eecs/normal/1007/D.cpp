#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, maxm = 5000000, maxk = 10010;
int n, m, tp, tim, cnt, tot, ecnt, dep[maxn], fa[maxn];
int son[maxn], sz[maxn], tid[maxn], top[maxn];
int a[maxk], b[maxk], c[maxk], d[maxk];
int st[maxm], dfn[maxm], low[maxm], bel[maxm], head[maxm];
vector<int> G[maxn], V[maxn << 2];
struct edge { int to, nxt; } e[maxm * 2];

void add(int u, int v) {
    e[++ecnt] = (edge){v, head[u]}, head[u] = ecnt;
    u ^= 1, v ^= 1;
    e[++ecnt] = (edge){u, head[v]}, head[v] = ecnt;
}

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void ins(int k, int l, int r, int ql, int qr, int id) {
    if (l >= ql && r <= qr) { V[k].push_back(id); return; }
    if (mid >= ql) ins(ls, l, mid, ql, qr, id);
    if (mid < qr) ins(rs, mid + 1, r, ql, qr, id);
}

void build(int k, int l, int r, int lst = 0) {
    if (lst) add(lst << 1, (tot + 1) << 1);
    int fir = ++tot; lst = (tot += V[k].size());
    for (int i = 0; i < V[k].size(); i++) {
        add(V[k][i], (fir + i + 1) << 1);
        add((fir + i) << 1, (fir + i + 1) << 1);
        add((fir + i) << 1, V[k][i] ^ 1);
    }
    if (l == r) return;
    build(ls, l, mid, lst), build(rs, mid + 1, r, lst);
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int)> dfs1 = [&](int v) {
        dep[v] = dep[fa[v]] + 1, sz[v] = 1;
        for (int u : G[v]) if (u ^ fa[v]) {
            fa[u] = v, dfs1(u), sz[v] += sz[u];
            if (sz[u] > sz[son[v]]) son[v] = u;
        }
    };
    function<void(int, int)> dfs2 = [&](int v, int rt) {
        tid[v] = ++tim, top[v] = rt;
        if (son[v]) dfs2(son[v], rt);
        for (int u : G[v]) if (u ^ fa[v] && u ^ son[v]) dfs2(u, u);
    };
    dfs1(1), dfs2(1, 1);
    scanf("%d", &m), tot = m;
    auto path = [&](int u, int v, int id) {
        while (top[u] ^ top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            ins(1, 2, n, tid[top[u]], tid[u], id), u = fa[top[u]];
        }
        if (tid[u] > tid[v]) swap(u, v);
        if (tid[u] < tid[v]) ins(1, 2, n, tid[u] + 1, tid[v], id);
    };
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        path(a[i], b[i], i << 1), path(c[i], d[i], i << 1 | 1);
    }
    build(1, 2, n);
    function<void(int)> tarjan = [&](int v) {
        dfn[v] = low[v] = ++tim, st[++tp] = v;
        for (int i = head[v]; i; i = e[i].nxt) {
            int u = e[i].to;
            if (!dfn[u]) tarjan(u), low[v] = min(low[v], low[u]);
            else if (!bel[u]) low[v] = min(low[v], dfn[u]);
        }
        if (dfn[v] == low[v]) {
            cnt++;
            while (1) {
                int u = st[tp--]; bel[u] = cnt;
                if (u == v) break;
            }
        }
    };
    for (int i = 2; i <= (tot << 1 | 1); i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= m; i++) {
        if (bel[i << 1] == bel[i << 1 | 1]) puts("NO"), exit(0);
    }
    puts("YES");
    for (int i = 1; i <= m; i++) {
        puts(bel[i << 1] < bel[i << 1 | 1] ? "1" : "2");
    }
    return 0;
}