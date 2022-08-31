#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+1;
ll n,d,r1,r2,r3;
ll a[N];
ll c1[N];
ll c2[N];
ll dp[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> r1 >> r2 >> r3 >> d;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		c1[i]=a[i]*r1+r3;
		c2[i]=min(r1*(a[i]+2),r2+r1);
		c2[i]=min(c2[i],c1[i]);
	}
	dp[0]=-d;
	for(int i=1; i<=n ;i++){
		dp[i]=1e18;
		if(i>=2){
			dp[i]=min(dp[i],dp[i-2]+4*d+c2[i-1]+c2[i]);
		}
		dp[i]=min(dp[i],dp[i-1]+3*d+c2[i]);
		dp[i]=min(dp[i],dp[i-1]+d+c1[i]);
	}
	ll ans=dp[n];//cost for ending at n
	ll xa=2*d+c2[n];
	ll xb=c1[n];
	for(int i=n-1; i>=1 ;i--){
		xa+=2*d+c2[i];
		xb+=2*d+c2[i];
		ans=min(ans,dp[i-1]+min(xa,xb)+d);
	}
	cout << ans << '\n';
}