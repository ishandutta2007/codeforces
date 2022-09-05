#include<bits/stdc++.h>

using namespace std;

const int maxN = 100009;
int N, lev[maxN];
vector < int > v[maxN];

void dfs (int nod, int tata)
{
    for (auto it : v[nod])
        if (it != tata)
            lev[it] = lev[nod] + 1, dfs (it, nod);
}
int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    int a, b, da, db;
    scanf ("%d %d %d %d %d", &N, &a, &b, &da, &db);
    for (int i=1; i<N; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        v[x].push_back (y);
        v[y].push_back (x);
    }
    lev[a] = 0, dfs (a, -1);
    int d = lev[b], x = 1;
    for (int i=1; i<=N; i++)
        if (lev[i] > lev[x])
            x = i;
    lev[x] = 0, dfs (x, -1);
    int y = 1;
    for (int i=1; i<=N; i++)
        if (lev[i] > lev[y])
            y = i;
    int diam = lev[y];
    db = min (db, diam), da = min (da, diam);
    if (d <= da || db <= 2 * da)
        printf ("Alice\n");
    else printf ("Bob\n");
    for (int i=1; i<=N; i++)
        v[i].clear ();
}

return 0;
}