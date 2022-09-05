#include<bits/stdc++.h>

using namespace std;

int N, K, a[100009];
long long INF = 1000000000000000;

long long solve (long long val)
{
    map < long long, int > mp;
    mp[0] ++;
    long long s = 0, curr = 0;
    for (int i=1; i<=N; i++)
    {
        s += a[i];
        if (mp.count (s - val)) curr += mp[s - val];
        mp[s] ++;
    }
//    printf ("%I64d -> %I64d\n", val, curr);
    return curr;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
long long ans = 0;
if (K == 1) ans = solve (1);
else
if (K == -1) ans = solve (1) + solve (-1);
else
{
    long long p = 1;
    while (1)
    {
        ans += solve (p);
        if (1LL * p * K > INF || 1LL * p * K < -INF) break;
        p = 1LL * p * K;
    }
}
printf ("%I64d\n", ans);
return 0;
}