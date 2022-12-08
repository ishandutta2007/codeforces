#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define sz(x) (int)(x).size()
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin>>s>>t;
    int n = sz(s), m = sz(t);
    vector<ll> dp(n+1,1);
    ll ans=0;
    const ll MOD=998244353;
    rep(i,0,n) {
        vector<ll> next(n+1);
        rep(j,0,n+1) {
            ll x= dp[j];
            if(j>0 && (j-1>=m || s[i]==t[j-1])) {
                next[j-1]=(next[j-1]+x)%MOD;
            }
            if(i+j>=m || s[i]==t[i+j]) {
                next[j]=(next[j]+x)%MOD;
            }
        }
        dp = move(next);
        if(i>=m-1) ans = (ans+dp[0])%MOD;
        // rep(j,0,n+1) cerr<<dp[j]<<" ";
        // cerr<<endl;
    }
    cout<<ans<<"\n";
    
}