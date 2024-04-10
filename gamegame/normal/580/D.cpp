#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
ll dp[262144][18];
int bc[262144];
ll g[18][18];
ll a[18];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i=0; i<n ;i++) cin >> a[i];
	for(int i=1; i<=k ;i++){
		int x,y;ll c;cin >> x >> y >> c;
		x--;y--;
		g[x][y]+=c;
	}
	ll ans=0;
	for(int i=0; i<(1<<n) ;i++){
		if(i!=0) bc[i]=bc[i^(i&-i)]+1;
		for(int j=0; j<n ;j++){
			if((i&(1<<j))==0) continue;
			if(i==(1<<j)){
				dp[i][j]=a[j];
				if(bc[i]==m) ans=max(ans,dp[i][j]);
				continue;
			}
			for(int k=0; k<n ;k++){
				if((i&(1<<k)) && j!=k) dp[i][j]=max(dp[i][j],dp[i^(1<<j)][k]+a[j]+g[k][j]);
			}
			if(bc[i]==m) ans=max(ans,dp[i][j]);
		}
	}
	cout << ans << endl;
}