#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 5e5 + 7;

int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}

struct Edge {
    int u, v, c;
    Edge(int u_, int v_, int c_) {
        u = u_; v = v_; c = c_;
    }
    Edge(){}
};

int pw[MAXN];
void precalc() {
    pw[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        pw[i] = mod(pw[i - 1] << 1);
    }
}

int n, m, k;
int a[MAXN];
vector <Edge> g[MAXN];
Edge ed[MAXN];

void read() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(Edge(u, v, a[u] ^ a[v]));
        g[v].push_back(Edge(v, u, a[u] ^ a[v]));
        ed[i] = Edge(u, v, a[u] ^ a[v]);
    }
}

int ans = 0;

bool used[MAXN];
int par[MAXN];
int comp = 0;
int cnt = 0;

int root(int u) {
    if (u == par[u]) return u;
    else return par[u] = root(par[u]);
}

void merge(int u, int v) {
    cnt += !used[u] + !used[v];
    comp += !used[u] + !used[v];
    used[u] = used[v] = 1;
    u = root(u);
    v = root(v);
    if (u == v) return;
    --comp;
    par[v] = u;
}

int get(vector <int> v) {
    comp = cnt = 0;
    for (int e : v) {
        merge(ed[e].u, ed[e].v);
    }
    for (int e : v) {
        used[ed[e].u] = used[ed[e].v] = 0;
        par[ed[e].u] = ed[e].u;
        par[ed[e].v] = ed[e].v;
    }
    return pw[n - cnt + comp];
}

void solve() {  
    map <int, vector <int> > ms;
    for (int i = 0; i < m; ++i) {
        ms[ed[i].c].push_back(i);
    }
    for (int i = 0; i < n; ++i) par[i] = i;
    for (auto e : ms) {
        int add = mod(pw[n] - get(e.second));
        ans = mod(ans + add);
    }
}

void print() {
    int all = mod(pw[n] * mod(1ll << k));
    cout << mod(all - ans) << '\n';
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precalc();
    read();
    solve();
    print();

    return 0;
}