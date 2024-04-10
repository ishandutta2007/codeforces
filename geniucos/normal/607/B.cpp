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

int N, a[509], dp[509][509];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
for (int i=N; i>=1; i--)
{
    dp[i][i] = 1;
    if (i < N) dp[i][i + 1] = 1 + (a[i] != a[i + 1]);
    for (int j=i + 2; j<=N; j++)
    {
        dp[i][j] = j - i + 1;
        dp[i][j] = min (dp[i][j], dp[i + 1][j] + 1);
        dp[i][j] = min (dp[i][j], dp[i][j - 1] + 1);
        if (a[i] == a[j]) dp[i][j] = min (dp[i][j], dp[i + 1][j - 1]);
        for (int k=i; k<j; k++)
            if (dp[i][k] + dp[k + 1][j] < dp[i][j])
                dp[i][j] = dp[i][k] + dp[k + 1][j];
    }
}
printf ("%d\n", dp[1][N]);

return 0;
}