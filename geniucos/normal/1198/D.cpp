#include<bits/stdc++.h>

using namespace std;

int N, dp[59][59][59][59], s[59][59];
char sir[59][59];

int sum (int a1, int b1, int a2, int b2)
{
    return s[a2][b2] - s[a1 - 1][b2] - s[a2][b1 - 1] + s[a1 - 1][b1 - 1];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
for (int i=1; i<=N; i++)
    scanf ("%s\n", sir[i] + 1);
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        sir[i][j] = (sir[i][j] == '#'),
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + sir[i][j];
for (int i1=N; i1>=1; i1--)
    for (int j1=N; j1>=1; j1--)
        for (int i2=i1; i2<=N; i2++)
            for (int j2=j1; j2<=N; j2++)
            {
                if (sum (i1, j1, i2, j2) == 0)
                {
                    dp[i1][j1][i2][j2] = 0;
                    continue;
                }
                dp[i1][j1][i2][j2] = max (j2 - j1 + 1, i2 - i1 + 1);
                for (int i=i1; i<i2; i++)
                    if (dp[i1][j1][i][j2] + dp[i + 1][j1][i2][j2] < dp[i1][j1][i2][j2])
                        dp[i1][j1][i2][j2] = dp[i1][j1][i][j2] + dp[i + 1][j1][i2][j2];
                for (int j=j1; j<=j2; j++)
                    if (dp[i1][j1][i2][j] + dp[i1][j + 1][i2][j2] < dp[i1][j1][i2][j2])
                        dp[i1][j1][i2][j2] = dp[i1][j1][i2][j] + dp[i1][j + 1][i2][j2];
            }
printf ("%d\n", dp[1][1][N][N]);
return 0;
}