#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 300010;
int n, m, tot, dep[maxn], rt[maxn];
vector<int> G[maxn];
vector<pair<int, int>> H[maxn];
struct node {
    int l, r; ll tag, mn;
    node() { tag = 0, mn = 1e18; }
} t[maxn * 30];

#define mid (l + r >> 1)
void maintain(int &k) {
    t[k].mn = min(t[t[k].l].mn, t[t[k].r].mn);
    if (t[k].mn >= (ll)1e17) k = 0;
}

void pushdown(int k) {
    if (!t[k].tag) return;
    int ls = t[k].l, rs = t[k].r;
    if (ls) {
        t[ls].tag += t[k].tag, t[ls].mn += t[k].tag;
    }
    if (rs) {
        t[rs].tag += t[k].tag, t[rs].mn += t[k].tag;
    }
    t[k].tag = 0;
}

void modify(int &k, int l, int r, int p, ll v) {
    if (!k) k = ++tot;
    if (l == r) { t[k].mn = min(t[k].mn, v); return; }
    pushdown(k);
    if (mid >= p) modify(t[k].l, l, mid, p, v);
    else modify(t[k].r, mid + 1, r, p, v);
    maintain(k);
}

void add(int &k, int l, int r, int ql, int qr) {
    if (!k) return;
    if (l >= ql && r <= qr) { k = 0; return; }
    pushdown(k);
    if (mid >= ql) add(t[k].l, l, mid, ql, qr);
    if (mid < qr) add(t[k].r, mid + 1, r, ql, qr);
    maintain(k);
}

int merge(int k1, int k2, int l, int r, ll mn1, ll mn2) {
    if (!k1 && !k2) return 0;
    if (!k2) {
        if (mn2 >= (ll)1e17) return 0;
        t[k1].tag += mn2, t[k1].mn += mn2; return k1;
    }
    if (!k1) {
        if (mn1 >= (ll)1e17) return 0;
        t[k2].tag += mn1, t[k2].mn += mn1; return k2;
    }
    if (l == r) {
        t[k1].mn = min({t[k1].mn + mn2, t[k2].mn + mn1, t[k1].mn + t[k2].mn}); return k1;
    }
    pushdown(k1), pushdown(k2);
    t[k1].l = merge(t[k1].l, t[k2].l, l, mid, min(mn1, t[t[k1].r].mn), min(mn2,
        t[t[k2].r].mn));
    t[k1].r = merge(t[k1].r, t[k2].r, mid + 1, r, mn1, mn2);
    maintain(k1); return k1;
}

int main() {
    scanf("%d %d", &n, &m);
    if (n == 1) puts("0"), exit(0);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int, int)> dfs1 = [&](int v, int fa) {
        dep[v] = dep[fa] + 1;
        for (int u : G[v]) if (u ^ fa) dfs1(u, v);
    };
    dfs1(1, 0);
    while (m--) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        H[u].emplace_back(dep[v], c);
    }
    function<void(int, int)> dfs2 = [&](int v, int fa) {
        bool fir = 0;
        for (int u : G[v]) if (u ^ fa) {
            dfs2(u, v);
            if (!fir) rt[v] = rt[u], fir = 1;
            else rt[v] = ::merge(rt[v], rt[u], 1, n, 1e18, 1e18);
        }
        for (auto p : H[v]) {
            modify(rt[v], 1, n, p.first, p.second + (!fir ? 0 : t[rt[v]].mn));
        }
        add(rt[v], 1, n, dep[v] + (v == 1), n); 
        if (t[rt[v]].mn > (ll)1e17) puts("-1"), exit(0);
    };
    dfs2(1, 0);
    printf("%lld\n", t[rt[1]].mn);
    return 0;
}