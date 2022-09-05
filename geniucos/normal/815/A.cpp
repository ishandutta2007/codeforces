#include<bits/stdc++.h>

using namespace std;

int bst = -1, N, M, x[509], y[509], r[509], c[509], a[509][509];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        scanf ("%d", &a[i][j]);
for (r[1] = 0; r[1] <= a[1][1]; r[1] ++)
{
    bool ok = 1;
    for (int j=1; j<=M; j++)
    {
        c[j] = a[1][j] - r[1];
        if (c[j] < 0) ok = 0;
    }
    for (int i=2; i<=N; i++)
    {
        r[i] = a[i][1] - c[1];
        if (r[i] < 0) ok = 0;
    }
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            if (r[i] + c[j] != a[i][j])
                ok = 0;
    if (ok)
    {
        int curr = 0;
        for (int i=1; i<=N; i++)
            curr += r[i];
        for (int j=1; j<=M; j++)
            curr += c[j];
        if (curr < bst || bst == -1)
        {
            bst = curr;
            for (int i=1; i<=N; i++)
                x[i] = r[i];
            for (int i=1; i<=M; i++)
                y[i] = c[i];
        }
    }
}
printf ("%d\n", bst);
if (bst == -1) return 0;
for (int i=1; i<=N; i++)
    for (int j=1; j<=x[i]; j++)
        printf ("row %d\n", i);
for (int i=1; i<=M; i++)
    for (int j=1; j<=y[i]; j++)
        printf ("col %d\n", i);
return 0;
}