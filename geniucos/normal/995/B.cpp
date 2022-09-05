#include<bits/stdc++.h>

using namespace std;

int N, ans, a[209];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=2 * N; i++)
    scanf ("%d", &a[i]);
for (int i=1; i<=2 * N; i+=2)
    if (a[i] != a[i + 1])
    {
        int j = i + 1;
        while (a[j] != a[i])
            j ++;
        while (j > i + 1)
            swap (a[j - 1], a[j]), j --, ans ++;
    }
printf ("%d\n", ans);
return 0;
}