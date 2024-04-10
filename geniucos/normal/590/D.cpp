#include<cstdio>

using namespace std;

int N, a[159], K, S;
long long INF = 1LL << 58, dp[2][159][158 * 153];

int mod (int x)
{
    if (x < 0) return -x;
    return x;
}

void Clear (int lin)
{
    for (int j=0; j<=K; j++)
        for (int p=0; p<=S; p++)
            dp[lin][j][p] = INF;
}

void Update (long long &val, long long curr)
{
    if (curr < val) val = curr;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &K, &S);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
if (N * (N - 1) / 2 < S) S = N * (N - 1) / 2;

Clear (0);
dp[0][0][0] = 0;
for (int i=0; i<N; i++)
{
    Clear ((i & 1) ^ 1);
    for (int j=0; j<=K && j<=i; j++)
        for (int p=0; p<=S; p++)
            if (dp[i & 1][j][p] < INF)
            {
                Update (dp[(i & 1) ^ 1][j][p], dp[i & 1][j][p]);
                if (p + mod (i + 1 - (j + 1)) <= S && j < K)
                    Update (dp[(i & 1) ^ 1][j + 1][p + mod (i + 1 - (j + 1))], dp[i & 1][j][p] + a[i + 1]);
            }
}

long long mini = INF;
for (int i=0; i<=S; i++)
    if (dp[N & 1][K][i] < mini)
        mini = dp[N & 1][K][i];
printf ("%I64d\n", mini);

return 0;
}