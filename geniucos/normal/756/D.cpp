#include<bits/stdc++.h>

using namespace std;

int nr, ans, mod, N, lst[40], dp[5009][5009], c[5009][5009], b[5009];
char sir[5009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N), mod = 1e9 + 7;
gets (sir + 1);
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
    if (i == 1 || sir[i] != sir[i - 1])
        b[++nr] = sir[i] - '0';
b[++nr] = 30;
for (int i=1; i<=nr; i++)
    dp[1][i] = 1;
for (int i=2; i<=nr; i++)
{
    for (int j=1; j<=nr; j++)
        lst[b[j]] = 0;
    int curr = 0;
    for (int j=1; j<=nr; j++)
    {
        ///suma de dp[i - 1][k] cu k ultima aparitie a vreunuia
        if (j > 1)
        {
            if (lst[b[j - 1]] != 0)
            {
                curr -= dp[i - 1][lst[b[j - 1]]];
                if (curr < 0) curr += mod;
            }
            lst[b[j - 1]] = j - 1;
            curr += dp[i - 1][j - 1];
            if (curr >= mod) curr -= mod;
        }
        dp[i][j] = curr;
        if (lst[b[j]] != 0)
        {
            dp[i][j] -= dp[i - 1][lst[b[j]]];
            if (dp[i][j] < 0) dp[i][j] += mod;
        }
    }
//    printf ("%d -> %d\n", i - 1, dp[i][nr]);
    ///am dp[i][nr + 1] subsecvente diferite de lungime i - 1
    ans = ((long long) ans + 1LL * dp[i][nr] * c[N - 1][i - 2]) % mod;
}
printf ("%d\n", ans);
return 0;
}