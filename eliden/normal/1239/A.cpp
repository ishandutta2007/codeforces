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
    int n, m;
    cin >> n >> m;
    int k = max(n,m);
    vector<ll> dp(k);
    dp[0]=1, dp[1] = 2;
    const ll MOD=1e9+7;
    rep(i,2,k) {
        dp[i]=(dp[i-1]+dp[i-2])%MOD;
    }
    ll ans = (2*dp[n-1]+dp[m-1]*2+MOD-2)%MOD;
    cout << ans << endl;
}