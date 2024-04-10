#include<bits/stdc++.h>

using namespace std;

int N, x[100009], y[100009], a[100009], b[100009];
long long sx = 0, sy = 0;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &x[i], &y[i]),
    sx += x[i], sy += y[i];
for (int i=1; i<=N; i++)
    scanf ("%d %d", &a[i], &b[i]),
    sx += a[i], sy += b[i];
printf ("%lld %lld\n", sx / N, sy / N);

return 0;
}