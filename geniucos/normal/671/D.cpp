#include<bits/stdc++.h>

using namespace std;

int nr, N, M, st[300009], dr[300009], ps[300009], c[300009];
long long ansQ, INF = 5e14, dp[300009], add[1048570], aint[1048570];
vector < int > ad[300009], del[300009], v[300009];

void dfs (int nod, int tata)
{
    st[nod] = nr + 1;
    for (auto it = ad[nod].begin (); it != ad[nod].end (); it ++)
        ps[*it] = ++nr;
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (*it != tata)
            dfs (*it, nod);
    dr[nod] = nr;
}

void do_add (long long &x, long long y)
{
    x += y;
    if (x > 2LL * INF) x = 2 * INF;
}

void split (int nod)
{
    if (add[nod] == 0) return ;
    int f1 = nod << 1, f2 = f1 | 1;
    do_add (add[f1], add[nod]), do_add (add[f2], add[nod]);
    do_add (aint[f1], add[nod]), do_add (aint[f2], add[nod]);
    add[nod] = 0;
}

void Build (int nod, int st, int dr)
{
    aint[nod] = INF;
    if (st == dr) return ;
    int mij = (st + dr) >> 1;
    Build (nod << 1, st, mij);
    Build (nod << 1 | 1, mij + 1, dr);
}

void Update (int nod, int st, int dr, int pos, long long val)
{
    if (st == dr)
    {
        aint[nod] = val, do_add (aint[nod], add[nod]);
        return ;
    }
    int mij = (st + dr) >> 1;
    split (nod);
    if (pos <= mij) Update (nod << 1, st, mij, pos, val);
    else Update (nod << 1 | 1, mij + 1, dr, pos, val);
    aint[nod] = min (aint[nod << 1], aint[nod << 1 | 1]);
}

void Update2 (int nod, int st, int dr, int x, int y, long long val)
{
    if (x <= st && dr <= y)
    {
        do_add (add[nod], val), do_add (aint[nod], val);
        return ;
    }
    int mij = (st + dr) >> 1;
    split (nod);
    if (x <= mij) Update2 (nod << 1, st, mij, x, y, val);
    if (mij < y) Update2 (nod << 1 | 1, mij + 1, dr, x, y, val);
    aint[nod] = min (aint[nod << 1], aint[nod << 1 | 1]);
}

void Query (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        if (aint[nod] < ansQ) ansQ = aint[nod];
        return ;
    }
    int mij = (st + dr) >> 1;
    split (nod);
    if (x <= mij) Query (nod << 1, st, mij, x, y);
    if (mij < y) Query (nod << 1 | 1, mij + 1, dr, x, y);
}

void solve (int nod, int tata)
{
    long long sum_fii = 0;
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (*it != tata)
            solve (*it, nod), do_add (sum_fii, dp[*it]);
    if (nod == 1)
    {
        dp[1] = sum_fii;
        return ;
    }
    for (auto it = ad[nod].begin (); it != ad[nod].end (); it ++)
        Update (1, 1, nr, ps[*it], c[*it] + sum_fii);
    for (auto it = del[nod].begin (); it != del[nod].end (); it ++)
        Update (1, 1, nr, ps[*it], 2LL * INF);
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (*it != tata && st[*it] <= dr[*it])
            Update2 (1, 1, nr, st[*it], dr[*it], sum_fii - dp[*it]);
    ansQ = INF;
    if (st[nod] <= dr[nod]) Query (1, 1, nr, st[nod], dr[nod]);
    dp[nod] = ansQ;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
for (int i=1; i<=M; i++)
{
    int u, v;
    scanf ("%d %d %d", &u, &v, &c[i]);
    ad[u].push_back (i), del[v].push_back (i);
}
dfs (1, -1), Build (1, 1, nr);
solve (1, -1);
if (dp[1] >= INF) dp[1] = -1;
printf ("%I64d\n", dp[1]);

return 0;
}