#include<bits/stdc++.h>

using namespace std;

int N, M, nr, ans, diam[1009], ap[1009], comp[1009], dist[1009], cc[1009];
vector < int > v[1009];

void dfs (int nod, int color)
{
    if (ap[nod] != 0 && ap[nod] != color)
    {
        printf ("-1\n");
        exit (0);
    }
    if (ap[nod] != 0) return ;
    ap[nod] = color, comp[nod] = nr;
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        dfs (*it, 3 - color);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
while (M --)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
for (int i=1; i<=N; i++)
    if (ap[i] == 0) nr ++, dfs (i, 1);
for (int i=1; i<=N; i++)
{
    cc[0] = 1, cc[1] = i, dist[i] = 1;
    for (int j=1; j<=cc[0]; j++)
        for (auto it = v[cc[j]].begin (); it != v[cc[j]].end (); it ++)
            if (dist[*it] == 0)
                cc[++cc[0]] = *it, dist[*it] = dist[cc[j]] + 1;
    int curr = dist[cc[cc[0]]] - 1;
    if (curr > diam[comp[i]]) diam[comp[i]] = curr;
    for (int j=1; j<=cc[0]; j++)
        dist[cc[j]] = 0;
}
for (int i=1; i<=nr; i++)
    ans += diam[i];
printf ("%d\n", ans);
return 0;
}