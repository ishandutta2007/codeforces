#include<bits/stdc++.h>

using namespace std;

int ans, l, N, INF, str2, dp[200009], msk[200009], nxt[200009], s[200009], str[21][(1 << 20) + 5];
char sir[30];

int getD (int m1, int m2)
{
    for (int i=l; i>0; i--)
        if ((m1 >> (l - i)) == (m2 & ((1 << i) - 1)))
            return i;
    return 0;
}

void push (int j)
{
    for (int k=0; k<=l; k++)
    {
        int curr = (msk[j] >> (l - k));
        str[k][curr] = min (str[k][curr], dp[j] - s[j] + l - k);
    }
    str2 = min (str2, dp[j] - s[j]);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N), INF = 1e9;
for (int i=1; i<=N; i++)
{
    gets (sir), l = strlen (sir);
    for (int j=0; j<l; j++)
        if (sir[j] == '1')
            msk[i] |= 1 << j;
}
if (N == 1)
{
    printf ("%d\n", l);
    return 0;
}
for (int i=0; i<=l; i++)
    for (int j=0; j<(1 << l); j++)
        str[i][j] = INF;
ans = l, str2 = INF;
for (int i=1; i<N; i++)
{
    nxt[i] = l - getD (msk[i], msk[i + 1]);
    s[i] = s[i - 1] + nxt[i], ans += nxt[i];
}
dp[1] = 2 * l;
for (int i=2; i<=N; i++)
{
    push (i - 1), dp[i] = INF;
    if (i + 1 <= N)
    {
        for (int j=0; j<=l; j++)
            dp[i] = min (dp[i], str[j][msk[i + 1] & ((1 << j) - 1)] + s[i - 1]);
        dp[i] = min (dp[i], s[i - 1] + 2 * l);
    }
    else
        dp[i] = min (dp[i], str2 + s[i - 1]);
}
if (dp[N] < ans)
    ans = dp[N];
printf ("%d\n", ans);
return 0;
}