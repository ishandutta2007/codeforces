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

int N, M, ap[509];
bool ap2[509][509];
vector < int > v[509], h[509];

void dfs (int nod, int cul)
{
    if (ap[nod] != 0 && ap[nod] != cul)
    {
        printf ("No\n");
        exit (0);
    }
    if (ap[nod] != 0) return ;
    ap[nod] = cul;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        dfs (*it, 4 - cul);
    for (vector < int > :: iterator it = h[nod].begin (); it != h[nod].end (); it ++)
        if (!v[*it].empty()) dfs (*it, cul);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
while (M --)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    ap2[x][y] = ap2[y][x] = 1;
}
for (int i=1; i<=N; i++)
    for (int j=i+1; j<=N; j++)
        if (ap2[i][j] == 0)
            v[i].push_back (j), v[j].push_back (i);
        else
            h[i].push_back (j), h[j].push_back (i);
for (int i=1; i<=N; i++)
    if (ap[i] == 0 && !v[i].empty ()) dfs (i, 1);
    else
    if (v[i].empty () && ap[i] == 0) ap[i] = 2;
printf ("Yes\n");
for (int i=1; i<=N; i++)
    printf ("%c", (char)'a' + ap[i] - 1);
printf ("\n");
return 0;
}