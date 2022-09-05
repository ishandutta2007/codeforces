#include<bits/stdc++.h>

using namespace std;

const int maxN = 200009LL;
int N, M;
long long a[maxN], b[maxN];

long long gcd (long long a, long long b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    if (a == 0 || b == 0)
        return a + b;
    long long r = 0;
    while (b)
        r = a % b,
        a = b,
        b = r;
    return a;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%I64d", &a[i]);
long long ans = 0;
for (int i=2; i<=N; i++)
    ans = gcd (ans, a[i] - a[1]);
for (int i=1; i<=M; i++)
{
    scanf ("%I64d", &b[i]);
    long long curr = gcd (a[1] + b[i], ans);
    printf ("%I64d%c", curr, " \n"[i == M]);
}
return 0;
}