#include<bits/stdc++.h>

using namespace std;

int N, a[509], b[509], k[509];
long long dp[509][509];
const long long INF = 1LL << 60;

void read ()
{
    pair < int, pair < int, int > > v[509];
    scanf ("%d", &N);
    for (int i=1; i<=N; i++)
        scanf ("%d %d %d", &v[i].second.first, &v[i].first, &v[i].second.second);
    sort (v + 1, v + N + 1);
    reverse (v + 1, v + N + 1);
    for (int i=1; i<=N; i++)
        a[i] = v[i].second.first, b[i] = v[i].first, k[i] = v[i].second.second;
}

void update (long long &x, long long y)
{
    if (y > x)
        x = y;
}

int main ()
{
//freopen("test.in", "r", stdin);

read ();
for (int i=0; i<=N; i++)
    for (int j=0; j<=N; j++)
        dp[i][j] = -INF;
dp[0][0] = 0;
for (int i=1; i<=N; i++)
    for (int j=0; j<i; j++)
        if (dp[i - 1][j] > -INF)
        {
            update (dp[i][j], dp[i - 1][j] + max (0LL, a[i] - 1LL * b[i] * k[i]));
            update (dp[i][j + 1], dp[i - 1][j] + a[i] - 1LL * b[i] * j);
        }
long long ans = -INF;
for (int i=0; i<=N; i++)
    if (dp[N][i] > ans)
        ans = dp[N][i];
printf ("%I64d\n", ans);
return 0;
}