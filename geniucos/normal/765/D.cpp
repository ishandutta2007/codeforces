#include<bits/stdc++.h>

using namespace std;

int N, mod = 1e9 + 7;
char sir[1009];

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

/*void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = pow (fac[lim], mod - 2);for (int i=lim - 1; i>=1; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}*/

int nr, pos[100009], f[100009], v[100009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &f[i]);
    if (f[i] == i) v[++nr] = i, pos[i] = nr;
}
for (int i=1; i<=N; i++)
    if (f[f[i]] != f[i])
    {
        printf ("-1\n");
        return 0;
    }
printf ("%d\n", nr);
for (int i=1; i<=N; i++)
    printf ("%d ", pos[f[i]]);
printf ("\n");
for (int i=1; i<=nr; i++)
    printf ("%d ", v[i]);
printf ("\n");
return 0;
}