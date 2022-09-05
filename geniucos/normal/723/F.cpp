#include<bits/stdc++.h>

using namespace std;

int nr, S, T, limS, limT, N, M, ap[200009], fir[200009], sec[200009];
char msk[200009];
bool Found;
vector < int > v[200009];
vector < pair < int, int > > edges;

void dfs (int nod)
{
    ap[nod] = nr;
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (ap[*it] == 0)
            dfs (*it), edges.push_back (make_pair (nod, *it));
}

void No ()
{
    printf ("No\n");
    exit (0);
}

void Print ()
{
    printf ("Yes\n");
    for (auto it = edges.begin (); it != edges.end (); it ++)
        printf ("%d %d\n", it->first, it->second);
}

void ConS (int i)
{
    edges.push_back (make_pair (S, fir[i])), limS --;
}

void ConT (int i)
{
    edges.push_back (make_pair (sec[i], T)), limT --;
}

void Connect_SorT ()
{
    for (int i=1; i<=nr; i++)
    {
        if (msk[i] == 0) No ();
        if (msk[i] == 1)
        {
            if (limS == 0) No ();
            ConS (i);
            continue;
        }
        if (msk[i] == 2)
        {
            if (limT == 0) No ();
            ConT (i);
            continue;
        }
    }
}

void Connect_SwithT ()
{
    for (int i=1; i<=N; i++)
        if (msk[i] == 3)
        {
            if (limS == 0 || limT ==0) No ();
            msk[i] = 0, ConS (i), ConT (i);
            return ;
        }
    if (Found)
    {
        if (limS == 0 || limT == 0) No ();
        edges.push_back (make_pair (S, T)), limS --, limT --;
    }
    else No ();
}

void Connect_SandT ()
{
    for (int i=1; i<=nr; i++)
    if (msk[i] == 3)
    {
        if (limS) ConS (i);
        else
        if (limT) ConT (i);
        else No ();
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=M; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
scanf ("%d %d %d %d", &S, &T, &limS, &limT), Found = 0, ap[S] = ap[T] = -1;
for (auto it = v[S].begin (); it != v[S].end (); it ++)
    if (*it == T) Found = 1;
for (int i=1; i<=N; i++)
    if (ap[i] == 0)
        nr ++, dfs (i);
for (auto it = v[S].begin (); it != v[S].end (); it ++)
    if (*it != T) msk[ap[*it]] |= 1, fir[ap[*it]] = *it;
for (auto it = v[T].begin (); it != v[T].end (); it ++)
    if (*it != S) msk[ap[*it]] |= 2, sec[ap[*it]] = *it;
Connect_SorT ();
Connect_SwithT ();
Connect_SandT ();
Print ();
return 0;
}