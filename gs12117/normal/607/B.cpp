#include<stdio.h>
int n;
int a[510];
int dp[510][510];
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		dp[i][i]=1;
	}
	for(i=n;i>0;i--){
		for(j=i+1;j<=n;j++){
			dp[i][j]=999999999;
			if(a[i]==a[j]){
				if(j==i+1)dp[i][j]=1;
				else if(dp[i][j]>dp[i+1][j-1]){
					dp[i][j]=dp[i+1][j-1];
				}
			}
			for(k=i;k<j;k++){
				if(dp[i][j]>dp[i][k]+dp[k+1][j]){
					dp[i][j]=dp[i][k]+dp[k+1][j];
				}
			}
		}
	}
	printf("%d",dp[1][n]);
}