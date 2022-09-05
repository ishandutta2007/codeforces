#include<bits/stdc++.h>

using namespace std;

int maxi, N, f[209], ap[209];
long long ans;
vector < int > v[209];

void df (int nod)
{
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (ap[*it] % 4 == 0)
            ap[*it] = 1, df (*it);
}

long long gcd (long long a, long long b)
{
    long long r;
    while (b)
        r = a % b, a = b, b = r;
    return a;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &f[i]), v[f[i]].push_back (i);
long long ans = 1;
for (int i=1; i<=N; i++)
    if (ap[i] == 0)
    {
        int j = i;
        while (ap[j] == 0) ap[j] = 4, j = f[j];
        int k = f[j], v2[209]; ap[k] = 2, v2[0] = 1, v2[1] = k;
        while (k != j) k = f[k], ap[k] = 2, v2[++v2[0]] = k;
        for (int i=1; i<=v2[0]; i++) df (v2[i]);
        ans = 1LL * ans / gcd (ans, v2[0]) * v2[0];
    }
for (int i=1; i<=N; i++)
if (ap[i] == 1)
{
    int j = i, sz = 1;
    while (ap[f[j]] == 1) j = f[j], sz ++;
    if (sz > maxi) maxi = sz;
}
long long ans2 = ans;
while (ans2 < maxi) ans2 += ans;
printf ("%I64d\n", ans2);
return 0;
}