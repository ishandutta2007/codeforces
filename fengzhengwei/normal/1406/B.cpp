#include<bits/stdc++.h>
using namespace std;
long long read()
{
	char c;
	long long w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	long long ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
long long f[100006][6];
long long g[100006][6];
long long a[100006];
int main(){
	int T;
	T=read();
	while(T--)
	{
		int n;
		n=read();
		for(int i=0;i<=n;i++)
		{
			if(i!=0)
			a[i]=read();
			for(int j=1;j<=5;j++)
			{
				f[i][j]=-1e9-7;
				g[i][j]=1e9+7;
			}
			f[i][0]=1;
			g[i][0]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=5;j++)
			{
				f[i][j]=f[i-1][j];
				g[i][j]=g[i-1][j];
				if(a[i]>=0&&g[i-1][j-1]!=1e9+7)
				{
					g[i][j]=min(g[i][j],g[i-1][j-1]*a[i]);
					if(g[i][j]==1e9+7)g[i][j]=g[i-1][j-1]*a[i];
				}
				if(a[i]<=0&&f[i-1][j-1]!=-1e9-7)
				{
					g[i][j]=min(g[i][j],f[i-1][j-1]*a[i]);
					if(g[i][j]==1e9+7)g[i][j]=f[i-1][j-1]*a[i];
				}
				if(a[i]>=0&&f[i-1][j-1]!=-1e9-7)
				{
					f[i][j]=max(f[i][j],f[i-1][j-1]*a[i]);
					if(f[i][j]==-1e9-7)f[i][j]=f[i-1][j-1]*a[i];
				}
				if(a[i]<=0&&g[i-1][j-1]!=1e9+7)
				{
					f[i][j]=max(f[i][j],g[i-1][j-1]*a[i]);
					if(f[i][j]==-1e9-7)f[i][j]=f[i-1][j-1]*a[i];
				}
			}
		}
		printf("%lld\n",f[n][5]);
	}
	return 0;
}