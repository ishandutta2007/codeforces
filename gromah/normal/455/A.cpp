#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000

int n, cnt[N + 1];
LL Dp[N + 1][2];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        int t;
        scanf("%d", &t);
        cnt[t] ++;
    }
    for (int i = 1; i <= N; i ++)
    {
        Dp[i][0] = max(Dp[i - 1][0], Dp[i - 1][1]);
        Dp[i][1] = Dp[i - 1][0] + (LL) i * cnt[i];
    }
    cout << max(Dp[N][0], Dp[N][1]) << endl;
    return 0;
}