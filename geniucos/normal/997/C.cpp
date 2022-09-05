#include<bits/stdc++.h>

using namespace std;

int N, p3[1000009], ip3[1000009];
const int mod = 998244353;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int power (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}

int fac[3000009], inv[3000009];
void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=0; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){if (K > N || N < 0 || K < 0) return 0; int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}

int pw3 (long long x)
{
    assert (x >= -N);
    if (x < 0)
        return ip3[-x];
    if (x <= N)
        return p3[x];
    return power (3, x % (mod - 1));
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), Prec (2 * N + 10);
p3[0] = 1;
for (int i=1; i<=N; i++)
    p3[i] = mul (p3[i - 1], 3);
ip3[0] = 1, ip3[1] = power (3, mod - 2);
for (int i=2; i<=N; i++)
    ip3[i] = mul (ip3[i - 1], ip3[1]);
int ans = 0;
for (int i=1; i<=N; i++)
{
    int curr = mul (p3[i], pw3 (1LL * N * (N - i)));
    curr = mul (curr, comb (N, i));
    curr = add (curr, curr);
    if (i % 2 == 0)
        curr = subtract (0, curr);
    adto (ans, curr);
}
for (int a=1; a<=N; a++)
{
    int base = subtract (0, pw3 (a - N));
    int sm = subtract (power (base + 1, N), 1);
    int curr = mul (3, comb (N, a));
    if (a % 2 == 0)
        curr = subtract (0, curr);
    curr = mul (curr, pw3 (1LL * N * (N - a)));
    curr = mul (curr, sm);
    adto (ans, curr);
}
printf ("%d\n", ans);
return 0;
}