#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const ll Inf = 1e18;
 
struct SegmentTree {
    vector <ll> t, mod;
    int n;
    void build(int l, int r, int v, const vector <ll> &a) {
        if (l + 1 == r) {
            t[v] = a[l];
        } else {
            int m = (l + r) >> 1;
            build(l, m, 2 * v + 1, a);
            build(m, r, 2 * v + 2, a);
            t[v] = max(t[2 * v + 1], t[2 * v + 2]);
        }
    }
    SegmentTree() {}
    void init(const vector <ll> &a) {
        n = a.size();
        int x = 31 - __builtin_clz(n);
        int rofl = 1 << x;
        t.resize(2 * rofl);
        mod.resize(2 * rofl);
        build(0, n, 0, a);
    }
    void init(int sz) {
        n = sz;
        t.resize(4 * n);
        mod.resize(4 * n);
    }
    void update(int v, ll val) {
        t[v] += val;
        mod[v] += val;
    }
    void push(int v) {
        if (mod[v]) {
            update(2 * v + 1, mod[v]);
            update(2 * v + 2, mod[v]);
            mod[v] = 0;
        }
    }
    void modify(int ql, int qr, ll val, int l, int r, int v) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            update(v, val);
        } else {
            push(v);
            int m = (l + r) >> 1;
            modify(ql, qr, val, l, m, 2 * v + 1);
            modify(ql, qr, val, m, r, 2 * v + 2);
            t[v] = max(t[2 * v + 1], t[2 * v + 2]);
        }
    }
    void modify(int ql, int qr, ll val) {
        modify(ql, qr, val, 0, n, 0);
    }
    ll get(int ql, int qr, int l, int r, int v) {
        if (qr <= l || r <= ql) return -Inf;
        if (ql <= l && r <= qr) return t[v];
        else {
            push(v);
            int m = (l + r) >> 1;
            return max(get(ql, qr, l, m, 2 * v + 1), get(ql, qr, m, r, 2 * v + 2));
        }
    }
    ll get(int ql, int qr) {
        return get(ql, qr, 0, n, 0);
    }
};
 
const int N = 1e5 + 7;
const int K = 18;
 
vector <pair <int, ll>> g[N];
multiset <ll> cAns;
 
multiset <ll> fromC[N];
SegmentTree tr[N];
 
int par[N], d[N], l[K][N], r[K][N], cmp[K][N], parC[K][N];
 
ll ans[K][N];
bool used[N];
 
ll getSum(const multiset <ll> &a) {
    ll res = 0;
    if ((int)a.size() >= 1) res += *prev(a.end());
    if ((int)a.size() >= 2) res += *prev(prev(a.end()));
    return res;
}
 
void updateCentroid(int c, int v, ll val) {
    int cd = d[c];
    int who = cmp[cd][v];
    cAns.erase(cAns.find(getSum(fromC[c])));
    fromC[c].erase(fromC[c].find(ans[cd][who]));
    tr[c].modify(l[cd][v], r[cd][v], val);
    ll cVal = tr[c].get(l[cd][who], r[cd][who]);
    fromC[c].insert(cVal);
    ans[cd][who] = cVal;
    cAns.insert(getSum(fromC[c]));
}
 
int dfs(int u, int sz, int &c, int p) {
    int sum = 1;
    for (auto &[v, w] : g[u]) {
        if (!used[v] && v != p) {
            sum += dfs(v, sz, c, u);
        }
    }
    if (c == -1 && (p == -1 || 2 * sum >= sz)) {
        c = u;
    }
    return sum;
}
 
int t = 0;
 
void jhfs(int u, int cd, int st, int c, ll wg, int p) {
    parC[cd][u] = p;
    cmp[cd][u] = st;
    l[cd][u] = t++;
    cmp[cd][u] = st;
    for (auto &[v, w] : g[u]) {
        if (!used[v] && v != p) jhfs(v, cd, st, c, w, u);
    }
    r[cd][u] = t;
    tr[c].modify(l[cd][u], r[cd][u], wg);
    if (u == st) {
        ll cVal = tr[c].get(l[cd][u], r[cd][u]);
        fromC[c].insert(cVal);
        ans[cd][u] = cVal;
    }
}   

int cmpSize = 0;

void memfs(int u, int p) {
    ++cmpSize;
    for (auto &[v, w] : g[u]) {
        if (!used[v] && v != p) {
            memfs(v, u);
        }
    }
}
 
void buildCentroid(int u, int sz, int p) {
    int c = -1;
    dfs(u, sz, c, -1);
    used[c] = 1;
    par[c] = p;
    d[c] = (p == -1 ? 0 : d[p] + 1);
    t = 0;
    cmpSize = 1;
    for (auto &[v, w] : g[c]) {
        if (!used[v]) {
            memfs(v, c);
        }
    }
    tr[c].init(cmpSize);
    for (auto &[v, w] : g[c]) {
        if (!used[v]) {
            jhfs(v, d[c], v, c, w, c);
        }
    }
 
    cAns.insert(getSum(fromC[c]));
 
    for (auto &[v, w] : g[c]) {
        if (!used[v]) {
            buildCentroid(v, (sz + 1) / 2, c);
        }
    }
}
 
void update(int u, int v, ll w) {
    vector <int> crd;
    int cur = u;
    while (cur != -1) {
        crd.push_back(cur);
        cur = par[cur];
    }
    reverse(crd.begin(), crd.end());
    for (int i = 0; i < K; ++i) {
        if (parC[i][u] != v && parC[i][v] != u) break;
        if (parC[i][u] == v) swap(u, v);
        assert(parC[i][v] == u);
        updateCentroid(crd[i], v, w);
    }
}
 
ll getDiam() {
    return *prev(cAns.end());
}
 
struct Edge {
    int u, v; ll w;
};
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < N; ++j) {
            parC[i][j] = -1;
        }
    }
    vector <Edge> E;
    int n, q; ll w;
    cin >> n >> q >> w;
    for (int i = 0; i + 1 < n; ++i) {
        int a, b; ll c;
        cin >> a >> b >> c;
        --a, --b;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
        E.push_back({a, b, c});
    }
    buildCentroid(0, n, -1);
    ll last = 0;
    for (int i = 0; i < q; ++i) {
        ll d, e;
        cin >> d >> e;
        d += last, e += last;
        d %= (n - 1);
        e %= w;
        update(E[d].u, E[d].v, e - E[d].w);
        E[d].w = e;
        last = getDiam();
        cout << last << '\n';
    }
}