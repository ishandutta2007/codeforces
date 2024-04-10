#include<bits/stdc++.h>

using namespace std;

const int NMAX = 500009;
//const int NMAX = 100;
int N, Q, t[NMAX][20], rgt[NMAX], w[NMAX], lev[NMAX], lg[NMAX];
long long lftImprovement[NMAX][20], rgtImprovement[NMAX][20], minH[NMAX], h[NMAX], rmq[20][NMAX];
const long long INF = 1LL << 60;
vector < int > v[NMAX];

void init ()
{
    scanf ("%d %d", &N, &Q);
    for (int i=2; i<=N; i++)
        scanf ("%d %d", &t[i][0], &w[i]),
        lev[i] = lev[t[i][0]] + 1, h[i] = h[t[i][0]] + w[i],
        v[t[i][0]].push_back (i);
    for (int i=1; i<=N; i++)
        for (int j=1; (1 << j) <= lev[i]; j++)
            t[i][j] = t[t[i][j - 1]][j - 1];
    for (int i=N; i>=1; i--)
        if (v[i].empty ()) minH[i] = h[i], rgt[i] = i;
        else
        {
            minH[i] = INF, rgt[i] = i;
            for (auto j : v[i])
                minH[i] = min (minH[i], minH[j]),
                rgt[i] = max (rgt[i], rgt[j]);
        }
    for (int i=1; i<=N; i++)
        lftImprovement[i][0] = rgtImprovement[i][0] = INF;
    for (int i=1; i<=N; i++)
    {
        long long soFar = INF;
        for (auto j : v[i])
        {
            lftImprovement[j][0] = soFar;
            soFar = min (soFar, minH[j] - 2LL * h[i]);
        }
        soFar = INF;
        for (auto it = v[i].rbegin (); it != v[i].rend (); it ++)
        {
            int j = *it;
            rgtImprovement[j][0] = soFar;
            soFar = min (soFar, minH[j] - 2LL * h[i]);
        }
    }
    for (int i=1; i<=N; i++)
        for (int j=1; (1 << j) <= lev[i]; j++)
            lftImprovement[i][j] = min (lftImprovement[i][j - 1], lftImprovement[t[i][j - 1]][j - 1]),
            rgtImprovement[i][j] = min (rgtImprovement[i][j - 1], rgtImprovement[t[i][j - 1]][j - 1]);
    for (int i=2; i<=N; i++)
        lg[i] = lg[i >> 1] + 1;
    for (int i=1; i<=N; i++)
        if (v[i].empty ()) rmq[0][i] = h[i];
        else rmq[0][i] = INF;
    for (int i=1; i<=lg[N]; i++)
        for (int j=1; j + (1 << i) - 1 <= N; j++)
            rmq[i][j] = min (rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
}

long long getMinOnRange (int i, int j)
{
    if (i > j) return INF;
    int p = lg[j - i + 1];
    return min (rmq[p][i], rmq[p][j - (1 << p) + 1]);
}

long long getAns (int v, int x, int y)
{
    if (x > y)
        return INF;
    ///[v, rgt[v]] and [x, y] are disjoint
    long long ans = INF;
    if (y < v)
    {
        int q = v;
        for (int i=lg[lev[q]]; i>=0; i--)
            if ((1 << i) <= lev[q] && t[q][i] > y)
                q = t[q][i];
        q = t[q][0];///now q <= y <= rgt[q]
        ans = getMinOnRange (max (x, q), y) - 2LL * h[q];
        if (x < q)
        {
            ///now, as long as x <= q, we can look at what's new on left, and then we stop
            for (int i=lg[lev[q]]; i>=0; i--)
                if ((1 << i) <= lev[q] && x <= t[q][i])
                    ans = min (ans, lftImprovement[q][i]),
                    q = t[q][i];
            q = t[q][0];
            if (q != 0)
            {
                ///q < x <= y <= rgt[q]
                ans = min (ans, getMinOnRange (x, y) - 2LL * h[q]);
            }
        }
    }
    else
    if (rgt[v] < x)
    {
        int q = v;
        for (int i=lg[lev[q]]; i>=0; i--)
            if ((1 << i) <= lev[q] && rgt[t[q][i]] < x)
                q = t[q][i];
        q = t[q][0];///now q <= x <= rgt[q]
        ans = getMinOnRange (x, min (rgt[q], y)) - 2LL * h[q];
        if (rgt[q] < y)
        {
            ///now, as long as rgt[q] <= y, we can look at what's new on right, and then we stop
            for (int i=lg[lev[q]]; i>=0; i--)
                if ((1 << i) <= lev[q] && rgt[t[q][i]] <= y)
                    ans = min (ans, rgtImprovement[q][i]),
                    q = t[q][i];
            q = t[q][0];
            if (q != 0)
            {
                ///q <= x <= y < rgt[q]
                ans = min (ans, getMinOnRange (x, y) - 2LL * h[q]);
            }
        }
    }
    return ans;
}

const bool DBG = 0;
namespace brute {
    vector < pair < int, int > > e[209];
    long long d[209][209];
    void dfs (int lin, int nod, long long s, int t)
    {
        d[lin][nod] = s;
        for (auto it : e[nod])
            if (it.first != t)
                dfs (lin, it.first, s + it.second, nod);
    }
    void init ()
    {
        for (int i=1; i<=N; i++)
            for (auto j : v[i])
                e[i].push_back ({j, w[j]}),
                e[j].push_back ({i, w[j]});
        for (int i=1; i<=N; i++)
            dfs (i, i, 0, -1);
    }
    long long brute (int vv, int x, int y)
    {
        long long ans = INF;
        for (int i=x; i<=y; i++)
            if (v[i].empty ())
                ans = min (ans, d[vv][i]);
        return ans;
    }
}

long long getFinalAns (int v, int x, int y)
{
    long long ans = getMinOnRange (max (x, v), min (y, rgt[v])) - 2LL * h[v];
    if (x < v)
        ans = min (ans, getAns (v, x, min (v - 1, y)));
    if (rgt[v] < y)
        ans = min (ans, getAns (v, max (rgt[v] + 1, x), y));
    return ans + h[v];
}

void check ()
{
    for (int i=1; i<=N; i++)
    {
        bool anyLeaf = 0;
        for (int j=i; j<=N; j++)
        {
            anyLeaf |= (v[j].empty ());
            if (anyLeaf)
            {
                for (int k=1; k<=N; k++)
                    if (getFinalAns (k, i, j) != brute::brute (k, i, j))
                    {
                        printf ("WA %d %d %d\n%I64d instead of %I64d\n", k, i, j, getFinalAns (k, i, j), brute::brute (k, i, j));
                        exit (0);
                    }
            }
        }
    }
    printf ("OK\n");
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

init ();
if (DBG)
    brute::init ();
if (DBG) check ();
while (Q --)
{
    int v, x, y;
    scanf ("%d %d %d", &v, &x, &y);
    printf ("%I64d\n", getFinalAns (v, x, y));
}
return 0;
}