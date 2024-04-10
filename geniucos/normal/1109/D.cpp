#include<bits/stdc++.h>

using namespace std;

int N, C;
const int mod = 1e9 + 7;

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

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &C), Prec (N + C + 10);
int ans = 0;
for (int K=1; K<N; K++)
{
    int M = N - K, ways = mul (power (C, N - K - 1), mul (mul (comb (N - 2, K - 1), fac[K - 1]), comb (C - 1, K - 1)));
    int trees = 1;
    if (K < N - 1)
    {
        trees = 0;
        int x = mul (K + 1, power (M - 1, mod - 2));
        trees = power (x + 1, M - 2);
        trees = mul (trees, K + 1);
        trees = mul (trees, power (M - 1, M - 2));
/*        for (int dg = 0; dg <= M - 2; dg ++)
        {
            int curr = mul (mul (comb (M - 2, dg), power (M - 1, M - 2 - dg)), power (K + 1, dg + 1));
            adto (trees, curr);
        }*/
    }
    adto (ans, mul (trees, ways));
}
printf ("%d\n", ans);
return 0;
}