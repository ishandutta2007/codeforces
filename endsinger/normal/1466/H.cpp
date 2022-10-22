#include<bits/stdc++.h>
using namespace std;
const int N=50,M=2005,mod=1e9+7;
int n,m,z,p[N],c[N][N],dp[M],w[N][N],k,v[N],mx[N],a[N],b[N],vis[N],si,sj,ci,cj,f;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=0;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=n;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			int j=i,s=0;
			while(!vis[j])
			{
				vis[j]=1;
				j=p[j];
				s++;
			}
			a[s]++;
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i])
			k++,v[k]=i,mx[k]=a[i];
	for(int i=1;i<=k;i++)
		z=z*(mx[i]+1)+mx[i];
	for(int i=0;i<=n;i++)
	{
		w[i][0]=w[i][1]=1;
		for(int j=1;j<=n;j++)
			if(j!=n-i)
				w[i][1]=1ll*w[i][1]*j%mod;
		for(int j=2;j<=n;j++)
			w[i][j]=1ll*w[i][j-1]*w[i][1]%mod;
	}
	dp[0]=1;
	for(int i=0;i<=z;i++)
	{
		int y=i;
		for(int x=k;x>=1;x--)
		{
			a[x]=y%(mx[x]+1);
			y/=(mx[x]+1);
		}
		for(int x=1;x<=k;x++)
			b[x]=0;
		si=ci=0;
		for(int x=1;x<=k;x++)
			si+=a[x]*v[x],ci+=a[x];
		while(1)
		{
			int j=0;
			for(int x=1;x<=k;x++)
				j=j*(mx[x]+1)+b[x];
			if(j==i)
				break;
			sj=cj=0,f=1;
			for(int x=1;x<=k;x++)
				sj+=b[x]*v[x],cj+=b[x],f=1ll*f*c[a[x]][b[x]]%mod;
			if((ci-cj)%2==0)
				f=(mod-f)%mod;
			dp[i]=(dp[i]+1ll*dp[j]*f%mod*w[sj][si-sj]%mod)%mod;
			b[1]++;
			for(int x=1;x<=k;x++)
			{
				if(b[x]>mx[x])
				{
					b[x]=0;
					b[x+1]++;
				}
				else
					break;
			}
		}
	}
	printf("%d\n",dp[z]);
	return 0;
}