#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int dp[2000][2000], p[2000][2000];

int repair(int i, int j)
{
    if (i) repair(i - 1, p[i][j]);
    cout << j << " ";
}

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 1; i <= n; i++) dp[0][i] = i;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = 123456789;
            if (s[i - 1] == 'R')
            {
                for (int k = 1; k < j; k++)
                    if (dp[i - 1][k] < dp[i][j]) dp[i][j] = dp[i - 1][k], p[i][j] = k;
            }
            if (s[i - 1] == 'L')
            {
                for (int k = j + 1; k <= n; k++)
                    if (dp[i - 1][k] < dp[i][j]) dp[i][j] = dp[i - 1][k], p[i][j] = k;
            }
            if (s[i - 1] == '=')
                dp[i][j] = dp[i - 1][j], p[i][j] = j;
            if (dp[i][j] != 123456789) dp[i][j] += j;
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    int mink = 1;
    for (int i = 2; i <= n; i++) if (dp[n - 1][i] < dp[n - 1][mink]) mink = i;
    repair(n - 1, mink);
}