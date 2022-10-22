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

const int maxn = 2000 + 5;
int mod;

int add(int x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}

int mul(int a, int b) {
    LL r = 1LL * a * b;
    return r - r / mod * mod;
}

vector<int> g[maxn];
int c[maxn][maxn], ans[maxn];
int dp[maxn][maxn], s[maxn][maxn], l[maxn][maxn], r[maxn][maxn];

void dfs(int u, int fa, int n) {
    vector<int> adj;
    adj.push_back(0);
    for (auto v:g[u]) {
        if (v == fa) continue;
        dfs(v, u, n);
        for (int i = 1; i < n; i++) s[v][i] = add(s[v][i - 1], dp[v][i]);
        adj.push_back(v);
    }

    int m = adj.size();
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) l[i][j] = mul(l[i - 1][j], s[adj[i]][j]);
        for (int j = 1; j < n; j++) r[i][j] = mul(r[i - 1][j], s[adj[m - i]][j]);
    }

    for (int j = 1; j < n; j++) dp[u][j] = l[m - 1][j];
    if (u == 1 || m == 1) {
        return;
    }

    for (int i = 1; i < m; i++) {
        int sum = 0;
        for (int j = 1; j < n; j++) {
            dp[u][j] = add(dp[u][j], mul(sum, dp[adj[i]][j]));
            sum = add(sum, mul(l[i - 1][j], r[m - i - 1][j]));
        }
    }
}

void solve()
{
    int n, u, v;
    cin >> n >> mod;

    for (int i = 0; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) c[i][j] = add(c[i  -1][j - 1], c[i - 1][j]);
    }

    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    fill(l[0] + 1, l[0] + n, 1);
    fill(r[0] + 1, r[0] + n, 1);
    dfs(1, 0, n);

    for (int i = 1; i < n; i++) {
        ans[i] = dp[1][i];
        for (int j = 1; j < i; j++) ans[i] = add(ans[i], mod - mul(c[i][j], ans[j]));
        cout << ans[i] << " ";
    }
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