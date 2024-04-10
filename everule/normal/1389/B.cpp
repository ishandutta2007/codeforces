#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
void solve(){
    int n,k,z;
    cin>>n>>k>>z;
    vector<int> seq(n);
    cin>>seq;
    vector<vector<int>> dp(n, vector<int>(z+1, -1e5));
    int ans = 0;
    dp[0][0] = seq[0];
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0] + seq[i];
        if(i==k){
            ans = max(ans, dp[i][0]);
        }
        if(i==k-1 && 0!=z){
            ans = max(ans, dp[i][0] + seq[i-1]);
        }
        for(int j=1;j<=z;j++){
            dp[i][j] = max(dp[i-1][j] + seq[i], dp[i][j-1] + seq[i-1] + seq[i]);
            if(i+2*j==k){
                ans = max(ans, dp[i][j]);
            }
            if(i+2*j==k-1 && j!=z){
                ans = max(ans, dp[i][j] + seq[i-1]);
            }
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}