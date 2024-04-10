#include<bits/stdc++.h>

using namespace std;

int N, a[1009][1009], ans[1009];
long long s[1009];

long long gcd (long long a, long long b)
{
    long long r;
    while (b)
        r = a % b,
        a = b,
        b = r;
    return a;
}

int getRoot (long long val)
{
    int p = 0, u = 1e9, mij, ras = 0;
    while (p <= u)
    {
        mij = p + (u - p) / 2;
        if (1LL * mij * mij <= val) ras = mij, p = mij + 1;
        else u = mij - 1;
    }
    return ras;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        scanf ("%d", &a[i][j]), s[i] += a[i][j];
long long u = s[1] - a[1][2], j = s[2] - a[2][1];
long long p12 = a[1][2];
long long curr = gcd (u, j); u /= curr, j /= curr;
curr = gcd (p12, j); p12 /= curr, j /= curr;
assert (j == 1LL);
ans[1] = getRoot (1LL * u * p12);
for (int i=2; i<=N; i++)
    ans[i] = a[1][i] / ans[1];
for (int i=1; i<=N; i++)
    printf ("%d%c", ans[i], " \n"[i == N]);
return 0;
}