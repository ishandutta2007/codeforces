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
const int N = 1e5 + 7;
int dp[N][2], ans = 0;
vector <int> g[N];
void dfs(int u, int p) {
    int child = 0;
    for (int v : g[u])  
        child += v != p;

    dp[u][1] = 1;
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u);
            dp[u][0] = max(dp[u][0], max(dp[v][0], dp[v][1]) + child - 1);
            dp[u][1] = max(dp[u][1], dp[v][0] + 1);
        }   
    }   

    vector <int> a, b;
    int adj = child - 2 + (u != p);
    for (int v : g[u]) {
        if (v != p) {
            a.app(max(dp[v][0], dp[v][1]));
            b.app(dp[v][0]);
        }   
    }   
    sort(all(a)); reverse(all(a));
    sort(all(b)); reverse(all(b));
    if (a.size() > 1)
        ans = max(ans, a[0] + a[1] + adj);
    if (b.size() > 1)
        ans = max(ans, b[0] + b[1] + 1);

    adj = child - 1 + (u != p);
    for (int v : g[u])
        if (v != p) {
            ans = max(ans, adj + max(dp[v][0], dp[v][1]));
            ans = max(ans, 1 + dp[v][0]);
        }   


    #ifdef HOME
    cout << u << " : " << dp[u][0] << ' ' << dp[u][1] << endl;
    #endif
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v);
        g[v].app(u);
    }   
    dfs(1, 1);
    cout << ans << endl;
}