#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll mod = 998244353;

ll dp[2005][2005];

ll dfs(int n, int m, int k){
    if(n == 1)return (k == 0);
    if(k < 0)return 0;
    if(dp[n][k] != -1)return dp[n][k];
    ll ret = (m-1)*dfs(n - 1, m, k - 1) + dfs(n - 1, m, k);
    return dp[n][k] = ret % mod;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, k;
    cin>>n>>m>>k;

    memset(dp, -1, sizeof(dp));
    cout<<(m*dfs(n, m, k))%mod;
}