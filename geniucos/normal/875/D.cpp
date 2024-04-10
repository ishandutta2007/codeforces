#include<bits/stdc++.h>

using namespace std;

int N, x[200009], rmq[18][200009], ma[18][200009], lg[200009];
long long ans;

int getOr (int i, int j)
{
    int p = lg[j - i + 1];
    return (rmq[p][i] | rmq[p][j - (1 << p) + 1]);
}

int getMa (int i, int j)
{
    int p = lg[j - i + 1];
    return max (ma[p][i], ma[p][j - (1 << p) + 1]);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &x[i]), rmq[0][i] = x[i], ma[0][i] = x[i];
for (int i=1; i<=N; i++)
{
    lg[i] = lg[i - 1];
    if ((2 << lg[i]) <= i) lg[i] ++;
}
for (int i=1; i<=lg[N]; i++)
    for (int j=1; j + (1 << i) - 1 <= N; j++)
        rmq[i][j] = rmq[i - 1][j] | rmq[i - 1][j + (1 << (i - 1))],
        ma[i][j] = max (ma[i - 1][j], ma[i - 1][j + (1 << (i - 1))]);
for (int i=1; i<=N; i++)
{
    int p = i, u = N, mij, rgt2 = i, lft1, lft2, rgt1;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (getMa (i, mij) <= x[i]) rgt2 = mij, p = mij + 1;
        else u = mij - 1;
    }
    p = 1, u = i - 1, lft1 = i;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (getMa (mij, i - 1) < x[i]) lft1 = mij, u = mij - 1;
        else p = mij + 1;
    }
    p = i, u = rgt2, rgt1 = i;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (getOr (i, mij) == x[i]) rgt1 = mij, p = mij + 1;
        else u = mij - 1;
    }
    p = lft1, u = i - 1, lft2 = i;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (getOr (mij, i) == x[i]) lft2 = mij, u = mij - 1;
        else p = mij + 1;
    }
    ans += 1LL * (rgt2 - i + 1) * (i - lft1 + 1) - 1LL * (rgt1 - i + 1) * (i - lft2 + 1);
}
printf ("%I64d\n", ans);
return 0;
}