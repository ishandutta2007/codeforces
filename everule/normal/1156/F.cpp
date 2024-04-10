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
ll inv(ll x){
    assert(x != 0); //this was 100% smart idea you should do too
    return modpower(x, p - 2, p);
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;
    sort(a.begin(), a.end());
    vector<int> c;
    {
        int j = 0;
        int i = 1;
        int cnt = 1;
        while(i < n){
            if(a[i] == a[j]){
                cnt++;
            }
            else{
                c.push_back(cnt);
                cnt = 1;
                j = i;
            }
            i++;
        }
        if(cnt != 0) c.push_back(cnt);
    }
    //cout+c; // I need 1 2 1
    //why I suck at programming basic loop
    ll ans = 0;
    vector<vector<ll>> dp(c.size(), vector<ll>(n + 1));
    //new dp state accounts for symmetry of equal elements
    //dp[i][j] is probability of reaching i with j steps
    //dp[i][j] = dp[<= i-1][j-1] * c[i] / (n - j + 1)
    //ans += dp[i][j] * (c[i] - 1) / (n - j)
    vector<ll> constantfactor(n + 1);
    for(int i=1;i<=n;i++) constantfactor[i] = inv(i);
    for(int i=0;i<c.size();i++){
        dp[i][1] = c[i] * constantfactor[n] % p;
        ans += dp[i][1] * (c[i] - 1) % p * constantfactor[n - 1] % p;
        ans %= p;
        if(i) dp[i][1] += dp[i-1][1];
        dp[i][1] %= p;
    }
    for(int j=2;j<=n;j++){
        for(int i=1;i<c.size();i++){
            dp[i][j] += dp[i-1][j-1] * c[i] % p * constantfactor[n - j + 1] % p;
            dp[i][j] %= p;
            if(j != n) ans += dp[i][j] * (c[i] - 1) % p * constantfactor[n - j] % p;
            ans %= p;
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= p;
        }
    }
    //cout*dp;
    cout<<ans<<"\n";
    //:weary:
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    computefactorial(1e5 + 7);
    solve();
}