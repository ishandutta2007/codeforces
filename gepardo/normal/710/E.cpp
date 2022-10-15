#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

const int INF = (int)1e18;
const int MAX = (int)3e7;

int dp[MAX];

main()
{
    int n, x, y; cin >> n >> x >> y;
    for (int i = 0; i < MAX; i++) dp[i] = INF;
    dp[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        dp[i + 1] = min(dp[i + 1], dp[i] + x);
        dp[i * 2] = min(dp[i * 2], dp[i] + y);
        dp[i*2+1] = min(dp[i*2+1], dp[i]+x+y);
        dp[i*2-1] = min(dp[i*2-1], dp[i]+x+y);
    }
    cout << dp[n];
}