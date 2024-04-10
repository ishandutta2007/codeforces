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

int nr, N, M, ans[200009], P[200009], vol[200009], A[200009], K[200009];

vector < int > v[200009], qr[200009];
map < int, int > mp[24];
int aib[24][200009];

void Update (int lv, int pos, int val)
{
    if (pos == 0)
        return;
    while (pos <= 200003)
    {
        aib[lv][pos] += val;
        pos += pos - (pos & (pos - 1));
    }
}

int Query (int lv, int pos)
{
    int sum = 0;
    while (pos)
    {
        sum += aib[lv][pos];
        pos &= pos - 1;
    }
    return sum;
}

void make_paths (int nod, int tata)
{
    int p = -1;
    vol[nod] = 1;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (*it != tata)
        {
            make_paths (*it, nod);
            vol[nod] += vol[*it];
            if (p == -1 || vol[*it] > vol[p])
                p = *it;
        }
    P[nod] = p;
}

void solve (int nod, int tata, int lv)
{
    int old;
    if (v[nod].size () > 1 || nod == 1)
    {
        solve (P[nod], nod, lv);

        for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
            if (*it != tata && *it != P[nod])
            {
                solve (*it, nod, lv + 1);
                for (map < int , int > :: iterator it2 = mp[lv + 1].begin (); it2 != mp[lv + 1].end (); it2 ++)
                {
                    old = mp[lv][it2->first];
                    Update (lv + 1, it2->second, -1);
                    Update (lv, old, -1);
                    mp[lv][it2->first] += it2->second;
                    Update (lv, old + it2->second, 1);
                }
                mp[lv + 1].clear ();
            }
    }

    old = mp[lv][A[nod]];
    Update (lv, old, -1);
    mp[lv][A[nod]] ++;
    Update (lv, old + 1, 1);

    for (vector < int > :: iterator it = qr[nod].begin (); it != qr[nod].end (); it ++)
        ans[*it] = Query (lv, 200000) - Query (lv, K[*it] - 1);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%d", &A[i]);

for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}

for (int i=1; i<=M; i++)
{
    int nod;
    scanf ("%d %d", &nod, &K[i]);
    qr[nod].push_back (i);
}

make_paths (1, 0);
solve (1, 0, 0);
//if (A[1] == 44640)
  //  return 0;
for (int i=1; i<=M; i++)
    printf ("%d\n", ans[i]);

return 0;
}