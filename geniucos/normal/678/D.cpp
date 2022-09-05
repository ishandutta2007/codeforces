#include<bits/stdc++.h>

using namespace std;

int A, B, X, mod;
long long N;

int pow (int a, long long b, int mod)
{
    int p = 1;
    for (int i=0; (1LL<<i) <= b; i++)
    {
        if (b & (1LL << i)) p = (1LL * p * a) % mod;
        a = (1LL * a * a) % mod;
    }
    return p;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %I64d %d", &A, &B, &N, &X), mod = 1e9 + 7;
if (A == 1)
{
    printf ("%d\n", (1LL * (N % mod) * B + X) % mod);
    return 0;
}
int oldA = A;
A = pow (A, N, mod);
int ans = (1LL * B * (A - 1)) % mod;
ans = (1LL * ans * pow (oldA - 1, mod - 2, mod)) % mod;
ans = ((long long) ans + 1LL * A * X) % mod;
printf ("%d\n", ans);

return 0;
}