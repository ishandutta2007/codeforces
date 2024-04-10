#include<bits/stdc++.h>

using namespace std;

int mod, N, lim[300], dp[1009], pref[1009], mi[1009], suf[1009];
char sir[1009];
bool mere[1009][1009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N), mod = 1e9 + 7;
gets (sir + 1);
for (int i='a'; i<='z'; i++)
    scanf ("%d", &lim[i]);
dp[0] = 1, pref[0] = 1;
mi[0] = 0;
for (int i=1; i<=N; i++)
{
    mi[i] = N + 2;
    int curr_lim = N + 5;
    for (int j=i; j>=1; j--)
    {
        if (lim[sir[j]] < curr_lim) curr_lim = lim[sir[j]];
        if (i - j + 1 > curr_lim) break;
        mere[j][i] = 1;
        if (pref[j - 1]) mi[i] = min (mi[i], mi[j - 1] + 1);
        dp[i] += dp[j - 1], pref[i] |= pref[j - 1];
        if (dp[i] >= mod) dp[i] -= mod;
    }
}
suf[N + 1] = 1;
for (int i=N; i>=1; i--)
    for (int j=i; j<=N; j++)
    {
        if (mere[i][j] == 0) break;
        suf[i] |= suf[j + 1];
    }
int maxi = 0;
for (int i=1; i<=N; i++)
    for (int j=i; j<=N; j++)
        if (mere[i][j] && pref[i - 1] && suf[j + 1])
        {
            int l = j - i + 1;
            maxi = max (maxi, l);
        }
printf ("%d\n%d\n%d\n", dp[N], maxi, mi[N]);
return 0;
}