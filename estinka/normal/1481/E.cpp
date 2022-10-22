#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const int inf = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), now(n, -1);
    vector<vector<int> > pos(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        now[i] = pos[a[i]].size();
        pos[a[i]].push_back(i);
    }
    vector<int> dp(n + 1, inf); // how many books
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int r = pos[a[i]].back(), len = pos[a[i]].size();
        if (i == pos[a[i]].front())
        {
            dp[r + 1] = min(dp[r + 1], dp[i] + r - i + 1 - len);
        }
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    }
    int ans = dp[n];
    for (int i = 0; i < n; i++)
    {
        int stay = pos[a[i]].size() - now[i];
        int move = n - i - stay;
        ans = min(ans, dp[i] + move);
    }
    cout << ans << "\n";
    return 0;
}