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
ll C(int n, int r){
    return fact[n] * invfact[r] % p * invfact[n-r] % p;
}

void solve(){
    int n;
    cin>>n;
    vector<ll> f2(n+1), f12(n+1);
    f2[0] = 1;
    f12[0] = 1;
    f2[2] = 1;
    f12[1] = 1;
    f12[2] = 2;
    for(int i=3;i<=n;i++){
        if(i % 2 == 0) f2[i] = f2[i-2] * (i - 1) % p;
        f12[i] = (f12[i-1] + (i - 1) * f12[i-2]) % p;
    }
    ll ans = 0;
    for(int k=0;k<=n-k;k+=2){
        ans += C(n - k, k) * f2[k] % p * modpower(2, k/2) % p * f12[n - 2 * k] % p;
    }
    cout<<ans % p<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    computefactorial(5e5);
    while(t--){
        solve();
    }
}