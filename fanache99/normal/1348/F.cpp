#include<bits/stdc++.h>

using namespace std;

int N, where[200009], a[200009], b[200009], ans[200009];
vector < int > v[200009];

void findAssignment ()
{
    set < pair < int, int > > S;
    for (int i=1; i<=N; i++)
    {
        for (auto j : v[i])
            S.insert ({b[j], j});
        auto it = S.lower_bound (make_pair (i, 0));
        assert (it != S.end ());
        ans[it->second] = i;
        where[i] = it->second;
        S.erase (it);
    }
}

void printAns ()
{
    for (int i=1; i<=N; i++)
        printf ("%d%c", ans[i], " \n"[i == N]);
}

void trySwap (int v1, int v2)
{
    int i = where[v1], j = where[v2];
    assert (a[j] <= v1 && v1 <= b[j] && a[i] <= v2 && v2 <= b[i]);
    printf ("NO\n");
    printAns ();
    swap (ans[i], ans[j]);
    printAns ();
    exit (0);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &a[i], &b[i]),
    v[a[i]].push_back (i);
findAssignment ();
set < int > S;
for (int i=1; i<=N; i++)
{
    for (auto j : v[i])
        S.insert (ans[j]);
    ///a[anything in S] <= i
    ///want some i < j <= b[where[i]]
    if (i < b[where[i]])
    {
        auto it = S.lower_bound (i + 1);
        if (it != S.end () && *it <= b[where[i]])
            trySwap (i, *it);
    }
}
printf ("YES\n");
printAns ();
return 0;
}