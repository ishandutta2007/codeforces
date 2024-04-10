#include<bits/stdc++.h>

using namespace std;

int nodes, N, M, w[200009], up[200009], lev[200009], crit[200009], t[200009], sz[200009];
bool isFine[200009];
long long realW[200009];
vector < int > v[200009], g[200009], h[200009];

void dfs (int nod, int tata)
{
    up[nod] = lev[nod];
    for (auto it : v[nod])
        if (lev[it] == -1)
        {
            t[it] = nod, lev[it] = lev[nod] + 1;
            dfs (it, nod);
            if (up[it] > lev[nod]) crit[it] = 1;
            if (up[it] < up[nod])
                up[nod] = up[it];
        }
    for (auto it : v[nod])
        if (it != tata && lev[it] < up[nod])
            up[nod] = lev[it];
}

void df2 (int nod, int currId)
{
    if (crit[nod])
    {
        if (currId != 0)
            g[currId].push_back (nodes + 1);
        currId = ++nodes;
    }
    realW[currId] += w[nod], sz[currId] ++;
    //printf ("%d %d\n", nod, currId);
    for (auto it : h[nod])
        df2 (it, currId);
}

long long ans;
void df3 (int nod)
{
    if (sz[nod] > 1) isFine[nod] = 1;
    for (auto it : g[nod])
        df3 (it), isFine[nod] |= isFine[it];
}

long long ans2 = 0;
void df4 (int nod, long long sum)
{
    if (sum > ans2)
        ans2 = sum;
    for (auto it : g[nod])
        df4 (it, sum + (isFine[it] ? 0 : realW[it]));
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%d", &w[i]);
while (M --)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
int s;
scanf ("%d", &s);
for (int i=1; i<=N; i++)
    lev[i] = -1;
lev[s] = 0, dfs (s, -1);
for (int i=1; i<=N; i++)
    if (i != s)
        h[t[i]].push_back (i);
crit[s] = 1, df2 (s, 0);
/*for (int i=1; i<=nodes; i++)
{
    printf ("realW[%d]=%I64d\n", i, realW[i]);
    for (auto j : g[i])
        printf ("%d -> %d\n", i, j);
}*/
ans = 0, df3 (1);
for (int i=1; i<=N; i++)
    if (isFine[i])
        ans += realW[i];
df4 (1, (isFine[1] ? 0 : realW[1]));
printf ("%I64d\n", ans + ans2);
return 0;
}