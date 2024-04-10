#include<cstdio>
#include<bitset>
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

int T, N, M, mod, d2[60][1015], sum[60][1015], dp[60][1015], ap[1015][1015], ans[1015][1015], fac[1015];

int solve (int N, int K)
{
    if (ap[N][K]) return ans[N][K];
    ap[N][K] = 1;
    int sol = 0;
    for (int sum = 0; sum <= N; sum ++)
        sol = ((long long) sol + 1LL * dp[K][sum] * d2[K + 1][N - sum]) % mod;
    sol = (1LL * sol * fac[K]) % mod;
    ans[N][K] = sol;
    return sol;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &T), N = 1000, mod = 1e9 + 7;

dp[0][0] = 1;
for (int i=1; i<=50; i++)
    for (int j=0; j<=N; j++)
    {
        if (j >= i)
        {
            dp[i][j] = dp[i][j - i] + dp[i - 1][j - i];
            if (dp[i][j] >= mod) dp[i][j] -= mod;
        }
        else dp[i][j] = 0;
    }

d2[0][0] = 1;
for (int i=0; i<=1000; i++)
    sum[0][i] = 1;
for (int i=1; i<=50; i++)
    for (int j=0; j<=N; j++)
    {
        d2[i][j] = sum[i-1][j];
        if (j == 0) sum[i][j] = d2[i][j];
        else
        {
            sum[i][j] = sum[i][j-1] + d2[i][j];
            if (sum[i][j] >= mod) sum[i][j] -= mod;
        }
    }

fac[0] = 1;
for (int i=1; i<=N; i++)
    fac[i] = (1LL * fac[i-1] * i) % mod;

while (T --)
{
    int N, M;
    scanf ("%d %d", &N, &M);
    if (M > 50) printf ("0\n");
    else printf ("%d\n", solve (N, M));
}

return 0;
}