#include<bits/stdc++.h>

using namespace std;

int N, tests, a[400009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

//for (int i=-10; i<=10; i++)
  //  printf ("%d\n", i % 4);

scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d", &N);
    for (int i=0; i<N; i++)
    {
        scanf ("%d", &a[i]),
        a[i] += i, a[i] %= N;
        if (a[i] < 0)
            a[i] += N;
    }
    sort (a, a + N);
    bool ok = 1;
    for (int i=1; i<N; i++)
        if (a[i] == a[i - 1])
        {
            ok = 0;
            break;
        }
    if (ok) printf ("YES\n");
    else printf ("NO\n");
}

return 0;
}