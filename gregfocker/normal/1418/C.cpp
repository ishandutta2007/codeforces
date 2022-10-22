#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
int n;
int a[N];
int dp[N][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        dp[n + 1][0] = dp[n + 1][1] = dp[n + 2][0] = dp[n + 2][1] = 0;
        for (int i = n; i >= 1; i--)
        {
            /// dp[i][0]
            dp[i][0] = min(dp[i + 2][1], dp[i + 1][1]);
            /// dp[i][1]
            dp[i][1] = min(dp[i + 1][0] + a[i], dp[i + 2][0] + a[i] + a[i + 1]);
        }
        cout << dp[1][1] << "\n";
    }
}