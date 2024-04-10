#include<bits/stdc++.h>

using namespace std;

int N, M, mod = 1e9 + 7, init[100009], a[109][100009], fac[101000], inv[101000];

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int substract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}

int pow (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}

void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = pow (fac[lim], mod - 2);for (int i=lim - 1; i>=1; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){if (K > N || N < 0 || K < 0) return 0;int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M), Prec (N + 200);
for (int i=1; i<=N; i++)
    scanf ("%d", &init[i]);
while (M --)
{
    int l, r, k;
    scanf ("%d %d %d", &l, &r, &k);
    if (r - l + 1 <= k)
    {
        for (int i=l; i<=r; i++)
            init[i] = add (init[i], comb (i - l + k, k));
        continue;
    }
    a[k][l] = add (a[k][l], 1);
    for (int i=0; i <= k; i++)
    {
        int val = comb (r - l + k - i, k - i);
        a[i][r + 1] = substract (a[i][r + 1], val);
    }
}
for (int j=1; j<=N; j++)
{
    int curr = 0;
    for (int i=100; i>=0; i--)
    {
        curr = add (curr, a[i][j - 1]);
        a[i][j] = add (a[i][j], curr);
        init[j] = add (init[j], a[i][j]);
    }
}
for (int i=1; i<=N; i++)
    printf ("%d%c", init[i], (i < N ? ' ' : '\n'));
return 0;
}