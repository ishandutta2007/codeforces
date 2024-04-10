#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;
typedef long long ll;

int n, k;
int *dp[501][501];

int solve(int p, int mx, int st) {
    if(mx > n) mx = n;
    if(st > mx) return 0;

    if(p == n) return 1;
    if(dp[p][mx][st] != -1) return dp[p][mx][st];

    int x = solve(p + 1, mx, 1);
    x = (x + solve(p + 1, mx, st + 1));
    if(x >= MOD) x -= MOD;

    return dp[p][mx][st] = x;
}

int main() {
    scanf("%d %d", &n, &k);

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++) {
            dp[i][j] = new int[j+2];
            for(int k = 0; k < j + 2; k++) {
                dp[i][j][k] = -1;
            }
        }

    ll ans = 0;
    for(int i = 1; i <= k; i++) {
        int j = k / i;
        if(i * j == k) j--;

        ll z = (0LL + solve(0, i, 0) - solve(0, i-1, 0) + MOD) % MOD;
        ans = (ans + z*solve(1, j, 1)) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}