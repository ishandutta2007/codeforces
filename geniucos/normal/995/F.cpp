#include<bits/stdc++.h>

using namespace std;

int N, D, K, t[3009], dp[3009][6009], iv[6009];
vector < int > v[3009];
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

int fac[2000009], inv[2000009];
void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=0; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){if (K > N || N < 0 || K < 0) return 0; int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}
int getInverse (int i) {return mul (fac[i - 1], inv[i]);}

void dfs (int nod)
{
    for (int j=0; j<=K; j++)
        dp[nod][j] = 1;
    for (auto it : v[nod])
    {
        dfs (it);
        for (int j=0; j<=K; j++)
            dp[nod][j] = mul (dp[nod][j], dp[it][j]);
    }
    for (int j=1; j<=K; j++)
        adto (dp[nod][j], dp[nod][j - 1]);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &D), D --, K = min (D, 2 * N);
for (int i=2; i<=N; i++)
    scanf ("%d", &t[i]),
    v[t[i]].push_back (i);
dfs (1);
if (K == D) printf ("%d\n", dp[1][D]);
else
{
    Prec (3 * N + 100);
    for (int i=1; i<=K; i++)
        iv[i] = getInverse (i);
    int ans = 0;
    for (int i=0; i<=K; i++)
    {
        int curr = dp[1][i];
        for (int j=0; j<=K; j++)
            if (i != j)
            {
                if (i > j)
                    curr = mul (curr, D - j), curr = mul (curr, iv[i - j]);
                else
                    curr = mul (curr, subtract (j, D)), curr = mul (curr, iv[j - i]);
            }
        adto (ans, curr);
    }
    printf ("%d\n", ans);
}
return 0;
}