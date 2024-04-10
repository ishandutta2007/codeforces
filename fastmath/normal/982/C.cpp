#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

vector <int> g[MAXN];
int dp[MAXN];
int cnt[MAXN];

void jfs(int u, int parent) {
    for (int v : g[u]) {
        if (v == parent) continue;
        jfs(v, u);
    }  

    cnt[u] = 1;
    for (int v : g[u]) {
        if (v == parent) continue;
        cnt[u] += cnt[v];
    }
        
    if (cnt[u] == 1) {
        dp[0] = 0;
        return;
    }
    
    for (int v : g[u]) {
        if (v == parent) continue;
        dp[u] += dp[v];
        dp[u] += (cnt[v] % 2 == 0);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    if (n % 2 == 1) {
        cout << "-1\n";
        return 0;
    }
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    jfs(0, 0);

    cout << dp[0] << '\n';

    return 0;
}