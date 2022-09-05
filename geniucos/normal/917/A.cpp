#include<bits/stdc++.h>

using namespace std;

int ans, N, dp[5009][2], old[5009][2];
char sir[5009];
int val[] = {+1, -1};

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (sir + 1), N = strlen (sir + 1);
for (int i=1; i<=N; i++)
{
    memcpy (old, dp, sizeof (dp)), memset (dp, 0, sizeof (dp));
    if (sir[i] == '?')
    {
        for (int j=0; j<i; j++)
            for (int k=0; k<2; k++)
                if (old[j][k])
                    for (int p=k; p<2; p++)
                    {
                        int nv = j + val[p];
                        if (nv >= 0)
                            dp[nv][p] += old[j][k];
                    }
        dp[1][0] ++;
    }
    else
    {
        int nv = val[sir[i] == ')'];
        for (int j=0; j<i; j++)
            for (int k=0; k<2; k++)
                if (old[j][k])
                {
                    if (j + nv >= 0)
                        dp[j + nv][k] += old[j][k];
                }
        if (nv >= 0) dp[nv][0] ++;
    }
//    printf ("%d -> %d\n", i, dp[0][0] + dp[0][1]);
    ans += dp[0][0] + dp[0][1];
}
printf ("%d\n", ans);
return 0;
}