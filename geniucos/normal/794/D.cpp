#include<bits/stdc++.h>

using namespace std;

int nr, N, M, id[300009], ans[300009], pos[300009], x[300009], y[300009];
pair < vector < int >, int > v[300009];
set < int > h[300009];

void add_edge (int x, int y)
{
    if (x == y) return ;
    h[x].insert (y), h[y].insert (x);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    v[i].first.push_back (i);
for (int i=1; i<=M; i++)
    scanf ("%d %d", &x[i], &y[i]), v[x[i]].first.push_back (y[i]), v[y[i]].first.push_back (x[i]);
for (int i=1; i<=N; i++)
    sort (v[i].first.begin (), v[i].first.end ()), v[i].second = i;
sort (v + 1, v + N + 1);
for (int i=1; i<=N; i++)
{
    int j = i;
    while (j + 1 <= N && v[j + 1].first == v[i].first) j ++;
    ///[i, j]
    nr ++;
    for (int k=i; k<=j; k++)
        id[v[k].second] = nr;
    ///
    i = j;
}
for (int i=1; i<=M; i++)
    add_edge (id[x[i]], id[y[i]]);
int BG = -1;
for (int i=1; i<=nr; i++)
{
    if (h[i].size () > 2)
    {
        printf ("NO\n");
        return 0;
    }
    else
    if (h[i].size () < 2) BG = i;
}
if (BG == -1)
{
    printf ("NO\n");
    return 0;
}
ans[1] = BG;
if (nr != 1)
{
    ans[2] = (*h[BG].begin ());
    for (int i=2; i<nr; i++)
        ans[i + 1] = (*h[ans[i]].begin ()) ^ (*h[ans[i]].rbegin ()) ^ ans[i - 1];
}
for (int i=1; i<=nr; i++)
    pos[ans[i]] = i;
printf ("YES\n");
for (int i=1; i<=N; i++)
    printf ("%d%c", pos[id[i]], " \n"[i == N]);
return 0;
}