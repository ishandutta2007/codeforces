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

int N, M, x[100009], y[100009], l[100009], r[100009], ap[100009];
vector < int > v[100009], h[100009];

void dfs (int i)
{
    ap[i] = 1, r[i] = 0;
    for (vector < int > :: iterator it = v[i].begin (); it != v[i].end (); it ++)
    {
        if (ap[*it] == 0) dfs (*it);
        if (r[*it] > r[i]) r[i] = r[*it];
    }
    r[i] ++;
}

void dfp (int i)
{
    ap[i] = 0, l[i] = 0;
    for (vector < int > :: iterator it = h[i].begin (); it != h[i].end (); it ++)
    {
        if (ap[*it] == 1) dfp (*it);
        if (l[*it] > l[i]) l[i] = l[*it];
    }
    l[i] ++;
}

bool ok (int pos)
{
    for (int i=1; i<=N; i++)
        v[i].clear (), h[i].clear ();
    for (int i=1; i<=pos; i++)
        v[x[i]].push_back (y[i]), h[y[i]].push_back (x[i]);
    for (int i=1; i<=N; i++)
        if (ap[i] == 0) dfs (i);
    for (int i=1; i<=N; i++)
        if (ap[i] == 1) dfp (i);
    for (int i=1; i<=N; i++)
        if (l[i] + r[i] - 1 != N) return 0;
    return 1;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=M; i++)
    scanf ("%d %d", &x[i], &y[i]);
int p = 1, u = M, mij, ras = -1;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (ok (mij)) ras = mij, u = mij - 1;
    else p = mij + 1;
}
printf ("%d\n", ras);

return 0;
}