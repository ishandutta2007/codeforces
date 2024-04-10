#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, a[400100], d[20][20], freq[21], dp[1<<20][20];

int main() {
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i]--;
        for(int o = 0; o < 20; o++)
            if(o != a[i]) d[o][a[i]] += freq[o];
        freq[a[i]]++;
    }

    for(int m = 0; m < (1 << 20); m++)
        for(int b = 0; b < 20; b++)
            dp[m][b] = 100000000000000LL;

    for(int b = 0; b < 20; b++)
        dp[1 << b][b] = 0;

    for(int m = 0; m < (1 << 20); m++) {
        for(int j = 0; j < 20; j++) {
            if((m & (1 << j)) != 0) continue;
            ll cost = 0;
            for(int b = 0; b < 20; b++) {
                if((m & (1 << b)) == 0) continue;
                cost += d[j][b];
            }
            for(int b = 0; b < 20; b++) {
                if((m & (1 << b)) == 0) continue;
                dp[m|(1<<j)][j] = min(dp[m|(1<<j)][j], dp[m][b] + cost);
            }
        }
    }

    ll ans = 100000000000000LL;
    for(int b = 0; b < 20; b++)
        ans = min(ans, dp[(1<<20)-1][b]);

    printf("%lld\n", ans);
    return 0;
}