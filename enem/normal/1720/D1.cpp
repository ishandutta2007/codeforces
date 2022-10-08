#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, a, n) for(ll i=a; i<n; i++)

int main() {

    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    ll tc;
    cin>>tc;
    while(tc--) {
        ll n;
        cin>>n;
        ll a[n];
        rep(i,0,n) cin>>a[i];

        ll dp[n];
        dp[0] = 1;
        ll ans = 0;
        rep(i,1,n) {
            dp[i] = 1;
            rep(j, max(i-1025, 0LL), i) {
                if((a[j]^i) < (a[i]^j) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            ans = max(ans, dp[i]);
        }
        cout<<ans;

        cout<<'\n';
    }
    return 0;
}