#include<bits/stdc++.h>

using namespace std;

int N, M, Q, t[500009], x[500009], y[500009], w[500009], ind[500009], ans[500009];
vector < pair < int, int > > moves;
vector < int > inList[500009];
vector < pair < int, pair < int, int > > > op[500009];

int tata (int x)
{
    if (t[x] == x) return t[x];
    int curr = tata (t[x]);
    moves.push_back ({x, t[x]}), t[x] = curr;
    return curr;
}

void unite (int x, int y)
{
    x = tata (x), y = tata (y);
    if (x == y) return;
    moves.push_back ({x, t[x]}), t[x] = y;
}

void rollBack ()
{
    for (auto it = moves.rbegin (); it != moves.rend (); it ++)
        t[it->first] = it->second;
}

bool cmp (int i, int j) {return (w[i] < w[j]);}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=M; i++)
    scanf ("%d %d %d", &x[i], &y[i], &w[i]), ind[i] = i;
sort (ind + 1, ind + M + 1, cmp);
scanf ("%d", &Q);
for (int i=1; i<=Q; i++)
{
    int l, x;
    scanf ("%d", &l);
    for (int j=1; j<=l; j++)
        scanf ("%d", &x), inList[i].push_back (x);
    sort (inList[i].begin (), inList[i].end (), cmp);
    for (int j=0; j<l; j++)
    {
        int k = j;
        for (; k<l; k++)
            if (w[inList[i][k]] != w[inList[i][j]])
                break;
        k --;
        ///[j, k]
        op[w[inList[i][j]]].push_back ({i, {j, k}});
        ///
        j = k;
    }
}
for (int i=1; i<=N; i++)
    t[i] = i;
for (int i=1; i<=M; i++)
{
    int j = i;
    for (; j<=M; j++)
        if (w[ind[j]] != w[ind[i]])
            break;
    j --;
    ///[i, j]
    for (auto trp : op[w[ind[i]]])
    {
        int pos = trp.first, lft = trp.second.first, rgt = trp.second.second;
        if (ans[pos]) continue;
        moves.clear ();
        for (int pp = lft; pp<=rgt; pp++)
        {
            int id = inList[pos][pp], u = x[id], v = y[id];
            if (tata (u) == tata (v))
            {
                ans[pos] = 1;
                break;
            }
            unite (u, v);
        }
        rollBack();
    }
    for (int k=i; k<=j; k++)
    {
        int u = x[ind[k]], v = y[ind[k]];
        if (tata (u) != tata (v))
            unite (u, v);
    }
    moves.clear ();
    ///
    i = j;
}
for (int i=1; i<=Q; i++)
    if (ans[i]) printf ("NO\n");
    else printf ("YES\n");
return 0;
}