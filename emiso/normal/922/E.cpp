#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, W, B, X, q[1010], dp[1010][10101], c[1010];

int main() {
    scanf("%lld %lld %lld %lld", &n, &W, &B, &X);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &q[i]);
    } for(int i = 0; i < n; i++) {
        scanf("%lld", &c[i]);
    }

    memset(dp, -1, sizeof dp);
    dp[0][0] = W;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= 10010; j++) {
            if(dp[i][j] == -1) break; // break?
            for(int k = 0; k <= q[i]; k++) {
                if(dp[i][j] - c[i]*k < 0) break;
                dp[i+1][j+k] = max(dp[i+1][j+k], min(dp[i][j] - c[i]*k + X, W + B*(j+k)));
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i <= 10010; i++) {
        if(dp[n][i] != -1) ans = max(ans, i);
    }

    printf("%lld\n", ans);
    return 0;
}