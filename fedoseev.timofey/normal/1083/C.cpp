#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-reorder-functions")
#pragma GCC optimize("profile-values")
#pragma GCC optimize("tracer")
#pragma GCC optimize("vpt")
#pragma GCC target("sse2")
#pragma GCC target("sse3")
#pragma GCC target("ssse3")
#pragma GCC target("sse4.1")
#pragma GCC target("sse4.2")
#pragma GCC target("avx")
#pragma GCC target("avx2")
#pragma GCC target("popcnt")
#pragma GCC target("abm")
#pragma GCC target("mmx")
#pragma GCC target("tune=native")


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 7;
const int K = 20;

int go[K][N];
int tin[N], tout[N];
vector <int> g[N];
int timer = 0;
int perm[N];
int where[N];

pair <int, int> t[4 * N];

int n;

void dfs(int u, int p = 0) {
    go[0][u] = p;
    tin[u] = timer++;
    for (int i = 1; i < K; ++i) {
        go[i][u] = go[i - 1][go[i - 1][u]];
    }
    for (auto v : g[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    tout[u] = timer++;
}

bool anc(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
    if (anc(a, b)) return a;
    if (anc(b, a)) return b;
    for (int k = K - 1; k >= 0; --k) {
        if (!anc(go[k][a], b)) {
            a = go[k][a];
        }
    }
    return go[0][a];
}

pair <int, int> null = {-1, -1};
pair <int, int> empt = {-2, -2};

int d;

bool on_path(int a, int b, int c) {
    return anc(d, c) && (anc(c, a) || anc(c, b));
}

bool check(int l, int r, const pair <int, int> &a, const pair <int, int> &b) {
    d = lca(l, r);
    return on_path(l, r, a.first) && on_path(l, r, a.second) && on_path(l, r, b.first) && on_path(l, r, b.second);
}

pair <int, int> merge(const pair <int, int> &a, const pair <int, int> &b) {
    if (a == null || b == null) return null;
    if (a == empt) return b;
    if (b == empt) return a;
    if (check(a.first, a.second, a, b)) return a;
    if (check(b.first, b.second, a, b)) return b;
    if (check(a.first, b.first, a, b)) return {a.first, b.first};
    if (check(a.second, b.second, a, b)) return {a.second, b.second};
    if (check(a.first, b.second, a, b)) return {a.first, b.second};
    if (check(a.second, b.first, a, b)) return {a.second, b.first};
    return null;
}

void build(int l, int r, int v) {
    if (l == r) {
        t[v] = {where[l], where[l]};
    }
    else {
        int m = (l + r) >> 1;
        build(l, m, 2 * v + 1);
        build(m + 1, r, 2 * v + 2);
        t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
    }
}

void modify(int ind, int l, int r, int v) {
    if (l == r) {
        t[v] = {where[ind], where[ind]};
    }
    else {
        int m = (l + r) >> 1;
        if (ind <= m) modify(ind, l, m, 2 * v + 1);
        else modify(ind, m + 1, r, 2 * v + 2);
        t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
    }
}

void update(int a, int b) {
    int pa = perm[a];
    int pb = perm[b];
    swap(where[perm[a]], where[perm[b]]);
    swap(perm[a], perm[b]);
    modify(pa, 0, n - 1, 0);
    modify(pb, 0, n - 1, 0);
}

int get(int v, int l, int r, pair <int, int> cur) {
    if (l == r) {
        return l;
    }
    int m = (l + r) >> 1;
    auto mem = merge(t[2 * v + 1], cur);
    if (mem.first != -1) return get(2 * v + 2, m + 1, r, mem);
    return get(2 * v + 1, l, m, cur);
}


int mex() {
    if (t[0].first != -1) return n;
    return get(0, 0, n - 1, {where[0], where[0]});
}

void init() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> perm[i];
        where[perm[i]] = i;
    }
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].push_back(i);
    }
    dfs(0);
    build(0, n - 1, 0);
}

void solve() {
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            update(a, b);
        }
        else {
            cout << mex() << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    init();
    solve();
}