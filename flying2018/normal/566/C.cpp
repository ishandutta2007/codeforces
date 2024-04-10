#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define N 200010
using namespace std;
int nxt[N<<1],to[N<<1],w1[N<<1],head[N],cnt;
void add(int u,int v,int w)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	w1[cnt]=w;
	head[u]=cnt;
}
int siz[N],all,root,minr;
bool cut[N];
void dfs(int u,int fa)
{
	siz[u]=1;
	int maxn=0;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(cut[v] || v==fa) continue;
		dfs(v,u);
		siz[u]+=siz[v];
		maxn=max(maxn,siz[v]);
	}
	maxn=max(maxn,all-siz[u]);
	if(maxn<minr) minr=maxn,root=u;
}
double sum,val[N];
int num[N];
void solve(int u,int fa,int s,int w)
{
	sum+=pow(w,1.5)*num[u];
	val[s]+=sqrt(w)*1.5*num[u];
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa) continue;
		solve(v,u,s,w+w1[i]);
	}
}
double ans=1e20,res;
int id;
void work(int u,int sumsiz)
{
	all=minr=sumsiz,root=0;
	dfs(u,0);
	u=root;
	dfs(u,0);
	if(cut[u]) return;
	cut[u]=true;
	sum=res=0;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		val[v]=0;
		solve(v,u,v,w1[i]);
		res+=val[v];
	}
	if(sum<ans) id=u,ans=sum;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(res>=val[v]*2) continue;
		work(v,siz[v]);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	work(1,n);
	printf("%d %.10f\n",id,ans);
	return 0;
}