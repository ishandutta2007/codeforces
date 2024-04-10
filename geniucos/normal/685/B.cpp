#include<bits/stdc++.h>

using namespace std;

int N, M, t[300009], sz[300009], ans[300009];
vector < int > v[300009];

void solve (int nod)
{
    sz[nod] = 1;
    if (v[nod].empty ())
    {
        ans[nod] = nod;
        return ;
    }
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
    {
        solve (*it);
        sz[nod] += sz[*it];
    }
    int val = -1;
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (2 * sz[*it] > sz[nod])
            val = *it;
    if (val == -1)
    {
        ans[nod] = nod;
        return ;
    }
    int curr = ans[val];
    while (2 * sz[curr] <= sz[nod]) curr = t[curr];
    ans[nod] = curr;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=2; i<=N; i++)
    scanf ("%d", &t[i]), v[t[i]].push_back (i);
solve (1);
while (M --)
{
    int x;
    scanf ("%d", &x);
    printf ("%d\n", ans[x]);
}
return 0;
}