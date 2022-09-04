#include<bits/stdc++.h>
using namespace std;
int a[200];
main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	int dp[200][3];
	for(int i=0;i<200;i++)
	for(int j=0;j<3;j++)
	dp[i][j]=1e9;
	dp[0][0]=1;
	if(a[0]!=0&&a[0]!=2)
	dp[0][1]=0;
	if(a[0]!=0&&a[0]!=1)
	dp[0][2]=0;
	for(int i=1;i<n;i++)
	{
		dp[i][0]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;
		if(a[i]!=0&&a[i]!=2)
		dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
		if(a[i]!=0&&a[i]!=1)
		dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
	}
	printf("%d\n",min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]));
}