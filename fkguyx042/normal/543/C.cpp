#include <bits/stdc++.h>
using namespace std;

int dp[1 << 20];
int cost[30][30], f[30][30], change[30][30];

int n, m;
char s[30][30];

inline void getCost ()
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < m; ++i)
        {
            int sum = 0, tem = 0;
            f[i][k] = 0x7fffffff;
            for (int j = 0; j < n; ++j)
            {
                if (s[j][i] == s[k][i])
                {
                    change[i][k] |= 1 << j;
                    sum += cost[j][i];
                    tem = max (tem, cost[j][i]);
                }
            }
            f[i][k] = min (f[i][k], sum - tem);
        }
    }
}

int main()
{
    ios::sync_with_stdio (0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> cost[i][j];

    getCost();

    memset (dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int st = 0; st < (1 << n); ++st)
    {
        for (int i = 0; i < n; ++i)
        {
            if ( (st & 1 << i) == 0)
            {
                for (int j = 0; j < m; ++j)
                {
                    dp[st | change[j][i]] = min (dp[st | change[j][i]], dp[st] + f[j][i]);
                    dp[st | 1 << i] = min (dp[st | 1 << i], dp[st] + cost[i][j]);
                }
                break;
            }
        }
    }
    cout << dp[ (1 << n) - 1] << endl;
}