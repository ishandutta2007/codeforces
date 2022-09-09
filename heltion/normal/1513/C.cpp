#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr int maxm = 200000;
    vector<vector<int>> dp(maxm + 1, vector<int>(10));
    for(int i = 0; i < 10; i += 1) dp[0][i] = 1;
    for(int i = 1; i <= maxm; i += 1)
        for(int j = 0; j < 10; j += 1){
            if(j < 9) dp[i][j] = dp[i - 1][j + 1];
            else dp[i][j] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        }
    int t;
    for(cin >> t; t; t -= 1){
        string s;
        int m;
        cin >> s >> m;
        LL ans = 0;
        for(char c : s) ans = (ans + dp[m][c - '0']) % mod;
        cout << ans << "\n";
    }
    return 0;
}