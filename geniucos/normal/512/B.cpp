#include<bits/stdc++.h>

using namespace std;

int N, M, l[309], c[309], dp[500009];
vector < int > vals;
map < int, int > mp;

void addDivisors (int n)
{
    for (int i=1; i * i <= n; i++)
        if (n % i == 0)
        {
            vals.push_back (i);
            if (n / i != i)
                vals.push_back (n / i);
        }
}

int gcd (int a, int b)
{
    int r;
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

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &l[i]);
    addDivisors (l[i]);
}
for (int i=1; i<=N; i++)
    scanf ("%d", &c[i]);
sort (vals.begin (), vals.end ());
vals.erase (unique (vals.begin (), vals.end ()), vals.end ()), M = vals.size ();
for (int i=0; i<M; i++)
    dp[i] = 1e9, mp[vals[i]] = i;
for (int i=1; i<=N; i++)
{
    for (int j=0; j<M; j++)
    if (dp[j] < 1e9)
    {
        int k = mp[gcd (vals[j], l[i])];
        if (dp[k] > dp[j] + c[i])
            dp[k] = dp[j] + c[i];
    }
    int k = mp[l[i]];
    if (dp[k] > c[i])
        dp[k] = c[i];
}
if (dp[0] >= 300000000) printf ("-1\n");
else printf ("%d\n", dp[0]);
return 0;
}