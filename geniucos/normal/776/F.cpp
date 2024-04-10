#include<bits/stdc++.h>

using namespace std;

int nr, id, N, M, nxt[100009], prv[100009], rgt[100009], lft[100009], reMap[200009];
bool EndNow, cva[100009], del[100009];
multiset < pair < int, int > > S;
vector < pair < vector < int >, int > > poly;
set < int > v[100009];
vector < int > h[200009];
map < pair < int, int >, int > mp;

void Push (int i, int j) {if (i > j) swap (i, j); S.insert (make_pair (i, j));}
bool ex (int i, int j) {if (i > j) swap (i, j); if (S.find (make_pair (i, j)) != S.end ()) return 1; return 0;}

void calcRgt (int i)
{
    if (rgt[i] != 0) return ;
    int j = nxt[i];
    if (cva[j]) rgt[i] = j;
    else calcRgt (j), rgt[i] = rgt[j];
}

void calcLft (int i)
{
    if (lft[i] != 0) return ;
    int j = prv[i];
    if (cva[j]) lft[i] = j;
    else calcLft (j), lft[i] = lft[j];
}

int steps = 0;
int Rgt (int x)
{
    if (++steps == N) {EndNow = 1; return -1;}
    if (!v[rgt[x]].empty ()) return rgt[x];
    return rgt[x] = Rgt (nxt[x]);
}

int Lft (int x)
{
    if (++steps == N) {EndNow = 1; return -1;}
    if (!v[lft[x]].empty ()) return lft[x];
    return lft[x] = Lft (prv[x]);
}

int code (int x, int y)
{
    if (x > y) swap (x, y);
    if (mp.count (make_pair (x, y))) return mp[make_pair (x, y)];
    mp[make_pair (x, y)] = ++nr;
    return nr;
}

void Add (vector < int > &v)
{
    for (int i=0; i<v.size () - 1; i++)
        h[code (v[i], v[i + 1])].push_back (id);
    h[code (v[v.size () - 1], v[0])].push_back (id);
}

void Try (int i)
{
    if (EndNow) return ;
    steps = 0, Lft (i), steps = 0, Rgt (i);
    if (EndNow) return ;
    if (ex (lft[i], rgt[i]) && v[i].empty () && (!del[i]))
    {
        vector < int > curr;
        int j = lft[i];
        while (1)
        {
            curr.push_back (j);
            if (j != lft[i] && j != rgt[i]) del[j] = 1;
            if (j == rgt[i]) break;
            j = nxt[j];
        }
        id ++, Add (curr);
        sort (curr.begin (), curr.end ()), reverse (curr.begin (), curr.end ());
        poly.push_back (make_pair (curr, id));
        int x = lft[i], y = rgt[i];
        nxt[x] = y, prv[y] = x;
        v[x].erase (y), v[y].erase (x);
        if (!v[x].empty ()) lft[y] = x;
        else lft[y] = lft[x];
        if (!v[y].empty ()) rgt[x] = y;
        else rgt[x] = rgt[y];
        Try (x), Try (prv[x]), Try (nxt[x]), Try (y), Try (prv[y]), Try (nxt[y]);
    }
}

void Print (vector < int > v)
{
    for (auto it = v.begin (); it != v.end (); it ++)
        printf ("%d ", *it);
    printf ("\n");
}

int ap[100009], vol[100009], ma[100009], ans[100009];
vector < int > tr[100009], comp;

void add_edge (int x, int y)
{
//    printf ("%d %d\n", x, y);
    tr[x].push_back (y);
    tr[y].push_back (x);
}

void dfs (int nod)
{
    comp.push_back (nod);
    ap[nod] = 1;
    vol[nod] = 1;
    ma[nod] = 0;
    for (vector < int > :: iterator it = tr[nod].begin (); it != tr[nod].end (); it ++)
        if (ap[*it] == 0)
        {
            dfs (*it);
            vol[nod] += vol[*it];
            if (vol[*it] > ma[nod])
                ma[nod] = vol[*it];
        }
}

void solve (int nod, int lv)
{
    comp.clear ();
    dfs (nod);
    for (vector < int > :: iterator it = comp.begin (); it != comp.end (); it ++)
        ap[*it] = 0;

    int CG = (*comp.begin ());
    for (vector < int > :: iterator it = comp.begin (); it != comp.end (); it ++)
    {
        if (comp.size () - vol[*it] > ma[*it])
            ma[*it] = comp.size () - vol[*it];
        if (ma[*it] < ma[CG])
            CG = *it;
    }
    ans[CG] = lv;
    //////////////////////////////////////////////////////////////////////////////////pot parcurge arborele rutat in CG
    //////////////////////////////////////////////////////////////////////////////////

    ap[CG] = 2;
    for (vector < int > :: iterator it = tr[CG].begin (); it != tr[CG].end (); it ++)
        if (ap[*it] == 0)
            solve (*it, lv + 1);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
if (M == 0)
{
    printf ("1\n");
    return 0;
}
for (int i=1; i<=M; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y), cva[x] = cva[y] = 1;
    Push (x, y), v[x].insert (y), v[y].insert (x);
}
for (int i=1; i<N; i++)
    nxt[i] = i + 1;
nxt[N] = 1, prv[1] = N;
for (int i=2; i<=N; i++)
    prv[i] = i - 1;
for (int i=1; i<=N; i++)
    calcLft (i), calcRgt (i);
for (int i=1; i<=N; i++)
    Try (i);
vector < int > curr;
for (int i=1; i<=N; i++)
    if (!del[i])
        curr.push_back (i);
id ++, Add (curr);
sort (curr.begin (), curr.end ()), reverse (curr.begin (), curr.end ());
poly.push_back (make_pair (curr, id));

sort (poly.begin (), poly.end ()), id = 0;
for (auto it = poly.begin (); it != poly.end (); it ++)
    reMap[it->second] = ++id;
for (int i=1; i<=nr; i++)
    if (h[i].size () > 1)
        add_edge (reMap[h[i][0]], reMap[h[i][1]]);
solve (1, 1);
for (int i=1; i<=poly.size (); i++)
    printf ("%d ", ans[i]);
printf ("\n");
return 0;
}