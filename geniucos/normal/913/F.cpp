#include<bits/stdc++.h>

using namespace std;

int P, Q, p[2017], q[2017], N, A[2017], B[2017], dp[2017], split[2017][2017], fac[2017], c[2017][2017], inv[2017];
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

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int sus, jos;
scanf ("%d\n%d %d", &N, &sus, &jos);
P = mul (sus, power (jos, mod - 2));
Q = mul (jos - sus, power (jos, mod - 2));
p[0] = q[0] = 1;
for (int i=1; i<=N; i++)
    p[i] = mul (p[i - 1], P), q[i] = mul (q[i - 1], Q);
split[0][0] = 1;
for (int i=0; i<N; i++)
    for (int j=0; j<=i; j++)
        adto (split[i + 1][j + 1], mul (split[i][j], p[i - j])),
        adto (split[i + 1][j], mul (split[i][j], q[j]));
A[1] = 1, B[1] = 0;
for (int n=2; n<=N; n++)
{
    for (int x=1; x<n; x++)
    {
        int curr = mul (A[x], split[n][x]);
        adto (B[n], curr);
    }
    A[n] = subtract (1, B[n]);
}
dp[1] = 0, dp[2] = 1;
for (int n=2; n<=N; n++)
{
    int s = 0;
    for (int x=1; x<n; x++)
    {
        int curr = add (x * (n - x) + x * (x - 1) / 2, add (dp[x], dp[n - x]));
        curr = mul (curr, mul (A[x], split[n][x])), adto (s, curr);
    }
    adto (s, mul (n * (n - 1) / 2, A[n]));
    dp[n] = mul (s, power (B[n], mod - 2));///B[n] = 1 - A[n];
}
printf ("%d\n", dp[N]);
return 0;
}