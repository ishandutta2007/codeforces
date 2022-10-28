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
    int n,k,p;
    cin>>n>>k>>p;
    vector<int> people(n), keys(k);
    cin>>people>>keys;
    sort(people.begin(), people.end());
    sort(keys.begin(), keys.end());
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 1e18));
    for(int i=0;i<=k;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = max(dp[i-1][j-1],ll(std::abs(people[i-1] - keys[j-1]) + std::abs(keys[j-1] - p)));
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
        }
    }
    //cout*dp;
    cout<<dp[n][k]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}