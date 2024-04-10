#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

void solve() {
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n, h, l, r;
    cin >> n >> h >> l >> r;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp(h, -1e9);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        vector<int> dp1(dp.size(), -1e9);
//        cout << i << " : " << endl;
//        for(int j = 0; j < h; j++)
//            cout << (dp[j] < 0 ? -1 : dp[j]) << ' ';
//        cout << endl;

        for(int j = 0; j < h; j++) {
            int a1 = (j + a[i]) % h;
            int a2 = (j + a[i] - 1) % h;
//            cout << j << ' ' << a1 << ' ' <<a2 << ' ' << dp[j] << endl;
            dp1[a1] = max(dp[j] + (a1 >= l && a1 <= r), dp1[a1]);
            dp1[a2] = max(dp[j] + (a2 >= l && a2 <= r), dp1[a2]);
//            cout << dp1[a1] << ' ' << dp1[a2] << endl;
        }
//        cout << i << " : " << endl;
//        for(int j = 0; j < h; j++)
//            cout << (dp[j] < 0 ? -1 : dp[j]) << ' ';
//        cout << endl;
        dp = dp1;
    }

    int ans = 0;
    for(int i = 0; i < dp.size(); i++)
        ans = max(ans, dp[i]);
    cout << ans ;
}