#include<bits/stdc++.h>

using namespace std;

int INF = 1000000, ans, N, a[1009], dp[1009][300], nxt[20][1009], frst[1009][10], ap[10];

int moveK (int i, int nr)
{
    for (int j=0; (1<<j) <= nr; j++)
        if (nr & (1 << j)) i = nxt[j][i];
    return i;
}

bool ok (int L)
{
    ///dp[i][j] in [i, N] sa fi colorat tot din j(masca)
    dp[N + 1][0] = 0;
    for (int i=1; i<256; i++)
        dp[N + 1][i] = -INF;
    for (int i=N; i>=1; i--)
        for (int j=1; j<256; j++)
        {
            dp[i][j] = dp[i + 1][j];
            for (int k=0; k<8; k++)
                if (j & (1 << k))
                {
                    int p = frst[i][k], q = moveK (p, L - 1), q2 = moveK (p, L);
                    if (q == 0) continue;
//                    if (dp[q][j ^ (1 << k)] >= 0) printf ("(%d, %d) merge pentru ca %d\n", i, j, k);
                    if (q != 0) dp[i][j] = max (dp[q + 1][j ^ (1 << k)] + L, dp[i][j]);
                    if (q2 != 0) dp[i][j] = max (dp[q2 + 1][j ^ (1 << k)] + L + 1, dp[i][j]);
                }
        }
    if (dp[1][255] > ans)
        ans = dp[1][255];
    if (dp[1][255] < 0) return 0;
    return 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

/*int N, ans = 0, curr = 1;
scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    int x, sc = 0;
    scanf ("%d", &x), sc = (x - 1) / curr;
    ans += sc, x -= sc * curr, curr = max (curr, x + 1);
}
printf ("%d\n", ans);*/
scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &a[i]), a[i] --;
    if (!ap[a[i]])
        ap[a[i]] = 1, ans ++;
}
for (int i=0; i<8; i++)
    ap[i] = 0;
for (int i=N; i>=1; i--)
{
    nxt[0][i] = ap[a[i]];
    ap[a[i]] = i;
}
for (int i=1; (1 << i) <= N; i++)
    for (int j=1; j<=N; j++)
        nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
for (int i=N; i>=1; i--)
{
    for (int j=0; j<8; j++)
        frst[i][j] = frst[i + 1][j];
    frst[i][a[i]] = i;
}
int p = 1, u = N / 8, mij, ras;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (!ok (mij)) u = mij - 1;
    else p = mij + 1;
}
printf ("%d\n", ans);
return 0;
}