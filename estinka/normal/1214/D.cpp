#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

int n, m;
vector<vector<int> > ans;
void good(vector<string>& v, const ll& mod)
{
    vector<vector<ll> > dp1(n, vector<ll>(m, 0)), dp2(n, vector<ll>(m, 0));
    dp1[0][0] = 1; dp2[n - 1][m - 1] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '#') continue;
            if (i) dp1[i][j] += dp1[i - 1][j];
            if (j) dp1[i][j] += dp1[i][j - 1];
            dp1[i][j] %= mod;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (v[i][j] == '#') continue;
            if (i < n - 1) dp2[i][j] += dp2[i + 1][j];
            if (j < m - 1) dp2[i][j] += dp2[i][j + 1];
            dp2[i][j] %= mod;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 && j == 0) || (i == n - 1 && j == m - 1)) continue;
            if (dp1[n - 1][m - 1] != (dp1[i][j] * dp2[i][j]) % mod) ans[i][j] = false;
        }
    }
}
const ll mod = 999999937, mod2 = 999999893;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<vector<int> > dp(n, vector<int>(m, 0)); dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '#') continue;
            if (i) dp[i][j] |= dp[i - 1][j];
            if (j) dp[i][j] |= dp[i][j - 1];
        }
    }
    if (!dp[n - 1][m - 1])
    {
        cout << "0\n";
        return 0;
    }
    ans.assign(n, vector<int>(m, true)); ans[0][0] = ans[n - 1][m - 1] = false;
    good(v, mod); good(v, mod2);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (ans[i][j])
            {
                cout << "1\n";
                return 0;
            }
    cout << "2\n";
    return 0;
}