#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    int N;
    scanf ("%d", &N);
    vector < int > v[2];
    v[0].clear (), v[1].clear ();
    for (int i=1; i<=N; i++)
    {
        int x;
        scanf ("%d", &x);
        v[x & 1].push_back (i);
    }
    if (!v[0].empty ()) printf ("1\n%d\n", v[0][0]);
    else
    if (v[1].size () >= 2) printf ("2\n%d %d\n", v[1][0], v[1][1]);
    else printf ("-1\n");
}
return 0;
}