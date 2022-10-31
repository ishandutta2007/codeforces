#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
typedef long long ll;

int n, k, m;
ll dp[100010][13][1<<4];

ll solve(int pos, int rem, int msk) {
    if(rem == 0) return 1;
    if(pos == 0) return 0;

    ll &x = dp[pos][rem][msk];
    if(x != -1) return x;

    int nmsk = ((msk << 1) & ((1 << m) - 1));
    x = solve(pos - 1, rem, nmsk);
    x = (x + (1LL + __builtin_popcount(msk)) * solve(pos - 1, rem - 1, nmsk | 1)) % MOD;
    return x;
}

int main() {
    scanf("%d %d %d", &n, &k, &m);
    memset(dp, -1, sizeof dp);
    printf("%lld\n", solve(n, k, 0));
    return 0;
}