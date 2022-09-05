#include<bits/stdc++.h>

using namespace std;

int N, a[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), a[i] -= (N + 1 - i);
sort (a + 1, a + N + 1);
for (int i=1; i<=N; i++)
    a[i] += N - i + 1;
for (int i=1; i<N; i++)
    if (a[i] > a[i + 1])
    {
        printf (":(");
        return 0;
    }
for (int i=1; i<=N; i++)
    printf ("%d ", a[i]);
printf ("\n");

return 0;
}