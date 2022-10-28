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
    string s;
    cin>>s;
    int n = s.size();
    int dp[10][10];
    int ans = 0;
    for(int j=0;j<10;j++){
        for(int k=0;k<10;k++){
            dp[j][k] = 0;
            for(int i=0;i<n;i++){
                if(s[i] - '0' == j && dp[j][k]%2 == 0){
                    ++dp[j][k];
                }   
                if(s[i] - '0' == k && dp[j][k]%2==1){
                    ++dp[j][k];
                }   
                if(j!=k){
                    ans = max(ans, dp[j][k] - 1 + (dp[j][k]%2==0));
                }
                else{
                    ans = max(ans, dp[j][k]/2);
                }
            }
        }
    }
    cout<<n-ans<<"\n";
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