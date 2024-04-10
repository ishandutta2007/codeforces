#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e6 + 100;
int N, M, K, p2[maxN], ip2[maxN];
int dp[2020][2020];

double dpr[2020][2020];
const double eps = 1e-8;

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

int div2 (int x)
{
    if (x & 1) x += mod;
    return x >> 1;
}

int fac[4000009], inv[4000009];
void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=0; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){if (K > N || N < 0 || K < 0) return 0; int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}

int cnt(int n, int k)
{
    return subtract (comb(n + k, k), comb (n + k, k - 1));
}

int compute(int n, int m)
{
    if (n == m)
        return n;
    int ans = 0;
    for (int i=1; i<=m; i++)
    {
        int curr = mul (i + 1, p2[i - 1]);
        curr = mul (curr, comb(n - i, n - m));
        adto (ans, curr);
    }
    return mul(ans, ip2[n]);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests, testId = 0;
scanf ("%d", &tests), Prec(2000009);
p2[0] = 1, ip2[0] = 1;
for (int i=1; i<=2000008; i++)
{
    p2[i] = add (p2[i - 1], p2[i - 1]);
    ip2[i] = div2 (ip2[i - 1]);
}
/*for (int i=1; i<=4; i++, printf("\n"))
    for (int j=1; j<=i; j++)
        printf("%d ", cnt(i, j));
//N = 2001, K = 1;
//printf("%d\n", compute(4, 3));
//return 0;
K = 1;
dp[0][0] = 0;
for (int i=1; i<=200; i++)
{
    dp[i][0] = dp[i - 1][0];
    dp[i][i] = mul (i, K);
    for (int j=1; j<i; j++)
        dp[i][j] = div2 (add (dp[i - 1][j - 1], dp[i - 1][j]));
    for (int j=0; j<=i; j++)
        if (dp[i][j] != compute(i, j))
        {
            printf("Wa (%d, %d) %d instead of %d\n", i, j, compute(i, j), dp[i][j]);
            return 0;
        }
}
for (int i=1; i<=10; i++, printf("\n"))
    for (int j=1; j<=10; j++)
        printf ("%6d ", mul (1 << i, dp[i][j]));*/
while (tests --)
{
    //printf ("Case #%d: ", ++testId);
    scanf ("%d %d %d", &N, &M, &K);
    printf("%d\n", mul (K, compute(N, M)));
    //printf("%d %.5f\n", dp[N][M], dpr[N][M]);
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/