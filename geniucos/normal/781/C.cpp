#include<bits/stdc++.h>

using namespace std;

int N, M, K, nr, ans[400009];
bool ap[200009];
vector < int > v[200009];

void dfs (int nod)
{
    ap[nod] = 1, ans[++nr] = nod;
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (ap[*it] == 0)
            dfs (*it), ans[++nr] = nod;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &K);
for (int i=1; i<=M; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
dfs (1);
int lim = (2 * N) / K;
if ((2 * N) % K != 0) lim ++;
int pos = 1;
for (int i=1; i<=K; i++)
{
    if (pos > nr)
    {
        printf ("1 1\n");
        continue;
    }
    int l = min (lim, nr - pos + 1);
    printf ("%d", l);
    for (int j=pos; j<=pos + l - 1; j++)
        printf (" %d", ans[j]);
    printf ("\n"), pos += l;
}
return 0;
}