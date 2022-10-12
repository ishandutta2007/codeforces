#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 300005;
const ll mod = 998244353;
ll dp[maxn][4];
vector<int> adj[maxn];

void dfs(int i, int p) {
    ll x = 1, y = 1, z = 1;
    for (auto& j : adj[i])
        if (j != p) {
            dfs(j, i);
            x = ((dp[j][0]+dp[j][1]+dp[j][2]+dp[j][3])%mod)*x%mod;
            y = ((dp[j][0]+dp[j][1]+dp[j][2])%mod)*y%mod;
            z = ((dp[j][0]+dp[j][2])%mod)*z%mod;
        }
    dp[i][0] = dp[i][1] = x;
    dp[i][3] = y;
    dp[i][2] = (y-z+mod)%mod;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(0, 0);
    cout << (dp[0][0]+dp[0][2]-1+mod)%mod << "\n";
}