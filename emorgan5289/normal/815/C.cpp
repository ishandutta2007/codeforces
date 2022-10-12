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

const int N = 5005;
vector<ll> dp[N][2];
ll c[N], d[N];
vector<int> adj[N];

vector<ll> merge(vector<ll>& a, vector<ll>& b) {
    vector<ll> r(a.size()+b.size()-1, inf_ll);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            cmin(r[i+j], a[i]+b[j]);
    return r;
}

void dfs(int i) {
    dp[i][0] = {0, c[i]};
    dp[i][1] = {inf_ll, c[i]-d[i]};
    for (int j : adj[i]) {
        dfs(j);
        dp[i][0] = merge(dp[i][0], dp[j][0]);
        dp[i][1] = merge(dp[i][1], dp[j][1]);
    }
    for (int j = 0; j < dp[i][1].size(); j++)
        cmin(dp[i][1][j], dp[i][0][j]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, b; cin >> n >> b;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> d[i];
        if (i > 0) {
            int x; cin >> x;
            adj[x-1].pb(i);
        }
    }
    dfs(0);
    for (int i = n; i >= 0; i--)
        if (dp[0][1][i] <= b) {
            cout << i << "\n"; break;
        }
}