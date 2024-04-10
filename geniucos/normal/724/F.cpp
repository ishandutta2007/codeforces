#include<bits/stdc++.h>

using namespace std;

int N, d, mod, inv[12], dp[1009][1009][12];

int pow (int a, int b)
{
    int p = 1;
    for (int i=0; (1 << i) <= b; i++)
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

scanf ("%d %d %d", &N, &d, &mod);
if (N <= 2)
{
    printf ("1\n");
    return 0;
}
for (int i=0; i<=N; i++)
    dp[1][i][0] = dp[1][i][d - 1] = 1;
for (int i=1; i<=10; i++)
    inv[i] = pow (i, mod - 2);
for (int i=1; i<=N; i++)
    for (int k=1; k<=d; k++)
    {
        if ((i - k - 1) % (d - 1) != 0) continue;
        for (int j=1; j<=N; j++)
        {
            dp[i][j][k] = dp[i][j - 1][k];
            if (j > i) continue;
            int val = dp[j][j][d - 1], curr = 1;
            for (int p=1; p<=k && j * p <= i; p++)
            {
                curr = (1LL * curr * (val + p - 1)) % mod;
                curr = (1LL * curr * inv[p]) % mod;
                dp[i][j][k] = ((long long) dp[i][j][k] + 1LL * curr * dp[i - j * p][j - 1][k - p]) % mod;
            }
        }
    }
int ans = dp[N][N / 2][d];
if (N % 2 == 0)
{
    ans = dp[N][N / 2 - 1][d];
    int val = dp[N / 2][N / 2][d - 1];
    val = (1LL * val * (val + 1)) % mod;
    val = (1LL * val * inv[2]) % mod;
    ans += val;
    if (ans >= mod) ans -= mod;
}
printf ("%d\n", ans);
return 0;
}