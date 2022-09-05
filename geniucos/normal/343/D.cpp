#include<bits/stdc++.h>

using namespace std;

int N, M, nr, ansHard, ansEasy, aint[2000016], lazy[2000016], pos[500009], dr[500009];
vector < int > v[500009];

void UpdateEasy (int nod, int st, int dr, int pos, int val)
{
    if (st == dr)
    {
        aint[nod] = max (aint[nod], val);
        return ;
    }
    int mij = (st + dr) >> 1;
    if (pos <= mij) UpdateEasy (nod << 1, st, mij, pos, val);
    else UpdateEasy (nod << 1 | 1, mij + 1, dr, pos, val);
    aint[nod] = max (aint[nod * 2], aint[nod * 2 + 1]);
}

void QueryEasy (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        if (aint[nod] > ansEasy) ansEasy = aint[nod];
        return ;
    }
    int mij = (st + dr) >> 1;
    if (x <= mij) QueryEasy (nod << 1, st, mij, x, y);
    if (mij < y) QueryEasy (nod << 1 | 1, mij + 1, dr, x, y);
}

void split (int nod)
{
    if (lazy[nod] == 0) return ;
    lazy[nod << 1] = lazy[nod << 1 | 1] = lazy[nod], lazy[nod] = 0;
}

void UpdateHard (int nod, int st, int dr, int x, int y, int val)
{
    if (x <= st && dr <= y)
    {
        lazy[nod] = val;
        return ;
    }
    split (nod);
    int mij = (st + dr) >> 1;
    if (x <= mij) UpdateHard (nod << 1, st, mij, x, y, val);
    if (mij < y) UpdateHard (nod << 1 | 1, mij + 1, dr, x, y, val);
}

void QueryHard (int nod, int st, int dr, int pos)
{
    if (st == dr)
    {
        ansHard = lazy[nod];
        return ;
    }
    split (nod);
    int mij = (st + dr) >> 1;
    if (pos <= mij) QueryHard (nod << 1, st, mij, pos);
    else QueryHard (nod << 1 | 1, mij + 1, dr, pos);
}

void dfs (int nod, int tata)
{
    pos[nod] = ++nr;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (*it != tata) dfs (*it, nod);
    dr[nod] = nr;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
dfs (1, -1);
scanf ("%d", &M);
for (int i=1; i<=M; i++)
{
    int type, X;
    scanf ("%d %d", &type, &X);
    if (type == 1)
    {
        UpdateHard (1, 1, N, pos[X], dr[X], i);
        continue;
    }
    if (type == 2)
    {
        UpdateEasy (1, 1, N, pos[X], i);
        continue;
    }
    ansEasy = ansHard = 0;
    QueryEasy (1, 1, N, pos[X], dr[X]), QueryHard (1, 1, N, pos[X]);
    printf ("%d\n", (ansHard > ansEasy));
}
return 0;
}