#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,dp[8005],a,b,c;

int main()
{
    cin >> n >> a >> b >> c;
    for (int i = 0; i < 8005; ++i) dp[i] = -2e9;
    dp[0] = 0;
    for (int i = 0; i < 4003; ++i) {
        dp[i + a] = max(dp[i + a], dp[i] + 1);
        dp[i + b] = max(dp[i + b], dp[i] + 1);
        dp[i + c] = max(dp[i + c], dp[i] + 1);
    }
    cout << dp[n];

    return 0;
}