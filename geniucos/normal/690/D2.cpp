#include<bits/stdc++.h>

using namespace std;

int ans, mod, B, N, fac[700009], inv[700009];

int pow (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = (1LL * p * a) % mod;
        a = (1LL * a * a) % mod;
    }
    return p;
}

int comb (int N, int K)
{
    if (K < 0 || K > N) return 0;
    int ans = (1LL * fac[N] * inv[K]) % mod;
    ans = (1LL * ans * inv[N - K]) % mod;
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &B, &N), mod = 1e6 + 3;
fac[0] = 1;
for (int i=1; i<=B + N + 1; i++)
    fac[i] = (1LL * fac[i - 1] * i) % mod;
inv[B + N + 1] = pow (fac[B + N + 1], mod - 2);
for (int i=B + N; i>=0; i--)
    inv[i] = (1LL * inv[i + 1] * (i + 1)) % mod;
for (int b=1; b<=B; b++)
{
    ans += comb (b + N - 1, N - 1);
    if (ans >= mod) ans -= mod;
}
printf ("%d\n", ans);
return 0;
}