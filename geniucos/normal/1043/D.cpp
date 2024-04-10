#include<bits/stdc++.h>

using namespace std;

int N, M, dp[100009], a[15][100009], pos[15][100009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=0; i<M; i++)
    for (int j=1; j<=N; j++)
        scanf ("%d", &a[i][j]), pos[i][a[i][j]] = j;
dp[N] = 1;
long long ans = 1;
for (int i=N - 1; i>=1; i--)
{
    int nxt = a[0][i + 1];
    bool ok = 1;
    for (int j=1; j<M; j++)
        if (a[j][pos[j][a[0][i]] + 1] != nxt)
        {
            ok = 0;
            break;
        }
    if (!ok) dp[i] = 1;
    else dp[i] = dp[i + 1] + 1;
    ans += dp[i];
}
printf ("%I64d\n", ans);
return 0;
}