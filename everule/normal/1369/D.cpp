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
const int MAXN = 2e6 + 7;
vector<ll> dp;
const int p = 1e9 + 7;
void precompute(int n){
    dp.resize(n + 1);
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 4;
    dp[4] = 4;
    for(int i=5;i<=n;i++){
        if(i%3){
            dp[i] =  2*dp[i-2] + dp[i-1];
        }
        else{
            dp[i] = dp[i-2] + 4*dp[i-3] + 4*dp[i-4] + 4;
        }
        dp[i]%=p;
    }
}
void solve(){
    int n;
    cin>>n;
    cout<<dp[n]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    precompute(MAXN);
    while(t--){
        solve();
    }
}