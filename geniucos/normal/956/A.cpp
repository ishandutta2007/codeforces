#include<bits/stdc++.h>

using namespace std;

int N, M, n, m, l[109], c[109], ap[109];
char sir[59][59];
vector < int > v[109];

void dfs (int nod)
{
    ap[nod] = 1;
    if (nod <= N) l[++n] = nod;
    else c[++m] = nod - N;
    for (auto it : v[nod])
        if (ap[it] == 0)
            dfs (it);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=1; i<=N; i++)
{
    scanf ("%s", sir[i] + 1);
    for (int j=1; j<=M; j++)
        if (sir[i][j] == '#')
            v[i].push_back (N + j),
            v[N + j].push_back (i);
}
for (int i=1; i<=N + M; i++)
    if (ap[i] == 0)
    {
        n = m = 0, dfs (i);
        for (int j=1; j<=n; j++)
            for (int k=1; k<=m; k++)
                if (sir[l[j]][c[k]] != '#')
                {
                    printf ("No\n");
                    return 0;
                }
    }
printf ("Yes\n");
return 0;
}