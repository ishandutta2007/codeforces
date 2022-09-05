#include<bits/stdc++.h>

using namespace std;

int N, M, P, a[2017], b[2017];

int modul (int x)
{
    if (x < 0) return -x;
    return x;
}

bool ok (int lim)
{
    int j = 1;
    for (int i=1; i<=N; i++)
    {
        while (modul (a[i] - b[j]) + modul (b[j] - P) > lim && j <= M)
            j ++;
        if (j > M) return 0;
        j ++;
    }
    return 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &P);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
for (int i=1; i<=M; i++)
    scanf ("%d", &b[i]);
sort (a + 1, a + N + 1);
sort (b + 1, b + M + 1);
int p = 0, u = 2e9, mij, ras = -1;
while (p <= u)
{
    mij = p + (u - p) / 2;
    if (ok (mij)) ras = mij, u = mij - 1;
    else p = mij + 1;
}
printf ("%d\n", ras);
return 0;
}