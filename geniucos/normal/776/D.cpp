#include<bits/stdc++.h>

using namespace std;

int N, M, a[100009], col[100009], ap[100009];
vector < pair < int, int > > v[100009];
vector < int > h[100009];

void dfs (int nod, int c)
{
    ap[nod] = 1, col[nod] = c;
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (ap[it->first] == 0)
            dfs (it->first, c ^ it->second);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), a[i] ^= 1;
for (int i=1; i<=M; i++)
{
    int l, x;
    scanf ("%d", &l);
    for (int j=1; j<=l; j++)
        scanf ("%d", &x), h[x].push_back (i);
}
for (int i=1; i<=N; i++)
    for (int j=0; j<2; j++)
        v[h[i][j]].push_back (make_pair (h[i][j ^ 1], a[i]));
for (int i=1; i<=M; i++)
    if (ap[i] == 0)
        dfs (i, 0);
for (int i=1; i<=N; i++)
    if ((col[h[i][0]] ^ col[h[i][1]]) != a[i])
    {
        printf ("NO\n");
        return 0;
    }
printf ("YES\n");
return 0;
}