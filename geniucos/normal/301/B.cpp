#include<bits/stdc++.h>

using namespace std;

int N, D, x[109], y[109], a[109], dist[109][109];

bool ok (int Init)
{
    int Max[109];
    for (int i=1; i<=N; i++)
        Max[i] = -1e8;
    Max[1] = Init;
    int steps = N;
    while (steps --)
    {
        for (int i=1; i<=N; i++)
            for (int j=1; j<=N; j++)
                if (i != j && Max[i] + a[j] - dist[i][j] * D > Max[j] && Max[i] >= dist[i][j] * D)
                    Max[j] = Max[i] + a[j] - dist[i][j] * D;
    }
    return (Max[N] >= 0);
}

int modul (int x)
{
    if (x < 0) return -x;
    return x;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &D);
for (int i=2; i<N; i++)
    scanf ("%d", &a[i]);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &x[i], &y[i]);
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        dist[i][j] = modul (x[i] - x[j]) + modul (y[i] - y[j]);
int p = 0, u = 4e7, mij, ras;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (ok (mij)) ras = mij, u = mij - 1;
    else p = mij + 1;
}
printf ("%d\n", ras);
return 0;
}