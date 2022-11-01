#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll n, k, m, dp[1010][101][2][2];

ll solve(int i, int mod, int ja, int nonzero, ll pot10) {
    if (mod == 0 && nonzero) ja = 1;
    if (i == n) return (ja && nonzero);
    ll &x = dp[i][mod][ja][nonzero];
    if (x != -1) return x;
    
    x = 0;
    for (ll d = 0; d <= 9; d++) {
        x += solve(i + 1, (mod + d*pot10) % k, ja, (d > 0), (pot10 * 10) % k);
        if (x >= m) x -= m;
    }

    return x;
}

int main() {
    scanf("%lld %lld %lld", &n, &k, &m);
    memset(dp, -1, sizeof dp);
    printf("%lld\n", solve(0, 0, 0, 0, 1));
    return 0;
}