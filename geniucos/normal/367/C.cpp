#include<bits/stdc++.h>

using namespace std;

int N, M, lim, a[100009];

long long getLength (int N)
{
    if (N & 1) return 1LL * N * (N - 1) / 2 + 1;
    return 1LL * N * (N - 1) / 2 + N / 2;
}

int main ()
{
scanf ("%d %d", &N, &M), lim = N, N = 0;
for (int i=1; i<=M; i++)
    scanf ("%d %d", &a[0], &a[i]);
sort (a + 1, a + M + 1), reverse (a + 1, a + M + 1);
long long ans = 0;
while (getLength (N + 1) <= lim) ans += a[++N];
printf ("%I64d\n", ans);
return 0;
}