#include<bits/stdc++.h>

using namespace std;

int N, lim = 260, a[20], b[20], tip[20];
long long ans, sA, sB, dp[(1 << 16) + 2][300];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
for (int i=0; i<N; i++)
{
    char c;
    scanf ("%c ", &c);
    if (c == 'R') tip[i] = 1;
    else tip[i] = 2;
    scanf ("%d %d\n", &a[i], &b[i]), sA += a[i], sB += b[i];
}
///dp[i][300];
for (int i=0; i<(1 << N); i++)
    for (int j=0; j<lim; j++)
        dp[i][j] = -1LL << 50;
dp[0][0] = 0, ans = max (sA, sB);
for (int i=0; i<(1 << N); i++)
    for (int j=0; j<lim; j++)
        if (dp[i][j] >= 0)
        {
            int A = 0, B = 0;
            for (int k=0; k<N; k++)
                if (i & (1 << k))
                    A += (tip[k] == 1), B += (tip[k] == 2);
            for (int k=0; k<N; k++)
                if ((i & (1 << k)) == 0)
                {
                    int eficA, eficB;
                    eficA = a[k] - max (0, a[k] - A);
                    eficB = b[k] - max (0, b[k] - B);
                    if (dp[i ^ (1 << k)][j + eficA] < dp[i][j] + eficB)
                        dp[i ^ (1 << k)][j + eficA] = dp[i][j] + eficB;
                }
        }
for (int i=0; i<lim; i++)
    if (dp[(1 << N) - 1][i] >= 0)
    {
        long long x = sA - i, y = sB - dp[(1 << N) - 1][i];
        long long curr = max (x, y);
        if (curr < ans) ans = curr;
    }
printf ("%I64d\n", N + ans);
return 0;
}