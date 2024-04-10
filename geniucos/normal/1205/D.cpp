#include<bits/stdc++.h>

using namespace std;

int CG, N, e[2009], ma[2009], vol[2009], t[2009], leftSide[2009];
vector < int > sons[2009], v[2009];

void dfs (int nod)
{
    vol[nod] = 1, ma[nod] = 0;
    for (auto it : v[nod])
        if (vol[it] == 0)
            dfs (it), vol[nod] += vol[it], ma[nod] = max (ma[nod], vol[it]);
}

void df2 (int nod)
{
    vol[nod] = 1;
    for (auto it : v[nod])
        if (vol[it] == 0)
            df2 (it), vol[nod] += vol[it], sons[nod].push_back (it);
}

bool ok (int s)
{
//    if ((s + 1) * (N - 1 - s + 1) - 1 >= (2 * N * N) / 9)
  //      printf ("%d\n", (s + 1) * (N - 1 - s + 1) - 1);
    return ((s + 1) * (N - 1 - s + 1) - 1 >= (2 * N * N) / 9);
}

vector < int > q[2];
void df3 (int nod, int tt, int isLeft)
{
    t[nod] = tt, leftSide[nod] = isLeft;
    q[isLeft].push_back (nod);
    for (auto it : sons[nod])
        df3 (it, nod, isLeft);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
dfs (1), CG = 1;
for (int i=1; i<=N; i++)
{
    ma[i] = max (ma[i], N - vol[i]);
    if (ma[i] < ma[CG])
        CG = i;
}
//assert (ma[CG] <= N / 2);
for (int i=1; i<=N; i++)
    vol[i] = 0;
df2 (CG);
vector < pair < int, int > > h;
for (auto f : sons[CG])
    h.push_back ({vol[f], f});//, printf ("%d %d\n", vol[f], f);
int s = 0;
bool isOk = 0;
sort (h.begin (), h.end ());
for (auto curr : h)
{
    int sz = curr.first, f = curr.second;
    if (ok (s))
    {
        isOk = 1;
        break;
    }
    s += sz, leftSide[f] = 1;
}
//assert (ok (s) || isOk);
int y = N - 1 - s;
for (auto f : sons[CG])
    df3 (f, CG, leftSide[f]);
int curr = 0;
for (auto nod : q[1])
    curr += y + 1, e[nod] = curr;
curr = 0;
for (auto nod : q[0])
    curr ++, e[nod] = curr;
for (int i=1; i<=N; i++)
    if (i != CG)
        printf ("%d %d %d\n", i, t[i], e[i] - e[t[i]]);
return 0;
}