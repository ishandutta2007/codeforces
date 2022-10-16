#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int mod=1e9+9,xx=105;// 
int f[xx][xx],g[xx][xx],w[xx][xx],s[xx],t[xx];
int f1[xx][xx],g1[xx][xx];
int n,m,o,a,b;
int dp[xx],to[xx],vis[xx];
//to:i 
//dp:ib 
signed main(){//n 
	n=read(),m=read(),a=read(),b=read();
	memset(w,0x3f,sizeof(w));
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		f[a][b]=1,g[a][b]=1,w[a][b]=1;
	}
	o=read();
	for(int i=1;i<=o;i++)s[i]=read(),t[i]=read();
	memset(dp,0x3f,sizeof(dp));
	dp[b]=0;
	vector<int>sx;// 
	sx.push_back(b);
	memcpy(f,w,sizeof(f));
	memcpy(g,w,sizeof(g));
	for(int k=1;k<=n;k++)g[k][k]=1,f[k][k]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				if(i==k||j==k)continue;
				if(f[i][j]>f[i][k]+f[k][j])
				{
					f[i][j]=f[i][k]+f[k][j];
					g[i][j]=0;
				}
				if(f[i][j]==f[i][k]+f[k][j])
				{
					g[i][j]+=1ll*g[i][k]*g[k][j]%mod;
					g[i][j]%=mod;
				}
			}
		}
	}
	memcpy(f1,f,sizeof(f));
	memcpy(g1,g,sizeof(g));
	for(int u=0;u<sx.size();u++)
	//s 
	{
		// 
		int x=sx[u];
		memcpy(f,w,sizeof(f));
		memcpy(g,w,sizeof(g));
		for(int k=1;k<=n;k++)g[k][k]=1,f[k][k]=0;
		for(int k=1;k<=n;k++)
		{
			if(vis[k])continue;
			for(int i=1;i<=n;i++)
			{
				if(vis[i])continue;
				for(int j=1;j<=n;j++)
				{
				if(vis[j])continue;
					if(i==j)continue;
					if(i==k||j==k)continue;
					if(f[i][j]>f[i][k]+f[k][j])
					{
						f[i][j]=f[i][k]+f[k][j];
						g[i][j]=0;
					}
					if(f[i][j]==f[i][k]+f[k][j])
					{
						g[i][j]+=1ll*g[i][k]*g[k][j]%mod;
						g[i][j]%=mod;
					}
				}
			}
		}
//		cout<<x<<"!!!\n";
		for(int i=1;i<=n;i++)
		{
			if(dp[i]<1e9)continue;
			for(int k=1;k<=o;k++)
			{
//				if(f[s[k]][t[k]]>1e9)continue;// (ix)
//				cout<<i<<" "<<k<<" ss "<<x<<"\n";
//				cout<<i<<" "<<k<<" "<<x<<"\n";
				if(1ll*g1[s[k]][i]*g1[i][t[k]]%mod!=g1[s[k]][t[k]]||f1[s[k]][i]+f1[i][t[k]]!=f1[s[k]][t[k]])continue;
				if(f1[s[k]][x]<f1[s[k]][i])continue;//x 
				// 
				// 
				//itx 
				if(1ll*g[i][x]*g[x][t[k]]%mod!=g[i][t[k]]||f[i][x]+f[x][t[k]]!=f[i][t[k]])continue;// 
				dp[i]=dp[x]+1;
				sx.push_back(i);
				if(i==a)cout<<dp[i]<<"\n",exit(0);
				break;
			}
		}
		
		vis[x]=1;
	}
	puts("-1");
    return 0;
}