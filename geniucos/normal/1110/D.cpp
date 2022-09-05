#include<bits/stdc++.h>

using namespace std;

int N, M, cnt[1000009], dp[1000009][3][3];
const int INF = 1e9;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
{
    int x;
    scanf ("%d", &x);
    cnt[x] ++;
}
if (M <= 2)
{
    printf ("%d\n", (cnt[1] / 3) + (cnt[2] / 3));
    return 0;
}
int ans = 0;
for (int i=1; i<=M; i++)
    ans += (cnt[i] / 3);
for (int i=1; i<=M; i++)
    for (int j=0; j<=2; j++)
        for (int k=0; k<=2; k++)
            dp[i][j][k] = -INF;
for (int j=0; j<=2; j++)
    for (int k=0; k<=2; k++)
        if (j <= cnt[1] && j + k <= cnt[2] && j + k <= cnt[3])
            dp[3][j][k] = j + k + (cnt[1] - j) / 3 + (cnt[2] - j - k) / 3;
        else
            dp[3][j][k] = -INF;
for (int i=3; i<=M - 1; i++)
    for (int j=0; j<=2; j++)
        for (int k=0; k<=2; k++)
            if (dp[i][j][k] >= 0)
                for (int p=0; p<=2; p++)
                    if (j + k + p <= cnt[i])
                        dp[i + 1][k][p] = max (dp[i + 1][k][p], p + dp[i][j][k] + (cnt[i] - j - k - p) / 3);
for (int j=0; j<3; j++)
    if (j <= cnt[M])
        ans = max (ans, dp[M][j][0] + (cnt[M] - j) / 3);
printf ("%d\n", ans);
return 0;
}