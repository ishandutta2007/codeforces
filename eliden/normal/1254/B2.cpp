#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<": "<<x<<endl
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];
    ll sum = 0;
    rep(i,0,n) sum += a[i];
    ll s2 = sum;
    vector<ll> primes;
    for(ll f=2; f*f<=sum; ++f) {
        if(s2%f==0) {
            primes.push_back(f);
            while(s2%f==0) s2/=f;
        }
    }
    if(s2!=1) primes.push_back(s2);
    if(primes.empty()) cout<<"-1\n";
    else {
        ll best=LLONG_MAX;
        for(ll p:primes) {
            auto b = a;
            ll gor=0;
            ll acc =0;
            rep(i,0,n) {
                if(b[i]+gor<=0) {
                    gor+=b[i];
                }
                else {
                    b[i] += gor;
                    gor = 0;
                    ll rem = b[i]%p;
                    if(rem<p-rem) {
                        gor = rem;
                    }
                    else {
                        gor = -(p-rem);
                    }
                }
                acc+=abs(gor);
            }
            best=min(best,acc);
        }
        cout<<best<<endl;
    }
}