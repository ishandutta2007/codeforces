#include <bits/stdc++.h>

#define MN 201000
#define MOD 998244353

using namespace std;
typedef long long ll;

ll n;
vector<ll> dp[MN][2][3], adj[MN];

ll solve(int u, int need, int conn, int ed) {
    if(adj[u].size() == 0) return 1;
    if(ed == adj[u].size()) return ((need && conn) || (!need && conn != 1)); /// ???

    ll &x = dp[u][need][conn][ed];
    if(x != -1) return x;
    x = 0;

    x = solve(adj[u][ed], 0, 0, 0) * solve(u, need, conn, ed + 1) % MOD;
    x = (x + solve(adj[u][ed], 1, 0, 0) * solve(u, need, min(conn + 1, 2), ed + 1)) % MOD;

    return x;
}

int main() {
    scanf("%lld", &n);

    for(int i = 2; i <= n; i++) {
        ll p;
        scanf("%lld", &p);
        adj[p].push_back(i);
    }

    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 3; k++)
                dp[i][j][k].resize(adj[i].size() + 1, -1);

    printf("%lld\n", solve(1, 0, 0, 0));
    return 0;
}