#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef long long ll;

int n, dp[5050][5050], acum[5050][5050];
char st[5050];

ll solve(ll i, ll ind);

ll sum(ll i, ll l, ll r) {
    if(i == n) return (r - l + 1);

    if(acum[i][0] == -1) {
        acum[i][0] = solve(i, 0);
        for(int j = 1; j <= i; j++) {
            acum[i][j] = (acum[i][j-1] + solve(i, j)) % MOD;
        }
    }

    return (acum[i][r] - (l ? acum[i][l-1] : 0) + MOD) % MOD;
}

ll solve(ll i, ll ind) {
    if(i == n) return 1;
    if(dp[i][ind] != - 1) return dp[i][ind];
    if(i && st[i-1] == 'f') return solve(i + 1, ind + (st[i] == 'f'));

    dp[i][ind] = sum(i + 1, (st[i] == 'f'), ind + (st[i] == 'f'));

    return dp[i][ind];
}

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf(" %c", &st[i]);
    }

    memset(dp, -1, sizeof dp);
    memset(acum, -1, sizeof acum);
    printf("%lld\n", solve(0, 0));

    return 0;
}