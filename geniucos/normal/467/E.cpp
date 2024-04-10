#include<bits/stdc++.h>

using namespace std;

int ansQ, N, dp[500009], ap[500009], a[500009], prv[500009], nxt[500009], lft[500009], how[500009], realVal[500009], aint[2000009];
pair < int, int > nrm[500009];

void read ()
{
    scanf ("%d", &N);
    for (int i=1; i<=N; i++)
        scanf ("%d", &nrm[i].first), nrm[i].second = i;
    sort (nrm + 1, nrm + N + 1);
    for (int i=1; i<=N; i++)
        a[nrm[i].second] = (i == 1 ? 1 : a[nrm[i - 1].second] + (nrm[i].first != nrm[i - 1].first)),
        realVal[a[nrm[i].second]] = nrm[i].first;
    for (int i=1; i<=N; i++)
    {
        prv[i] = ap[a[i]];
        ap[a[i]] = i;
    }
    for (int i=1; i<=N; i++)
        ap[i] = 0;
    for (int i=N; i>=1; i--)
    {
        if (ap[a[i]] == 0) nxt[i] = N + 1;
        else nxt[i] = ap[a[i]];
        ap[a[i]] = i;
    }
}

void Build (int nod, int st, int dr)
{
    aint[nod] = N + 1;
    if (st == dr) return ;
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    Build (f1, st, mij);
    Build (f2, mij + 1, dr);
}

void Update (int nod, int st, int dr, int pos, int val)
{
    if (st == dr)
    {
        aint[nod] = val;
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (pos <= mij) Update (f1, st, mij, pos, val);
    else Update (f2, mij + 1, dr, pos, val);
    aint[nod] = min (aint[f1], aint[f2]);
}

void Query (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        if (x == st) ansQ = aint[nod];
        else ansQ = min (ansQ, aint[nod]);
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (x <= mij) Query (f1, st, mij, x, y);
    if (mij < y) Query (f2, mij + 1, dr, x, y);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

read ();
Build (1, 1, N);
for (int i=1; i<=N; i++)
{
    if (prv[i] > 0 && prv[i] + 1 < i)
    {
        Query (1, 1, N, prv[i] + 1, i - 1);
        if (ansQ <= N && prv[i] > lft[ansQ])
            lft[ansQ] = prv[i];
    }
    if (prv[i] != 0) Update (1, 1, N, prv[i], N + 1);
    Update (1, 1, N, i, nxt[i]);
}
for (int i=1; i<=N; i++)
    if (prv[i] > 0 && prv[prv[i]] > 0 && prv[prv[prv[i]]] > lft[i])
        lft[i] = prv[prv[prv[i]]];
dp[0] = 0;
for (int i=1; i<=N; i++)
{
    dp[i] = dp[i - 1], how[i] = how[i - 1];
    if (lft[i] > 0 && dp[lft[i] - 1] + 1 > dp[i])
        dp[i] = dp[lft[i] - 1] + 1, how[i] = i;
}
printf ("%d\n", 4 * dp[N]);
vector < int > ans;
int i = how[N];
while (i > 0)
{
    ans.push_back (a[i]), ans.push_back (a[lft[i]]);
    ans.push_back (a[i]), ans.push_back (a[lft[i]]);
    i = how[lft[i] - 1];
}
for (auto it = ans.rbegin (); it != ans.rend (); it ++)
    printf ("%d ", realVal[*it]);
printf ("\n");
return 0;
}