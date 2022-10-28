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
    vector<int> a(n);
    cin>>a;
    vector<int> dp(n+1);
    map<int, int> pre_dp;
    pre_dp[0] = 0;
    int pre_xor = 0;
    for(int i=1;i<=n;i++){
        pre_xor ^= a[i-1];
        dp[i] = dp[i-1];
        if(pre_dp.count(pre_xor) == 0){
            pre_dp[pre_xor] = -1e9;
        }
        dp[i] = max(dp[i], pre_dp[pre_xor] + 1);
        pre_dp[pre_xor] = dp[i];
    }
    cout<<n - dp[n]<<"\n";
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