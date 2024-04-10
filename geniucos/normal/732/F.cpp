#include<bits/stdc++.h>

using namespace std;

int root, nr, N, M, maxi, curr_sz, ver_1[400009], ver_2[400009], ap[400009], niv[400009], dp[400009];
bool ori[400009], critical[400009];
vector < pair < int, int > > v[400009];
vector < int > h[400009];

void dfs (int nod, int tata)
{
    dp[nod] = niv[nod];
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
    if (niv[it->first] == 0)
    {
        niv[it->first] = niv[nod] + 1;
        dfs (it->first, nod);
        if (dp[it->first] > niv[nod]) critical[it->second] = 1;
    }
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (it->first != tata && dp[it->first] < dp[nod]) dp[nod] = dp[it->first];
}

void det_comps (int nod)
{
    ap[nod] = nr, curr_sz ++;
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if ((!critical[it->second]) && ap[it->first] == 0)
            niv[it->first] = niv[nod] + 1, ori[it->second] = 1, det_comps (it->first);
}

void build_tree (int nod)
{
    for (auto it = h[nod].begin (); it != h[nod].end (); it ++)
        if (dp[*it] == 0)
            dp[*it] = dp[nod] + 1, build_tree (*it);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=M; i++)
    scanf ("%d %d", &ver_1[i], &ver_2[i]), v[ver_1[i]].push_back (make_pair (ver_2[i], i)), v[ver_2[i]].push_back (make_pair (ver_1[i], i));
niv[1] = 1, dfs (1, -1);
for (int i=1; i<=N; i++)
    niv[i] = 0, dp[i] = 0;
for (int i=1; i<=N; i++)
    if (niv[i] == 0)
    {
        curr_sz = 0, nr ++, niv[i] = 1, det_comps (i);
        if (curr_sz > maxi) maxi = curr_sz, root = nr;
    }
for (int i=1; i<=M; i++)
    if (critical[i])
        h[ap[ver_1[i]]].push_back (ap[ver_2[i]]), h[ap[ver_2[i]]].push_back (ap[ver_1[i]]);
dp[root] = 1, build_tree (root);
printf ("%d\n", maxi);
for (int i=1; i<=M; i++)
{
    int x = ver_1[i], y = ver_2[i];
    if (ap[x] == ap[y])
    {
        if (ori[i])
        {
            if (niv[x] < niv[y]) ;
            else swap (x, y);
        }
        else
        if (niv[x] < niv[y]) swap (x, y);
    }
    else
    if (dp[ap[x]] < dp[ap[y]]) swap (x, y);
    printf ("%d %d\n", x, y);
}
return 0;
}