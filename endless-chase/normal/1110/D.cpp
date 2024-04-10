#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,cnt[1111111],ans,x,dp[2][10][10],la,nw,cr,cw,anp;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	for (int i=1;i<=m;i++)
	{
		while(cnt[i]>8) 
		{
			cnt[i]-=3;
			ans++;
		}
	}
	la=0;nw=1;
	for (int i=0;i<=1;i++)
	{
		for (int j=0;j<=8;j++)
		{
			for (int k=0;k<=8;k++)
			dp[i][j][k]=-1e9;
		}
	}
	dp[la][0][0]=0;
	for (int i=1;i<=m;i++)
	{
		for (int j=0;j<=8;j++)
		{
			for (int k=0;k<=8;k++)
			dp[nw][j][k]=-1e9;
		}
		for (int j=0;j<=8;j++)
		{
			for (int k=0;k<=8;k++)
			{
				if (dp[la][j][k]<0) continue;
				for (int h=0;h<=2;h++)
				{
					for (int t=0;t<=2;t++)
					{
						if (t>j || t>k) continue;
						cr=cnt[i]-3*h-t;
						if (cr<0) continue;
						cw=k-t;
						dp[nw][cw][cr]=max(dp[nw][cw][cr],dp[la][j][k]+h+t);
					}
				}
			}
		}
		la^=1;nw^=1;
	}
	for (int j=0;j<=8;j++)
	{
		for (int k=0;k<=8;k++)
		{
			anp=max(anp,ans+dp[la][j][k]);
		}
	}
	printf("%d\n",anp);
	return Accepted;
}