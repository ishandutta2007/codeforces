#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 3007;
int n, m, a[N], cnt[N];
ii dp[N][N];
ii t[N];
vector <int> g[N];
void add(int u, int v) {
    for (int i = 0; i <= cnt[u] + cnt[v]; ++i) 
        t[i] = mp(-N, -N);
    for (int i = 0; i < cnt[u]; ++i) {
        for (int j = 0; j < cnt[v]; ++j) {
            t[i + j] = max(t[i + j], mp(dp[u][i].f + dp[v][j].f, dp[u][i].s + dp[v][j].s));
        }   
        for (int j = 0; j < cnt[v]; ++j) {
            t[i + j + 1] = max(t[i + j + 1], mp(dp[u][i].f + dp[v][j].f + (dp[v][j].s > 0), dp[u][i].s));
        }   
    }   
    for (int i = 0; i <= cnt[u] + cnt[v]; ++i)
        dp[u][i] = t[i];
}   
void dfs(int u, int p) {
    for (int i = 0; i <= m; ++i) 
        dp[u][i] = mp(-N, -N);
    dp[u][0] = mp(0, a[u]);
    cnt[u] = 1;
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u);
            add(u, v);
            cnt[u] += cnt[v];
        }   
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            a[i] = 0;
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x;
            a[i] -= x;
        }   
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x;
            a[i] += x;
        }   

        #ifdef HOME
        for (int i = 1; i <= n; ++i)
            cout << a[i] << ' ';
        cout << '\n';
        #endif

        for (int i = 1; i <= n; ++i)
            g[i].clear();
        for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v;
            g[u].app(v); g[v].app(u);
        }   
        dfs(1, 1);
        cout << dp[1][m - 1].f + (dp[1][m - 1].s > 0) << '\n';
    }   
}