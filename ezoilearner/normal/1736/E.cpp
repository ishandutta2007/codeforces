#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
constexpr int N=505,inf=1e9;
int n,ans,a[N],dp[N][N][N],mx[N][N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",a+i);
	rep(i,1,n)rep(j,0,i)rep(k,1,n)dp[i][j][k]=-inf;
	rep(i,0,n)rep(j,1,n)mx[i][j]=-inf;
	dp[1][0][1]=a[1],dp[1][1][2]=a[2];
	rep(i,1,n)mx[0][i]=a[1];
	rep(i,2,n)mx[1][i]=a[2];
	rep(i,2,n){
		rep(j,0,i){
			rep(k,1,n){
				if(j)dp[i][j][k]=dp[i-1][j-1][k]+a[k];
				if(k>=i&&j>=k-i)dp[i][j][k]=max(dp[i][j][k],mx[j-(k-i)][k-1]+a[k]);
			}
		}
		rep(j,0,i)rep(k,1,n)mx[j][k]=max(mx[j][k-1],dp[i][j][k]);
	}
	rep(i,0,n)rep(j,1,n)ans=max(ans,dp[n][i][j]);
	return printf("%d\n",ans),0;
}