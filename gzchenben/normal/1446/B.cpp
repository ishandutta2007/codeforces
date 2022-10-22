#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,dp[5005][5005],ans;
char A[5005],B[5005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf(" %c",&A[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf(" %c",&B[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(A[i]!=B[j]) 
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
			else
			{
				dp[i][j]=max(4+(i-1)+(j-1),4+dp[i-1][j-1]);
			}
//			printf("dp %d %d=%d --%d\n",i,j,dp[i][j],dp[i][j]+(n-i)+(m-j)-n-m);
			ans=max(ans,dp[i][j]+(n-i)+(m-j)-n-m);
		}
	}
	printf("%d\n",ans);
}