#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<int> a(n), dp(n);
        for(int& x : a) cin >> x;
        for(int i = n - 1; i >= 0; i -= 1){
            if(i + a[i] >= n) dp[i] = a[i];
            else dp[i] = a[i] + dp[i + a[i]];
        }
        cout << *max_element(dp.begin(), dp.end()) << "\n";
    }
    return 0;
}