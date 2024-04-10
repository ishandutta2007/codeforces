#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e9+7;

void primefactorize(vector<ll>& f, ll n) {
    for(ll i=2; i<=sqrt(n); i++) {
        if(n%i==0) {
            f.push_back(i);
            while(n%i==0) n/=i;
        }
    }
    if(n>=2) f.push_back(n);
}

ll power(ll x, ll y) {
    if(y==0) return 1;
    else {
        ll k=power(x, y/2);
        if(y%2==0) return (k*k)%N;
        else return (((k*k)%N)*x)%N;
    }
}

int main () {
    ll x, n; cin>>x>>n; vector<ll> f; ll ans=1;
    primefactorize(f, x);
    for(ll i=0; i<f.size(); i++) {
        ans*=power(f[i], n/f[i]); ans%=N;
        ll tmp=f[i];
        while(n/f[i]>=tmp) {
            tmp*=f[i]; ans*=power(f[i], n/tmp); ans%=N;
        }
    }
    cout<<ans;
}