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
    int tests;
    cin>>tests;
    rep(test,0,tests) {
        int n,d;
        cin>>n>>d;
        vector<int> a(n);
        rep(i,0,n) cin>>a[i];
        int ans = a[0];
        rep(i,1,n) {
            int canadd = d/i;
            int will = min(canadd, a[i]);
            ans += will;
            d -= i*will;
        }
        cout<<ans<<"\n";
    }
}