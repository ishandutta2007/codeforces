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
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 2e5 + 7, MOD = 998244353;
int f[N], dp[N];
vector <int> g[N];
void dfs(int u, int p) {
    int k = 0;
    for (int v : g[u]) 
        if (v != p) {
            dfs(v, u);
            ++k;
        }   
    if (k == 0) {
        dp[u] = 1;
    }
    else {
        dp[u] = f[k] * (k + 1) % MOD;
        for (int v : g[u])
            if (v != p)
                dp[u] = dp[u] * dp[v] % MOD;
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = f[i - 1] * i % MOD;
    int n;
    cin >> n;
    if (n == 2) {
        cout << "2\n";
        exit(0);
    }   
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    int root = -1;
    for (int i = 1; i <= n; ++i)
        if (g[i].size() > 1)
            root = i;
    dfs(root, root);

    #ifdef HOME
    cout << "root " << root << '\n';
    for (int i = 1; i <= n; ++i)
        cout << dp[i] << ' ';
    cout << '\n';            
    #endif

    int ans = 1;
    for (int v : g[root])
        ans = ans * dp[v] % MOD;
    ans = ans * f[g[root].size()] % MOD;
    ans = ans * n % MOD;
    cout << ans << '\n';
}