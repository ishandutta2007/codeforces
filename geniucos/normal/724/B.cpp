#include<bits/stdc++.h>

using namespace std;

int N, M, a[29][29];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    for (int j=1; j<=M ;j++)
        scanf ("%d", &a[i][j]);
for (int j1=1; j1<=M; j1++)
    for (int j2=j1; j2<=M; j2++)
    {
        if (j1 != j2)
        {
            for (int i=1; i<=N; i++)
                swap (a[i][j1], a[i][j2]);
        }
        bool ok = 1;
        for (int i=1; i<=N; i++)
        {
            int cnt = 0;
            for (int j=1; j<=M; j++)
                cnt += (a[i][j] != j);
            if (cnt > 2) ok = 0;
        }
        if (ok)
        {
            printf ("YES\n");
            return 0;
        }
        if (j1 != j2)
        {
            for (int i=1; i<=N; i++)
                swap (a[i][j1], a[i][j2]);
        }
    }
printf ("NO\n");
return 0;
}