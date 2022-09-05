#include<bits/stdc++.h>

using namespace std;

int tests, N, M, x[500009], y[500009], ap[500009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d %d", &N, &M);
    for (int i=1; i<=3 * N; i++)
        ap[i] = 0;
    vector < int > matching;
    for (int i=1; i<=M; i++)
    {
        scanf ("%d %d", &x[i], &y[i]);
        if (ap[x[i]] == 0 && ap[y[i]] == 0)
            matching.push_back (i), ap[x[i]] = ap[y[i]] = 1;
    }
    if (matching.size () >= N)
    {
        printf ("Matching\n");
        for (auto i : matching)
        {
            printf ("%d", i);
            if (--N == 0)
            {
                printf ("\n");
                break;
            }
            else printf (" ");
        }
    }
    else
    {
        printf ("IndSet\n");
        for (int i=3 * N; i>=1; i--)
            if (ap[i] == 0)
            {
                printf ("%d", i);
                if (--N == 0)
                {
                    printf ("\n");
                    break;
                }
                else printf (" ");
            }
    }
}

return 0;
}