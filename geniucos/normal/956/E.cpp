#include<bits/stdc++.h>

using namespace std;

int N, L, R, S, dp[10009];
pair < int, int > v[10009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &L, &R);
for (int i=1; i<=N; i++)
    scanf ("%d", &v[i].second), S += v[i].second;
for (int i=1; i<=N; i++)
    scanf ("%d", &v[i].first), v[i].first ^= 1;
sort (v + 1, v + N + 1);
reverse (v + 1, v + N + 1);
L = S - L, R = S - R, swap (L, R);
for (int i=1; i<=S; i++)
    dp[i] = -2 * N;
for (int i=1; i<=N; i++)
{
    v[i].first ^= 1;
    for (int j=S; j>=v[i].second; j--)
        if (dp[j - v[i].second] + (v[i].first & (L <= j) & (j <= R)) > dp[j])
            dp[j] = dp[j - v[i].second] + (v[i].first & (L <= j) & (j <= R));
}
int ans = 0;
for (int i=1; i<=S; i++)
    if (dp[i] > ans)
        ans = dp[i];
printf ("%d\n", ans);
return 0;
}