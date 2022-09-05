#include<bits/stdc++.h>

using namespace std;

int N, INF, a[309][309], dp[309][309], old[309][309];

int val (int diag, int i) {return a[i][diag - i];}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), INF = 1e8;
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        scanf ("%d", &a[i][j]);
dp[1][1] = a[1][1];
for (int diag=3; diag<=2 * N; diag++)
{
    memcpy (old, dp, sizeof (dp));
    int maxN = min (N, diag - 1);
    for (int i1=1; i1<=maxN; i1++)
        for (int i2=1; i2<=maxN; i2++)
        {
            dp[i1][i2] = -INF;
            for (int dx=0; dx<2 && dx < i1; dx++)
                for (int dy=0; dy<2 && dy < i2; dy++)
                    if (i1 - dx < diag - 1 && i2 - dy < diag - 1 && old[i1 - dx][i2 - dy] > dp[i1][i2])
                        dp[i1][i2] = old[i1 - dx][i2 - dy];
            if (i1 != i2) dp[i1][i2] += val (diag, i1) + val (diag, i2);
            else dp[i1][i2] += val (diag, i1);
        }
}
printf ("%d\n", dp[N][N]);
return 0;
}