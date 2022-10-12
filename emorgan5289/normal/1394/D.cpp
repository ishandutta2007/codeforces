#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e13;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 2e5+5;
ll t[N], h[N], dp[N][2];
vector<int> adj[N];

void dfs(int i, int p) {
    ll x = 0;
    vector<ll> d;
    for (auto& j : adj[i]) {
        if (j == p) continue;
        dfs(j, i);
        x += dp[j][0];
        d.pb(dp[j][1]-dp[j][0]);
    }
    sort(all(d));
    dp[i][0] = dp[i][1] = inf_ll;
    ll s = d.size();
    for (ll j = 0; j <= s; j++) {
        if (j > 0) x += d[j-1];
        ll y = i == 0 ? 0 : 1;
        dp[i][0] = min(dp[i][0], x+t[i]*max(j+y, s-j));
        dp[i][1] = min(dp[i][1], x+t[i]*max(j, s-j+y));
    }
    if (i != 0 && h[i] < h[p]) dp[i][0] = inf_ll;
    if (i != 0 && h[i] > h[p]) dp[i][1] = inf_ll;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    dfs(0, -1);
    cout << dp[0][0] << "\n";
}