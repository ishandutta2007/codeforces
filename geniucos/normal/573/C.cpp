#include<cstdio>
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

int rad, N, ap[100009], sters[100009], frunze[100009], minu[100009], viu_in_sub[100009];
vector < int > v[100009], h[100009];
bool mergemerge;

void dfs (int nod)
{
    ap[nod] = 1;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (ap[*it] == 0)
            h[nod].push_back (*it), dfs (*it);
}

void df_5 (int nod)
{
    if (h[nod].empty ()) frunze[nod] = 1;
    for (vector < int > :: iterator it = h[nod].begin (); it != h[nod].end (); it ++)
        df_5 (*it), frunze[nod] += frunze[*it];
}

void df_del (int nod)
{
    for (vector < int > :: iterator it = h[nod].begin (); it != h[nod].end (); it ++)
    {
        int curr = *it;
        if (frunze[curr] == 1)
        {
            while (h[curr].size () == 1)
            {
                sters[curr] = 1;
                //h[nod].push_back (h[curr][0]);
                curr = h[curr][0];
                continue;
            }
        }
        *it = curr;
        df_del (curr);
    }
}

void df3 (int nod)
{
    ap[nod] = 1;
    for (vector < int > :: iterator it = h[nod].begin (); it != h[nod].end (); it ++)
        if (ap[*it] == 0 && sters[*it] == 0)
            v[nod].push_back (*it), df3 (*it);
}

void df4 (int nod)
{
    ap[nod] = 1;
    viu_in_sub[nod] = (sters[nod] == 0);
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (ap[*it] == 0 && sters[*it] == 0)
            h[nod].push_back (*it), df4 (*it), viu_in_sub[nod] += viu_in_sub[*it];
}

void chk (int nod, int folosit)
{
    int cnt = 0, F;
    for (vector < int > :: iterator it = h[nod].begin (); it != h[nod].end (); it ++)
        if (viu_in_sub[*it] > 0)
            cnt ++, F = *it;
    if (cnt == 0) return;
    if (sters[nod] == 1)
    {
        if (cnt > 2) mergemerge = 0;
        else
        if (cnt == 1)
            chk (F, folosit);
        else
        if (folosit == 1)
            mergemerge = 0;
        else
        {
            for (vector < int > :: iterator it = h[nod].begin (); it != h[nod].end (); it ++)
                if (viu_in_sub[*it] > 0)
                    chk (*it, folosit + 1);
        }
    }
    else
    {
        if (cnt > 2) mergemerge = 0;
        else
        if (cnt == 1)
            chk (F, 1);
        else
        if (folosit == 1) mergemerge = 0;
        else
        {
            for (vector < int > :: iterator it = h[nod].begin (); it != h[nod].end (); it ++)
                if (viu_in_sub[*it] > 0)
                    chk (*it, folosit + 1);
        }
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}

rad = -1;
for (int i=1; i<=N; i++)
    if (v[i].size () >= 3)
        rad = i;

if (rad == -1)
{
    /////lant
    printf ("Yes\n");
    return 0;
}
dfs (rad);
df_5 (rad);
df_del (rad);
for (int i=1; i<=N; i++)
    v[i].clear (), ap[i] = 0;
df3 (rad);
/*printf ("%d\n", v[1].size ());
printf ("%d\n", v[v[1][0]].size ());
printf ("%d\n", v[v[1][1]].size ());
printf ("%d\n", sters[1]);*/
for (int i=1; i<=N; i++)
    if (v[i].size () == 2 && v[v[i][0]].empty () && v[v[i][1]].empty () && sters[i] == 0)
        sters[i] = 1;
for (int i=1; i<=N; i++)
    if (v[i].empty () && sters[i] == 0)
        sters[i] = 1;
for (int i=1; i<=N; i++)
    h[i].clear (), ap[i] = 0;
int cnt = 0;
for (vector < int > :: iterator it = v[rad].begin (); it != v[rad].end (); it ++)
    if (v[*it].empty ())
        cnt ++;
if (cnt <= 2) sters[rad] = 1;
df4 (rad);
/////am un arbore si un sir sters si vreau sa vad daca exista lant care trece prin toate nodurile cu sters = 0
mergemerge = 1;
chk (rad, 0);
if (mergemerge) printf ("Yes\n");
else printf ("No\n");
return 0;
}