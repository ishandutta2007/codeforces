#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define sz(x) (int)(x).size()
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
using ll = long long;
ll f(ll x, ll y, ll z) {
    return (x-y)*(x-y)+(y-z)*(y-z)+(x-z)*(x-z);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    rep(test,0,tests) {
        vector<vector<ll>> a(3);
        rep(i,0,3) {
            int n;
            cin>>n;
            a[i].resize(n);
        }
        rep(i,0,3) {
            rep(j,0,sz(a[i])) cin>>a[i][j];
            sort(all(a[i]));
        }
        vector<int> p{0,1,2};
        ll ans=LLONG_MAX;
        do {
            //cerr<<p[0]<<" "<<p[1]<<" "<<p[2]<<endl;
            auto &a1 = a[p[0]], &a2 = a[p[1]], &a3=a[p[2]];
            int j=0,k=0;
            rep(i,0,sz(a1)) {
                while(j+1<sz(a2) && a2[j+1]<=a1[i]) ++j;
                while(k<sz(a3) && a3[k]<a2[j]) ++k;
                if(k>=sz(a3)) break;
                ans=min(ans,f(a1[i],a2[j],a3[k]));
            }
        }while(next_permutation(all(p)));
        cout<<ans<<"\n";
    }
}