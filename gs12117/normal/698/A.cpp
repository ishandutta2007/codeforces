#include<stdio.h>
int n;
int a[100100];
int dp[100100][3];
int ans;
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	a[n]=0;
	dp[0][0]=0;
	dp[0][1]=0;
	dp[0][2]=0;
	for(i=0;i<=n;i++){
		dp[i+1][0]=99999999;
		dp[i+1][1]=99999999;
		dp[i+1][2]=99999999;
		for(j=0;j<3;j++){
			if((a[i]&j)!=j)continue;
			dp[i+1][j]=dp[i][0];
			for(k=1;k<3;k++){
				if(j!=k&&dp[i+1][j]>dp[i][k]){
					dp[i+1][j]=dp[i][k];
				}
			}
		}
		dp[i+1][0]++;
	}
	printf("%d",dp[n+1][0]-1);
	return 0;
}