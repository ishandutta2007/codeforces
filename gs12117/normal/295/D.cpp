#include<stdio.h>
int n,m;
int mod=1000000007;
long long int dp[2010][2010][2];
long long int dps[2010][2010][2];
long long int ans;
int main(){
	int i,j,k;
	scanf("%d%d",&m,&n);
	for(i=1;i<n;i++){
		dp[0][i][0]=1;
		dp[0][i][1]=n-i;
		ans+=dp[0][i][1]*m;
		ans%=mod;
	}
	for(i=1;i<m;i++){
		for(j=1;j<n;j++){
			dps[i-1][j][0]=dp[i-1][j][0]+dps[i-1][j-1][0];
			dp[i][j][0]=dps[i-1][j][0]+dp[i][j-1][0];
			dp[i][j][0]%=mod;
		}
		for(j=n-1;j>0;j--){
			dps[i-1][j][1]=dp[i-1][j][1]+dps[i-1][j+1][1];
			dp[i][j][1]=dps[i-1][j][1]+dp[i][j+1][1];
		}
		for(j=1;j<n;j++){
			dp[i][j][1]+=(dp[i][j][0]+mod-dp[i-1][j][0])*(n-j);
			dp[i][j][1]%=mod;
			ans+=dp[i][j][1]*(m-i);
			ans%=mod;
		}
	}
	printf("%I64d",ans);
}