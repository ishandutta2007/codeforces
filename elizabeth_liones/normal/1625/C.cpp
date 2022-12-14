#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const int inf = 1e9 + 5;
void upd(int& a, int b) { a = min(a, b); }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, l, lim;
    cin >> n >> l >> lim;
    vector<int> d(n), a(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int> > dp(n, vector<int>(n, inf));
    dp[0][0] = 0;
    int ans = inf;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= min(i, lim); j++)
        {
            for (int k = i + 1; k < n; k++)
            {
                upd(dp[k][j + k - i - 1], dp[i][j] + a[i] * (d[k] - d[i]));
            }
            if (j + n - i - 1 <= lim) upd(ans, dp[i][j] + a[i] * (l - d[i]));
        }
    }
    cout << ans << "\n";
    return 0;
}