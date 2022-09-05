#include<bits/stdc++.h>

using namespace std;

int N, sz[100009], szQ[100009], ans[100009], ap[100009], col[100009], ma[100009], vol[100009], initQ[100009], init[100009];
const int mod = 1e9 + 7;
const int M = 1e7 + 2;
int cr[M + 3], *val[100009], *valQ[100009];
bool *type[100009], *typeQ[100009];
vector < int > comp;
vector < int > v[100009], fii[100009];
vector < pair < int, int > > qry[100009];

void multo (int &x, int y) {x = (1LL * x * y) % mod;}

int gcd (int a, int b)
{
    int r;
    while (b)
        r = a % b,
        a = b,
        b = r;
    return a;
}

void dfs (int nod)
{
    comp.push_back (nod);
    ap[nod] = 1;
    vol[nod] = 1;
    ma[nod] = 0;
    for (auto it : v[nod])
        if (ap[it] == 0)
        {
            dfs (it);
            vol[nod] += vol[it];
            if (vol[it] > ma[nod])
                ma[nod] = vol[it];
        }
}

void df2 (int nod)
{
    ap[nod] = 1;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (ap[*it] == 0)
            fii[nod].push_back (*it),
            col[*it] = col[nod],
            df2 (*it);
}

int cnt[2][M + 3], currCG;
bool rightNow[100009];
void df3 (int nod, bool isRoot)
{
    vector < pair < pair < int, bool >, int > > old;
    if (!isRoot)
    {
        for (int j=0; j<sz[nod]; j++)
            old.push_back ({{val[nod][j], type[nod][j]}, cnt[type[nod][j]][val[nod][j]]}),
            multo (cnt[type[nod][j]][val[nod][j]], val[nod][j]);
    }
    for (auto q : qry[nod])
        if (col[q.first] != col[nod] && rightNow[q.first] == 1)
        {
            int pos = q.second;
            for (int j=0; j<szQ[pos]; j++)
                if (typeQ[pos][j])
                    multo (ans[pos], cnt[0][valQ[pos][j]]),
                    multo (ans[pos], cnt[1][valQ[pos][j]]);
                else
                    multo (ans[pos], cnt[1][valQ[pos][j]]);
            if (nod < q.first)
                multo (ans[pos], gcd (init[currCG], initQ[pos]));
        }
    for (auto it : fii[nod])
        df3 (it, 0);
    if (!isRoot)
    {
        for (auto it : old)
            cnt[it.first.second][it.first.first] = it.second;
    }
}

void solve (int nod)
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

    ap[CG] = 1, col[CG] = -1;
    for (auto it : v[CG])
        if (ap[it] == 0)
            col[it] = it, df2 (it), fii[CG].push_back (it);
    for (auto it : comp)
        ap[it] = 0, rightNow[it] = 1;
    //////////////////////////////////////////////////////////////////////////////////pot parcurge arborele rutat in CG
    currCG = CG, df3 (CG, 1);
    //////////////////////////////////////////////////////////////////////////////////

    for (auto it : comp)
        fii[it].clear (), rightNow[it] = 0;

    ap[CG] = 2;
    for (vector < int > :: iterator it = v[CG].begin (); it != v[CG].end (); it ++)
        if (ap[*it] == 0)
            solve (*it);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

for (int i=2; i*i<=M; i++)
    if (cr[i] == 0)
        for (int j=i * i; j<=M; j+=i)
            cr[j] = i;
for (int i=2; i<=M; i++)
    if (cr[i] == 0)
        cr[i] = i;

scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
for (int i=1; i<=N; i++)
{
    int x;
    vector < int > curr, currT;
    scanf ("%d", &x), init[i] = x;
    while (x > 1)
    {
        int p = cr[x], e = 0;
        while (x % p == 0)
            x /= p, e ++;
        for (int j=1, k=p; j<=e; j++, k*=p)
            curr.push_back (k), currT.push_back (j == e);
    }
    val[i] = new int[curr.size ()], type[i] = new bool[curr.size ()], sz[i] = curr.size ();
    for (int j=0; j<curr.size (); j++)
        val[i][j] = curr[j], type[i][j] = currT[j];
}
int Q;
scanf ("%d", &Q);
for (int i=1; i<=Q; i++)
{
    int x, y, z;
    scanf ("%d %d %d", &x, &y, &z), initQ[i] = z;
    qry[x].push_back ({y, i});
    qry[y].push_back ({x, i});
    vector < int > curr, currT;
    while (z > 1)
    {
        int p = cr[z], e = 0;
        while (z % p == 0)
            z /= p, e ++;
        for (int j=1, k=p; j<=e; j++, k*=p)
            curr.push_back (k), currT.push_back (j == e);
    }
    valQ[i] = new int[curr.size ()], typeQ[i] = new bool[curr.size ()], szQ[i] = curr.size ();
    for (int j=0; j<curr.size (); j++)
        valQ[i][j] = curr[j], typeQ[i][j] = currT[j];
    ans[i] = 1;
    if (x == y)
        ans[i] = gcd (initQ[i], init[x]);
}
for (int i=1; i<=M; i++)
    cnt[0][i] = cnt[1][i] = 1;
/*for (int i=1; i<=N; i++, printf ("\n"))
    for (int j=0; j<sz[i]; j++)
        printf ("%d ", val[i][j]);
for (int i=1; i<=Q; i++, printf ("\n"))
    for (int j=0; j<szQ[i]; j++)
        printf ("%d ", valQ[i][j]);*/
solve (1);
for (int i=1; i<=Q; i++)
    printf ("%d\n", ans[i]);
return 0;
}