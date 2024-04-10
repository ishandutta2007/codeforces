#include <iostream>

using namespace std;

int n, l, a[100], b[100], dp[3001][100][2] = {{{0}}};

const int mod = 1e9 + 7;

int main(void)
{
    cin >> n >> l;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i];
        if (a[i] <= l)
            dp[a[i]][i][0] = 1;
        if ((b[i] <= l) && (b[i] != a[i]))
            dp[b[i]][i][1] = 1;
    }
    for (int i = 1; i < l; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < 2; ++k)
                if (dp[i][j][k])
                {
                    if (k == 0)
                    {
                        for (int jj = 0; jj < n; ++jj)
                            if (jj != j)
                            {
                                if ((b[jj] != a[jj]) && (b[jj] == b[j]) && (i + b[jj] <= l))
                                    dp[i + b[jj]][jj][1] = (dp[i + b[jj]][jj][1] + dp[i][j][k]) % mod;
                                else
                                    if ((a[jj] == b[j]) && (i + a[jj] <= l))
                                        dp[i + a[jj]][jj][0] = (dp[i + a[jj]][jj][0] + dp[i][j][k]) % mod;
                            }
                    }
                    else
                    {
                        for (int jj = 0; jj < n; ++jj)
                            if (jj != j)
                            {
                                if ((b[jj] != a[jj]) && (b[jj] == a[j]) && (i + b[jj] <= l))
                                    dp[i + b[jj]][jj][1] = (dp[i + b[jj]][jj][1] + dp[i][j][k]) % mod;
                                else
                                    if ((a[jj] == a[j]) && (i + a[jj] <= l))
                                        dp[i + a[jj]][jj][0] = (dp[i + a[jj]][jj][0] + dp[i][j][k]) % mod;
                            }
                    }
                }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < 2; ++k)
            ans = (ans + dp[l][i][k]) % mod;
    cout << ans << endl;
    return 0;
}