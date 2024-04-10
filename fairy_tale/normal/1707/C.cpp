#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t << 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#define endl '\n'
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> PL;

const int maxn = 2e5 + 5;
const int mod = 998244353;

int p[maxn];
int ff(int x) {
    if (p[x] != x) p[x] = ff(p[x]);
    return p[x];
}

bool merge(int u, int v) {
    u = ff(u);
    v = ff(v);
    if (u != v) p[u] = v;
    return (u != v);
}

vector<int> g[maxn];
int d[maxn], st[maxn][18];
int mask[maxn], val[maxn];

void dfs(int u, int fa) {
    for(auto v:g[u]) {
        if(v == fa) continue;
        d[v] = d[u] + 1;
        st[v][0] = u;
        for(int i = 1;i < 18; i++) st[v][i] = st[st[v][i - 1]][i - 1];
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if(d[u] > d[v]) swap(u, v);
    int x = d[v] - d[u];
    for(int i = 0; i < 18; i++) {
        if((x >> i) & 1) v = st[v][i];
    }
    if(u != v) {
        for(int i = 17; i >= 0; i--) {
            if(st[u][i] != st[v][i]) {
                u = st[u][i];
                v = st[v][i];
            }
        }
        u = st[u][0];
    }
    return u;
}

int query(int u, int v) { // get the son of u
    int x = d[v] - d[u] - 1;
    for(int i = 0; i < 18; i++) {
        if((x >> i) & 1) v = st[v][i];
    }
    return v;
}

void dfs2(int u, int fa, int x) {
    x += mask[u];
    val[u] = (x == 0);

    for(auto v:g[u]) {
        if(v == fa) continue;
        dfs2(v, u, x);
    }
}

void solve()
{
    int n, m, u, v, k, cnt = 0;
    vector<P> f;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        if (!merge(u, v)) f.push_back(P(u, v));
        else {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    dfs(1, 0);
    for (auto e:f) {
        u = e.fi, v = e.se;
        //cout << u << " ?? " << v << endl;
        k = lca(u, v);
        if (k == u || k == v) {
            if (k == v) swap(u, v);
            mask[query(u, v)]--;
            mask[v]++;
        } else {
            cnt--;
            mask[u]++;
            mask[v]++;
        }
    }

    dfs2(1, 0, cnt);
    for (int i = 1; i <= n; i++) cout << val[i];
    cout << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    //cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}