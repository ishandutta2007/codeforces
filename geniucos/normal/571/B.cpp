#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int N, K, p, q, catep, catep1, A[300009];
long long INF, dp[3][300009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
for (int i=1; i<=N; i++)
    scanf ("%d", &A[i]);
sort (A + 1, A + N + 1);
p = N / K;
q = N % K;
catep1 = q;
catep = K - q;
INF = 1LL << 60;
for (int i=0; i<2; i++)
    for (int j=0; j<=catep1; j++)
        dp[i][j] = INF;
dp[0][0] = 0;
for (int i=0; i<=catep; i++)
{
    for (int j=0; j<=catep1; j++)
        dp[(i&1)^1][j] = INF;
    for (int j=0; j<=catep1; j++)
        if (dp[i&1][j] < INF)
        {
            int pos = i * p + j * (p + 1) + 1;
            if (pos + p - 1 <= N) dp[(i&1)^1][j] = min (dp[(i&1)^1][j], dp[i&1][j] + A[pos + p - 1] - A[pos]);
            if (pos + p <= N) dp[i&1][j + 1] = min (dp[i&1][j+1], dp[i&1][j] + A[pos + p] - A[pos]);
        }
}
printf ("%I64d\n", dp[catep&1][catep1]);
return 0;
}