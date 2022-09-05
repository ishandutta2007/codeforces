#include <bits/stdc++.h>
using namespace std;

const int maxn = 250010;
int n, fa[maxn], sz[maxn], dep[maxn];
int tim, son[maxn], top[maxn], tid[maxn], mp[maxn];
bool tr[maxn << 2];
vector<int> G[maxn], H[maxn];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void upd(int k, int l, int r, int p) {
    if (l == r) { tr[k] = 0; return; }
    mid >= p ? upd(ls, l, mid, p) : upd(rs, mid + 1, r, p);
    tr[k] = tr[ls] | tr[rs];
}

int find_l(int k, int l, int r, int ql, int qr) {
    if (!tr[k]) return 0;
    if (l == r) return l;
    int t = 0;
    if (mid >= ql) t = find_l(ls, l, mid, ql, qr);
    if (mid < qr && !t) t = find_l(rs, mid + 1, r, ql, qr);
    return t;
}

int find_r(int k, int l, int r, int ql, int qr) {
    if (!tr[k]) return 0;
    if (l == r) return l;
    int t = 0;
    if (mid < qr) t = find_r(rs, mid + 1, r, ql, qr);
    if (mid >= ql && !t) t = find_r(ls, l, mid, ql, qr);
    return t;
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        H[u].push_back(v), H[v].push_back(u);
    }
    function<void(int)> dfs1 = [&](int u) {
        dep[u] = dep[fa[u]] + 1, sz[u] = 1;
        for (int v : G[u]) if (v ^ fa[u]) {
            fa[v] = u, dfs1(v), sz[u] += sz[v];
            if (sz[v] > sz[son[u]]) son[u] = v;
        }
    };
    function<void(int, int)> dfs2 = [&](int u, int anc) {
        mp[tid[u] = ++tim] = u, top[u] = anc;
        if (son[u]) dfs2(son[u], anc);
        for (int v : G[u]) {
            if (v ^ fa[u] && v ^ son[u]) dfs2(v, v);
        }
    };
    dfs1(1), dfs2(1, 1);
    fill(tr, tr + (n << 2), 1);
    printf("%d\n", n - 1);
    auto cov = [&](int u, int v) {
        int x = u, y = v;
        auto chk = [&](int l, int r, int op = 1) {
            int t = (op == 1 ? find_r : find_l)(1, 1, n, l, r);
            if (!t) return 0;
            printf("%d %d %d %d\n", mp[t], fa[mp[t]], x, y);
            return upd(1, 1, n, t), 1;
        };
        vector<array<int, 2>> V;
        while (top[u] ^ top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                if (chk(tid[top[u]], tid[u])) return;
                u = fa[top[u]];
            } else {
                V.push_back({tid[top[v]], tid[v]}), v = fa[top[v]];
            }
        }
        if (tid[u] < tid[v]) V.push_back({tid[u] + 1, tid[v]});
        else if (tid[u] > tid[v] && chk(tid[v] + 1, tid[u])) return;
        reverse(V.begin(), V.end());
        for (auto &p : V) {
            if (chk(p[0], p[1], 2)) return;
        }
    };
    function<void(int, int)> solve = [&](int u, int fa) {
        for (int v : H[u]) if (v ^ fa) solve(v, u);
        if (fa) cov(u, fa);
    };
    solve(1, 0);
    return 0;
}