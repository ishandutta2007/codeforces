#include<bits/stdc++.h>

using namespace std;

int N, M, K, x[100009], y[100009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &K);
for (int i=1; i<=N; i++)
    scanf ("%d", &x[i]);
for (int i=1; i<N; i++)
    y[i] = x[i + 1] - x[i] - 1;
sort (y + 1, y + N);
reverse (y + 1, y + N);
int ans = x[N] - x[1] + 1;
for (int i=1; i<K; i++)
    ans -= y[i];
printf ("%d\n", ans);
return 0;
}