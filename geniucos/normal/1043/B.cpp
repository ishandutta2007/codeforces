#include<bits/stdc++.h>

using namespace std;

int x[1009], ans[1009], nr, N, a[1009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]),
    x[i - 1] = a[i] - a[i - 1];
for (int K=1; K<=N; K++)
{
    bool ok = 1;
    for (int i=K; i<N; i++)
        ok &= (x[i] == x[i - K]);
    if (ok)
        ans[++nr] = K;
}
printf ("%d\n", nr);
for (int i=1; i<=nr; i++)
    printf ("%d ", ans[i]);
printf ("\n");
return 0;
}