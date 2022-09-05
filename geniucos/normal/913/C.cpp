#include<bits/stdc++.h>

using namespace std;

int N, L;
long long c[1009];

long long solve (int L, int i)
{
    if (i == 0) return 1LL * c[i] * L;
    if ((1LL << i) <= L)
    {
        long long curr = solve (L - (1LL << i), i - 1) + c[i];
        return min (curr, c[i + 1]);
    }
    long long curr = solve (L, i - 1);
    return min (curr, c[i]);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &L);
for (int i=0; i<N; i++)
{
    int x;
    scanf ("%d", &x);
    if (i == 0) c[i] = x;
    else c[i] = min ((long long) x, 2LL * c[i - 1]);
}
int lst = N - 1;
for (int i=N; (1LL << i) <= 2LL * L; i++)
    c[i] = 2LL * c[i - 1], lst = i;
printf ("%I64d\n", solve (L, lst));
return 0;
}