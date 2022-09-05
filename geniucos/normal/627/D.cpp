#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int M, N, K, up[200009], down[200009], dwf[200009], surp[200009], vol[200009], vol2[200009], t[200009], a[200009], b[200009], MV;
vector < int > fii[200009], v[200009];

void dfs (int nod, int tata)
{
    vol[nod] = 1;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (*it != tata)
            t[*it] = nod, fii[nod].push_back (*it), dfs (*it, nod), vol[nod] += vol[*it];
}

void df2 (int nod)
{
    down[nod] = vol2[nod] = (a[nod] >= MV);
    int maxi = 0;
    for (vector < int > :: iterator it = fii[nod].begin (); it != fii[nod].end (); it ++)
    {
        df2 (*it), vol2[nod] += vol2[*it];
        if (a[nod] >= MV)
        {
            if (vol2[*it] == vol[*it]) down[nod] += vol[*it];
            else
            if (a[*it] >= MV && down[*it] > maxi) maxi = down[*it];
        }
    }
    dwf[nod] = down[nod];
    down[nod] += maxi;
}

void df3 (int nod)
{
    if (a[t[nod]] < MV || t[nod] == 0) up[nod] = (a[nod] >= MV);
    else
    {
        up[nod] ++;
        if (M - vol2[nod] != N - vol[nod])
        {
            if (M - vol2[t[nod]] == N - vol[t[nod]]) up[nod] += up[t[nod]] + surp[nod];
            else up[nod] += max (up[t[nod]], surp[nod] + 1);
        }
        else up[nod] = M - vol2[nod] + 1;
        if (a[nod] < MV) up[nod] = 0;
    }
    if (a[nod] >= MV)
    {
        int sum = 0;
        for (vector < int > :: iterator it = fii[nod].begin (); it != fii[nod].end (); it ++)
            if (vol[*it] == vol2[*it]) sum += vol[*it];
        for (vector < int > :: iterator it = fii[nod].begin (); it != fii[nod].end (); it ++)
            if (vol[*it] == vol2[*it]) up[*it] = sum - vol[*it];
            else up[*it] = sum;
        int maxi = 0;
        for (vector < int > :: iterator it = fii[nod].begin (); it != fii[nod].end (); it ++)
        {
            if (maxi > surp[*it]) surp[*it] = maxi;
            if (vol[*it] != vol2[*it] && down[*it] > maxi) maxi = down[*it];
        }
        maxi = 0;
        for (vector < int > :: reverse_iterator it = fii[nod].rbegin (); it != fii[nod].rend (); it ++)
        {
            if (maxi > surp[*it]) surp[*it] = maxi;
            if (vol[*it] != vol2[*it] && down[*it] > maxi) maxi = down[*it];
        }
    }
    for (vector < int > :: iterator it = fii[nod].begin (); it != fii[nod].end (); it ++)
        df3 (*it);
}

bool solve (int min_val)
{
    MV = min_val;
    df2 (1), M = vol2[1];
    for (int i=1; i<=N; i++)
        up[i] = surp[i] = 0;
    df3 (1);
    for (int i=1; i<=N; i++)
    {
        if (down[i] >= K) return 1;
        if (up[i] >= K) return 1;
        if (down[i] == vol[i] && down[i] + up[i] - 1 >= K) return 1;
        if (up[i] == N - vol[i] + 1 && down[i] + up[i] - 1 >= K) return 1;
        if (dwf[i] + up[i] - 1 >= K) return 1;
    }
    return 0;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), b[i] = a[i];
for (int i=1;i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
dfs (1, -1);
sort (b + 1, b + N + 1);
int p = 1, u = N - K + 1, mij, ras;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (solve (b[mij])) ras = mij, p = mij + 1;
    else u = mij - 1;
}
printf ("%d\n", b[ras]);

return 0;
}