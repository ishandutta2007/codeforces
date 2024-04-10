#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

struct Edge
{
	int next,to;
}e[MAXN*2];
int head[MAXN],etot=0;
int deg[MAXN];
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
	++deg[u];
}

int c[4][MAXN];
int dep[MAXN];
void dfs(int u,int fa)
{
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}

int t[4],tt[4];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=3; ++i)
		for(int j=1; j<=n; ++j)
			scanf("%d",&c[i][j]);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for(int i=1; i<=n; ++i)
		if(deg[i]>2)
		{
			printf("-1");
			return 0;
		}
	
	for(int i=1; i<=n; ++i)
		if(deg[i]==1)
		{
			dfs(i,0);
			break;
		}
	
	for(int i=0; i<3; ++i)
		t[i]=i+1;
	
	ll ans=1e18;
	do
	{
		ll res=0;
		for(int i=1; i<=n; ++i)
			res += c[t[dep[i]%3]][i];
		if(ans>res)
		{
			ans=res;
			for(int i=0; i<3; ++i) tt[i]=t[i];
		}
	}while(next_permutation(t,t+3));
	
	cout<<ans<<endl;
	for(int i=1; i<=n; ++i)
		cout<<tt[dep[i]%3]<<' ';
	return 0;
}