#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

int n, m;

const int N = 207;
vector <int> g[N], rg[N];

int dp[N];

void rel(int &a, int b) {
    a = min(a, b);
}   

int mem[N];
int solve(int S) {
    for (int i = 1; i <= n; ++i)
        dp[i] = N;
    dp[S] = 0;
    for (int t = 0; t <= n; ++t) {
        for (int u = 1; u <= n; ++u) {
            for (int v : g[u])
                rel(dp[v], dp[u] + 1);
            for (int v : rg[u])
                rel(dp[v], dp[u] - 1);
        }   
    }   
    for (int i = 1; i <= n; ++i)
        if (dp[i] < 0)
            return -1;

    for (int u = 1; u <= n; ++u)
        for (int v : g[u])
            if (abs(dp[u] - dp[v]) != 1)
                return -1;
    
    for (int u = 1; u <= n; ++u)
        for (int v : rg[u])
            if (dp[v] != dp[u] - 1)
                return -1;

    int mx = 0;
    for (int i = 1; i <= n; ++i)
        mx = max(mx, dp[i]);
    return mx;            
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        g[u].app(v);
        g[v].app(u);
        if (t) {
            rg[v].app(u);
        }   
    }   

    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        mem[i] = solve(i);
        ans = max(ans, mem[i]);
    }   

    if (ans == -1) {
        cout << "NO" << endl;
    }   
    else {
        cout << "YES" << endl;
        cout << ans << endl;
        for (int i = 1; i <= n; ++i) {
            if (mem[i] == ans) {
                solve(i);
                for (int u = 1; u <= n; ++u)
                    cout << dp[u] << ' ';
                cout << endl;
                exit(0);
            }   
        }   
    }   
}