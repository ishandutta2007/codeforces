#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 3e5 + 7;

int n;
int w[MAXN];
vector <pair <int, int> > g[MAXN];

int dp[MAXN];

int ans = 0;
void dfs(int u, int par) {
    vector <int> a = {0, 0};
    for (auto e : g[u]) {
        int v = e.first;
        int c = e.second;
        if (v == par) {
            continue;
        }   
        dfs(v, u);
        a.push_back(dp[v] - c);
    }   
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ans = max(ans, a[0] + a[1] + w[u]);
    dp[u] = a[0] + w[u];
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }   
    for (int i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u; --v;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }   
    
    dfs(0, 0);

    cout << ans << '\n';
    return 0;
}