#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
const int R=501;
const int T=2e6+1;
const int iu=1e6;
ll r,n;
ll dp[N];
ll x[N],y[N],z[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> r >> n;
	x[0]=1;y[0]=1;
	z[0]=0;
	ll duh=-1e9;
	ll ans=0;
	for(int i=1; i<=n ;i++){
		cin >> z[i] >> x[i] >> y[i];
		dp[i]=duh+1;
		for(int j=max(0LL,i-2*r); j<i ;j++){
			if(abs(x[i]-x[j])+abs(y[i]-y[j])<=z[i]-z[j]) dp[i]=max(dp[i],dp[j]+1);
		}
		if(i>=2*r) duh=max(duh,dp[i-2*r]);
		ans=max(ans,dp[i]);
	}
	cout << ans << '\n';
	
}