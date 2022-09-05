#include<cstdio>

using namespace std;

int max_N, N, M, maxi, nr, tot, G[5015], a[5015], dp[5015], b[5015], c_g[5015], pr[50009];
bool cr[50009];

int gcd (int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int cost_P (int prime)
{
    int p = 1, u = M, mij;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (b[mij] == prime) return -1;
        if (b[mij] < prime) p = mij + 1;
        else u = mij - 1;
    }
    return 1;
}

int cost_N (int val)
{
    int sol = 0;
    for (int i=1; pr[i] * pr[i] <= val && i <= nr; i++)
        if (val % pr[i] == 0)
        {
            int e = 0;
            while (val % pr[i] == 0) e ++, val /= pr[i];
            sol += e * cost_P (pr[i]);
        }
    if (val > 1) sol += cost_P (val);
    return sol;
}

void sieve ()
{
    for (max_N = 1; max_N * max_N <= maxi; max_N ++);
    for (int i=2; i * i <= max_N; i++)
        if (cr[i] == 0)
        {
            for (int j=i * i; j<=max_N; j+=i)
                cr[j] = 1;
        }
    for (int i=2; i<=max_N; i++)
        if (cr[i] == 0) pr[++nr] = i;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &a[i]);
    if (a[i] > maxi) maxi = a[i];
}
for (int i=1; i<=M; i++)
    scanf ("%d", &b[i]);
sieve ();
G[1] = a[1];
c_g[1] = tot = cost_N (a[1]);
int mini = 0;
for (int i=2; i<=N; i++)
{
    G[i] = gcd (G[i-1], a[i]);
    tot += cost_N (a[i]);
    c_g[i] = cost_N (G[i]);
}
if (c_g[N] * N < mini) mini = c_g[N] * N;
dp[N] = c_g[N] * N;
for (int i=N - 1; i>=1; i--)
{
    dp[i] = c_g[i] * i;
    for (int j=i + 1; j<=N; j++)
        if (dp[j] + (c_g[i] - c_g[j]) * i < dp[i])
            dp[i] = dp[j] + (c_g[i] - c_g[j]) * i;
    if (dp[i] < mini) mini = dp[i];
}
printf ("%d\n", tot - mini);

return 0;
}