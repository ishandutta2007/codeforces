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
void solve(){
    ll q,p;
    cin>>p>>q;
    if(p%q != 0){
        cout<<p<<"\n";
        return;
    }
    vector<pair<ll,ll>> primes;
    auto factor = [&](ll k){
        while(q%k==0){
            if(primes.empty() || primes.back().first != k) primes.push_back({k,0});
            ++primes.back().second;
            q/=k;
        }
    };
    factor(2);
    factor(3);
    for(ll i=5;i*i<=q;i+=6){
        factor(i);
        factor(i+2);
    }
    if(q > 1) primes.push_back({q,1});
    ll ans = p;
    auto poww = [&](ll a,ll b){
        ll ans = 1;
        while(b){
            if(b&1) ans*=a;
            a*=a;
            b>>=1;
        }
        return ans;
    };
    auto factor2 = [&](ll k){
        ll ans = 0;
        ll x = p;
        while(x%k==0){
            x/=k;
            ++ans;
        }
        return ans;
    };
    for(const auto &[prime,power] : primes){
        ans = min(ans, poww(prime, factor2(prime) - power + 1));
    }
    cout<<p/ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}