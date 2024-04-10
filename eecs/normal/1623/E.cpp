#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, K, ls[maxn], rs[maxn], fa[maxn], top[maxn], son[maxn];
int tim, cur, tid[maxn], sz[maxn], dep[maxn];
char s[maxn];

struct BIT {
    int c[maxn];

    void add(int p, int v) {
        for (; p <= n; p += p & -p) c[p] += v;
    }
    int sum(int p) {
        int s = 0;
        for (; p; p -= p & -p) s += c[p];
        return s;
    }
} ban;

namespace SEG {
#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
int cov[maxn << 2], sum[maxn << 2];
void init() { memset(cov, -1, sizeof(cov)), memset(sum, 0, sizeof(sum)); }

void apply(int k, int l, int r, int v) {
    sum[k] = (r - l + 1) * v, cov[k] = v;
}
void pushdown(int k, int l, int r) {
    if (~cov[k]) apply(ls, l, mid, cov[k]), apply(rs, mid + 1, r, cov[k]), cov[k] = -1;
}

void cover(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) { apply(k, l, r, v); return; }
    pushdown(k, l, r);
    if (mid >= ql) cover(ls, l, mid, ql, qr, v);
    if (mid < qr) cover(rs, mid + 1, r, ql, qr, v);
    sum[k] = sum[ls] + sum[rs];
}

int query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return sum[k];
    pushdown(k, l, r);
    int s = 0;
    if (mid >= ql) s = query(ls, l, mid, ql, qr);
    if (mid < qr) s += query(rs, mid + 1, r, ql, qr);
    return s;
}
#undef ls
#undef rs
}  // namespace SEG

int main() {
    scanf("%d %d %s", &n, &K, s + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &ls[i], &rs[i]);
        if (ls[i]) fa[ls[i]] = i;
        if (rs[i]) fa[rs[i]] = i;
    }
    vector<int> V;
    function<void(int)> dfs = [&](int u) {
        dep[u] = dep[fa[u]] + 1, sz[u] = 1;
        if (ls[u]) dfs(ls[u]), sz[u] += sz[ls[u]];
        V.push_back(u);
        if (rs[u]) dfs(rs[u]), sz[u] += sz[rs[u]];
        son[u] = sz[ls[u]] > sz[rs[u]] ? ls[u] : rs[u];
    };
    dfs(1);
    function<void(int, int)> dfs2 = [&](int u, int rt) {
        tid[u] = ++tim, top[u] = rt;
        if (son[u]) dfs2(son[u], rt);
        if (ls[u] && ls[u] ^ son[u]) dfs2(ls[u], ls[u]);
        if (rs[u] && rs[u] ^ son[u]) dfs2(rs[u], rs[u]);
    };
    dfs2(1, 1);
    SEG::init();
    auto calc = [&](int x) {
        int s = 0;
        for (; x; x = fa[top[x]]) {
            s += SEG::query(1, 1, n, tid[top[x]], tid[x]);
        }
        return s;
    };
    auto upd = [&](int x) {
        for (; x; x = fa[top[x]]) {
            SEG::cover(1, 1, n, tid[top[x]], tid[x], 1);
        }
    };
    for (int i = 0, j; i < V.size(); i = j) {
        for (j = i; j < V.size() && s[V[i]] == s[V[j]]; j++);
        if (j == V.size() || s[V[i]] > s[V[j]]) {
            for (int k = i; k < j; k++) {
                if (!SEG::query(1, 1, n, tid[V[k]], tid[V[k]])) {
                    ban.add(tid[V[k]], 1), ban.add(tid[V[k]] + sz[V[k]], -1);
                }
            }
            continue;
        }
        for (int k = i; k < j; k++) {
            if (SEG::query(1, 1, n, tid[V[k]], tid[V[k]])) {
                continue;
            } else if (!ban.sum(tid[V[k]]) && cur + dep[V[k]] - calc(V[k]) <= K) {
                cur += dep[V[k]] - calc(V[k]), upd(V[k]);
            } else {
                ban.add(tid[V[k]], 1), ban.add(tid[V[k]] + sz[V[k]], -1);
            }
        }
    }
    for (int x : V) {
        putchar(s[x]);
        if (SEG::query(1, 1, n, tid[x], tid[x])) putchar(s[x]);
    }
    return 0;
}