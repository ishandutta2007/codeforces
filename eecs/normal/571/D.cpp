#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, m, id[maxn], val[maxn];
long long ans[maxn];
char op[maxn];
vector<array<int, 3>> Q[maxn];

struct Graph {
    int tot, tim, bel[maxn], dfn[maxn], sz[maxn];
    vector<int> G[maxn];

    void init() {
        tot = n, iota(bel + 1, bel + maxn, 1);
        fill(sz + 1, sz + n + 1, 1);
    }
    int find(int x) {
        return x == bel[x] ? x : bel[x] = find(bel[x]);
    }
    int add_edge(int u, int v) {
        u = find(u), v = find(v);
        G[++tot].push_back(u), G[tot].push_back(v);
        sz[tot] = sz[u] + sz[v];
        return bel[u] = bel[v] = tot;
    }

    void dfs(int u) {
        dfn[u] = ++tim, sz[u] = 1;
        for (int v : G[u]) dfs(v), sz[u] += sz[v];
    }
    void build() {
        for (int i = 1; i <= tot; i++) {
            if (i == find(i)) dfs(i);
        }
    }
} G1, G2;

namespace BIT {
long long c[maxn];

void add(int p, int v) {
    for (; p <= G1.tot; p += p & -p) c[p] += v;
}

long long sum(int p) {
    long long s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}
} // namespace BIT

namespace SEG {
#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
int tag[maxn << 2];
void init() { memset(tag, -1, sizeof(tag)); }

void cov(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) { tag[k] = v; return; }
    if (~tag[k]) tag[ls] = tag[rs] = tag[k], tag[k] = -1;
    if (mid >= ql) cov(ls, l, mid, ql, qr, v);
    if (mid < qr) cov(rs, mid + 1, r, ql, qr, v);
}

int query(int k, int l, int r, int p) {
    if (l == r) return tag[k];
    if (~tag[k]) tag[ls] = tag[rs] = tag[k], tag[k] = -1;
    return mid >= p ? query(ls, l, mid, p) : query(rs, mid + 1, r, p);
}
} // namespace SEG

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    G1.init(), G2.init();
    for (int i = 1, x, y; i <= m; i++) {
        cin >> op[i];
        if (op[i] == 'U' || op[i] == 'M') {
            cin >> x >> y;
            id[i] = (op[i] == 'U' ? G1 : G2).add_edge(x, y);
        } else {
            cin >> id[i];
            if (op[i] == 'A') id[i] = G1.find(id[i]), val[i] = G1.sz[id[i]];
            if (op[i] == 'Z') id[i] = G2.find(id[i]);
        }
    }
    G1.build(), G2.build();
    for (int i = 1; i <= m; i++) {
        if (op[i] == 'Z') {
            SEG::cov(1, 1, G2.tot, G2.dfn[id[i]], G2.dfn[id[i]] + G2.sz[id[i]] - 1, i);
        } else if (op[i] == 'Q') {
            Q[i].push_back({id[i], 1, i});
            int t = SEG::query(1, 1, G2.tot, G2.dfn[id[i]]);
            if (~t) Q[t].push_back({id[i], -1, i});
        }
    }
    for (int i = 1; i <= m; i++) {
        if (op[i] == 'A') {
            BIT::add(G1.dfn[id[i]], val[i]);
            BIT::add(G1.dfn[id[i]] + G1.sz[id[i]], -val[i]);
        }
        for (auto &p : Q[i]) {
            ans[p[2]] += p[1] * BIT::sum(G1.dfn[p[0]]);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (op[i] == 'Q') cout << ans[i] << '\n';
    }
    return 0;
}