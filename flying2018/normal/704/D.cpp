#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#define inf 100000000
#define N 200010
using namespace std;
int nxt[N<<3],to[N<<3],f[N<<3],head[N],rcnt=1;
int cur[N];
void add(int u,int v,int w)
{
	nxt[++rcnt]=head[u];
	to[rcnt]=v;
	f[rcnt]=w;
	head[u]=rcnt;
	nxt[++rcnt]=head[v];
	to[rcnt]=u;
	f[rcnt]=0;
	head[v]=rcnt;
}
int in[N];
void add(int u,int v,int l,int r)
{
	in[v]+=l;
	in[u]-=l;
	add(u,v,r-l);
}
queue<int>q;
int dis[N],dep[N],all;
bool bfs(int s,int t)
{
	for(int i=1;i<=all;i++) dep[i]=0,cur[i]=head[i];
	q.push(s);
	dep[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=nxt[i])
		if(f[i])
		{
			int v=to[i];
			if(!dep[v]) dep[v]=dep[u]+1,q.push(v);
		}
	}
	return dep[t];
}
int dfs(int u,int t,int flow)
{
	if(!flow || u==t) return flow;
	int res=0;
	for(int &i=cur[u];i;i=nxt[i])
	if(f[i])
	{
		int v=to[i],fl;
		if(dep[v]==dep[u]+1 && (fl=dfs(v,t,min(flow,f[i]))))
		{
			f[i]-=fl;
			f[i^1]+=fl;
			flow-=fl;
			res+=fl;
			if(!flow) break;
		}
	}
	return res;
}
int dinic(int s,int t)
{
	int ans=0;
	while(bfs(s,t)) ans+=dfs(s,t,inf);
	return ans;
}
map<int,int>mx,my;
int tot,cnt[N],id[N],mw[N];
bool lf[N];
int main()
{
	int n,m,rw,bw,chg=0;
	scanf("%d%d%d%d",&n,&m,&rw,&bw);
	if(rw>bw) swap(rw,bw),chg=1;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(!mx.count(x)) mx[x]=++tot;
		if(!my.count(y)) lf[my[y]=++tot]=true;
		cnt[mx[x]]++,cnt[my[y]]++;
		add(mx[x],my[y],1);
		id[i]=rcnt;
	}
	for(int i=1;i<=tot;i++) mw[i]=inf;
	for(int i=1;i<=m;i++)
	{
		int opt,x,v;
		scanf("%d%d%d",&opt,&x,&v);
		x=opt==1?mx[x]:my[x];
		if(x) mw[x]=min(mw[x],v);
	}
	int s=tot+1,t=s+1,ss=t+1,tt=ss+1;
	for(int i=1;i<=tot;i++)
	{
		int a=cnt[i],b=min(mw[i],cnt[i]);
		int l=(a-b+1)>>1,r=(a+b)>>1;
		if(l>r){puts("-1");return 0;}
		if(!lf[i]) add(s,i,l,r);
		else add(i,t,l,r);
	}
	add(t,s,inf);
	all=tt;
	int res=0;
	for(int i=1;i<=t;i++)
	{
		if(in[i]<0) add(i,tt,-in[i]);
		if(in[i]>0) add(ss,i,in[i]),res+=in[i];
	}
	if(dinic(ss,tt)!=res){puts("-1");return 0;}
	res=dinic(s,t);
	printf("%lld\n",1ll*res*rw+1ll*(n-res)*bw);
	for(int i=1;i<=n;i++)
	putchar((chg^f[id[i]])?'r':'b');
	return 0;
}