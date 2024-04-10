#include<bits/stdc++.h>

using namespace std;

int N, M, realCount[300009], cnt[300009], dp[300009], a[300009], cr[300009], nonZeroBit[500], nrb[500], prod[500];
bool canDo[300009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), M = 0;
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), M = max (M, a[i]), dp[a[i]] = 1;
for (int i=2; i<=M; i++)
    if (cr[i] == 0)
        for (int j=i + i; j<=M; j+=i)
            cr[j] = i;
for (int i=2; i<=M; i++)
    if (cr[i] == 0)
        cr[i] = i;
for (int i=1; i<256; i++)
{
    for (int j=0; j<8; j++)
        if (i & (1 << j))
        {
            nonZeroBit[i] = j;
            break;
        }
    nrb[i] = nrb[i >> 1] ^ (i & 1);
}
prod[0] = 1;
for (int i=1; i<=N; i++)
{
    int aux = a[i], p[10], nr = 0;
    while (aux != 1)
    {
        int pr = cr[aux];
        while (aux % pr == 0) aux /= pr;
        p[nr ++] = pr;
    }
    for (int msk = 1; msk < (1 << nr); msk ++)
    {
        int bit = nonZeroBit[msk];
        prod[msk] = prod[msk ^ (1 << bit)] * p[bit];
        if (nrb[msk]) cnt[prod[msk]] ++;
        else cnt[prod[msk]] --;
    }
}
for (int i=1; i<=M; i++)
    for (int j=i; j<=M; j+=i)
        realCount[j] += cnt[i];
/*for (int i=1; i<=M; i++)
    printf ("%d\n", realCount[i]);*/
for (int i=2; i<=M; i++)
    canDo[i] = (realCount[i] != N);
canDo[1] = 1;
for (int i=M; i>=1; i--)
{
    if (dp[i] == 0)
        dp[i] = -1;
    for (int j=2; i * j <= M; j++)
        if (canDo[j] == 1 && dp[i * j] != -1 && (dp[i] == -1 || 1 + dp[i * j] < dp[i]))
            dp[i] = 1 + dp[i * j];
}
printf ("%d\n", dp[1]);
return 0;
}