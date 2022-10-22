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
typedef pair<LL, int> PL;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int add(int x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}

int mul(int a, int b) {
    LL r = 1LL * a * b;
    return r - r / mod * mod;
}

int p[maxn], inv[maxn];
int n, k, ans = 0;
int sz[maxn];
vector<int> g[maxn];
int C(int n, int m) {
    if (n < m) return 0;
    return mul(p[n], mul(inv[m], inv[n - m]));
}

void dfs(int u, int fa) {
    sz[u] = 1;
    for (auto v:g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }

    int m = g[u].size();
    vector<int> d(m, 0);
    int tmp = 0, val;
    for (int i = 0; i < m; i++) {
        if (g[u][i] == fa) d[i] = n - sz[u];
        else d[i] = sz[g[u][i]];
        tmp = add(tmp, C(d[i], k));
    }

    for (int i = 0; i < m; i++) {
        val = add(tmp, mod - C(d[i], k));
        val = add(C(n - d[i], k), mod - val);
        ans = add(ans, mul(n - d[i], mul(val, d[i])));
    }

    ans = add(ans, mul(n, add(C(n, k), mod - tmp)));
}

void solve()
{
    int u, v;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) g[i].clear();
    p[0] = inv[0] = inv[1] = 1;
    for (int i = 1; i <= n; i++) p[i] = mul(p[i - 1], i);
    for (int i = 2; i <= n; i++) inv[i] = mul(inv[mod % i], mod - mod / i);
    for (int i = 2; i <= n; i++) inv[i] = mul(inv[i - 1], inv[i]);

    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    cout << ans << endl;
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