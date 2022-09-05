#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<algorithm>

using namespace std;

int nr, N, M, ans[400009], ap[100009], comp[100009], odd[100009];
bool ok;
vector < int > v[100009];

void add_to_path (int nod)
{
    odd[nod] ^= 1;
    ans[++nr] = nod;
}

void dfs (int nod, int tata)
{
    ap[nod] = 1;
    add_to_path (nod);
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (ap[*it] == 0)
        {
            dfs (*it, nod);
            add_to_path (nod);
        }
    if (odd[nod] && tata != -1)
    {
        add_to_path (tata);
        add_to_path (nod);
    }
}

void df (int nod)
{
    if (odd[nod])
        ok = 1;
    comp[nod] = 1;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (comp[*it] == 0)
            df (*it);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
while (M)
{
    M --;
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
for (int i=1; i<=N; i++)
    scanf ("%d", &odd[i]);

int C = 0, where;
for (int i=1; i<=N; i++)
    if (comp[i] == 0)
    {
        ok = 0;
        df (i);
        if (ok)
            C ++, where = i;
    }

if (C > 1)
{
    printf ("-1\n");
    return 0;
}

if (C == 0)
{
    printf ("0\n");
    return 0;
}

dfs (where, -1);
if (odd[where])
    nr --;

printf ("%d\n", nr);
for (int i=1; i<=nr; i++)
    printf ("%d ", ans[i]);
printf ("\n");
return 0;
}