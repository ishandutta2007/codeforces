#include <bits/stdc++.h>
#define MN 200020
#define MOD 1000000007

using namespace std;
typedef long long ll;

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll mul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b % 2) return mul(a, expo(a * a, b >> 1));
    return expo(a * a, b >> 1);
}

ll inv(ll a) {
    return expo(a, MOD - 2);
}

ll dp[MN], ans[MN], zeroes[MN];
int n, p;
vector<int> adj[MN];

ll solve(int node, int p = -1) {
    ll ret = 1;
    for(int i = 0; i < adj[node].size(); i++) {
        if(adj[node][i] != p) {
            ll x = solve(adj[node][i], node);
            if(add(x, 1) == 0) zeroes[node]++;
            else ret = mul(ret, add(x, 1));
        }
    }

    dp[node] = ret;
    return zeroes[node] ? 0 : dp[node];
}

ll gdp(int i) {
    return zeroes[i] ? 0 : dp[i];
}

ll change(int a, int b) {
    if(add(gdp(b), 1) == 0) zeroes[a]--;
    else dp[a] = mul(dp[a], inv(add(gdp(b), 1)));

    if(add(gdp(a), 1) == 0) zeroes[b]++;
    else dp[b] = mul(dp[b], add(gdp(a), 1));
}

void fix(int node, int p = -1) {
    ans[node] = zeroes[node] ? 0 : dp[node];
    for(int i = 0; i < adj[node].size(); i++) {
        int v = adj[node][i];
        if(v != p) {
            change(node, v);
            fix(v, node);
            change(v, node);
        }
    }
}

int main() {
    scanf("%d", &n);

    for(int i = 2; i <= n; i++) {
        scanf("%d", &p);
        adj[p].push_back(i);
    }

    solve(1);
    fix(1);

    for(int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }

    return 0;
}