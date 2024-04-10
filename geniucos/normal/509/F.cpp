#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int N, mod, dp[509][509], sub[509][509], a[509];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);

mod = 1000000007;
for (int i=N; i>=1; i--)
{
    dp[i][i] = 1;

    for (int j=i+1; j<=N; j++)
    {
        dp[i][j] = 0;
        for (int k=i+2; k<=j; k++)
            if (a[k] > a[i+1])
                dp[i][j] = ((long long) dp[i][j] + 1LL * dp[i+1][k-1] * dp[k-1][j]) % mod;
        dp[i][j] = ((long long)dp[i][j] + dp[i+1][j]) % mod;
    }
}

printf ("%d\n", dp[1][N]);

return 0;
}