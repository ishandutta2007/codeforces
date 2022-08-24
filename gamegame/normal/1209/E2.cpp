#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int n,m;
int a[12][2001];
int dp[2][4096];
int sos[4096];
bool use[2001];
pair<int,int>b[2001];
void solve(){
	cin >> n >> m;
	for(int j=1; j<=m ;j++) b[j].fi=0;
	for(int i=0; i<n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> a[i][j];
			b[j].fi=max(b[j].fi,a[i][j]);
			b[j].se=j;
		}
	}
	sort(b+1,b+m+1);
	for(int j=m; j>=max(1,m-n+1) ;j--) use[b[j].se]=true;
	for(int l=0; l<(1<<n) ;l++) dp[0][l]=0;
	int c=0,p=1;
	for(int j=1; j<=m ;j++){
		if(!use[j]) continue;
		c^=1;p^=1;
		for(int l=0; l<(1<<n) ;l++) dp[c][l]=0;
		for(int k=0; k<n ;k++){
			int tmp=a[0][j];
			for(int l=0; l<n-1 ;l++) a[l][j]=a[l+1][j];
			a[n-1][j]=tmp;
			for(int l=0; l<(1<<n) ;l++) sos[l]=dp[p][l];
			for(int i=0; i<n ;i++){
				for(int l=0; l<(1<<n) ;l++){
					if(l&(1<<i)) sos[l]=max(sos[l],sos[l^(1<<i)]+a[i][j]);
				}
			}
			for(int l=0; l<(1<<n) ;l++) dp[c][l]=max(dp[c][l],sos[l]);
		}
	}
	for(int j=m; j>=max(1,m-n+1) ;j--) use[b[j].se]=false;
	cout << dp[c][(1<<n)-1] << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}