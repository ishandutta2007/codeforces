#include<bits/stdc++.h>

using namespace std;

int xo, N, t[500009], vol[500009], P[500009], dp[500009], lev[500009], deep[1 << 22];
char c[500009];
vector < int > v[500009];

void UpdateDeep (int i, int j) {if (deep[i] == 0 || deep[i] < j) deep[i] = j;}
void UpdateDp (int i, int j) {if (j > dp[i]) dp[i] = j;}

void dfQ (int x, int nod, int msk)
{
    ///incerc sa combin msk cu ce am pana acu
    if (deep[msk ^ xo] != 0) UpdateDp (x, deep[msk ^ xo] + lev[nod] - 2 * lev[x]);
    for (int i=0; i<22; i++)
        if (deep[msk ^ (1 << i) ^ xo] != 0)
            UpdateDp (x, deep[msk ^ (1 << i) ^ xo] + lev[nod] - 2 * lev[x]);
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        dfQ (x, *it, msk ^ (1 << c[*it]));
}

void dfP (int nod, int msk, bool cl)
{
    ///incerc sa combin modific deep (fie sterg fie imbunatatesc)
    if (cl) deep[msk ^ xo] = 0;
    else UpdateDeep (msk ^ xo, lev[nod]);
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        dfP (*it, msk ^ (1 << c[*it]), cl);
}

void solve (int nod, bool destroy)
{
    if (P[nod] == -1)
    {
        xo = 0;
        if (!destroy) deep[0] = lev[nod];
        return ;
    }
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (*it != P[nod])
            solve (*it, 1), UpdateDp (nod, dp[*it]);
    int cc = 1 << c[P[nod]];
    solve (P[nod], 0), UpdateDp (nod, dp[P[nod]]);
    if (deep[cc ^ xo]) UpdateDp (nod, deep[cc ^ xo] - lev[nod]);
    for (int i=0; i<22; i++)
        if (deep[cc ^ (1 << i) ^ xo])
            UpdateDp (nod, deep[cc ^ (1 << i) ^ xo] - lev[nod]);
    xo ^= cc, UpdateDeep (xo, lev[nod]);
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (*it != P[nod])
            dfQ (nod, *it, 1 << c[*it]), dfP (*it, 1 << c[*it], 0);
    if (destroy) dfP (nod, 0, 1), xo = 0;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), P[1] = -1;
for (int i=2; i<=N; i++)
    scanf ("%d %c\n", &t[i], &c[i]), c[i] -= 'a', P[i] = -1, v[t[i]].push_back (i), lev[i] = lev[t[i]] + 1;
for (int i=N; i>=1; i--)
{
    vol[i] ++, vol[t[i]] += vol[i];
    if (P[t[i]] == -1 || vol[P[t[i]]] < vol[i]) P[t[i]] = i;
}
solve (1, 0);
for (int i=1; i<=N; i++)
    printf ("%d\n", dp[i]);
printf ("\n");

return 0;
}