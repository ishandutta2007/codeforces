#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
typedef long long ll;
typedef long double ld;
using namespace std;

const ll inf = 1e18 + 79;
void updmin(ll& a, const ll& b)
{
    a = min(a, b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k; ll p;
    cin >> n >> k >> p;
    vector<ll> a(n), b(k);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < k; i++) cin >> b[i];
    sort(b.begin(), b.end());
    vector<vector<ll> > dp(n + 1, vector<ll>(k + 1, inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            updmin(dp[i][j + 1], dp[i][j]);
            updmin(dp[i + 1][j + 1], max(dp[i][j], abs(a[i] - b[j]) + abs(b[j] - p)));
        }
    }
    cout << *min_element(dp[n].begin(), dp[n].end()) << "\n";
    return 0;
}