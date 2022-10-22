#include<bits/stdc++.h>
using namespace std;
//#define HOME
#define f first
#define s second
#define int long long
const int N = 5e5 + 7;
int n, k, dp[N][2];
vector <pair <int, int > > g[N];
// 0 - k, 1 - k - 1
void dfs(int u, int p) {
    int sum = 0;
    vector <int> add;
    for (auto e : g[u]) {
        if (e.f != p) {
            dfs(e.f, u);
            sum += dp[e.f][0];
            add.push_back(max(0ll, dp[e.f][1] + e.s - dp[e.f][0]));
        }
    }
    dp[u][0] = dp[u][1] = sum;
    sort(add.begin(), add.end()); reverse(add.begin(), add.end());
    for (int i = 0; i < min(k, (int)add.size()); ++i) dp[u][0] += add[i];
    for (int i = 0; i < min(k - 1, (int)add.size()); ++i) dp[u][1] += add[i];
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) g[i].clear();
    for (int i = 0; i < n - 1; ++i) {
        int u, v, c; cin >> u >> v >> c;
        g[u].push_back({v, c}); g[v].push_back({u, c});
    }
    dfs(1, 1);
    cout << dp[1][0] << '\n';
}
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif // HOME
    int t; cin >> t; while (t--) solve();
}