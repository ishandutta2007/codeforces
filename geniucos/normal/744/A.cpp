#include<bits/stdc++.h>

using namespace std;

int nr, ans, nr2, N, M, K, ap[1009], a[10009], A[1009], B[1009], sz[1009];
bool good[1009];
vector < int > v[1009];

void dfs (int nod)
{
    ap[nod] = nr, sz[nr] ++;
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (ap[*it] == 0)
            dfs (*it);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &K), ans = -M;
for (int i=1; i<=K; i++)
    scanf ("%d", &a[i]);
while (M --)
{
    int x, y;
    scanf ("%d %d", &x, &y), v[x].push_back (y), v[y].push_back (x);
}
for (int i=1; i<=N; i++)
    if (ap[i] == 0) nr ++, dfs (i);
for (int i=1; i<=nr; i++)
    ans += sz[i] * (sz[i] - 1) / 2;
for (int i=1; i<=K; i++)
    A[i] = sz[ap[a[i]]], good[ap[a[i]]] = 1;
sort (A + 1, A + K + 1);
for (int i=1; i<=nr; i++)
    if (!good[i]) ans += A[K] * sz[i], A[K] += sz[i];
printf ("%d\n", ans);
return 0;
}