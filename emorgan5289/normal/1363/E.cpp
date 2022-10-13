#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 200005;
vector<int> adj[maxn];
ll a[maxn], b[maxn], c[maxn], dp[maxn][2];
ll out = 0;

void dfs(int i, int p) {
    a[i] = min(a[i], a[p]);
    dp[i][0] = dp[i][1] = 0;
    for (auto& j : adj[i])
        if (j != p) {
            dfs(j, i);
            dp[i][0] += dp[j][0];
            dp[i][1] += dp[j][1];
        }
    if (b[i] != c[i])
        dp[i][b[i]]++;
    ll m = min(dp[i][0], dp[i][1]);
    out += 2*a[i]*m;
    dp[i][0] -= m;
    dp[i][1] -= m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(0, 0);
    if (max(dp[0][0], dp[0][1]) != 0)
        cout << -1 << "\n";
    else
        cout << out << "\n";
}