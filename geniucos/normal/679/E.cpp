#include<bits/stdc++.h>

using namespace std;

int nr, N, Q, a[100009];
long long put[50], full[280009], mi[280009], dl[280009];
bool OnceAgain;

long long FirstBigger (long long val)
{
    int p = 0, u = nr, mij, ras;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (put[mij] >= val) ras = mij, u = mij - 1;
        else p = mij + 1;
    }
    return put[ras] - val;
}

void split (int nod)
{
    int f1 = nod << 1, f2 = f1 | 1;
    if (full[nod] != 0)
    {
        mi[f1] = mi[f2] = mi[nod];
        full[f1] = full[f2] = full[nod];
        dl[f1] = dl[f2] = dl[nod];
        full[nod] = dl[nod] = 0;
        return ;
    }
    if (dl[nod] != 0)
    {
        dl[f1] += dl[nod], dl[f2] += dl[nod];
        mi[f1] -= dl[nod], mi[f2] -= dl[nod];
        dl[nod] = 0;
    }
}

void build (int nod, int st, int dr)
{
    if (st == dr)
    {
        full[nod] = a[st];
        mi[nod] = FirstBigger (a[st]);
        return ;
    }
    int mij = (st + dr) >> 1;
    build (nod << 1, st, mij);
    build (nod << 1 | 1, mij + 1, dr);
    mi[nod] = min (mi[nod << 1], mi[nod << 1 | 1]);
}

void Update1 (int nod, int st, int dr, int x, int y, long long val)
{
    if (x <= st && dr <= y)
    {
        dl[nod] = 0, full[nod] = val;
        mi[nod] = FirstBigger (val);
        return ;
    }
    int mij = (st + dr) >> 1;
    split (nod);
    if (x <= mij) Update1 (nod << 1, st, mij, x, y, val);
    if (mij < y) Update1 (nod << 1 | 1, mij + 1, dr, x, y, val);
    mi[nod] = min (mi[nod << 1], mi[nod << 1 | 1]);
}

void RepairDown (int nod, int st, int dr)
{
    if (st == dr || full[nod] != 0)
    {
        full[nod] += dl[nod], mi[nod] = FirstBigger (full[nod]), dl[nod] = 0;
        if (mi[nod] == 0) OnceAgain = 1;
        return ;
    }
    int mij = (st + dr) >> 1;
    split (nod);
    if (mi[nod << 1] <= 0) RepairDown (nod << 1, st, mij);
    if (mi[nod << 1 | 1] <= 0) RepairDown (nod << 1 | 1, mij + 1, dr);
    mi[nod] = min (mi[nod << 1], mi[nod << 1 | 1]);
}

void Update2 (int nod, int st, int dr, int x, int y, long long ad)
{
    if (x <= st && dr <= y)
    {
        dl[nod] += ad, mi[nod] -= ad;
        if (mi[nod] <= 0)
            RepairDown (nod, st, dr);
        return ;
    }
    int mij = (st + dr) >> 1;
    split (nod);
    if (x <= mij) Update2 (nod << 1, st, mij, x, y, ad);
    if (mij < y) Update2 (nod << 1 | 1, mij + 1, dr, x, y, ad);
    mi[nod] = min (mi[nod << 1], mi[nod << 1 | 1]);
}

void Query (int nod, int st, int dr, int pos)
{
    if (st == dr)
    {
        printf ("%I64d\n", full[nod] + dl[nod]);
        return ;
    }
    int mij = (st + dr) >> 1;
    split (nod);
    if (pos <= mij) Query (nod << 1, st, mij, pos);
    else Query (nod << 1 | 1, mij + 1, dr, pos);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &Q), put[0] = 1;
for (int i=1; i <= 11; i++)
    put[i] = 42LL * put[i - 1], nr = i;
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
build (1, 1, N);
while (Q --)
{
/*    printf ("Array:\n");
    for (int i=1; i<=N; i++)
        Query (1, 1, N, i);
    printf ("\n\n");*/
    int type;
    scanf ("%d", &type);
    if (type == 1)
    {
        int pos;
        scanf ("%d", &pos);
        Query (1, 1, N, pos);
        continue;
    }
    if (type == 2)
    {
        int st, dr, val;
        scanf ("%d %d %d", &st, &dr, &val);
        Update1 (1, 1, N, st, dr, val);
        continue;
    }
    int st, dr, ad;
    scanf ("%d %d %d", &st, &dr, &ad);
    while (1)
    {
        OnceAgain = 0, Update2 (1, 1, N, st, dr, ad);
        if (!OnceAgain) break;
    }
}
return 0;
}