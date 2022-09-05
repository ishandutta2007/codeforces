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

int N, M, B, mod, dp[2][509][509], a[509];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d", &N, &M, &B, &mod);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
dp[0][0][0] = 1;
for (int i=1; i<=N; i++)
{
    for (int j=0; j<=M; j++)
        for (int k=0; k<=B; k++)
        {
            dp[i&1][j][k] = dp[(i&1)^1][j][k];
            if (k >= a[i] && j >= 1)
            {
                dp[i&1][j][k] += dp[i&1][j-1][k-a[i]];
                if (dp[i&1][j][k] >= mod)
                    dp[i&1][j][k] -= mod;
            }
        }

    /*for (int j=0; j<=M; j++)
        for (int k=0; k<=B; k++)
            dp[(i&1)^1][j][k] = 0;*/
}

int sol = 0;
for (int k=0; k<=B; k++)
{
    sol += dp[N&1][M][k];
    if (sol >= mod)
        sol -= mod;
}
printf ("%d\n", sol);

return 0;
}