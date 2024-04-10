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

const int N = 1e5+5, K = 21;
ll n, k;
ll dp[N][2*K], a[N], ans[N];
vector<int> adj[N];

void dfs1(int i, int p) {
    for (int j : adj[i])
        if (j != p) {
            dfs1(j, i);
            for (int l = 0; l < 2*k; l++)
                dp[i][l] ^= dp[j][(l+1)%(2*k)];
        }
    for (int l = 0; l < k; l++)
        dp[i][l] ^= a[i];
}

void shift(int i, int j) {
    for (int l = 0; l < 2*k; l++)
        dp[i][l] ^= dp[j][(l+1)%(2*k)];
    for (int l = 0; l < 2*k; l++)
        dp[j][l] ^= dp[i][(l+1)%(2*k)];
}

void dfs2(int i, int p) {
    ans[i] = dp[i][k];
    for (int j : adj[i])
        if (j != p) {
            shift(i, j);
            dfs2(j, i);
            shift(j, i);
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dfs1(0, 0);
    dfs2(0, 0);
    for (int i = 0; i < n; i++)
        cout << (ans[i] ? 1 : 0) << " \n"[i == n-1];
}