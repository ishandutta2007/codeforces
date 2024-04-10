#include<bits/stdc++.h>

using namespace std;

int N, M, K, Q, ansAint, aint[270009], ind[200009], a1[200009], b1[200009], a2[200009], b2[200009];
bool ans[200009];
pair < int, int > a[200009];

void Build (int nod, int st, int dr)
{
    aint[nod] = 0;
    if (st == dr) return ;
    int mij = (st + dr) >> 1;
    Build (nod << 1, st, mij);
    Build (nod << 1 | 1, mij + 1, dr);
}

void Update (int nod, int st, int dr, int pos, int val)
{
    if (st == dr)
    {
        aint[nod] = val;
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (pos <= mij) Update (f1, st, mij, pos, val);
    else Update (f2, mij + 1, dr, pos, val);
    aint[nod] = min (aint[f1], aint[f2]);
}

void Query (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        if (aint[nod] < ansAint) ansAint = aint[nod];
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (x <= mij) Query (f1, st, mij, x, y);
    if (mij < y) Query (f2, mij + 1, dr, x, y);
}

int GetMin (int st, int dr) {ansAint = M + 1, Query (1, 1, N, st, dr); return ansAint;}
bool cmp (int i, int j) {return b2[i] < b2[j];}

void Print ()
{
    for (int i=1; i<=Q; i++)
        if (ans[i]) printf ("YES\n");
        else printf ("NO\n");
}

void Rev ()
{
    swap (N, M);
    for (int i=1; i<=K; i++)
        swap (a[i].first, a[i].second);
    for (int i=1; i<=Q; i++)
        swap (a1[i], b1[i]), swap (a2[i], b2[i]);
}

void Solve ()
{
    Build (1, 1, N);
    sort (a + 1, a + K + 1);
    sort (ind + 1, ind + Q + 1, cmp);
    int j = 1;
    for (int i=1; i<=Q; i++)
    {
        while (a[j].first <= b2[ind[i]] && j <= K)
            Update (1, 1, N, a[j].second, a[j].first), j ++;
        ans[ind[i]] |= (GetMin (a1[ind[i]], a2[ind[i]]) >= b1[ind[i]]);
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d", &N, &M, &K, &Q);
for (int i=1; i<=K; i++)
    scanf ("%d %d", &a[i].second, &a[i].first);
for (int i=1; i<=Q; i++)
    scanf ("%d %d %d %d", &a1[i], &b1[i], &a2[i], &b2[i]), ind[i] = i;
Solve ();
Rev ();
Solve ();
Print ();
return 0;
}