#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), pf(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            pf[i + 1] = pf[i] ^ a[i];
        }
        vector<int> dp(n + 1, 0);
        map<int, int> dp2;
        dp2[0] = -1;
        for (int r = 1; r <= n; r++)
        {
            dp[r] = dp[r - 1] + 1;
            if (dp2.count(pf[r])) dp[r] = min(dp[r], dp2[pf[r]] + r);
            else dp2[pf[r]] = 1e9;
            dp2[pf[r]] = min(dp2[pf[r]], dp[r] - r - 1);
        }
        //cout << "                   ";
        cout << dp[n] << "\n";
    }
    return 0;
}