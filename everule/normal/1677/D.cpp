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
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    cin>>v;
    for(int i=0;i<k;i++){
        if(v[n-1-i] > 0){
            cout<<"0\n";
            return;
        }
    }
    ll ans = 1;
    for(int i=0;i<n-k;i++){
        if(v[i] > 0) continue;
        else if(v[i] == 0){
            ans *= (k + 1);
            ans %= p;
        }
        else{
            ans *= (k + 1 + i);
            ans %= p;
        }
    }
    ans *= fact[k];
    ans %= p;
    cout<<ans<<"\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    computefactorial(1e6 + 7);
    while(t--){
        solve();
    }
}