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

int N, M, nr, T[100009], aib[100009], sum[100009], pos[100009], dr[100009], niv[100009], sens[100009];
bool ap[100009];
vector < int > v[100009];
vector < int > ans[100009];

void dfs (int nod)
{
    pos[nod] = ++nr, ap[nod] = 1;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
    {
        if (ap[*it] == 0)
        {
            T[*it] = nod, niv[*it] = niv[nod] + 1, dfs (*it);
            sens[*it] = 0, sum[nod] ^= 1;///sens = 0 -> tata->fiu
        }
        else
        if (nod < *it && T[nod] != *it) ans[nod].push_back (*it), sum[nod] ^= 1;
    }
    dr[nod] = nr;
}

void xor_path (int x, int y)
{
    sens[x] ^= 1, sens[y] ^= 1;
}

void all_mars (int nod)
{
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (T[*it] == nod)
            all_mars (*it), sens[nod] ^= sens[*it];
}

void Print ()
{
/*    for (int i=1; i<=N; i++, printf ("\n"))
        for (int j=0; j<ans[i].size (); j++)
            printf ("%d ", ans[i][j]);
    return ;*/
    for (int i=1; i<=N; i++)
        for (int j=0; j + 1<ans[i].size (); j+=2)
            printf ("%d %d %d\n", ans[i][j], i, ans[i][j + 1]);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
if (M & 1)
{
    printf ("No solution\n");
    return 0;
}
for (int i=1; i<=M; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
dfs (1);
int lst = 0;
for (int i=1; i<=N; i++)
    if (sum[i])
    {
        if (lst == 0)
        {
            lst = i;
            continue;
        }
        xor_path (i, lst), lst = 0;
    }
//Print ();
//return 0;
all_mars (1);
for (int i=2; i<=N; i++)
    if (sens[i] == 0) ans[T[i]].push_back (i);
    else ans[i].push_back (T[i]);
Print ();
return 0;
}