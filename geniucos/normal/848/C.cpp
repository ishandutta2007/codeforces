#include<bits/stdc++.h>

using namespace std;

int N, M, a[100009], ap[100009], prv[100009];
map < int, long long > aib[100009];

void U (int x, int y, int val)
{
    for (int i=x; i<=N; i += i - (i & (i - 1)))
        for (int j=y; j<=N; j += j - (j & (j - 1)))
            aib[i][j] += val;
}

long long Q (int x, int y)
{
    long long ans = 0;
    for (int i=x; i>0; i &= i - 1)
        for (int j=y; j>0; j &= j - 1)
            if (aib[i].count (j))
                ans += aib[i][j];
    return ans;
}

void add (int i, int prv, int sg)
{
/*    if (sg == 1) printf ("+ ");
    else printf ("- ");
    printf ("(%d, %d)\n", i, prv);*/
    int val = i - prv;
    U (i, N - prv + 1, sg * val);
}

long long qry (int st, int dr)
{
    return Q (dr, N - st + 1);
}

set < pair < int, int > > S;
int getRealPrev (int pos, int newA)
{
    auto it = S.lower_bound ({newA, pos});
    if (it == S.begin ()) return 0;
    it --;
    if (it->first == newA) return it->second;
    return 0;
}

int getRealNext (int pos, int newA)
{
    auto it = S.upper_bound ({newA, pos});
    if (it != S.end () && it->first == newA) return it->second;
    return 0;
}

void ReadInit ()
{
    scanf ("%d %d", &N, &M);
    for (int i=1; i<=N; i++)
    {
        scanf ("%d", &a[i]);
        if (ap[a[i]] != 0) prv[i] = ap[a[i]];
        ap[a[i]] = i;
    }
    for (int i=1; i<=N; i++)
    {
        ap[i] = 0;
        if (prv[i] != 0)
            add (i, prv[i], +1);
    }
    for (int i=1; i<=N; i++)
        S.insert ({a[i], i});
}

void changePrv (int i, int newPrv)
{
    if (prv[i] == newPrv) return ;
    if (prv[i] != 0)
        add (i, prv[i], -1);
    prv[i] = newPrv;
    if (prv[i] != 0)
        add (i, prv[i], +1);
}

void Change (int pos, int val)
{
    if (val == a[pos]) return ;
    S.erase ({a[pos], pos});
    int prv = getRealPrev (pos, a[pos]), nxt = getRealNext (pos, a[pos]);
    if (nxt != 0) changePrv (nxt, prv);
    int i = getRealPrev (pos, val), j = getRealNext (pos, val);
    if (j != 0) changePrv (j, pos);
    changePrv (pos, i);
    S.insert ({val, pos}), a[pos] = val;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

ReadInit ();
while (M --)
{
    int type, x, y;
    scanf ("%d %d %d", &type, &x, &y);
    if (type == 1) Change (x, y);
    else printf ("%I64d\n", qry (x, y));
}

return 0;
}