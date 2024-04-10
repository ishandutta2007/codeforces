#include<bits/stdc++.h>

using namespace std;

int cnt, N, M, ap[10009];
vector < int > v[10009];

void dfs (int nod)
{
    ap[nod] = 1, cnt ++;
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
    if (ap[*it] == 0)
        dfs (*it);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
if (M != N - 1)
{
    printf ("no\n");
    return 0;
}
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y), v[y].push_back (x);
}
dfs (1);
if (cnt == N) printf ("yes\n");
else printf ("no\n");
return 0;
}