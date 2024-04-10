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
    string s,t;
    cin>>s>>t;
    int n=s.size(), m=t.size();
    vector<int> len(n, -1);
    for(int i=1;i<n;i++){
        for(int j=i, sum=0;j>=0;--j){
            if(s[j]=='.'){
                --sum;
            }
            else{
                ++sum;
            }
            if(sum>0){
                break;
            }
            if(sum==0){
                len[i]=i-j+1;
                break;   
            }
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9 + 7));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=min(dp[i-1][j] + 1, dp[i][j]); 
            if(j && s[i-1]==t[j-1]){
                dp[i][j]=min(dp[i][j], dp[i-1][j-1]);
            }
            if(~len[i-1]){
                dp[i][j]=min(dp[i-len[i-1]][j], dp[i][j]);
            }
        }
    }
    cout<<dp[n][m];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}