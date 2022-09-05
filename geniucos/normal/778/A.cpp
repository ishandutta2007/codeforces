#include<bits/stdc++.h>

using namespace std;

int N, M, p[200009], ap[200009];
char a[200009], b[200009];

bool ok (int l)
{
    for (int i=1; i<=N; i++)
        ap[i] = 0;
    for (int i=1; i<=l; i++)
        ap[p[i]] = 1;
    int j = 1;
    for (int i=1; i<=M; i++)
    {
        while (j <= N && (a[j] != b[i] || ap[j] == 1)) j ++;
        if (j > N || a[j] != b[i] || ap[j] == 1) return 0;
        j ++;
    }
    return 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (a + 1), N = strlen (a + 1);
gets (b + 1), M = strlen (b + 1);
for (int i=1; i<=N; i++)
    scanf ("%d", &p[i]);
//printf ("%d\n", ok (3));
//return 0;
int p = 0, u = N, mij, ras = -1;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (ok (mij)) ras = mij, p = mij + 1;
    else u = mij - 1;
}
printf ("%d\n", ras);
return 0;
}