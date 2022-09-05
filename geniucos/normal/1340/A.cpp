#include<bits/stdc++.h>

using namespace std;

int N, a[1000009], pos[1000009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d", &N);
    for (int i=1; i<=N; i++)
        scanf ("%d", &a[i]),
        pos[a[i]] = i;
    bool ok = 1;
    for (int i=2; i<=N; i++)
        if (pos[i] != pos[i - 1] + 1)
            ok &= (pos[i - 1] == N || a[pos[i - 1] + 1] < i);
    if (ok) printf ("Yes\n");
    else printf ("No\n");
}

return 0;
}