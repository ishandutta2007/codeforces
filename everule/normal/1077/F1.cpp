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
const ll INF = 1e18;
void solve(){
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> a(n);
    cin>>a;
    vector<vector<ll>> dp(n+1, vector<ll>(x+1, -INF));
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            ll mx = -1e18;
            for(int l=i-1;l>=max(0,i-k);--l){
                mx = max(mx, dp[l][j-1]);
            }
            dp[i][j] = mx + a[i-1];
        }
    }
    ll ans = -INF;
    for(int i=n-k+1;i<=n;i++){
        ans = max(ans, dp[i][x]);
    }
    if(ans < 0) cout<<"-1\n";
    else cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}