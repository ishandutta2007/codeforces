#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int N = 55;
int n, m, h, dp[N][N][N];
int L[N], R[N], X[N], C[N];
inline void smax(int &a, int b){a = max(a, b);}
int main()
{
    scanf("%d%d%d", &n, &h, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d%d", &L[i], &R[i], &X[i], &C[i]);
    for (int i = 1; i <= h; i ++)
    {
        for (int len = 1; len <= n; len ++)
        {
            for (int l = 1; l + len - 1 <= n; l ++)
            {
                int r = l + len - 1;
                dp[i][l][r] = dp[i - 1][l][r];
                for (int j = l; j <= r; j ++)
                {
                    int sum = i * i;
                    for (int q = 0; q < m; q ++)
                        if (l <= L[q] && R[q] <= r && L[q] <= j && j <= R[q] && X[q] < i)
                            sum -= C[q];
                    smax(dp[i][l][r], dp[i][l][j - 1] + dp[i][j + 1][r] + sum);
                }
            }

        }
    }
    return !printf("%d\n", dp[h][1][n]);
}