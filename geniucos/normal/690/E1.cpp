#include<bits/stdc++.h>

using namespace std;

int T, N, M, a[709][709];

int dist (int i1, int i2)
{
    int sol = 0;
    for (int j=1; j<=M; j++)
    {
        int curr = a[i1][j] - a[i2][j];
        if (curr < 0) curr = -curr;
        sol += curr;
    }
    return sol;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &T);
while (T --)
{
    scanf ("%d %d", &N, &M);
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            scanf ("%d", &a[i][j]);
    if (dist (1, N) <= 20 * M) printf ("YES\n");
    else printf ("NO\n");
}

return 0;
}