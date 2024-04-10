#include<bits/stdc++.h>

using namespace std;

int N, nr;
long long ans[1000009];

void add (int d)
{
    int k = N / d;
    ans[++nr] = k + 1LL * d * (1LL * k * (k - 1) / 2);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int d=1; d * d<=N; d++)
    if (N % d == 0)
        add (d), add (N / d);
sort (ans + 1, ans + nr + 1);
for (int i=1; i<=nr; i++)
    if (i == 0 || ans[i] != ans[i - 1])
        printf ("%lld ", ans[i]);
printf ("\n");
return 0;
}