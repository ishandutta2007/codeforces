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

int N, nr, ap[2015], Q[2015];
vector < int > v[2015], h[2015];

void dfs (int nod)
{
    ap[nod] = 1;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (ap[*it] == 0) dfs (*it);
    Q[++nr] = nod;
}

void dfp (int nod)
{
    ap[nod] = 0;
    for (vector < int > :: iterator it = h[nod].begin (); it != h[nod].end (); it ++)
        if (ap[*it] == 1) dfp (*it);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
    {
        int aij;
        scanf ("%d", &aij);
        if (i != j && aij) v[i].push_back (j), h[j].push_back (i);
    }
for (int i=1; i<=N; i++)
    if (ap[i] == 0) dfs (i);
dfp (Q[nr]);
for (int i=1; i<=N; i++)
    if (ap[i] == 1)
    {
        printf ("NO\n");
        return 0;
    }
printf ("YES\n");
return 0;
}