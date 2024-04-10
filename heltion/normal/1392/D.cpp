#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int cmp(const string& s, const string& t){
    int res = 0;
    for(int i = 0; i < (int)s.size(); i += 1) res += s[i] != t[i];
    return res;
}
int f(const string& s){
    int n = s.size();
    vector<int> dp(n + 1, n);
    dp[0] = 0;
    for(int j = 0; j < n; j += 1){
        if(j + 2 <= n) dp[j + 2] = min(dp[j + 2], dp[j] + cmp(s.substr(j, 2), "RL"));
        if(j + 3 <= n) dp[j + 3] = min(dp[j + 3], dp[j] + cmp(s.substr(j, 3), "RRL"));
        if(j + 3 <= n) dp[j + 3] = min(dp[j + 3], dp[j] + cmp(s.substr(j, 3), "RLL"));
        if(j + 4 <= n) dp[j + 4] = min(dp[j + 4], dp[j] + cmp(s.substr(j, 4), "RRLL"));
    }
    return dp.back();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, ans = INT_MAX;
        string s;
        cin >> n >> s;
        for(int j = 0; j <= 3; j += 1){
            string t = s.substr(j) + s.substr(0, j);
            ans = min(f(t), ans);
        }
        for(int j = 1; j <= 3; j += 1){
            string t = s.substr(n - j) + s.substr(0, n - j);
            ans = min(f(t), ans);
        }
        cout << ans << "\n";
    }
    return 0;
}