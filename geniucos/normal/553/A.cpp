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

int mod, N, K, dp[1009][1009], c[1009][1009], ap[1009], s[1009], sum[1009][1009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

mod = 1000000007;
c[0][0] = c[1][0] = c[1][1] = 1;
for (int i=2; i<=1000; i++)
{
    c[i][0] = 1;
    for (int j=1; j<=i; j++)
    {
        c[i][j] = c[i-1][j-1] + c[i-1][j];
        if (c[i][j] >= mod)
            c[i][j] -= mod;
    }
}

scanf ("%d", &K);
for (int i=1; i<=K; i++)
{
    scanf ("%d", &ap[i]);
    s[i] = s[i-1] + ap[i];
}
N = s[K];
for (int i=1; i<=N; i++)
{
    dp[i][1] = c[i-1][ap[1] - 1];
    sum[i][1] = sum[i-1][1] + dp[i][1];
    if (sum[i][1] >= mod)
        sum[i][1] -= mod;
    for (int j=2; j<=K; j++)
    {
        if (i - 1 - s[j-1] >= 0)
            dp[i][j] = ((long long)1LL * sum[i-1][j-1] * c[i-1-s[j-1]][ap[j]-1]) % mod;
        else
            dp[i][j] = 0;
        sum[i][j] = sum[i-1][j] + dp[i][j];
        if (sum[i][j] >= mod)
            sum[i][j] -= mod;

/*        for (int p=1; p<i; p++)
            if (i - 1 - s[j-1] >= 0)
                dp[i][j] = ((long long) dp[i][j] + 1LL * dp[p][j-1] * c[i-1 - s[j-1]][ap[j] - 1]) % mod;*/
    }
}
printf ("%d\n", dp[N][K]);

return 0;
}