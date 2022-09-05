#include<bits/stdc++.h>

using namespace std;

int N, K, allP, a[5009], dp[5009][5009], coef[5009];
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

int main ()
{
scanf ("%d %d", &N, &K), allP = 1;
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), allP = mul (allP, a[i]);
dp[0][0] = 1;
for (int i=0; i<N; i++)
    for (int j=0; j<=i; j++)
        adto (dp[i + 1][j], mul (dp[i][j], a[i + 1])),
        adto (dp[i + 1][j + 1], mul (dp[i][j], mod - 1));
for (int i=0; i<=N; i++)
    coef[i] = dp[N][i];
int ans = power (power (N, mod - 2), K), sum = 0, currCoefEnx = 1;
for (int j=0; j<=N && j<=K; j++)
    adto (sum, mul (coef[j], mul (power (N, K - j), currCoefEnx))), currCoefEnx = mul (currCoefEnx, K - j);
ans = mul (ans, sum);
printf ("%d\n", subtract (allP, ans));
return 0;
}