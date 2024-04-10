#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 3005;
ll par[N][N], dp[N][N], sz[N][N];
vector<array<int, 2>> len[N];
vector<int> adj[N];

void dfs(int i, int k, int r, int d) {
    len[d].pb({i, r});
    par[r][i] = k;
    sz[r][i] = 1;
    for (auto& j : adj[i])
        if (j != k) {
            dfs(j, i, r, d+1);
            sz[r][i] += sz[r][j];
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    for (int i = 0; i < n; i++)
        dfs(i, i, i, 0);
    ll ans = 0;
    for (int i = 1; i < n; i++)
        for (auto& [x, y] : len[i])
            cmax(ans, dp[x][y] = sz[x][y]*sz[y][x] + max(dp[par[y][x]][y], dp[par[x][y]][x]));
    cout << ans << "\n";
}