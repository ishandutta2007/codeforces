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
ll ncr(int n,int r){
    if(n<0 || r<0 || r>n) return 0ll;
    return fact[n] * invfact[r] %p * invfact[n-r] % p;
}
void solve(){
    int n,k;
    ll m;
    cin>>n>>m>>k;
    vector<vector<int>> dp(n+1, vector<int>(k+1));
    vector<vector<int>> val(n, vector<int>(n+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            val[i][j] = modpower(ncr(n,j), m/n + (i < m%n));
        }
    }
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int l=j;l>=max(0,int(j-n));--l){
                dp[i][j] = (dp[i][j] +  1LL * dp[i-1][l] * val[i-1][j-l])%p;
            }
        }
    }
    cout<<dp[n][k]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    computefactorial(10000);
    solve();
}