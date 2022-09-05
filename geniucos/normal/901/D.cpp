#include<bits/stdc++.h>

using namespace std;

int N, M, C[100009], ap[100009], lev[100009], fath[100009], label[100009];
long long x[100009], su[100009], ans[100009], spart[200009];
vector < int > cyc;
vector < pair < int, int > > v[100009];
map < pair < int, int >, int > mp;

void dfsInit (int nod, int col)
{
    ap[nod] = 1, C[nod] = col;
    for (auto it : v[nod])
        if (ap[it.first] == 0)
            lev[it.first] = lev[nod] + 1, fath[it.first] = nod, dfsInit (it.first, col ^ 1);
}

int getCode (int x, int y) {if (x > y) swap (x, y); return mp[{x, y}];}

void dfsOdd (int nod)
{
    ap[nod] = 0;
    for (auto e : v[nod])
    {
        if (ap[e.first] == 0) continue;
        dfsOdd (e.first), ans[e.second] += su[e.first];
        su[nod] -= su[e.first], su[e.first] = 0;
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%I64d", &su[i]);
for (int i=1; i<=M; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back ({y, i});
    v[y].push_back ({x, i});
    if (x > y) swap (x, y);
    mp[{x, y}] = i;
}
dfsInit (1, 0);
bool foundOddCycle = 0;
for (int i=1; i<=N; i++)
    for (auto jj : v[i])
    {
        int j = jj.first;
        if (C[i] == C[j])
        {
            ///it's not bipartite
            vector < int > secondHalf;
            while (i != j)
            {
                if (lev[i] > lev[j]) cyc.push_back (i), i = fath[i];
                else secondHalf.push_back (j), j = fath[j];
            }
            cyc.push_back (i);
            for (auto it = secondHalf.rbegin (); it != secondHalf.rend (); it ++)
                cyc.push_back (*it);
            foundOddCycle = 1;
            i = N + 1; break;
        }
    }
if (foundOddCycle)
{
    for (int i=1; i<=M; i++)
        ans[i] ++;
    for (int i=1; i<=N; i++)
        su[i] -= (long long) v[i].size ();
    int L = cyc.size ();
    for (int i=0; i<L; i++)
        ap[cyc[i]] = 0, label[i] = getCode (cyc[i], cyc[(i + 1) % L]);
    for (int i=0; i<L; i++)
        dfsOdd (cyc[i]);
    printf ("YES\n");
    for (int i=0; i<L; i++)
        x[i] = su[cyc[i]];
    long long overAll = 0;
    for (int i=0; i<L; i++)
    {
        x[i] /= 2;
        ///ans[i], ans[i + 2], ans[i + 4], .., ans[i + 2 * ((L - 1) / 2)] += x[i]
        spart[i] += 2LL * x[i], spart[i + L + 1] -= 2LL * x[i];
        overAll -= x[i];///assuming I decreased this amount from all of them and increased those doubled
    }
    for (int i=0; i<2 * L; i++)
    {
        if (i >= 2) spart[i] += spart[i - 2];
        ans[label[i % L]] += spart[i];
    }
    for (int i=0; i<L; i++)
        ans[label[i]] += overAll;
    for (int i=1; i<=M; i++)
        printf ("%I64d\n", ans[i]);
    return 0;
}
long long sParity[2] = {0, 0};
for (int i=1; i<=N; i++)
    sParity[C[i]] += su[i];
if (sParity[0] != sParity[1])
{
    printf ("NO\n");
    return 0;
}
dfsOdd (1);
printf ("YES\n");
for (int i=1; i<=M; i++)
    printf ("%I64d\n", ans[i]);
return 0;
}