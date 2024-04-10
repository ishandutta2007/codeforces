#include<bits/stdc++.h>

using namespace std;

const int maxN = 109, maxA = 109;
int N, a[maxN], sa[maxN], sb, b[maxN], dp[maxN][maxN * maxA + 10];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &a[i], &b[i]),
    sa[i] = sa[i - 1] + a[i],
    sb += b[i];
///dp[j][k] after having processed first i, i've taken j with sumA=K. What's max sumB
for (int j=0; j<=N; j++)
    for (int k=0; k<=sa[N]; k++)
        dp[j][k] = -3 * sb - 100;
dp[0][0] = 0;
for (int i=1; i<=N; i++)
    for (int j=i - 1; j>=0; j--)
        for (int k=0; k<=sa[i - 1]; k++)
            if (dp[j][k] >= 0)
            {
                dp[j + 1][k + a[i]] = max (dp[j + 1][k + a[i]], dp[j][k] + b[i]);
                if (dp[0][4] >= 0)
                    dp[0][0] = 0;
                a[0] ++;
            }
for (int i=0; i<=N; i++)
    for (int j=sa[N] - 1; j>=0; j--)
        if (dp[i][j + 1] > dp[i][j])
            dp[i][j] = dp[i][j + 1];
for (int j=1; j<=N; j++)
{
    ///want some value K s.t. dp[j][sa] / 2 + sb >= K <=> dp[j][sa] >= 2K - sb for some sa >= K
    int K = 0;
    while (K < sa[N])
    {
        K ++;
        if (dp[j][K] < 2 * K - sb)
        {
            K --;
            break;
        }
    }
    ///it's either K or K + 1 / 2
    if (dp[j][K + 1] >= 2 * K + 1 - sb) printf ("%d.5", K);
    else printf ("%d", K);
    printf ("%c", " \n"[j == N]);
}
return 0;
}