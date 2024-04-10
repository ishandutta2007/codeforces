#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000 + 1;
int dp[maxn][3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int i = 1; i <= 1000; i += 1){
        dp[i][0] = -1;
        if(i >= 3 and dp[i - 3][0] != -1){
            dp[i][0] = dp[i - 3][0] + 1;
            dp[i][1] = dp[i - 3][1];
            dp[i][2] = dp[i - 3][2];
        }
        if(i >= 5 and dp[i - 5][0] != -1){
            dp[i][0] = dp[i - 5][0];
            dp[i][1] = dp[i - 5][1] + 1;
            dp[i][2] = dp[i - 5][2];
        }
        if(i >= 7 and dp[i - 7][0] != -1){
            dp[i][0] = dp[i - 7][0];
            dp[i][1] = dp[i - 7][1];
            dp[i][2] = dp[i - 7][2] + 1;
        }
    }
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        if(dp[n][0] == -1) cout << "-1\n";
        else cout << dp[n][0] << " " << dp[n][1] << " " << dp[n][2] << "\n";
    }
    return 0;
}