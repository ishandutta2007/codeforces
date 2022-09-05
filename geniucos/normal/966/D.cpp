#include<bits/stdc++.h>

using namespace std;

int N, M, nr, cnt, edges = 0, d[300009], how[300009], d2[300009], how2[300009], ap[300009];
vector < int > v[300009], comp;
queue < int > cc;

void dfs (int nod)
{
    ap[nod] = nr, cnt ++, edges += v[nod].size ();
    comp.push_back (nod);
    for (auto it : v[nod])
        if (ap[it] == 0)
            dfs (it);
}

void bfs ()
{
    for (int i=2; i<=N; i++)
        d[i] = -1;
    cc.push (1), d[1] = 0;
    while (!cc.empty ())
    {
        int nod = cc.front ();
        cc.pop ();
        for (auto it : v[nod])
            if (d[it] == -1)
                d[it] = d[nod] + 1, how[it] = nod, cc.push (it);
    }
    if (d[N] <= 3 && d[N] != -1)
    {
        vector < int > path;
        int aux = N;
        while (aux != 1)
            path.push_back (aux), aux = how[aux];
        path.push_back (1);
        printf ("%d\n", d[N]);
        for (auto it = path.rbegin (); it != path.rend (); it ++)
            printf ("%d ", *it);
        printf ("\n");
        exit (0);
    }
}

void finish ()
{
    int source = -1;
    for (auto it : comp)
        if (v[it].size () != cnt)
            source = it;
    for (int i=1; i<=N; i++)
        d2[i] = -1;
    cc.push (source), d2[source] = 0, d2[1] = 0;
    while (!cc.empty ())
    {
        int nod = cc.front ();
        cc.pop ();
        for (auto it : v[nod])
            if (d2[it] == -1)
                d2[it] = d2[nod] + 1, how2[it] = nod, cc.push (it);
    }
    for (auto it : comp)
        if (d2[it] == 2)
        {
            printf ("5\n1 %d %d %d %d %d\n", source, how2[it], it, source, N);
            exit (0);
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
    if (x > y) swap (x, y);
    if (x == 1 && y == N)
    {
        printf ("1\n1 %d\n", N);
        return 0;
    }
    v[x].push_back (y);
    v[y].push_back (x);
}
cnt = 0, nr = 1, dfs (1);
cnt --;///delete 1
bfs ();
if (cnt != v[1].size ())
{
    for (int i=2; i<=N; i++)
        if (d[i] == 2)
        {
            printf ("4\n1 %d %d 1 %d\n", how[i], i, N);
            return 0;
        }
    return 0;
}
for (int i=1; i<=N; i++)
    ap[i] = 0;
ap[1] = -1;
for (int i=2; i<=N; i++)
    if (d[i] == 1 && ap[i] == 0)
    {
        edges = 0, nr ++, cnt = 0, comp.clear ();
        dfs (i);
        if (edges != 1LL * cnt * cnt)
        {
            finish ();
            return 0;
        }
    }
printf ("-1\n");
return 0;
}