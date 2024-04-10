#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, m, q, tim, c[maxn];
int tid[maxn], fa[maxn], sz[maxn], son[maxn], top[maxn], dep[maxn];
vector<int> G[maxn], V, ans;
struct node {
    int cur; ll sum, tag;
    vector<pair<int, int>> V;
    tuple<ll, int, int> mn;
} t[maxn << 2];

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
inline void maintain(int k) {
    t[k].mn = min(t[ls].mn, t[rs].mn);
}

void pushdown(int k) {
    t[ls].sum += t[k].tag, t[ls].tag += t[k].tag;
    get<0>(t[ls].mn) += t[k].tag;
    t[rs].sum += t[k].tag, t[rs].tag += t[k].tag;
    get<0>(t[rs].mn) += t[k].tag, t[k].tag = 0;
}

void ins(int k, int l, int r, int p, int v, int id) {
    if (l == r) {
        t[k].V.emplace_back(v, id);
        t[k].mn = make_tuple(t[k].V[0].first, t[k].V[0].second, t[k].V[0].first);
        return;
    }
    if (mid >= p) ins(ls, l, mid, p, v, id);
    else ins(rs, mid + 1, r, p, v, id);
    maintain(k);
}

void add(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) {
        t[k].sum += v, t[k].tag += v;
        get<0>(t[k].mn) += v; return;
    }
    if (t[k].tag) pushdown(k);
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
    maintain(k);
}

void del(int k, int l, int r, int p) {
    if (l == r) {
        if (++t[k].cur == t[k].V.size()) {
            t[k].mn = make_tuple(1e18, 0, 0);
        } else {
            auto &p = t[k].V[t[k].cur];
            t[k].mn = make_tuple(p.first + t[k].sum, p.second, p.first);
        }
        return;
    }
    if (t[k].tag) pushdown(k);
    if (mid >= p) del(ls, l, mid, p);
    else del(rs, mid + 1, r, p);
    maintain(k);
}

void query(int k, int l, int r, int ql, int qr, vector<int> &V) {
    if (l >= ql && r <= qr) { V.push_back(k); return; }
    if (t[k].tag) pushdown(k);
    if (mid >= ql) query(ls, l, mid, ql, qr, V);
    if (mid < qr) query(rs, mid + 1, r, ql, qr, V);
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
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
        top[v] = rt, tid[v] = ++tim;
        if (son[v]) dfs2(son[v], rt);
        for (int u : G[v]) {
            if (u ^ fa[v] && u ^ son[v]) dfs2(u, u);
        }
    };
    dfs1(1), dfs2(1, 1);
    for (int i = 1; i <= n << 2; i++) {
        t[i].mn = make_tuple(1e18, 0, 0);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &c[i]);
        ins(1, 1, n, tid[c[i]], i, c[i]);
    }
    while (q--) {
        int op, x, y, k;
        scanf("%d %d %d", &op, &x, &y);
        if (op == 1) {
            scanf("%d", &k);
            V.clear(), ans.clear();
            while (top[x] ^ top[y]) {
                if (dep[top[x]] < dep[top[y]]) swap(x, y);
                query(1, 1, n, tid[top[x]], tid[x], V), x = fa[top[x]];
            }
            query(1, 1, n, min(tid[x], tid[y]), max(tid[x], tid[y]), V);
            while (k--) {
                tuple<ll, int, int> mn(1e18, 0, 0);
                for (int k : V) mn = min(mn, t[k].mn);
                if (get<0>(mn) == 1e18) break;
                ans.push_back(get<2>(mn));
                del(1, 1, n, tid[c[get<2>(mn)]]);
            }
            printf("%d", ans.size());
            for (int x : ans) printf(" %d", x);
            putchar('\n');
        } else {
            add(1, 1, n, tid[x], tid[x] + sz[x] - 1, y);
        }
    }
    return 0;
}