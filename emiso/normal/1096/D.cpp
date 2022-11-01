#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, a[100010], dp[100010][5];
char s[100010];
string str, pat = "hard";

int main() {
    scanf("%lld %s", &n, s);
    str = s;

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    for(int i = 0; i <= n; i++)
        for(int k = 0; k <= 4; k++)
            dp[i][k] = 10000000000000000LL;
    dp[0][0] = 0;

    ll ans = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < 4; k++) {
            if(str[i] == pat[k]) {
                dp[i+1][k] = min(dp[i+1][k], dp[i][k] + a[i]);
                dp[i+1][k+1] = min(dp[i][k+1], dp[i][k]);
            } else {
                dp[i+1][k] = min(dp[i+1][k], dp[i][k]);
            }
        }
    }

    for(int i = 0; i < 4; i++) {
        ans = min(ans, dp[n][i]);
    }

    printf("%lld\n", ans);
    return 0;
}