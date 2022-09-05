#include<bits/stdc++.h>

using namespace std;

int N, K, mod, c[102][102], ways[102][102], cnt[102], dp[102][10002];
long long M;

int pow (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = (1LL * p * a) % mod;
        a = (1LL * a * a) % mod;
    }
    return p;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %I64d %d", &N, &M, &K), mod = 1e9 + 7;
c[0][0] = 1;
for (int i=1; i<=N; i++)
{
    c[i][0] = 1;
    for (int j=1; j<=i; j++)
    {
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        if (c[i][j] >= mod) c[i][j] -= mod;
    }
}
for (int i=1; i<=N; i++)
    cnt[i] = ((M - i) / N + 1) % (mod - 1);
/*int ans = 1;
for (int i=1; i<=N; i++)
{
    int j;
    for (j=i; j<=N; j++)
        if (cnt[j] != cnt[i]) break;
    j --;
    ///
    ///
    i = j;
}*/
for (int i=1; i<=N; i++)
    for (int j=0; j<=N; j++)
        ways[i][j] = pow (c[N][j], cnt[i]);
dp[0][0] = 1;
for (int i=1; i<=N; i++)
    for (int j=0; j<=K && j <= i * N; j++)
        for (int p=0; p<=N && p<=j; p++)
            dp[i][j] = ((long long) dp[i][j] + 1LL * dp[i - 1][j - p] * ways[i][p]) % mod;
printf ("%d\n", dp[N][K]);
return 0;
}