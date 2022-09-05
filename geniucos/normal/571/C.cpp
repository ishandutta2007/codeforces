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

int sol[200009], rez[200009], cod[200009], nr, N, M, AP[200009], AP2[200009], cul, X, Y, cnt[200009], ap[200009][3], cum[200009][3];
vector < pair < int , int > > v[200009];
vector < int > comp, mul[200009];

void dfs (int nod, int cul)
{
    AP[nod] = 1;
    AP2[nod] = 1;
    comp.push_back (nod);
    for (vector < pair < int , int > > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
    if (it->second != cul)
    {
        if (AP[it->first] == 0) dfs (it->first, it->second);
        else
        if (AP2[it->first] == 1)
        {
            X = it->first;
            Y = nod;
        }
    }
    AP2[nod] = 0;
}

void df2 (int nod, int cul)
{
    AP[nod] = 1;
    rez[nod] = cul;
    for (vector < pair < int , int > > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (AP[it->first] == 0)
            df2 (it->first, it->second);
}

void sterg (int X, int Y)
{
    for (vector < pair < int , int > > :: iterator it = v[X].begin (); it != v[X].end (); it ++)
        if (it->first == Y)
        {
            cul = it->second;
            v[X].erase (it);
            break;
        }
    for (vector < pair < int , int > > :: iterator it = v[Y].begin (); it != v[Y].end (); it ++)
        if (it->first == X && it->second == cul)
        {
            v[Y].erase (it);
            break;
        }
}

/*void fix (int i)
{
    for ()
}*/

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &M, &N);
for (int i=1; i<=M; i++)
{
    int l;
    scanf ("%d", &l);
    while (l--)
    {
        int val;
        scanf ("%d", &val);
        mul[i].push_back (val);
        bool sg = 0;
        if (val < 0) sg = 1, val = -val;
        if (cnt[val])
        {
            ap[val][1] = i;
            cum[val][1] = sg;
            if (ap[val][0] == i)
            {
                v[i].push_back (make_pair (i, val));
                v[i].push_back (make_pair (i, val));
            }
        }
        else ap[val][0] = i, cum[val][0] = sg;
        cnt[val] ++;
    }
}

for (int i=1; i<=N; i++)
    if (ap[i][1] == 0 && ap[i][0] != 0)
    {
        int lin = ap[i][0];
        v[lin].push_back (make_pair (lin, i));
        v[lin].push_back (make_pair (lin, i));
    }

for (int i=1; i<=N; i++)
    if (ap[i][1] != 0 && cum[i][0] == cum[i][1])
    {
        v[ap[i][1]].push_back (make_pair (ap[i][1], i)), v[ap[i][1]].push_back (make_pair (ap[i][1], i));
        v[ap[i][0]].push_back (make_pair (ap[i][0], i)), v[ap[i][0]].push_back (make_pair (ap[i][0], i));
    }

for (int i=1; i<=N; i++)
    if (ap[i][1] != 0 && cum[i][0] != cum[i][1])
        v[ap[i][1]].push_back (make_pair (ap[i][0], i)), v[ap[i][0]].push_back (make_pair (ap[i][1], i));

bool merg = 1;
for (int i=1; i<=M; i++)
    if (AP[i] == 0)
    {
        X = -1, Y = -1;
        comp.clear ();
        dfs (i, 0);
        if (X == -1 || Y == -1)
        {
            printf ("NO\n");
            return 0;
        }
        for (vector < int > :: iterator it = comp.begin (); it != comp.end (); it ++)
            AP[*it] = 0;
        sterg (X, Y);
        df2 (X, cul);
    }
for (int i=1; i<=M; i++)
    {
        bool sg = 0;
        if (ap[rez[i]][0] == i) sg = cum[rez[i]][0];
        else sg = cum[rez[i]][1];
        if (!sg) sol[rez[i]] = 1;
    }
if (!merg) printf ("NO\n");
else
{
    printf ("YES\n");
    for (int i=1; i<=N; i++)
        printf ("%d", sol[i]);
    printf ("\n");
}
return 0;
}