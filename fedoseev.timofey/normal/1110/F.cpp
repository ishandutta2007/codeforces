#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Inf = 2e18;
const int N = 5e5 + 7;

ll t[4 * N];
ll mod[4 * N];

void update(int u, ll x) {
    t[u] += x;
    mod[u] += x;
}

void push(int u) {
    if (mod[u]) {
        update(2 * u + 1, mod[u]);
        update(2 * u + 2, mod[u]);
        mod[u] = 0;
    }
}

void build(int l, int r, int v, vector <ll> &a) {
    if (l == r) t[v] = a[l];
    else {
        int m = (l + r) >> 1;
        build(l, m, 2 * v + 1, a);
        build(m + 1, r, 2 * v + 2, a);
        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }
}

void modify(int ql, int qr, int x, int l, int r, int v) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        update(v, x);
    }
    else {
        push(v);
        int m = (l + r) >> 1;
        modify(ql, qr, x, l, m, 2 * v + 1);
        modify(ql, qr, x, m + 1, r, 2 * v + 2);
        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }
}

ll get(int ql, int qr, int l, int r, int v) {
    if (qr < l || r < ql) return Inf;
    if (ql <= l && r <= qr) {
        return t[v];
    }
    push(v);
    int m = (l + r) >> 1;
    return min(get(ql, qr, l, m, 2 * v + 1), get(ql, qr, m + 1, r, 2 * v + 2));
}

vector <pair <int, int>> g[N];

ll h[N];
int par[N];
ll wg[N];
vector <int> qrs[N];
int ql[N], qr[N];
int l[N], r[N];

vector <int> e;

void dfs(int u) {
    e.push_back(u);
    l[u] = e.size() - 1;
    for (auto &[v, w] : g[u]) {
        dfs(v);
    }
    r[u] = e.size() - 1;
}

ll ans[N];

int n;

void jhfs(int u) {
    for (auto i : qrs[u]) {
        ans[i] = get(ql[i], qr[i], 0, n - 1, 0);
    }
    for (auto &[v, w] : g[u]) {
        modify(l[v], r[v], -w, 0, n - 1, 0);
        if (l[v] != 0) modify(0, l[v] - 1, w, 0, n - 1, 0);
        if (r[v] != n - 1) modify(r[v] + 1, n - 1, w, 0, n - 1, 0);
        jhfs(v);
        modify(l[v], r[v], w, 0, n - 1, 0);
        if (l[v] != 0) modify(0, l[v] - 1, -w, 0, n - 1, 0);
        if (r[v] != n - 1) modify(r[v] + 1, n - 1, -w, 0, n - 1, 0);

    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int p, w;
        cin >> p >> w;
        --p;
        par[i] = p;
        wg[i] = w;
        g[p].push_back({i, w});
    }
    for (int i = 1; i < n; ++i) {
        h[i] = h[par[i]] + wg[i];
    }
    vector <ll> a(n);
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 0) {
            a[i] = h[i];
        }
        else {
            a[i] = Inf;
        }
    }
    build(0, n - 1, 0, a);
    for (int i = 0; i < q; ++i) {
        int v, l, r;
        cin >> v >> l >> r;
        --v, --l, --r;
        ql[i] = l;
        qr[i] = r;
        qrs[v].emplace_back(i);
    }
    dfs(0);
    jhfs(0);
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
}