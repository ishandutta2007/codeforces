#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
typedef long long ll;
using namespace std;

const int mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int> > dp(k, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; i++) dp[0][i] = 1;
        for (int i = 1; i < k; i++)
        {
            dp[i][n] = 1;
            for (int j = n - 1; j >= 0; j--)
            {
                dp[i][j] = dp[i - 1][n - j] + dp[i][j + 1];
                dp[i][j] %= mod;
            }
        }
        cout << dp[k - 1][0] << "\n";
    }
    return 0;
}