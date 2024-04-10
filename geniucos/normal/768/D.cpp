#include<bits/stdc++.h>

using namespace std;

int N, M, Queries;
double dp[7509][1009], eps = 1e-8;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &Queries), M = 7500;
dp[0][0] = 2000.0;
for (int i=1; i<=M; i++)
    for (int j=0; j<=N; j++)
        dp[i][j] += dp[i - 1][j] * ((double) j / N), dp[i][j + 1] += dp[i - 1][j] * ((double) (N - j) / N);
while (Queries --)
{
    int p;
    scanf ("%d", &p);
    for (int i=1; i<=M; i++)
        if (dp[i][N] >= p - eps)
        {
            printf ("%d\n", i);
            break;
        }
}
return 0;
}