#include<bits/stdc++.h>

using namespace std;

int N, Q, a[759];
long long dp[759][759], opt[759], INF = 1LL << 60;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &Q);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), opt[i] = INF;
reverse (a + 1, a + N + 1);
dp[0][0] = 0;
for (int i=1; i<=N; i++)
{
    dp[i][0] = INF;
    long long curr = INF;
    for (int j=1; j<=N; j++)
    {
        if (dp[i - 1][j - 1] < curr) curr = dp[i - 1][j - 1];
        if (j < i) dp[i][j] = INF;
        else dp[i][j] = max ((long long) -a[j], curr - a[j]);
        if (dp[i][j] < opt[i]) opt[i] = dp[i][j];
    }
}
for (int i=N - 1; i>=1; i--)
    if (opt[i + 1] < opt[i]) opt[i] = opt[i + 1];

while (Q --)
{
    long long val;
    int p = 1, u = N, mij, ras = 0;
    scanf ("%I64d", &val);
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (val >= opt[mij]) ras = mij, p = mij + 1;
        else u = mij - 1;
    }
    printf ("%d\n", N - ras);
}
return 0;
}