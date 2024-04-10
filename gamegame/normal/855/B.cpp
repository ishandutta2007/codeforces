#include<iostream>
using namespace std;
typedef long long ll;
ll dp[4][100001];
ll a[100001];
int n;
ll p,q,r;
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> p >> q >> r;
    dp[1][0]=-6e18;
    for(int i=1; i<=n ;i++) cin >> a[i];
    for(int i=1; i<=n ;i++){
        dp[1][i]=max(dp[1][i-1],dp[0][i]+p*a[i]);
    }
    dp[2][0]=-6e18;
    dp[3][0]=-6e18;
    ll ans=-6e18;
    for(int i=1; i<=n ;i++){
        dp[2][i]=max(dp[2][i-1],dp[1][i]+q*a[i]);
    }
    for(int i=1; i<=n ;i++){
        dp[3][i]=max(dp[3][i-1],dp[2][i]+r*a[i]);
        ans=max(ans,dp[3][i]);
    }
    cout << ans << '\n';
}