#include<bits/stdc++.h>

using namespace std;

long long gcd (long long a, long long b)
{
    long long r;
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

int N, K, A, B;
scanf ("%d %d", &N, &K);
scanf ("%d %d", &A, &B);
vector < long long > maybeS (1, A), maybeB;
if (A != 0)
    maybeS.push_back (K - A);
for (int i=0; i<N; i++)
{
    maybeB.push_back (1LL * i * K + B);
    if (B != 0)
        maybeB.push_back (1LL * i * K + K - B);
}
long long M = 1LL * N * K, mini = M + 10, maxi = -1;
for (auto s : maybeS)
    for (auto b : maybeB)
    {
        long long l = b - s;
        if (l <= 0)
            l += M;
        long long stops = M / gcd (M, l);
        if (stops < mini)
            mini = stops;
        if (stops > maxi)
            maxi = stops;
    }
printf ("%I64d %I64d\n", mini, maxi);
return 0;
}