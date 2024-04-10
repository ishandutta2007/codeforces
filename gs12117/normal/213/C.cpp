#include<stdio.h>
int n;
int a[310][310];
int dp[610][310][310];
int main(){
	int i,j,k,ts,te;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<=2*n;i++){
		for(j=0;j<=n;j++){
			for(k=0;k<=n;k++){
				dp[i][j][k]=-999999999;
			}
		}
	}
	dp[0][0][0]=a[0][0];
	for(i=1;i<n*2+1;i++){
		if(i<n){
			ts=0;
			te=i;
		}
		else{
			ts=i-n+1;
			te=n-1;
		}
		for(j=ts;j<=te;j++){
			for(k=ts;k<=te;k++){
				dp[i][j][k]=dp[i-1][j][k];
				if(j>0&&dp[i][j][k]<dp[i-1][j-1][k])dp[i][j][k]=dp[i-1][j-1][k];
				if(k>0&&dp[i][j][k]<dp[i-1][j][k-1])dp[i][j][k]=dp[i-1][j][k-1];
				if(j>0&&k>0&&dp[i][j][k]<dp[i-1][j-1][k-1])dp[i][j][k]=dp[i-1][j-1][k-1];
				if(j==k)dp[i][j][k]+=a[i-j][j];
				else dp[i][j][k]+=a[i-j][j]+a[i-k][k];
			}
		}
	}
	printf("%d",dp[2*n-2][n-1][n-1]);
}