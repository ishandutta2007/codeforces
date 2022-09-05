#include<bits/stdc++.h>

using namespace std;

int A, B, M, lim, minX[1000009];
const int INF = 1e9;

void dfs (int nod, int newVal)
{
    if (nod < 0 || nod > newVal) return ;
    if (minX[nod] != INF) return ;
    minX[nod] = newVal;
    dfs (nod + A, newVal), dfs (nod - B, newVal);
}

int gcd (int a, int b)
{
    int r;
    while (b)
        r = a % b, a = b, b = r;
    return a;
}

const bool DBG = 0;
void getMinX ()
{
    if (!DBG) scanf ("%d %d %d", &M, &A, &B), lim = A + B;
    else lim = A + B;
    minX[0] = 0;
    for (int i=1; i<=lim; i++)
        minX[i] = INF;
    for (int i=1; i<=lim; i++)
        if (minX[i] == INF && i >= A && minX[i - A] != INF)
            dfs (i, i);
    int d = gcd (A, B);
    for (int i=0; i<=lim; i++)
        assert ((minX[i] != INF) == (i % d == 0));
}

long long solve (int M, int d)
{
    ///sum of i / d for i from 0 to M
    long long ans = M + 1;///0 is for all
    while (M > 0 && M % d != d - 1)
        ans += M / d, M --;
    if (M > 0)
    {
        ///now M is divisible by d
        long long k = M / d;
        ans += 1LL * d * k * (k + 1) / 2LL;
    }
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

if (DBG)
{
    for (A=1; A<=100; A++)
        for (B=1; B<=100; B++)
            getMinX ();
    printf ("OK\n");
    return 0;
}
else getMinX ();
long long ans = 0;
int P = min (lim, M);
for (int i=0; i<=P; i++)
    if (minX[i] != INF && minX[i] <= P)
        ans += P - minX[i] + 1;
if (M > lim)
{
    int d = gcd (A, B);
    ans += solve (M, d) - solve (lim, d);
}
printf ("%I64d\n", ans);
return 0;
}