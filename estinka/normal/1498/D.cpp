#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
typedef long long ll;
using namespace std;

const ll one = 1e5;
void apply(ll& k, int t,ll x)
{
    if (t == 1) k = (k + (x + one - 1) / one);
    else k = (k * x + one - 1) / one;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> dp(m + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        ll x, y;
        cin >> t >> x >> y;
        for (int j = m - 1; j >= 0; j--)
        {
            if (dp[j] == -1) continue;
            for (ll val = j, k = 0; k < y; k++)
            {
                apply(val, t, x);
                if (val > m || dp[val] != -1) break;
                dp[val] = i + 1;
            }
        }
    }
    for (int i = 1; i <= m; i++) cout << dp[i] << " ";
    cout << "\n";
    return 0;
}