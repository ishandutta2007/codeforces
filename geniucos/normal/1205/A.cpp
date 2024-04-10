#include<bits/stdc++.h>

using namespace std;

int N, a[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
if (N % 2 == 0)
    printf ("NO\n");
else
{
    printf ("YES\n");
    for (int i=1; i<=N; i++)
    {
        int bg = i << 1, sml = bg - 1;
        if (i & 1) swap (bg, sml);
        a[i] = sml, a[i + N] = bg;
    }
    for (int i=1; i<=2 * N; i++)
        printf ("%d%c", a[i], " \n"[i == 2 * N]);
}
return 0;
}