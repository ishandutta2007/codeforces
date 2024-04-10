#include<bits/stdc++.h>

using namespace std;

int N, K, a[509], b[509];
long long dp[2][509][509];
const long long INF = 1LL << 60;

pair < int, int > getInterval (int a, int b, int sum)
{
    ///returns interval of i s.t. I can obtain i red and sum - i blue
    ///s.t. 0<=i<=a, K - 1, 0<=sum-i<=b, K - 1
    a = min (a, K - 1), b = min (b, K - 1);
    int l = max (0, sum - b), r = min (a, sum);
    return {l, r};
}

void update (int lin, int j, int k, long long val)
{
    if (j >= K)
        j -= K, val ++;
    if (k >= K)
        k -= K, val ++;
    assert (j < K && k < K);
    if (val > dp[lin][j][k])
        dp[lin][j][k] = val;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
for (int i=0; i<K; i++)
    for (int j=0; j<K; j++)
        dp[0][i][j] = -INF;
dp[0][0][0] = 0;
for (int i=1; i<=N; i++)
{
    scanf ("%d %d", &a[i], &b[i]);
    int lin = i & 1;
    for (int j=0; j<K; j++)
        for (int k=0; k<K; k++)
            dp[lin][j][k] = -INF;
    int times = (a[i] + b[i]) / K, r = (a[i] + b[i]) % K;
    auto takeAll = getInterval (a[i], b[i], r);
    auto takeAlmost = getInterval (a[i], b[i], r + K);
    for (int j=0; j<K; j++)
        for (int k=0; k<K; k++)
            if (dp[lin ^ 1][j][k] >= 0)
            {
                if (times >= 1)
                    for (int p=takeAlmost.first; p<=takeAlmost.second; p++)
                        update (lin, j + p, k + r + K - p, dp[lin ^ 1][j][k] + times - 1);
                for (int p=takeAll.first; p<=takeAll.second; p++)
                    update (lin, j + p, k + r - p, dp[lin ^ 1][j][k] + times);
            }
}
long long ans = 0;
for (int j=0; j<K; j++)
    for (int k=0; k<K; k++)
        if (dp[N & 1][j][k] > ans)
            ans = dp[N & 1][j][k];
printf ("%I64d\n", ans);
return 0;
}