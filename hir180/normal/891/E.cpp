#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000007
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
ll n,a[5005],sum,ans,dp[5005][5005];
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int main(){
	cin>>n>>sum;
	repn(i,n) cin>>a[i];
	dp[0][0] = 1;
	rep(i,n) rep(j,i+1){
		if(dp[i][j] == 0) continue;
		dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
		dp[i+1][j+1] = (dp[i+1][j+1]+dp[i][j]*a[i+1]%mod)%mod;
	}
	rep(i,n){
		ll add = dp[n][i],rev = modpow(n,mod-2);
		for(ll j=sum;j>=sum-(n-i)+1;j--) add = add*j%mod*rev%mod;
		if(i%2 == n%2) ans=(ans+mod-add)%mod;
		else ans=(ans+add)%mod;
	}
	cout<<ans<<endl;
}