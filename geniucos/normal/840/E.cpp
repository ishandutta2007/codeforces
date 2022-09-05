#include<bits/stdc++.h>

using namespace std;

int N, Qs, a[50009], lev[50009], t[50009], jumpTo[50009], ans[150009];
const int maxSz = 512, lg = 15;
vector < int > v[50009];

struct trieSet
{
    short son[maxSz * (lg + 1) + 3][2], nr = 1;
    void add (int val)
    {
        int q = 1;
        for (int i=lg; i>=0; i--)
        {
            int bit = (val >> i) & 1;
            if (son[q][bit] == 0)
                son[q][bit] = ++nr;
            q = son[q][bit];
        }
    }
    int maxVal (int val)
    {
        int q = 1, ans = 0;
        for (int i=lg; i>=0; i--)
        {
            int bit = ((val >> i) & 1) ^ 1;
            if (son[q][bit] != 0)
                q = son[q][bit], ans |= 1 << i;
            else
                q = son[q][bit ^ 1];
        }
        //printf ("-> %d\n", ans);
        return ans;
    }
    void clear ()
    {
        for (int i=1; i<=nr; i++)
            son[i][0] = son[i][1] = 0;
        nr = 1;
    }
}currSet;

void dfs (int nod)
{
    for (auto it : v[nod])
        if (it != t[nod])
            t[it] = nod, lev[it] = lev[nod] + 1, dfs (it);
}

int kthAncestor (int nod, int jump)
{
    while (jump >= maxSz)
        nod = jumpTo[nod], jump -= maxSz;
    while (jump --)
        nod = t[nod];
    return nod;
}

vector < pair < int, int > > up[50009];
void processQueries ()
{
    for (int i=1; i<=N; i++)
        if (lev[i] >= maxSz)
        {
            if (!up[i].empty ())
            {
                currSet.clear ();
                for (int j = 0, k = i; j<maxSz; j++, k = t[k])
                    currSet.add (a[k] ^ j);
                for (auto q : up[i])
                    ans[q.second] = max (ans[q.second], currSet.maxVal (q.first));
            }
        }
}

void addRequest (int id, int node, int val)
{
    up[node].push_back ({val, id});
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &Qs);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
lev[1] = 1, dfs (1);
for (int i=1; i<=N; i++)
    if (lev[i] >= maxSz)
        for (int j = 0, k = i; j<maxSz; j++, k = t[k])
            jumpTo[i] = t[k];
for (int id=1; id<=Qs; id++)
{
    int u, v, bigPart = 0;
    scanf ("%d %d", &u, &v);
    while (lev[v] - maxSz >= lev[u])
        addRequest (id, v, bigPart * maxSz),
        bigPart ++, v = jumpTo[v];
    int currD = bigPart * maxSz;
    while (v != t[u])
        ans[id] = max (ans[id], currD ^ a[v]),
        currD ++, v = t[v];
}
processQueries ();
for (int i=1; i<=Qs; i++)
    printf ("%d\n", ans[i]);
return 0;
}