#include<bits/stdc++.h>

using namespace std;

int N, M, type[100009];
int aint[800009], lzy[800009];
long long realVal[200009], st[100009], dr[100009];

void read ()
{
    vector < long long > norm;
    scanf ("%d", &N), norm.push_back (1);
    for (int i=1; i<=N; i++)
        scanf ("%d %I64d %I64d", &type[i], &st[i], &dr[i]), norm.push_back (st[i]), norm.push_back (dr[i] + 1);
    sort (norm.begin (), norm.end ());
    norm.erase (unique (norm.begin (), norm.end ()), norm.end ()), M = norm.size ();
    for (int i=0; i<norm.size (); i++)
        realVal[i + 1] = norm[i];
    for (int i=1; i<=N; i++)
    {
        st[i] = lower_bound (norm.begin (), norm.end (), st[i]) - norm.begin () + 1;
        dr[i] = upper_bound (norm.begin (), norm.end (), dr[i]) - norm.begin ();
    }
}

void split (int nod, int st, int dr)
{
    if (lzy[nod] == 0) return ;
    int t = lzy[nod], f1 = nod << 1, f2 = f1 | 1, mij = (st + dr) >> 1;
    if (t <= 2)
        lzy[f1] = lzy[f2] = t, aint[f1] = (mij - st + 1) * (t - 1), aint[f2] = (dr - mij) * (t - 1);
    else
        lzy[f1] = 3 - lzy[f1], lzy[f2] = 3 - lzy[f2], aint[f1] = mij - st + 1 - aint[f1], aint[f2] = dr - mij - aint[f2];
    lzy[nod] = 0;
}

void UpdateSegm (int nod, int st, int dr, int x, int y, int val)
{
    if (x <= st && dr <= y)
    {
        if (val <= 2) lzy[nod] = val, aint[nod] = (val - 1) * (dr - st + 1);
        else lzy[nod] = 3 - lzy[nod], aint[nod] = dr - st + 1 - aint[nod];
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    split (nod, st, dr);
    if (x <= mij) UpdateSegm (f1, st, mij, x, y, val);
    if (mij < y) UpdateSegm (f2, mij + 1, dr, x, y, val);
    aint[nod] = aint[f1] + aint[f2];
}

void Query (int nod, int st, int dr)
{
    if (st == dr)
    {
        printf ("%I64d\n", realVal[st]);
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    split (nod, st, dr);
    if (aint[f1] == mij - st + 1) Query (f2, mij + 1, dr);
    else Query (f1, st, mij);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

read ();
for (int i=1; i<=N; i++)
{
    if (type[i] <= 2) UpdateSegm (1, 1, M, st[i], dr[i], 3 - type[i]);
    else UpdateSegm (1, 1, M, st[i], dr[i], 3);
    Query (1, 1, M);
}

return 0;
}