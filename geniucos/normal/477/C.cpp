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

int N, M, dp[2015][2015], last[2015], prec[2015][256];
char S[2015], T[2015];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (S + 1), N = strlen (S + 1);
gets (T + 1), M = strlen (T + 1);

for (int i=1; i<=N; i++)
{
    for (int j='a'; j<='z'; j++)
        prec[i][j] = prec[i-1][j];
    prec[i][S[i]] = i;
}

for (int i=1; i<=N; i++)
{
    last[i] = i + 1;
    for (int j=M; j>=1; j--)
    {
        if (last[i] <= 0)
            break;
        last[i] = prec[last[i]-1][T[j]];
    }
}

dp[0][0] = 0;
for (int i=1; i<=N; i++)
{
    if (last[i] <= 0 || i - last[i] + 1 != M) dp[0][i] = dp[0][i-1];
    else dp[0][i] = dp[0][last[i] - 1] + 1;
}

for (int i=1; i<=N; i++)
{
    for (int j=0; j<i; j++)
        dp[i][j] = -(1<<20);

    for (int j=i; j<=N; j++)
    {
        dp[i][j] = dp[i - 1][j - 1];

        if (dp[i][j-1] > dp[i][j])
            dp[i][j] = dp[i][j-1];

        if (last[j] > 0 && i - (j - last[j] + 1 - M) >= 0 && dp[i - (j - last[j] + 1 - M)][last[j] - 1] + 1 > dp[i][j])
            dp[i][j] = dp[i - (j - last[j] + 1 - M)][last[j] - 1] + 1;
    }
}

for (int i=0; i<=N; i++)
    printf ("%d ", dp[i][N]);
printf ("\n");

return 0;
}