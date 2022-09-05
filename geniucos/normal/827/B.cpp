#include<bits/stdc++.h>

using namespace std;

int N, K, x[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
int val = (N - K - 1) / K;
for (int i=1; i<=K; i++)
    x[i] = val + (i <= (N - K - 1) % K);
reverse (x + 1, x + K + 1);
printf ("%d\n", 2 + x[K - 1] + x[K]), N = 1;
for (int i=1; i<=K; i++)
{
    int sz = x[i];
    printf ("1 %d\n", N + 1), N ++;
    while (sz --)
        printf ("%d %d\n", N, N + 1), N ++;
}
return 0;
}