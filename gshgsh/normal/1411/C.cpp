#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,M,to[MAXN],x[MAXN],y[MAXN],f[MAXN];bool vis[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
bool dfs(int u){if(f[u]!=-1)return f[u];if(vis[u])return 1;if(!to[u])return 0;return vis[u]=1,!(f[u]=dfs(to[u]))?vis[u]=0:0,f[u];}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)to[i]=vis[i]=0,f[i]=-1;M=get();int ans=M;For(i,1,M)x[i]=get(),y[i]=get(),to[x[i]]=y[i],ans-=x[i]==y[i];
		For(i,1,M)if(x[i]!=y[i]&&!vis[x[i]])ans+=dfs(x[i]);cout<<ans<<endl;
	}
	return 0;
}