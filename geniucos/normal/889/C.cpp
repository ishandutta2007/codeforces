#include<bits/stdc++.h>

using namespace std;

int N, K, dp[1000109], inv[1000109], fac[1000109], s[1000109];
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

void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=1; i--)inv[i] = mul (inv[i + 1], i + 1);}

int sum (int i, int j)
{
    return subtract (s[i], s[j + 1]);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K), Prec (N);
for (int i=N; i>=1; i--)
{
    dp[i] = mul (fac[N - 1], inv[i - 1]);
    adto (dp[i], mul (inv[i - 1], sum (i + 1, min (N, i + K))));
//    for (int j=i + 1; j<=N && j<=i + K; j++)
  //      adto (dp[i], mul (mul (fac[j - 2], inv[i - 1]), dp[j]));
    if (i >= 2) s[i] = add (s[i + 1], mul (fac[i - 2], dp[i]));
}
//for (int j=1; j<=N; j++)
  //  printf ("%d%c", dp[j], " \n"[j == N]);
printf ("%d\n", subtract (fac[N], dp[1]));

return 0;
}