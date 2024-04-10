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
ll ncr(int n, int r){
    if(r < 0 || n < 0 || r > n) return 0;
    return fact[n] * invfact[r] % p * invfact[n-r] % p; 
}
void solve(){
    int n;
    cin>>n;
    ++n;
    vector<int> a(n);
    cin>>a;
    while(a.size() > 0 && a.back() == 0){
        a.pop_back();
        --n;
    }
    if(n == 0){
        cout<<"0\n";
        return;
    }
    ll ans = 0;
    for(int i=a[0]-1,j=0;i>=0;--i){
        while(j < n && a[j] > i) ++j;
        ans += ncr(j + i - 1, i);
    }
    for(int i=1;i<n;i++){
        ans += ncr(a[i] + i - 1, i);
    }
    cout<<ans % p<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    computefactorial(5e5);
    solve();
}