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
    ll n;
    cin >> n;
    ll f = n;
    for(ll j = 2; j*j<=n; ++j) {
        if(n%j==0) {
            f = j;
            break;
        }
    }
    ll m = n;
    while(m!=1 && m%f==0) m/=f;
    ll ans = 1;
    if(m==1) ans = f;
    else ans = 1;
    cout<<ans<<endl;
}