#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[1111111],cmn[1111][1111],dp[1111][1111],sum1[1111][1111],sum2[1111][1111],b[1111111],cnt,L[1111],R[1111],l,r,mn,mnp,pre;
int ct[1111],pr[1111][555],cp;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d",&c[i]);
	b[++cnt]=c[1];
	for (int i=2;i<=m;i++)
	{
		if (c[i]==c[i-1]) continue;
		b[++cnt]=c[i];
	}
	for (int i=1;i<=cnt;i++)
	{
		if (!L[b[i]]) L[b[i]]=i;
	}
	for (int i=cnt;i>=1;i--)
	{
		if (!R[b[i]]) R[b[i]]=i;
	}
	if (cnt>=1100)
	{
		printf("0\n");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=L[i];j<=R[i];j++)
		{
			if (b[j]<i) 
			{
				printf("0\n");
				return 0;
			}
		}
	}
	for (int i=1;i<=cnt;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (b[i]==j) pr[i][j]=pr[i-1][j]+1;
			else pr[i][j]=pr[i-1][j];
		}
	}
	for (int i=1;i<=n;i++) ct[i]=pr[cnt][i];
	for (int i=1;i<=cnt;i++)
	{
		for (int j=i+1;j<=cnt;j++)
		{
			if (b[i]==b[j])
			{
				for (int k=b[i]+1;k<=n;k++)
				{
					cp=pr[j][k]-pr[i-1][k];
					if (cp && cp!=ct[k]) 
					{
						printf("0\n");
						return 0;
					}
				}
			}
		}
	}
	for (int i=1;i<=cnt;i++)
	{
		cmn[i][i]=b[i];
		for (int j=i+1;j<=cnt;j++) cmn[i][j]=min(cmn[i][j-1],b[j]);
	}
	for (int i=1;i<=cnt;i++)
	{
		dp[i][i-1]=1;
	}
	dp[cnt+1][cnt]=1;
	for (int i=0;i<cnt;i++)
	{
		for (int j=1;j+i<=cnt;j++)
		{
			l=j;r=i+j;
			for (int k=l;k<=r;k++)
			{
				sum1[l][r]=(1ll*dp[l][k-1]*dp[k][r-1]+sum1[l][r])%mod;
			}
			for (int k=l;k<=r;k++)
			{
				sum2[l][r]=(1ll*dp[l+1][k]*dp[k+1][r]+sum2[l][r])%mod;
			}
			mn=cmn[l][r];
			if (L[mn]<l || R[mn]>r) continue;
			dp[l][r]=1ll*sum1[l][L[mn]]*sum2[R[mn]][r]%mod;
			pre=L[mn];
			for (int k=L[mn]+1;k<=R[mn];k++)
			{
				if (b[k]==mn)
				{
					dp[l][r]=1ll*dp[l][r]*dp[pre+1][k-1]%mod;
					pre=k;
				}
			}
		}
	}
	printf("%d\n",dp[1][cnt]);
	return 0;
}