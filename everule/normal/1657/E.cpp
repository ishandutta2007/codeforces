#include <bits/stdc++.h>
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
const int p = 998244353;
ll modpower(ll base, ll power, ll mod=p){
    ll ans =1;
    base%=mod;
    while(power){
        if(power&1){
            ans*=base;
            ans%=mod;
        }
        base*=base;
        base%=mod;
        power>>=1;
    }
    return ans;
}
vector<ll> fact;
vector<ll> invfact;
void computefactorial(int n){
    ++n;
    fact.resize(n);
    invfact.resize(n);
    fact[0]=1;
    for(int i=1;i<n;i++){
        fact[i]=i*fact[i-1];
        fact[i]%=p;
    }
    invfact[n-1]=modpower(fact[n-1],p-2);
    for(int i=n-2;i>=0;i--){
        invfact[i]=(i+1)*invfact[i+1];
        invfact[i]%=p;
    }
}
ll ncr(int n, int r){
    return fact[n] * invfact[n-r] % p * invfact[r] % p;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<ll>> dp(n+1, vector<ll>(k+1));
    dp[0][k] = 1;
    for(int j=k;j>0;--j){
        for(int i=0;i<=n;i++){
            for(ll t=0;t<=i;t++){
                dp[i][j-1] += dp[i-t][j] * ncr(i, t) % p * modpower(j, (t*(t-1) / 2) + t * (i - t));
                dp[i][j-1] %= p;
            }
        }
    }
    //cout*dp;
    cout<<dp[n-1][0]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    computefactorial(500);
    solve();
}