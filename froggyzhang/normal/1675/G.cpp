#include<bits/stdc++.h>
using namespace std;
#define N 255
typedef long long ll;
inline void ckmin(int &x,int y){x=min(x,y);}
int n,m,dp[N][N][N],a[N],s[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=m;++j){
			for(int k=0;k<=j;++k){
				int w=dp[i-1][j][k];
				for(int p=k;j+p<=m;++p){
					ckmin(dp[i][j+p][p],abs(s[i]-(j+p))+w);
				}
			}
		}
	}
	int ans=1e9;
	for(int i=0;i<=m;++i){
		ckmin(ans,dp[n][m][i]);
	}
	cout<<ans<<'\n';
	return 0;
}