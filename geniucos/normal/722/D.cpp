#include<bits/stdc++.h>

using namespace std;

int N, a[50009], b[50009];
set < int > S;

bool ok (int maxi)
{
    S.clear ();
    for (int i=1; i<=N; i++)
    {
        int aux = a[i];
        while (aux > maxi) aux /= 2;
        while (S.find (aux) != S.end ()) aux /= 2;
        if (aux == 0) return 0;
        b[i] = aux, S.insert (aux);
    }
    return 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
sort (a + 1, a + N + 1);
int p = N, u = a[N], mij, ras;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (ok (mij)) ras = mij, u = mij - 1;
    else p = mij + 1;
}
ok (ras);
for (int i=1; i<=N; i++)
    printf ("%d ", b[i]);
printf ("\n");
return 0;
}