#include<bits/stdc++.h>

using namespace std;

int atLeastOnce, N, K, T, cost[25][25], order[25], lst[25], extra[25], last[25], dp[1 << 22];
char sir[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d\n", &N, &K, &T);
gets (sir + 1), atLeastOnce = 0;
for (int i=1; i<=N; i++)
    sir[i] -= 'A', atLeastOnce |= 1 << sir[i];
for (int i=0; i<K; i++)
    scanf ("%d", &extra[i]);
for (int i=0; i<K; i++)
    for (int j=0; j<K; j++)
        scanf ("%d", &cost[i][j]);
int nr = 0;
for (int i=1; i<=N; i++)
{
    int msk = 0;
    for (int j=nr; j>=1; j--)
    {
        int curr = cost[order[j]][sir[i]];
        //printf ("%d (%d %d) -> %d when at %d\n", msk, order[j], sir[i], curr, i);
        if (order[j] == sir[i])
        {
            dp[msk] += curr, dp[msk | (1 << sir[i])] -= curr;
            break;
        }
        else
        {
            int x = order[j], y = sir[i];
            dp[msk] += curr, dp[msk | (1 << x) | (1 << y)] += curr;
            dp[msk | (1 << x)] -= curr, dp[msk | (1 << y)] -= curr;
        }
        msk |= 1 << order[j];
    }
    ///prepare for the next step
    bool already = 0;
    for (int j=1; j<=nr; j++)
    {
        if (order[j] == sir[i]) already = 1;
        if (already) order[j] = order[j + 1];
    }
    if (already) order[nr] = sir[i];
    else order[++nr] = sir[i];
    last[sir[i]] = i;
}
/*for (int i=0; i<1 << K; i++)
    printf ("%2d%c", i, " \n"[i == (1 << K) - 1]);
for (int i=0; i<1 << K; i++)
    printf ("%2d%c", dp[i], " \n"[i == (1 << K) - 1]);*/
for (int i=0; i<K; i++)
    for (int j=0; j<1 << K; j++)
        if ((j >> i) & 1)
            dp[j] += dp[j ^ (1 << i)];
/*for (int i=0; i<1 << K; i++)
    printf ("%2d%c", dp[i], " \n"[i == (1 << K) - 1]);*/
int ans = 0;
for (int i=0; i<atLeastOnce; i++)
if ((i & atLeastOnce) == i)
{
    for (int j=0; j<K; j++)
        if ((i >> j) & 1)
            dp[i] += extra[j];
    /*for (int j=1; j<=N; j++)
        if (i & (1 << sir[j])) ;
        else printf ("%c", sir[j] + 'A');
    printf (" -> %d\n", dp[i]);*/
    ans += (dp[i] <= T);
}
printf ("%d\n", ans);
return 0;
}