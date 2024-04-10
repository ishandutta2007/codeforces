#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000;
int a[maxn + 2], dp[maxn + 2][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1){
            cin >> a[i];
            dp[i][0] = dp[i][1] = maxn;
        }
        dp[0][0] = maxn;
        for(int i = 0; i < n; i += 1){
            dp[i + 1][1] = min(dp[i][0], dp[i + 1][1]);
            dp[i + 2][1] = min(dp[i][0], dp[i + 2][1]);
            dp[i + 1][0] = min(dp[i][1] + a[i + 1], dp[i + 1][0]);
            dp[i + 2][0] = min(dp[i][1] + a[i + 1] + a[i + 2], dp[i + 2][0]);
        }
        cout << min(dp[n][0], dp[n][1]) << "\n";
    }
    return 0;
}