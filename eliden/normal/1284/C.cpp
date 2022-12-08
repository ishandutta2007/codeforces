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
    ll m;
    cin>>n>>m;
    vector<ll> fact(n+1,1);
    rep(i,1,n+1) fact[i] = (i*fact[i-1])%m;
    ll ans = 0;
    rep(i,1,n+1) {
        int j = n-i+1;
        ll x = (j*fact[j])%m;
        ans = (ans+x*fact[i])%m;
    }
    cout<<ans<<"\n";
}