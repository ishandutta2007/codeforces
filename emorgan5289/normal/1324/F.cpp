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

const int N = 2e5+5;
vector<int> adj[N];
int a[N], dp[N], ans[N];

void dfs1(int i, int k) {
    dp[i] = a[i] ? 1 : -1;
    for (int j : adj[i])
        if (j != k) {
            dfs1(j, i);
            dp[i] += max(0, dp[j]);
        }
}

void shift(int i, int j) {
    dp[i] -= max(0, dp[j]);
    dp[j] += max(0, dp[i]);
}

void dfs2(int i, int k) {
    ans[i] = dp[i];
    for (int j : adj[i])
        if (j != k) {
            shift(i, j);
            dfs2(j, i);
            shift(j, i);
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    dfs1(0, 0);
    dfs2(0, 0);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n-1];
}