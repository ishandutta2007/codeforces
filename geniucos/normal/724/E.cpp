#include<bits/stdc++.h>

using namespace std;

int N, C, p[10009], s[10009];
long long dp[2][10009];

void U (long long &x, long long val) {if (val < x) x = val;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &C);
for (int i=1; i<=N; i++)
    scanf ("%d", &p[i]);
for (int i=1; i<=N; i++)
    scanf ("%d", &s[i]);
dp[0][0] = 0;
for (int i=0; i<N; i++)
{
    int cr = i & 1, nx = cr ^ 1;
    for (int j=0; j<=i + 1; j++)
        dp[nx][j] = 1LL << 50;
    for (int j=0; j<=i; j++)
    {
        U (dp[nx][j + 1], dp[cr][j] + p[i + 1] + 1LL * C * (i - j));
        U (dp[nx][j], dp[cr][j] + s[i + 1]);
    }
}
long long bst = 1LL << 50;
for (int i=0; i<=N; i++)
    if (dp[N & 1][i] < bst) bst = dp[N & 1][i];
printf ("%I64d\n", bst);
return 0;
}