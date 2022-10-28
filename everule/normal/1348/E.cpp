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
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> shrubs(n);
    for(auto &shrub : shrubs){
        cin>>shrub.first>>shrub.second;
    }
    vector<vector<ll>> dp(n+1, vector<ll>(k, -1e18));
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            for(int l=0;l<=min(j,shrubs[i].first);l++){
                int blue = min(shrubs[i].second, (shrubs[i].second + shrubs[i].first - l)%k);
                int baskets = (shrubs[i].first + shrubs[i].second - l)/k * k;
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-l] + blue + baskets);   
            }
            for(int l=j+1;l<=min(shrubs[i].first, k-1);l++){
                int blue = min(shrubs[i].second, (shrubs[i].second + shrubs[i].first - l)%k);
                int baskets = (shrubs[i].first + shrubs[i].second - l)/k * k;
                dp[i+1][j] = max(dp[i+1][j], dp[i][k-l+j] + blue + baskets + k); 
            }
        }
    }
    ll ans = -1;
    for(const auto &val : dp[n]){
        ans = max(ans, val);
    }
    cout<<ans/k<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}