#include<bits/stdc++.h>

using namespace std;

int N, deg[100009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
if (N == 2)
{
    printf ("YES\n");
    return 0;
}
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    deg[x] ++, deg[y] ++;
}
for (int i=1; i<=N; i++)
    if (deg[i] == 2)
    {
        printf ("NO\n");
        return 0;
    }
printf ("YES\n");
return 0;
}