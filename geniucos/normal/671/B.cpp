#include<bits/stdc++.h>

using namespace std;

int N, K, a[500009];
long long s[500009];

bool ok1 (int X)
{
    int p = 1, u = N, mij, ras = 0;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (a[mij] <= X) ras = mij, p = mij + 1;
        else u = mij - 1;
    }
    return (1LL * X * ras - s[ras] <= K);
}

bool ok2 (int Y)
{
    int p = 1, u = N, mij, ras = N + 1;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (a[mij] >= Y) ras = mij, u = mij - 1;
        else p = mij + 1;
    }
    return (s[N] - s[ras - 1] - 1LL * Y * (N - ras + 1) <= K);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

/*printf ("1232 2000\n");
for (int i=1; i<=1232; i++)
    printf ("1 ");
printf ("\n");
return 0;*/

scanf ("%d %d", &N, &K);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
sort (a + 1, a + N + 1);
for (int i=1; i<=N; i++)
    s[i] = s[i - 1] + a[i];
int p = 1, u = 2e9, mij, X, Y;
while (p <= u)
{
    mij = p + (u - p) / 2;
    if (ok1 (mij)) X = mij, p = mij + 1;
    else u = mij - 1;
}
p = 1, u = 2e9;
while (p <= u)
{
    mij = p + (u - p) / 2;
    if (ok2 (mij)) Y = mij, u = mij - 1;
    else p = mij + 1;
}
//printf ("%d %d\n", X, Y);
if (X < Y) printf ("%d\n", Y - X);
else
if (s[N] % N == 0) printf ("0\n");
else printf ("1\n");
return 0;
}