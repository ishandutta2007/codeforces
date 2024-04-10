#include<bits/stdc++.h>

using namespace std;

int nr, N, M, rst[300009], frm[300009], stk[300009], ap[300009];
long long s[300009];
vector < int > v[300009];

void dfs (int nod, int tata)
{
    stk[++nr] = nod, ap[nod] = -nr;
    for (auto it : v[nod])
    {
        if (it == tata) continue;
        if (ap[it] == 0) dfs (it, nod);
        else
        if (ap[it] < 0)
        {
            int pos = -ap[it];
            vector < int > curr;
            for (int i=pos; i<=nr; i++)
                curr.push_back (stk[i]);
            sort (curr.begin (), curr.end ());
            rst[curr[curr.size () - 1]] = max (rst[curr[curr.size () - 1]], curr[0] + 1);
        }
    }
    nr --, ap[nod] = 1;
}

long long getAns (int st, int dr)
{
    if (st > dr) return 0LL;
    return 1LL * (dr - st + 1) * (st + dr + 2) / 2 - (s[dr] - s[st - 1]);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
while (M --)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
for (int i=1; i<=N; i++)
    rst[i] = 1;
for (int i=1; i<=N; i++)
    if (ap[i] == 0)
        dfs (i, -1);
int j = 1;
for (int i=1; i<=N; i++)
{
    j = max (j, rst[i]);
    frm[i] = j, s[i] = s[i - 1] + frm[i];
}
//for (int i=1; i<=N; i++)
  //  printf ("%d%c", frm[i], " \n"[i == N]);
int Q;
scanf ("%d", &Q);
while (Q --)
{
    int lft, rgt, p, u, mij, ras = -1;
    scanf ("%d %d", &lft, &rgt), p = lft, u = rgt;
    long long Ans = 1LL * (rgt - lft + 1) * (lft + rgt + 2) / 2;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (frm[mij] < lft) ras = mij, p = mij + 1;
        else u = mij - 1;
    }
    if (ras == -1) Ans -= (s[rgt] - s[lft - 1]);
    else Ans -= (s[rgt] - s[ras]), Ans -= 1LL * (ras - lft + 1) * lft;
    printf ("%I64d\n", Ans);
}
return 0;
}