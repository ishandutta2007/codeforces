#include<bits/stdc++.h>

using namespace std;

const int maxN = 2000009;
int N, K, p[maxN], p2[maxN], a[maxN];
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

int fac[2000009], inv[2000009];
void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=0; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){if (K > N || N < 0 || K < 0) return 0; int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K), Prec(N + 1);
for (int i=0; i<N; i++)
    scanf ("%d", &a[i]);
int cntEq = 0, cntDif = 0;
for (int i=0; i<N; i++)
    cntEq += (a[i] == a[(i + 1) % N]);
cntDif = N - cntEq;
p[0] = 1;
for (int i=1; i<=cntDif; i++)
    p[i] = mul(p[i - 1], K - 2);
p2[0] = 1;
for (int i=1; i<=cntDif; i++)
    p2[i] = add (p2[i - 1], p2[i - 1]);
int ans = 0;
/*for (int i=0; i<=cntDif; i++)
    for (int j=i + 1; i + j<=cntDif; j++)
    {
        int cnt = mul(comb(cntDif, i), comb(cntDif - i, j));
        cnt = mul(cnt, p[cntDif - i - j]);
        adto(ans, cnt);
    }*/
for (int k=1; k<=cntDif; k++)
{
    int curr = p2[k - 1];
    if (k % 2 == 0)
    {
        curr = subtract(p2[k], comb(k, k / 2));
        if (curr & 1) curr += mod;
        curr >>= 1;
    }
    curr = mul(curr, mul(comb(cntDif, k), p[cntDif - k]));
    adto(ans, curr);
}
while (cntEq --)
    ans = mul(ans, K);
printf("%d\n", ans);
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/