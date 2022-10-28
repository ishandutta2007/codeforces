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
const int p = 1e9 + 7;
void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<vector<int>> dp(k+1, vector<int>(n, 0));
    dp[0] = vector<int>(n,1);
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(j != 0) dp[i][j] += dp[i-1][j-1];
            if(j != n-1) dp[i][j] += dp[i-1][j+1];
            if(dp[i][j] >= p) dp[i][j]-=p;
        }
    }
    //cout*dp;
    vector<ll> coeff(n);
    for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++){
            coeff[j] += 1ll * dp[i][j] * dp[k-i][j];
            coeff[j] %= p;
        }
    }
    //cout+coeff;
    vector<int> a(n);
    cin>>a;
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans += 1ll * coeff[i] * a[i];
        ans %= p;
    }
    for(int i=0;i<q;i++){
        int idx,val;
        cin>>idx>>val;
        --idx;
        ans += 1ll * (val - a[idx]) * coeff[idx];
        ans %= p;
        a[idx] = val;
        if(ans < 0) ans+=p;
        cout<<ans<<"\n"; 
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}