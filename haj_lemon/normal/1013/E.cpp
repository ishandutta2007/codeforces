#include<bits/stdc++.h>
#define INF 2147483647
using namespace std;
int m,n,dp[5010][2510][4],a[5010],ans[5010];
int main(){
	cin>>n;m=(n+1)/2;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=0;i<=n;i++)
		for (int j=0;j<=m;j++)
			for (int k=1;k<=3;k++) dp[i][j][k]=INF;
	dp[0][0][1]=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<=m;j++){
			if (dp[i][j][1]!=INF){
				dp[i+1][j+1][3]=min(dp[i+1][j+1][3],dp[i][j][1]+max(0,a[i]-a[i+1]+1));
				dp[i+1][j][1]=min(dp[i+1][j][1],dp[i][j][1]);
			}
			if (dp[i][j][2]!=INF){
				dp[i+1][j][1]=min(dp[i+1][j][1],dp[i][j][2]);
				dp[i+1][j+1][3]=min(dp[i+1][j+1][3],dp[i][j][2]+max(0,a[i-1]-a[i+1]));
			}
			if (dp[i][j][3]!=INF){
				if (a[i+1]<a[i]){dp[i+1][j][1]=min(dp[i+1][j][1],dp[i][j][3]);}
				else dp[i+1][j][2]=min(dp[i+1][j][2],dp[i][j][3]+a[i+1]-a[i]+1);
			}
		}
	}
	for (int i=1;i<=m;i++)ans[i]=min(min(dp[n][i][1],dp[n][i][2]),dp[n][i][3]);
	for (int i=m-1;i>=1;i--)ans[i]=min(ans[i],ans[i+1]);
	for (int i=1;i<=m;i++) cout<<ans[i]<<' ';cout<<endl;
	return 0;
}