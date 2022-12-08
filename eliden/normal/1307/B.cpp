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
        int n, x;
        cin>>n>>x;
        vector<int> a(n);
        rep(i,0,n) cin>>a[i];
        bool eq = false;
        rep(i,0,n) if(a[i]==x) eq = true;
        int mx = a[0];
        rep(i,1,n) mx=max(mx,a[i]);
        int ans;
        if(mx*2>=x) ans = 2;
        else {
            ans = (x+mx-1)/mx;
        }
        if(eq) ans = 1;
        cout<<ans<<"\n";
    }
}