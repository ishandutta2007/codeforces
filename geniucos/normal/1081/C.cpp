#include<bits/stdc++.h>

using namespace std;

int N, M, K, dp[2018][2018];
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

/*int fac[2000009], inv[2000009];
void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=0; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){if (K > N || N < 0 || K < 0) return 0; int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}*/

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &K);
dp[1][0] = M;
for (int i=1; i<N; i++)
    for (int j=0; j<i; j++)
    {
        adto (dp[i + 1][j], dp[i][j]);
        adto (dp[i + 1][j + 1], mul (dp[i][j], M - 1));
    }
printf ("%d\n", dp[N][K]);
return 0;
}