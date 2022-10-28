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
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n==3){
        if(s=="LLL" || s=="RRR"){
            cout<<"1\n";
        }
        else{
            cout<<"0\n";
        }
        return;
    }
    vector<array<array<int, 4>, 4>> dp(n);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++) dp[1][i][j] = 100000000;
        dp[1][i][i] = 0;
        for(int j=0;j<2;j++){
            dp[1][i][i]+=((i>>j)&1) ^ s[2-j-1]=='R';
        }
        //cout<<dp[1][i][i]<<" ";
    }
    for(int i=2;i<n;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                dp[i][j][k] = 10000000;
                for(int l=0;l<4;l++){
                    if(((k>>1) == (l&1)) && (k!=3 || l!=3) && (k!=0 || l!=0)){
                        dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][l] + (s[i]=='R' ^ (k&1)));
                    }
                }
                //cout<<dp[i][j][k]<<" ";
            }
            //cout<<"\n";
        }
        //cout<<"\n";
    }
    int ans = 1e9;
    for(int j=0;j<4;j++){
        for(int k=0;k<4;k++){
            int x = (k<<2) + j;
            int l1 = x>>1;
            int l2 = x&7;
            if(l1==0 || l2==0 || l1==7 || l2==7){
                continue;
            }
            ans = min(ans, dp[n-1][j][k]);
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