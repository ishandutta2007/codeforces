#include<bits/stdc++.h>

using namespace std;

int N;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests, N;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d", &N);
    if (N == 1)
    {
        printf ("-1\n");
        continue;
    }
    if (N % 9 != 1)
    {
        for (int i=1; i<=N; i++)
            printf ("%d", (i < N ? 2 : 9));
        printf ("\n");
        continue;
    }
    for (int i=1; i<=N; i++)
        printf ("%d", (i < N - 1 ? 2 : 9));
    printf ("\n");
}

return 0;
}