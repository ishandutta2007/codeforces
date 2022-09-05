#include<bits/stdc++.h>

using namespace std;

int ans, N, M, D, ap[30], a[100009], nrb[1 << 20];
bool dp[1 << 20];

int main ()
{
scanf ("%d %d %d", &N, &M, &D), ans = M;
for (int i=0; i<M; i++)
{
    int l, x;
    scanf ("%d", &l);
    while (l --)
        scanf ("%d", &x), a[x] = i;
}
for (int i=1; i<D; i++)
    ap[a[i]] ++;
for (int i=D; i<=N; i++)
{
    if (i > D) ap[a[i - D]] --;
    ap[a[i]] ++;
    int msk = 0;
    for (int j=0; j<M; j++)
        if (ap[j])
            msk |= 1 << j;
    dp[msk] = 1;
}
for (int i=0; i<1 << M; i++)
    if (dp[i])
        for (int j=0; j<M; j++)
            if ((i & (1 << j)) == 0)
                dp[i ^ (1 << j)] |= 1;
for (int i=0; i<1 << M; i++)
{
    nrb[i] = nrb[i >> 1] + (i & 1);
    if (dp[i] == 0 && M - nrb[i] < ans)
        ans = M - nrb[i];
}
printf ("%d\n", ans);
return 0;
}