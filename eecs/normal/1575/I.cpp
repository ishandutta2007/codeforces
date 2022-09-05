#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, q, a[maxn], tid[maxn];
int fa[maxn], son[maxn], sz[maxn], dep[maxn], top[maxn];
vector<int> G[maxn];

struct node { int l, r; ll sum; } L[maxn << 2], R[maxn << 2];
node operator + (node A, node B) {
    node C;
    C.l = A.l, C.r = B.r;
    C.sum = A.sum + B.sum + max(abs(A.r + B.l), abs(A.r - B.l));
    return C;
}

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void modify(int k, int l, int r, int p, int v) {
    if (l == r) { L[k] = R[k] = (node){v, v, 0}; return; }
    mid >= p ? modify(ls, l, mid, p, v) : modify(rs, mid + 1, r, p, v);
    L[k] = L[ls] + L[rs], R[k] = R[rs] + R[ls];
}

node queryl(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return L[k];
    if (mid >= qr) return queryl(ls, l, mid, ql, qr);
    if (mid < ql) return queryl(rs, mid + 1, r, ql, qr);
    return queryl(ls, l, mid, ql, qr) + queryl(rs, mid + 1, r, ql, qr);
}

node queryr(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return R[k];
    if (mid >= qr) return queryr(ls, l, mid, ql, qr);
    if (mid < ql) return queryr(rs, mid + 1, r, ql, qr);
    return queryr(rs, mid + 1, r, ql, qr) + queryr(ls, l, mid, ql, qr);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
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
        static int tim = 0;
        tid[v] = ++tim, top[v] = rt;
        if (son[v]) dfs2(son[v], rt);
        for (int u : G[v]) {
            if (u ^ fa[v] && u ^ son[v]) dfs2(u, u);
        }
    };
    dfs1(1), dfs2(1, 1);
    for (int i = 1; i <= n; i++) {
        modify(1, 1, n, tid[i], a[i]);
    }
    while (q--) {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        if (op == 1) {
            modify(1, 1, n, tid[x], y);
        } else {
            vector<node> vl, vr;
            while (top[x] ^ top[y]) {
                if (dep[top[x]] > dep[top[y]]) {
                    vl.push_back(queryr(1, 1, n, tid[top[x]], tid[x]));
                    x = fa[top[x]];
                } else {
                    vr.push_back(queryl(1, 1, n, tid[top[y]], tid[y]));
                    y = fa[top[y]];
                }
            }
            if (tid[x] <= tid[y]) {
                vl.push_back(queryl(1, 1, n, tid[x], tid[y]));
            } else {
                vr.push_back(queryr(1, 1, n, tid[y], tid[x]));
            }
            reverse(vr.begin(), vr.end());
            node ans;
            if (!vl.empty()) {
                ans = vl[0];
                for (int i = 1; i < vl.size(); i++) ans = ans + vl[i];
                for (auto &p : vr) ans = ans + p;
            } else {
                ans = vr[0];
                for (int i = 1; i < vr.size(); i++) ans = ans + vr[i];
            }
            printf("%lld\n", ans.sum);
        }
    }
    return 0;
}