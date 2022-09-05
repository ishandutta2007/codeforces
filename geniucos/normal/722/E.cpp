#include<bits/stdc++.h>

using namespace std;

int mod, N, X, Y, S, dp[23][2016], fac[200009], inv[200009];
pair < int, int > a[2016];

int pow (int a, int b)
{
    int p = 1;
    for (int i=0; (1 << i) <= b; i++)
    {
        if (b & (1 << i)) p = (1LL * p * a) % mod;
        a = (1LL * a * a) % mod;
    }
    return p;
}

void Prec ()
{
    int lim = X + Y + 3;
    fac[0] = 1;
    for (int i=1; i<=lim; i++)
        fac[i] = (1LL * fac[i - 1] * i) % mod;
    inv[lim] = pow (fac[lim], mod - 2);
    for (int i=lim - 1; i>=0; i--)
        inv[i] = (1LL * inv[i + 1] * (i + 1)) % mod;
}

int comb (int N, int K)
{
    if (K < 0 || K > N || N < 0) return 0;
    int ans = (1LL * fac[N] * inv[K]) % mod;
    ans = (1LL * ans * inv[N - K]) % mod;
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d", &X, &Y, &N, &S), mod = 1e9 + 7, Prec ();
pair < int, int > fro = make_pair (1, 1), whe = make_pair (X, Y);
bool ad1 = 0, ad2 = 0;
for (int i=1; i<=N; i++)
{
    scanf ("%d %d", &a[i].first, &a[i].second);
    if (a[i] == fro) ad1 = 1;
    if (a[i] == whe) ad2 = 1;
}
if (!ad1) a[++N] = fro;
if (!ad2) a[++N] = whe;
sort (a + 1, a + N + 1);
///dp[i][j] = nr moduri sa ajung in i dupa exact j pasi(nu pasi neaparat cat j casute exact, inclusiv, proaste)
dp[ad1][1] = 1;
for (int i=2; i<=N; i++)
    for (int j=21; j>ad1; j--)
    {
        dp[j][i] = 0;
        for (int k=1; k<i; k++)
            if (a[k].second <= a[i].second)
            {
                int alf = a[i].second - a[k].second, bet = a[i].first - a[k].first;
                dp[j][i] = ((long long) dp[j][i] + 1LL * dp[j - 1][k] * comb (alf + bet, bet)) % mod;
            }
        for (int p=j + 1; p<=21; p++)
        {
            dp[j][i] -= dp[p][i];
            if (dp[j][i] < 0) dp[j][i] += mod;
        }
    }
///j + 1 - ad2 moduri sa iau j in realitate(cu tot cu cazurile particulare)
int Q = comb (X - 1 + Y - 1, X - 1), P = Q;
for (int i=0; i<=21; i++)
{
    P = ((long long) P + 1LL * (S - 1) * dp[i + 1 - ad2][N]) % mod;
    S -= S / 2;
}
printf ("%d\n", ((long long) 1LL * P * pow (Q, mod - 2)) % mod);
return 0;
}