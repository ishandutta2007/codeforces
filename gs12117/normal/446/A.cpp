#include<stdio.h>
int n;
int a[100100];
int dp[100100][2];
int ans;
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		dp[i][0]=i;
		dp[i][1]=i;
		if(i!=0&&a[i]>a[i-1]){
			dp[i][0]=dp[i-1][0];
			dp[i][1]=dp[i-1][1];
		}
		if(i>1&&a[i]>a[i-2]+1&&dp[i][1]>dp[i-2][0])dp[i][1]=dp[i-2][0];
		if(i-dp[i][1]>ans)ans=i-dp[i][1];
		if(i-dp[i][0]+1>ans)ans=i-dp[i][0]+1;
	}
	ans++;
	if(ans>n)ans=n;
	printf("%d",ans);
}