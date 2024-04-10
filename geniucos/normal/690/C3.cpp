#include<bits/stdc++.h>

using namespace std;

int N, x, y, D, t[20][200009], niv[200009];
vector < int > v[200009];

void dfs (int nod)
{
    for (int i=1; (1<<i) <= niv[nod]; i++)
        t[i][nod] = t[i - 1][t[i - 1][nod]];
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        niv[*it] = niv[nod] + 1, dfs (*it);
}

void go_up (int &x, int lv)
{
    for (int i=0; (1<<i) <= lv; i++)
        if (lv & (1 << i)) x = t[i][x];
}

int lca (int x, int y)
{
    int a = x, b = y;
    if (niv[x] > niv[y]) go_up (x, niv[x] - niv[y]);
    else go_up (y, niv[y] - niv[x]);
    for (int i=18; i>=0; i--)
        if ((1 << i) <= niv[x])
            if (t[i][x] != t[i][y])
                x = t[i][x], y = t[i][y];
    x = t[0][x];
    return niv[a] + niv[b] - 2 * niv[x];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=2; i<=N; i++)
    scanf ("%d", &t[0][i]), v[t[0][i]].push_back (i);
dfs (1);
printf ("1 "), x = 1, y = 2, D = 1;
for (int i=3; i<=N; i++)
{
    if (lca (x, i) > D) D = lca (x, i), y = i;
    if (lca (i, y) > D) D = lca (i, y), x = i;
    printf ("%d ", D);
}
printf ("\n");
return 0;
}