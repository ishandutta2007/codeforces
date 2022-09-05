#include<bits/stdc++.h>

using namespace std;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int N, T, K, D;
scanf ("%d %d %d %d", &N, &T, &K, &D);
if (N % K == 0) N /= K;
else N /= K, N ++;
int oldT = 1LL * T * N, newT, a = 0, b = D;
while (N --)
{
    if (a < b) a += T;
    else b += T;
}
newT = max (a, b);
if (newT < oldT) printf ("YES\n");
else printf ("NO\n");

return 0;
}