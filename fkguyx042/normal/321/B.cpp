#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<ctime>
#include<vector>
#include<utility>
using namespace std;
#define N 1010
#define M 1000010
#define INF (1<<30)
int n,m,s,t,ans;
int head[N],d[N],pre[N],cnt;
bool vis[N];
struct edge
{
	int v,w,c,next;
}e[M];
void addedge(int u,int v,int w,int c)
{
	e[cnt]=(edge){v,w,c,head[u]}; head[u]=cnt++;
	e[cnt]=(edge){u,0,-c,head[v]}; head[v]=cnt++;
}
int spfa()
{
	queue<int> q;
	memset(pre,-1,sizeof(pre));
	for(int i=0;i<N;++i) d[i]=-INF;
	d[s]=0;
	q.push(s);
	while (! q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i!=-1;i=e[i].next)
		if(e[i].w)
		if(d[e[i].v]<d[u]+e[i].c)
		{
			d[e[i].v]=d[u]+e[i].c;
			pre[e[i].v]=i;
			if(! vis[e[i].v]) q.push(e[i].v),vis[e[i].v]=1;
		}
	}
	return d[t]!=-INF;
}
int flow;
void mcmf1()
{
	ans=flow=0;
	while (spfa())
	{
		int u,mn=INF;
		for(u=t;u!=s;u=e[pre[u]^1].v)
			mn=min(mn,e[pre[u]].w);
		if(d[t]<0) break;
		flow+=mn;
		ans+=mn*d[t];
		for(u=t;u!=s;u=e[pre[u]^1].v)
			e[pre[u]].w-=mn,e[pre[u]^1].w+=mn;
	}
}
void mcmf2()
{
	ans=flow=0;
	while (spfa())
	{
		int u,mn=INF;
		for(u=t;u!=s;u=e[pre[u]^1].v)
			mn=min(mn,e[pre[u]].w);
		flow+=mn;
		ans+=mn*d[t];
		for(u=t;u!=s;u=e[pre[u]^1].v)
			e[pre[u]].w-=mn,e[pre[u]^1].w+=mn;
	}
}
int n1,n2,ans1;
char ss[N][6];
int J[N],C[N];
int main ()
{
	scanf("%d%d",&n1,&n2);
	for(int i=1;i<=n1;++i) scanf("%s %d",ss[i],&J[i]);
	for(int i=1;i<=n2;++i) scanf("%d",&C[i]);
	n=n1+n2;
	s=n+1;
	t=s+1;
	cnt=0;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n1;++i)
		addedge(n2+i,t,1,0);
	for(int i=1;i<=n2;++i)
	{
		addedge(s,i,1,0);
		for(int j=1;j<=n1;++j)
			if(strcmp(ss[j],"ATK")==0 && C[i]>=J[j]) addedge(i,j+n2,1,C[i]-J[j]);
	}
	mcmf1();
	ans1=ans;
	if(n2<=n1)
	{
		printf("%d\n",ans1);
		return 0;
	}
	cnt=0;
	memset(head,-1,sizeof(head));
	int ex=t+1;
	addedge(ex,t,n2-n1,0);
	for(int i=1;i<=n1;++i)
		addedge(n2+i,t,1,0);
	for(int i=1;i<=n2;++i)
	{
		addedge(s,i,1,0);
		addedge(i,ex,1,C[i]);
		for(int j=1;j<=n1;++j)
		{
			if(strcmp(ss[j],"ATK")==0)
			{
				if(C[i]>=J[j]) addedge(i,j+n2,1,C[i]-J[j]);
			}
			else
			{
				if(C[i]>J[j]) addedge(i,j+n2,1,0);
			}
		}
	}
	mcmf2();
	if(flow==n2) printf("%d\n",max(ans,ans1));
	else printf("%d\n",ans1);
	
	return 0;
}