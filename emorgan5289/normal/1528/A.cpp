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
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

int n;
vector<vector<int>> adj;
vector<ll> l, r;
vector<array<ll, 2>> dp;

void dfs(int i, int k) {
    // 0 l
    // 1 r
    for (int j : adj[i]) {
        if (j == k) continue;
        dfs(j, i);
        dp[i][0] += max(dp[j][0]+abs(l[i]-l[j]), dp[j][1]+abs(l[i]-r[j]));
        dp[i][1] += max(dp[j][0]+abs(r[i]-l[j]), dp[j][1]+abs(r[i]-r[j]));
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        adj.assign(n, {});
        l.resize(n);
        r.resize(n);
        dp.assign(n, {0, 0});
        for (int i = 0; i < n; i++)
            cin >> l[i] >> r[i];
        for (int i = 0; i < n-1; i++) {
            int x, y; cin >> x >> y; x--, y--;
            adj[x].pb(y), adj[y].pb(x);
        }
        dfs(0, 0);
        cout << max(dp[0][0], dp[0][1]) << "\n";
    }
}