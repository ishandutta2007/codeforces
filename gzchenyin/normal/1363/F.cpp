#include<cstdio>
#include<algorithm>
using namespace std;
 
int n,tt,cnt1[2005][30],cnt2[2005][30],dp[2005][2005];
char s[2005],t[2005];
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf(" %c",&s[i]);
		}
		for(int i=1;i<=n;i++)
		{
			scanf(" %c",&t[i]);
		}
		bool flag=true;
		for(int i=n;i>=1;i--)
		{
			for(int j=0;j<26;j++)
			{
				cnt1[i][j]=cnt1[i+1][j]+((s[i]-'a'==j) ? 1:0);
				cnt2[i][j]=cnt2[i+1][j]+((t[i]-'a'==j) ? 1:0);
				if(i==1 && cnt1[i][j]!=cnt2[i][j])
				{
					flag=false;
				}
//				printf("cnt1[%d][%d]=%d,cnt2[%d][%d]=%d\n",i,j,cnt1[i][j],i,j,cnt2[i][j]);
			}
		}
		if(!flag) 
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				dp[i][j]=dp[i-1][j]+1;
				if(s[i]==t[j]) dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
				if(cnt1[i+1][t[j]-'a']>cnt2[j+1][t[j]-'a']) dp[i][j]=min(dp[i][j],dp[i][j-1]);
//				printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
			}
		}
		printf("%d\n",dp[n][n]);
	}
	
}