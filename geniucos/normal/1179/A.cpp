#include<bits/stdc++.h>

using namespace std;

int N, M, x[100009], a[300009], b[300009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=0; i<N; i++)
    scanf ("%d", &x[i]);
for (int i=0,steps=0;steps<=2 * N + 10; i = (i + 1) % N,steps++)
{
    int j = (i + 1) % N;
    a[steps + 1] = x[i], b[steps + 1] = x[j];
    if (x[j] < x[i])
        swap (x[i], x[j]);
/*    for (int k=1; k<=N; k++)
        printf ("%d ", x[(i + k) % N]);
    printf ("\n");*/
}
for (int i=1; i<=M; i++)
{
    long long x;
    scanf ("%I64d", &x);
    int p = (x <= 2 * N ? x : x % (N - 1) + N - 1);
    printf ("%d %d\n", a[p], b[p]);
}
return 0;
}