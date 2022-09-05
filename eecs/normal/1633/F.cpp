#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, fa[maxn], sz[maxn], ew[maxn], cnt[maxn], lson[maxn];
int tim, son[maxn], top[maxn], tid[maxn], mp[maxn];
vector<int> ans;
vector<array<int, 2>> G[maxn];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
struct node { int tag, c0, c1; ll s0, s1; } t[maxn << 2];

void maintain(int k) {
    t[k].c0 = t[ls].c0 + t[rs].c0, t[k].c1 = t[ls].c1 + t[rs].c1;
    t[k].s0 = t[ls].s0 + t[rs].s0, t[k].s1 = t[ls].s1 + t[rs].s1;
}

void apply(int k) {
    t[k].tag ^= 1, swap(t[k].c0, t[k].c1), swap(t[k].s0, t[k].s1);
}

void pushdown(int k) {
    if (t[k].tag) apply(ls), apply(rs), t[k].tag = 0;
}

void build(int k, int l, int r) {
    if (l == r) { t[k].s0 = ew[mp[l]]; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    maintain(k);
}

void upd(int k, int l, int r, int p, int v) {
    if (l == r) { t[k].c0 = v + !t[k].tag > 1, t[k].c1 = v + t[k].tag > 1; return; }
    pushdown(k);
    mid >= p ? upd(ls, l, mid, p, v) : upd(rs, mid + 1, r, p, v);
    maintain(k);
}

int get(int k, int l, int r, int p) {
    if (l == r) return t[k].tag;
    pushdown(k);
    return mid >= p ? get(ls, l, mid, p) : get(rs, mid + 1, r, p);
}

void dfs(int k, int l, int r) {
    if (l == r) { if (t[k].tag) ans.push_back(t[k].s1); return; }
    pushdown(k);
    dfs(ls, l, mid), dfs(rs, mid + 1, r);
}

void flip(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return apply(k);
    pushdown(k);
    if (mid >= ql) flip(ls, l, mid, ql, qr);
    if (mid < qr) flip(rs, mid + 1, r, ql, qr);
    maintain(k);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        G[u].push_back({v, i}), G[v].push_back({u, i});
    }
    function<void(int)> dfs1 = [&](int u) {
        sz[u] = 1;
        for (auto &e : G[u]) if (e[0] ^ fa[u]) {
            fa[e[0]] = u, ew[e[0]] = e[1];
            dfs1(e[0]), sz[u] += sz[e[0]];
            if (sz[e[0]] > sz[son[u]]) son[u] = e[0];
        }
    };
    function<void(int, int)> dfs2 = [&](int u, int anc) {
        mp[tid[u] = ++tim] = u, top[u] = anc;
        if (son[u]) dfs2(son[u], anc);
        for (auto &e : G[u]) {
            if (e[0] ^ fa[u] && e[0] ^ son[u]) dfs2(e[0], e[0]);
        }
    };
    dfs1(1), dfs2(1, 1), build(1, 1, n);
    auto ins = [&](int u) {
        for (; u; u = fa[top[u]]) {
            int o = get(1, 1, n, tid[top[u]]), v = fa[top[u]];
            if (v) upd(1, 1, n, tid[v], lson[v] += o ? -1 : 1);
            flip(1, 1, n, tid[top[u]], tid[u]);
        }
    };
    ins(1);
    int op, s = 0;
    while (cin >> op && op <= 2) {
        if (op == 1) {
            int u;
            cin >> u;
            ins(u), s ^= 1;
            cout << (s && !t[1].c1 ? t[1].s1 : 0) << endl;
        } else {
            if (!s || t[1].c1) { cout << 0 << endl; continue; }
            ans.clear(), dfs(1, 1, n);
            sort(ans.begin(), ans.end());
            cout << ans.size();
            for (int x : ans) cout << " " << x;
            cout << endl;
        }
    }
    return 0;
}