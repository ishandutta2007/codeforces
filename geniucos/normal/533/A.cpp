#include<bits/stdc++.h>

using namespace std;

int ans, pos, N, M, K, place[500009], t[500009], h[500009], h2[500009], a[500009];
int mi[1100009], lazy[1100009];
bool ap[500009];
vector < int > v[500009];
priority_queue < pair < int, int > > PQ;
vector < pair < int, int > > moves;

void dfs (int nod)
{
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (*it != t[nod])
        {
            if (h2[nod] < h2[*it]) h2[*it] = h2[nod];
            t[*it] = nod, dfs (*it);
        }
}

int tallest_miner (int cave_height)
{
    int p = 1, u = M, mij, ras = M + 1;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (a[mij] <= cave_height) ras = mij, u = mij - 1;
        else p = mij + 1;
    }
    return ras;
}

void Build (int nod, int st, int dr)
{
    mi[nod] = -dr;
    if (st == dr) return ;
    int mij = (st + dr) >> 1;
    Build (nod << 1, st, mij);
    Build (nod << 1 | 1, mij + 1, dr);
}

void Update (int nod, int st, int dr, int x, int y, int val)
{
    if (x <= st && dr <= y)
    {
        lazy[nod] += val, mi[nod] += val;
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (lazy[nod])
        lazy[f1] += lazy[nod], lazy[f2] += lazy[nod], mi[f1] += lazy[nod], mi[f2] += lazy[nod], lazy[nod] = 0;
    if (x <= mij) Update (f1, st, mij, x, y, val);
    if (mij < y) Update (f2, mij + 1, dr, x, y, val);
    mi[nod] = min (mi[f1], mi[f2]);
}

void df2 (int nod)
{
    h2[nod] = min (h2[t[nod]], h[nod]);
    int pos = tallest_miner (h2[nod]);
    if (pos < place[nod])
        Update (1, 1, M, pos, place[nod] - 1, +1), moves.push_back (make_pair (pos, place[nod] - 1));
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (*it != t[nod]) df2 (*it);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &h[i]), h2[i] = h[i];
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
scanf ("%d", &K);
for (int i=1; i<=K; i++)
    scanf ("%d", &a[i]);
sort (a + 1, a + N + 1), reverse (a + 1, a + N + 1);///yep, that's N I consider some miners having height 0
t[1] = 0, ap[0] = 1, h2[0] = a[1] + 1, dfs (1);
PQ.push (make_pair (h2[1], 1));
for (int i=1; i<=N; i++)
{
    pair < int, int > curr = PQ.top ();
    if (curr.first >= a[i])
    {
        ap[curr.second] = 1, PQ.pop ();
        for (auto it = v[curr.second].begin (); it != v[curr.second].end (); it ++)
            if (*it != t[curr.second])
                PQ.push (make_pair (h2[*it], *it));
    }
    else
    {
        pos = i;
        break;
    }
}
if (pos == 0)
{
    printf ("0\n");
    return 0;
}
///then I should increase one of the nodes whose father is taken to value h[pos] hoping that'd be fine
///finally, I should have at least i - pos + 1 caves with h2 >= a[i] for each i >= pos
///let's reindexate the array so that it begins with pos and keep v[i] = cnt[i] - i the number of such caves
///v[i] should be non-negativa for each i
M = N - pos + 1, ans = -1;
for (int i=1; i<=M; i++)
    a[i] = a[i + pos - 1];
Build (1, 1, M);
for (int i=1; i<=N; i++)
    if (!ap[i])
    {
        place[i] = tallest_miner (h2[i]);
        if (place[i] <= M) Update (1, 1, M, place[i], M, +1);
    }
///now we'll try to change the height of each of the relevant caves to a[1] and update just at the moment
///the segment tree and then apply the inverse changes, right after checking whehter min >= 0 or not
for (int i=1; i<=N; i++)
    if (ap[t[i]] && ap[i] == 0)
    {
        int old = h[i];
        h[i] = a[1], df2 (i), h[i] = old;
        if (mi[1] >= 0 && (ans == -1 || ans > a[1] - h[i]))
            ans = a[1] - h[i];
        for (auto it = moves.begin (); it != moves.end (); it ++)
            Update (1, 1, M, it->first, it->second, -1);
        moves.clear ();
    }
printf ("%d\n", ans);
return 0;
}