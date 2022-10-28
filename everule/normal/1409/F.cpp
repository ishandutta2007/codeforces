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
    int n,k;
    string s,t;
    cin>>n>>k>>s>>t;
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(k+1, vector<ll>(n+1, -1e12)));
    dp[0][0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int l=0;l<=n;l++){
            if(s[i-1]==t[0]) {
                if(l==0) continue;
                dp[i][0][l] = dp[i-1][0][l-1];
            }
            else dp[i][0][l] = dp[i-1][0][l];
            if(s[i-1]==t[1]){
                dp[i][0][l] += l - (s[i-1]==t[0]);
            }
        }
        for(int j=1;j<=k;j++){
            dp[i][j][0] = 0;
            for(int l=1;l<=n;l++){
                if(s[i-1]==t[0]){
                    dp[i][j][l] = dp[i-1][j][l-1];
                }
                else{
                    dp[i][j][l] = dp[i-1][j][l];
                }
                if(s[i-1]==t[1]){
                    dp[i][j][l] += l - (s[i-1]==t[0]);
                }
                dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][l-1]);
                if(t[0]!=t[1]) dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][l] + l);
                else dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][l-1] + l-1);
            }
        }
    }   
    ll ans = -1;
    for(int j=0;j<=k;j++){
        for(int l=0;l<=n;l++){
            ans = max(ans, dp[n][j][l]);
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}