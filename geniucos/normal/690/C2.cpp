#include<bits/stdc++.h>

using namespace std;

int nr, N, M, d[100009], q[100009];
vector < int > v[100009];

int bfs (int S)
{
    for (int i=1; i<=N; i++)
        d[i] = -1;
    nr = 1, q[1] = S, d[S] = 0;
    for (int i=1; i<=nr; i++)
        for (auto it = v[q[i]].begin (); it != v[q[i]].end (); it ++)
            if (d[*it] == -1)
                d[*it] = d[q[i]] + 1, q[++nr] = *it;
    return q[nr];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y), v[y].push_back (x);
}
int nod1 = bfs (1), nod2;
nod2 = bfs (nod1);
printf ("%d\n", d[nod2]);
return 0;
}