#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010, INF = 1e6;
int n, m, u[maxn], v[maxn], dep[maxn], dist[maxn], mx[maxn << 3], mn[maxn << 3];
int tim, from[maxn], to[maxn], tag[maxn << 3], w[maxn << 1], type[maxn << 1];
vector<pair<int, int>> G[maxn];

void chk(int &x, int y) {
    if (x < y) x = y;
}

// dep_a + dep_c - 2 dep_b (a <= b <= c, type_a = type_c)
struct node { int mx, mn, ab, bc, abc; } t[maxn << 3][2];

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
node merge(int k, node A, node B) {
    node C;
    C.mx = max(A.mx, B.mx), C.mn = min(A.mn, B.mn);
    C.ab = max({A.ab, B.ab, A.mx - 2 * mn[rs]});
    C.bc = max({A.bc, B.bc, B.mx - 2 * mn[ls]});
    C.abc = max({A.abc, B.abc, A.ab + B.mx, A.mx + B.bc});
    return C;
}

void build(int k, int l, int r) {
    if (l == r) {
        mn[k] = mx[k] = w[l];
        t[k][type[l]] = (node){w[l], w[l], -w[l], -w[l], 0};
        t[k][!type[l]] = (node){-INF, INF, -INF, -INF, -INF}; return;
    }
    build(ls, l, mid), build(rs, mid + 1, r);
    mx[k] = max(mx[ls], mx[rs]), mn[k] = min(mn[ls], mn[rs]);
    for (int a : {0, 1}) t[k][a] = merge(k, t[ls][a], t[rs][a]);
}

void flip(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) { swap(t[k][0], t[k][1]), tag[k] ^= 1; return; }
    if (tag[k]) {
        swap(t[ls][0], t[ls][1]), swap(t[rs][0], t[rs][1]);
        tag[ls] ^= 1, tag[rs] ^= 1, tag[k] = 0;
    }
    if (mid >= ql) flip(ls, l, mid, ql, qr);
    if (mid < qr) flip(rs, mid + 1, r, ql, qr);
    for (int a : {0, 1}) t[k][a] = merge(k, t[ls][a], t[rs][a]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1, w; i < n; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w);
        G[u[i]].emplace_back(v[i], w), G[v[i]].emplace_back(u[i], w);
    }
    function<void(int, int)> dfs = [&](int v, int fa) {
        dep[v] = w[++tim] = dep[fa] + 1;
        type[tim] = dist[v], from[v] = tim;
        for (auto e : G[v]) if (e.first ^ fa) {
            dist[e.first] = dist[v] ^ e.second, dfs(e.first, v);
            w[++tim] = dep[v], type[tim] = dist[v];
        }
        to[v] = tim;
    };
    dfs(1, 0), build(1, 1, tim);
    scanf("%d", &m);
    while (m--) {
        int id; scanf("%d", &id);
        if (dep[u[id]] < dep[v[id]]) swap(u[id], v[id]);
        flip(1, 1, tim, from[u[id]], to[u[id]]);
        printf("%d\n", max(t[1][0].abc, t[1][1].abc));
    }
    return 0;
}