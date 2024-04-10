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
    srand(42);
    int n, k;
    cin>>n >> k;
    vector<vector<ll>> c(n, vector<ll>(n));
    rep(i,0,n) rep(j,0,n) cin>>c[i][j];
    const ll INF = LLONG_MAX/4;
    const int REPS=15000;
    ll ans = INF;
    rep(it,0,REPS) {
        vector<int> col(n);
        rep(i,1,n) col[i] = rand()&1;
        vector<vector<ll>> dp(2,vector<ll>(n,INF));
        dp[0][0] = 0;
        rep(i,0,k) {
            int t = i&1, tt = t^1;
            rep(j,0,n) if(col[j]==tt) {
                dp[tt][j] = INF;
                rep(i,0,n) if(col[i]==t) {
                    dp[tt][j] = min(dp[tt][j], dp[t][i]+c[i][j]);
                }
            }
        }
        ans = min(ans,dp[0][0]);
    }
    cout<<ans<<endl;
}