#include<bits/stdc++.h>

using namespace std;

int N, Q, l, nr, *v[200009], sz[200009], a[200009], b[200009], h[200009], where[200009], x[200009];
bool ap[200009];

int FirstAfter (int val, int i)
{
    int p = 1, u = sz[val], mij, ras = 0;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (v[val][mij] >= i) ras = mij, u = mij - 1;
        else p = mij + 1;
    }
    return v[val][ras];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &a[i], &b[i]), sz[a[i]] ++;
for (int i=1; i<=N; i++)
    v[i] = new int[sz[i] + 2], sz[i] = 0;
for (int i=1; i<=N; i++)
    v[a[i]][++sz[a[i]]] = i;
for (int i=N; i>=1; i--)
    if (ap[a[i]] == 0) h[++nr] = a[i], where[nr] = i, ap[a[i]] = 1;
for (int i=1; i<=N; i++)
    ap[i] = 0;
scanf ("%d", &Q);
while (Q --)
{
    int l;
    scanf ("%d", &l);
    for (int i=1; i<=l; i++)
        scanf ("%d", &x[i]), ap[x[i]] = 1;
    int j = 0;
    for (int i=1; i<=nr; i++)
        if (ap[h[i]] == 0)
        {
            j = i;
            break;
        }
    if (j == 0) printf ("0 0\n");
    else
    {
        int k = j + 1;
        while (k <= nr && ap[h[k]]) k ++;
        if (k > nr) j = v[h[j]][1];
        else j = FirstAfter (h[j], where[k]);
        printf ("%d %d\n", a[j], b[j]);
    }
    for (int i=1; i<=l; i++)
        ap[x[i]] = 0;
}
return 0;
}