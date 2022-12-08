#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<"@"<<__LINE__<<": "<<x<<endl
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin >> tests;
    rep(test,0,tests) {
        int n;
        cin >> n;
        vi a(n+1);
        rep(i,1,n+1) cin >> a[i];
        vector<map<int,int>> mps(n+1);
        vi root(n+1), dp(n+1);
        ll ans=0;
        rep(i,1,n+1) {
            root[i] = i;
            if(mps[root[i-1]].count(a[i])) {
                int p = mps[root[i-1]][a[i]]-1;
                dp[i] = 1+dp[p];
                root[i] = root[p];
            }
            mps[root[i]][a[i]] = i;
            ans += dp[i];
        }
        // rep(i,0,n+1) {
        //     debug(dp[i]);
        //     debug(root[i]);
        // }
        cout<<ans<<"\n";
    }
}