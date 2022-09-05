#include<bits/stdc++.h>

using namespace std;

int N, K, P, a[300009];

long long comb2 (int n)
{
    return 1LL * n * (n - 1) / 2;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &P, &K);
for (int i=1; i<=N; i++)
{
    int x;
    scanf ("%d", &x);
    int curr = (1LL * x * x) % P;
    curr = (1LL * curr * curr) % P;
    curr = (curr - 1LL * K * x) % P;
    if (curr < 0)
        curr += P;
    a[i] = curr;
}
sort (a + 1, a + N + 1);
long long ans = 0;
for (int i=1; i<=N; i++)
{
    int j = i;
    while (j < N && a[j + 1] == a[i])
        j ++;
    ans += comb2 (j - i + 1);
    i = j;
}
printf ("%I64d\n", ans);
return 0;
}