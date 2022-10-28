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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> d(n);
    cin>>d;
    sort(d.begin(), d.end());
    vector<int> pd(n+1);
    for(int i=1;i<=n;i++) pd[i] = (pd[i-1] + d[i-1]) % p;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        ll tot = pd[n];
        int spl = (lower_bound(d.begin(), d.end(), b) - d.begin());
        ll rel = pd[n] - pd[spl];
        ll unrel = pd[spl];
        spl = n - spl;
        //cout<<spl<<"\n";
        if(a > spl){
            cout<<"0\n";
            continue;
        }
        //cout<<rel<<" "<<unrel<<"\n";
        ll ansrel = rel * (spl - a) % p * modpower(spl, p-2) % p;
        ll ansunrel = unrel * (spl - a + 1) % p * modpower(spl + 1, p-2) % p;
        cout<< ((ansrel + ansunrel) % p + p) % p << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}