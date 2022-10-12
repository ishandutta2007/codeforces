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

const int N = 2e5+5;
ll a[N], mxl[N], mnl[N], l[N];
ll dp[N], mxdp[N], mndp[N];
vector<int> adj[N];

void dfs1(int i) {
    cmax(mxl[l[i]], a[i]), cmin(mnl[l[i]], a[i]);
    for (int j : adj[i]) l[j] = l[i]+1, dfs1(j);
}

void dfs2(int i) {
    dp[i] = 0;
    for (int j : adj[i]) {
        cmax(dp[i], max(dp[j]+a[j]-mnl[l[j]], dp[j]-a[j]+mxl[l[j]]));
        cmax(dp[i], max(mxdp[l[j]]-a[j], mndp[l[j]]+a[j]));
    }
    cmax(mxdp[l[i]], dp[i]+a[i]), cmax(mndp[l[i]], dp[i]-a[i]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++)
            adj[i].clear(), mxl[i] = mxdp[i] = mndp[i] = -inf_ll, mnl[i] = inf_ll;
        for (int i = 1; i < n; i++) {
            int x; cin >> x; adj[x-1].pb(i);
        }
        for (int i = 1; i < n; i++)
            cin >> a[i];
        dfs1(0);
        queue<int> q({0});
        vector<int> stk;
        while (!q.empty()) {
            int i = q.front(); q.pop();
            stk.pb(i);
            for (int j : adj[i]) q.push(j);
        }
        reverse(all(stk));
        for (int i : stk) dfs2(i);
        cout << dp[0] << "\n";
    }
}