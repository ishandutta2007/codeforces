#include<bits/stdc++.h>

using namespace std;

int Tests, n1, n2, n3, m1, m2, m3, s1, s2, s3, cr[1000009], E[1000009], nr, pr[1009];
long long N, M, S, INF = 1e18, nd[1009];

void add (int p, int e)
{
    if (E[p] == 0) pr[++nr] = p;
    E[p] += e;
}

void clr ()
{
    for (int i=1; i<=nr; i++)
        E[pr[i]] = 0;
}

void getDecomp (int a, int b, int c, bool doi)
{
    nr = 0;
    vector < int > h = {a, b, c};
    for (auto x : h)
    {
        while (x != 1)
        {
            int p = cr[x], e = 0;
            while (x % p == 0)
                e ++, x /= p;
            add (p, e);
        }
    }
    if (doi) add (2, 1);
}

void addAns (long long &ans, vector < int > ids, long long lim)
{
    for (int msk = 0; msk < 1 << ids.size (); msk ++)
    {
        long long nd2 = 1;
        int sg = 0;
        for (int i=0; i<ids.size (); i++)
            if (msk & (1 << i))
                sg ^= 1, nd2 *= nd[ids[i]];
        if (sg == 0) ans += lim / nd2;
        else ans -= lim / nd2;
    }
}

void back (int pos, long long val, long long lim, long long &ans)
{
    if (pos == nr + 1)
    {
        ans ++;
        return ;
    }
    back (pos + 1, val, lim, ans);
    for (int i=1; i<=E[pr[pos]]; i++)
    {
        if (val > lim / pr[pos]) return ;
        val *= pr[pos], back (pos + 1, val, lim, ans);
    }
}

int main ()
{
for (int i=2; i*i<=1000000; i++)
    if (cr[i] == 0)
    {
        for (int j=i*i;j<=1000000; j+=i)
            cr[j] = i;
    }
for (int i=2; i<=1000000; i++)
    if (cr[i] == 0)
        cr[i] = i;
scanf ("%d", &Tests);
while (Tests --)
{
    scanf ("%d %d %d", &n1, &n2, &n3), N = 1LL * n1 * n2 * n3;
    scanf ("%d %d %d", &m1, &m2, &m3), M = 1LL * m1 * m2 * m3;
    scanf ("%d %d %d", &s1, &s2, &s3), S = 1LL * s1 * s2 * s3;
    vector < int > pN;
    getDecomp (n1, n2, n3, 0), clr ();
    for (int i=1; i<=nr; i++)
        pN.push_back (pr[i]);

    getDecomp (s1, s2, s3, 1);
    vector < int > ids;
    for (int i=1; i<=nr; i++)
    {
        nd[i] = 1;
        for (int j=1; j<=E[pr[i]]; j++)
            nd[i] *= pr[i];
        if (nd[i] <= INF / pr[i]) nd[i] *= pr[i];
        else nd[i] = -1;
        if (nd[i] != -1 && N % nd[i] == 0) ids.push_back (i);
    }
    long long ans = 0;
    back (1, 1, N, ans);
    for (auto p : pN)
        if (E[p] == 0)
            nd[++nr] = p, ids.push_back (nr);
    addAns (ans, ids, M);
    printf ("%I64d\n", ans), clr ();
}
return 0;
}