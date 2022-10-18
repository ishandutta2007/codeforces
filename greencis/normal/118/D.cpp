#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

const int MOD = 100000000;
int n1,n2,k1,k2,ans;
int dp[105][105][25];

int main()
{
    cin >> n1 >> n2 >> k1 >> k2;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n1 + n2; ++i) {
        for (int j = max(i - n2, 0); j <= i && j <= n1; ++j) {
            /// try 1
            if (j > 0) {
                for (int z = 1; z <= 10; ++z) {
                    (dp[j][i-j][z] += dp[j-1][i-j][z-1]) %= MOD;
                    if (z <= k2)
                        (dp[j][i-j][1] += dp[j-1][i-j][10+z]) %= MOD;
                }
            }
            /// try 2
            if (i - j > 0) {
                for (int z = 1; z <= 10; ++z) {
                    (dp[j][i-j][10+z] += dp[j][i-j-1][10+z-1 == 10 ? 0 : 10+z-1]) %= MOD;
                    if (z <= k1)
                        (dp[j][i-j][11] += dp[j][i-j-1][z]) %= MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= k1; ++i)
        (ans += dp[n1][n2][i]) %= MOD;
    for (int i = 1; i <= k2; ++i)
        (ans += dp[n1][n2][10+i]) %= MOD;
    printf("%d",ans);

    return 0;
}