#include<bits/stdc++.h>

using namespace std;

int N, K;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
long long ans = 0;
for (int i=1; i<=N; i++)
{
    int x;
    scanf ("%d", &x);
    int st = max (1, i - K + 1), dr = min (i, N - K + 1);
    ans += 1LL * x * (dr - st + 1);
//    printf ("%d\n", dr - st + 1);
}
printf ("%.15f\n", (double) ans / (N - K + 1));
return 0;
}