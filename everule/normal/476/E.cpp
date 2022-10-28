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
const int AL = 26;
void solve(){
    string s,t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    vector<int> dp1(n+1, -1);
    for(int i=1;i<=n;i++){
        int idx = m-1;
        int j = i;
        while(idx>=0 && --j>=0){
            if(t[idx]==s[j]){
                --idx;
            }
        }
        dp1[i] = j;
    }
    //cout+dp1;
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1e9));
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        dp[i][0] = 0;
        for(int j=1;j<=n;j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);
            if(~dp1[i] && j>=m) dp[i][j] = max(dp[i][j], dp[dp1[i]][j-m] + 1);
        }
    }
    //cout*dp;
    for(int i=n;i>=0;--i){
        cout<<dp[n][i]<<" ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}