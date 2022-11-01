#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
typedef long long ll;

int dp[1010][1010], n, m, k;

int main() {
    scanf("%d %d %d", &n, &m, &k);

    if(n == 1 || m == 1 || min(n, m) <= 2 * k) {
        printf("0\n");
        return 0;
    }

    for(int i = 1; i < 1010; i++)
        dp[1][i] = (i + 1) * i / 2;

    for(int t = 2; t <= k; t++) {
        for(int i = 3; i <= 1000; i++) {
            for(int l = 3; l <= i; l++) {
                dp[t][i] += (i-l+1LL) * dp[t-1][l-2] % MOD;
                if(dp[t][i] >= MOD) dp[t][i] -= MOD;
            }
        }
    }

    printf("%d\n", 1LL * dp[k][n-2] * dp[k][m-2] % MOD);
    return 0;
}