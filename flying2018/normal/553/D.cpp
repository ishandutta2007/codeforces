#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define N 100010
using namespace std;
queue<int>q;
int nxt[N<<1],to[N<<1],head[N],cnt;
int deg[N],in[N],n;
bool cut[N];
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	deg[u]++;
	head[u]=cnt;
}
bool check(double x)
{
	for(int i=1;i<=n;i++) in[i]=cut[i]?0:deg[i];
	if(x<=1e-8) return true;
	for(int u=1;u<=n;u++)
	if(in[u])
		for(int i=head[u];i;i=nxt[i])
		if(cut[to[i]]) in[u]--;
	for(int i=1;i<=n;i++)
	if(in[i] && 1.0*in[i]/deg[i]<x) q.push(i),in[i]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			if(!in[v]) continue;
			in[v]--;
			if(1.0*in[v]/deg[v]<x) q.push(v),in[v]=0;
		}
	}
	for(int i=1;i<=n;i++)
	if(in[i]) return true;
	return false;
}
int ans[N];
int main()
{
	int m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		int a;
		scanf("%d",&a);
		cut[a]=true;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	double l=0,r=1;
	while(r-l>=1e-9)
	{
		double mid=(l+r)/2;
		if(check(mid)) l=mid,memcpy(ans,in,sizeof(ans));
		else r=mid;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	if(ans[i]) ++cnt;
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)
	if(ans[i]) printf("%d ",i);
	return 0;
}