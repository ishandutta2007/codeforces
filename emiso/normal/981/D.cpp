#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, k, ans, a[MN], dp[53][53];

int main() {
    scanf("%lld %lld", &n, &k);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    for(ll b = 60; b >= 0; b--) {
        ll mask = ans + (1LL << b);

        memset(dp, 0, sizeof dp);
        dp[n][0] = 1;
        for(ll i = n - 1; i >= 0; i--) {

            ll sum = 0;
            for(int j = i; j < n; j++) {
                sum += a[j];
                if((sum & mask) == mask) {
                    for(int p = 0; p <= 50; p++)
                        if(dp[j+1][p])
                            dp[i][p+1] = 1;
                }
            }
        }

        if(dp[0][k] == 1) {
            ans = mask;
        }
    }

    printf("%lld\n", ans);
    return 0;
}