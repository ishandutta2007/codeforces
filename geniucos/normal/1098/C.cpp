#include<bits/stdc++.h>

using namespace std;

int N, f[100009], l[100009], r[100009];
long long S;

long long fillOut (int pos, int K, int leftOver)
{
    if (leftOver == 0) return 0;
    if (leftOver <= 1LL * f[pos - 1] * K)
    {
        f[pos] = leftOver;
        return 1LL * f[pos] * pos;
    }
    f[pos] = f[pos - 1] * K;
    return 1LL * pos * f[pos] + fillOut (pos + 1, K, leftOver - f[pos]);
}

void printCurrentF (int K, int length)
{
    l[1] = r[1] = 1;
    for (int i=2; i<=length; i++)
    {
        l[i] = r[i - 1] + 1, r[i] = r[i - 1] + f[i];
        int steps = K, papa = l[i - 1];
        for (int j=l[i]; j<=r[i]; j++)
        {
            printf ("%d ", papa);
            if (--steps == 0)
                steps = K, papa ++;
        }
    }
    printf ("\n");
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %I64d", &N, &S);
if (S > 1LL * N * (N + 1) / 2 || S < 2 * N - 1)
{
    printf ("No\n");
    return 0;
}
printf ("Yes\n");
if (S == 1LL * N * (N + 1) / 2)
{
    for (int i=1; i<N; i++)
        printf ("%d ", i);
    printf ("\n");
    return 0;
}
f[1] = 1;
int p = 2, u = N - 1, mij, ras = -1;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (1 + fillOut (2, mij, N - 1) <= S) ras = mij, u = mij - 1;
    else p = mij + 1;
}
///K = ras
int K = ras, leftOver = N - 1;
S --;
for (int i=2; i<=N + 1; i++)
{
    if (leftOver == 0)
    {
        assert (S == 0);
        printCurrentF (K, i - 1);
        return 0;
    }
    int p = 1, u = min ((long long) leftOver, 1LL * f[i - 1] * K), mij, ras = -1;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        f[i] = mij;
        if (1LL * f[i] * i + fillOut (i + 1, K, leftOver - f[i]) <= S) ras = mij, u = mij - 1;
        else p = mij + 1;
    }
    assert (ras != -1);
    f[i] = ras, leftOver -= f[i], S -= 1LL * f[i] * i;
}
return 0;
}