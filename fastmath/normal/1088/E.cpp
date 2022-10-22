#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 3e5 + 7;
const int INF = 1e9 + 7;

int n;
int a[MAXN], dp[MAXN];
vector <int> g[MAXN];

int mx = -INF;
void dfs1(int u, int parent) {
    dp[u] = a[u];
    for (int v : g[u]) {
        if (v == parent) {
            continue;
        }   
        dfs1(v, u);
        dp[u] += max(0ll, dp[v]);
    }   
    mx = max(mx, dp[u]);
}   

int cnt = 0;
void dfs2(int u, int parent) {
    dp[u] = a[u];
    for (int v : g[u]) {
        if (v == parent) {
            continue;
        }   
        dfs2(v, u);
        dp[u] += max(0ll, dp[v]);
    }   
    if (dp[u] == mx) {
        ++cnt;
        dp[u] = 0;
    }   
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }   
    
    dfs1(0, 0);
    dfs2(0, 0);
    cout << mx * cnt << ' ' << cnt << '\n';

    return 0;
}