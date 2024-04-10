#include<bits/stdc++.h>

using namespace std;

int N, K, part[209][209], chooseK[209], pN[209], gx[209], vol[100009], t[100009], dp[100009][209], gx2[100009][209], old[209];
const int mod = 1e9 + 7;
vector < int > v[100009];

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

int fac[2000109], inv[2000109];
void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=0; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){if (K > N || N < 0 || K < 0) return 0; int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}

void dfs0 (int nod)
{
    vol[nod] = 1;
    for (auto it : v[nod])
        if (it != t[nod])
            t[it] = nod, dfs0 (it), vol[nod] += vol[it];
}

void dfs (int nod)
{
    dp[nod][0] = 2;
    int subSoFar = 0;
    for (auto it : v[nod])
    if (t[it] == nod)
    {
        dfs (it);
        for (int j=0; j<=subSoFar && j<=K; j++)
            old[j] = dp[nod][j], dp[nod][j] = 0;
        for (int k=0; k<vol[it] && k<=K; k++)
            chooseK[k] = comb (vol[it] - 1, k);
        for (int j=0; j<=subSoFar && j<=K; j++)
            for (int k=0; k<vol[it] && j + k<=K; k++)
                adto (dp[nod][j + k], mul (old[j], dp[it][k])),
                adto (dp[nod][j + k + 1], mul (old[j], chooseK[k]));
        subSoFar += vol[it];
    }
    ///too slow
    if (nod != 1)
    {
        ///choose the edge between nod and father
        for (int i=0; i<=K && i<=subSoFar; i++)
            adto (gx2[N - vol[nod] - 1][i + 1], dp[nod][i]);
    }
    else
    {
        for (int i=0; i<=K && i<=subSoFar; i++)
            adto (gx2[0][i], dp[nod][i]);
    }
}

void computeGx ()
{
    for (int i=N; i>=1; i--)
        for (int j=0; j<=K; j++)
            adto (gx2[i - 1][j], gx2[i][j]),
            adto (gx2[i - 1][j + 1], gx2[i][j]);
    for (int i=0; i<=K; i++)
        gx[i] = gx2[0][i];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K), Prec (max (2 * N, 2 * K));
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
dfs0 (1);
dfs (1);
computeGx ();
part[0][0] = 1;
for (int i=1; i<=K; i++)
    for (int j=0; j<=K; j++)
    {
        part[i][j] = mul (j, part[i - 1][j]);
        if (j > 0)
            adto (part[i][j], part[i - 1][j - 1]);
    }
pN[0] = 1;
for (int i=1; i<=K; i++)
    pN[i] = mul (pN[i - 1], N - 1);
for (int i=0; i<=K; i++)
    gx[i] = subtract (gx[i], mul (i, comb (N - 1, i)));
int ans = 0;
for (int e=0; e<=K; e++)
{
    int curr = 0;
    for (int i=0; i<=e; i++)
    {
        int cnt = mul (part[e][i], fac[i]);
        adto (curr, mul (cnt, gx[i]));
    }
    if (e & 1)
        curr = subtract (0, curr);
    int extraCoef = mul (pN[K - e], comb (K, e));
    adto (ans, mul (curr, extraCoef));
}
printf ("%d\n", ans);
return 0;
}