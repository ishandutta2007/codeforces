#include<bits/stdc++.h>

using namespace std;

int N, a[109];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
if (N > 100)
{
    printf ("YES\n");
    return 0;
}
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
sort (a + 1, a + N + 1);
for (int i=1; i<=N; i++)
    for (int j=i+1; j<=N; j++)
        for (int k=j + 1; k<=N; k++)
            if (a[i] + a[j] > a[k])
            {
                printf ("YES\n");
                return 0;
            }
printf ("NO\n");
return 0;
}