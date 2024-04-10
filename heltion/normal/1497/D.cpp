#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for(cin >> T; T; T -= 1){
        int n;
        cin >> n;
        vector<int> t(n + 1), s(n + 1);
        for(int i = 1; i <= n; i += 1) cin >> t[i];
        for(int i = 1; i <= n; i += 1) cin >> s[i];
        vector<LL> dp(n + 1);
        for(int i = 1; i <= n; i += 1){
            for(int j = i - 1; j >= 1; j -= 1) if(t[j] != t[i]){
                LL dpj = dp[i] + abs(s[i] - s[j]);
                LL dpi = dp[j] + abs(s[i] - s[j]);
                dp[i] = max(dp[i], dpi);
                dp[j] = max(dp[j], dpj);
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << "\n";
    }
    return 0;
}