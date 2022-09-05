#include<bits/stdc++.h>

using namespace std;

int nr, M, cr[1000009], p[1000009];
long long N, K;

long long phi (long long N)
{
    if (N == 1) return 1;
    long long ans = N;
    for (int i=1; i <= nr && 1LL * p[i] * p[i] <= N; i++)
        if (N % p[i] == 0)
        {
            while (N % p[i] == 0) N /= p[i];
            ans = ans / p[i], ans = 1LL * ans * (p[i] - 1);
        }
    if (N > 1) ans = ans / N, ans = 1LL * ans * (N - 1);
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

/*scanf ("%d", &N), f[1] = 1;
for (int i=2; i<=N; i++)
    for (int j=1; j<i; j++)
        f[i] += (gcd (j, i - j) == 1);
for (int i=1; i<=N; i++)
{
    g[i] = 0;
    for (int j=1; j<=i; j++)
        if (i % j == 0)
            g[i] += f[j];
}
for (int i=1; i<=N; i++)
    printf ("%d %d\n", g[i], f[i]);*/
scanf ("%I64d %I64d", &N, &K), M = 1e6;
for (int i=2; i * i <= M; i++)
    if (cr[i] == 0)
        for (int j=i * i; j<=M; j+=i)
            cr[j] = i;
for (int i=2; i<=M; i++)
    if (cr[i] == 0)
        p[++nr] = i, cr[i] = i;
long long steps = (K + 1) / 2;
while (steps --)
{
    N = phi (N);
    if (N == 1) break;
}
printf ("%I64d\n", N % 1000000007);
return 0;
}