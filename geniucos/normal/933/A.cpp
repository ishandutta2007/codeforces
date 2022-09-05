#include<bits/stdc++.h>

using namespace std;

int maxi, N, dp[2], a[2018], s[2][2018];

int frq (int type, int st, int dr)
{
    return s[type][dr] - s[type][st - 1];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), a[i] --, s[a[i]][i] = s[a[i]][i - 1] + 1, s[a[i] ^ 1][i] = s[a[i] ^ 1][i - 1];
dp[0] = dp[1] = 0;
for (int i=1; i<=N; i++)
{
    bool t = a[i];
    if (t == 0) dp[t] ++;
    else dp[t] = max (dp[0], dp[1]) + 1;
}
maxi = max (dp[0], dp[1]);
for (int j=1; j<=N; j++)
{
    dp[0] = dp[1] = 0;
    for (int i=j; i>=1; i--)
    {
        bool t = a[i];
        if (t == 0) dp[t] ++;
        else dp[t] = max (dp[0], dp[1]) + 1;
        ///assume [i, j] is the reverse stuff
        int ans = max (dp[0], dp[1]) + frq (0, 1, i - 1) + frq (1, j + 1, N);
        if (ans > maxi)
            maxi = ans;
    }
}
printf ("%d\n", maxi);
return 0;
}