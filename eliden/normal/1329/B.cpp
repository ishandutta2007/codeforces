#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a,x) for(auto &a:x)
using ll = long long;
using vi = vector<int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    rep(test,0,tests) {
        ll d,m;
        cin>>d>>m;
        ll ans = 1;
        for(ll x=1;x<=d;x*=2) {
            ll y = min(x,d-x+1)+1;
            //debug(y);
            ans=(ans*y)%m;
        }
        ans=(ans+m-1)%m;
        cout<<ans<<"\n";
    }
}