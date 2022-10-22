#include<bits/stdc++.h>
using namespace std;
const int N=200005,mx=200000,mod=998244353;
int n,a[N],f[N],g[N],pr[N],ud[N],s;
struct nd{int v,x,y;};
vector<nd>e[N];
vector<int>p[N];
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
void dfs(int u)
{
	ud[u]=1;
	for(auto i:e[u])
	{
		int v=i.v,x=i.x,y=i.y;
		if(!ud[v])
		{
			for(auto j:p[y]) f[j]++;
			for(auto j:p[x]) f[j]--;
			for(auto j:p[y]) g[j]=min(g[j],f[j]);
			for(auto j:p[x]) g[j]=min(g[j],f[j]);
			dfs(v);
			for(auto j:p[y]) f[j]--;
			for(auto j:p[x]) f[j]++;
		}
	}
}
void cal(int u)
{
	ud[u]=1;
	for(auto i:e[u])
	{
		int v=i.v,x=i.x,y=i.y;
		if(!ud[v])
		{
			a[v]=a[u];
			for(auto j:p[y]) a[v]=1ll*a[v]*j%mod;
			for(auto j:p[x]) a[v]=1ll*a[v]*qp(j,mod-2)%mod;
			cal(v);
		}
	}
}
int main()
{
	for(int i=2;i<=mx;i++)
	{
		if(pr[i])
			continue;
		for(int j=i;j<=mx;j+=i)
		{
			pr[j]=1;
			int x=j;
			while(x%i==0)
				p[j].push_back(i),x/=i;
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
			g[i]=ud[i]=0;
		for(int i=0;i<=n;i++)
			e[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v,x,y;
			scanf("%d%d%d%d",&u,&v,&x,&y);
			e[u].push_back({v,x,y});
			e[v].push_back({u,y,x});
		}
		dfs(1);
		int z=1;
		for(int i=1;i<=n;i++)
			if(g[i]<0)
				z=1ll*z*qp(i,-g[i])%mod;
		a[1]=z;
		for(int i=1;i<=n;i++)
			ud[i]=0;
		cal(1);
		s=0;
		for(int i=1;i<=n;i++)
			s=(s+a[i])%mod;
		printf("%d\n",s);
	}
	return 0;
}