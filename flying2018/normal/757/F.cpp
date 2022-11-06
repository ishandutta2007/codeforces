#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cstring>
#define ll long long
#define N 400010
using namespace std;
int dep[N],fa[N][25],in[N],n,m,s,die[N];
struct node{
	int now;
	ll dis;
	bool operator <(const node &a)const{return dis>a.dis;}
};
int uu[N<<1],vv[N<<1],ww[N<<1];
struct road{
	int nxt[N<<1],to[N<<1],head[N],cnt;
	void add(int u,int v)
	{
		to[++cnt]=v;
		nxt[cnt]=head[u];
		head[u]=cnt;
	}
}r1,r2;
struct road2{
	int nxt[N<<1],to[N<<1],w[N<<1],head[N],cnt;
	void add(int u,int v,int w1)
	{
		to[++cnt]=v;
		nxt[cnt]=head[u];
		w[cnt]=w1;
		head[u]=cnt;
	}
}road1; 
int lca(int a,int b)
{
	if(dep[a]>dep[b]) swap(a,b);
	for(int i=20;i>=0;i--)
	if(dep[fa[b][i]]>=dep[a]) b=fa[b][i];
	if(a==b) return a;
	for(int i=20;i>=0;i--)
	if(fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
	return fa[a][0];
}
int num[N],cnt;
int q[N],head,tail;
void topsort(void)
{
	q[tail++]=s;
	while(head!=tail)
	{
		int now=q[head++];
		num[++cnt]=now;
		for(int i=r1.head[now];i;i=r1.nxt[i])
		{
			in[r1.to[i]]--;
			if(!in[r1.to[i]]) q[tail++]=r1.to[i];
		}
	}
	n=cnt;
}
ll dis[N];
void dij(int u)
{
	memset(dis,30,sizeof(dis));
	priority_queue<node>q;
	q.push((node){u,0});
	dis[u]=0;
	while(!q.empty())
	{
		node now=q.top();
		q.pop();
		int u=now.now;
		if(dis[u]!=now.dis) continue;
		for(int i=road1.head[u];i;i=road1.nxt[i])
		if(dis[u]+road1.w[i]<dis[road1.to[i]])
		{
			dis[road1.to[i]]=dis[u]+road1.w[i];
			q.push((node){road1.to[i],dis[road1.to[i]]});
		}
//		for(int i=1;i<=n;i++) printf("%d ",dis[i]);
//		puts("");
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		road1.add(u,v,w);
		road1.add(v,u,w);
		uu[i]=u;
		vv[i]=v;
		ww[i]=w;
	}
	dij(s);
	for(int i=1;i<=m;i++)
	{
		if(dis[uu[i]]>dis[vv[i]]) swap(uu[i],vv[i]);
		if(dis[uu[i]]+ww[i]==dis[vv[i]])
		{
			r1.add(uu[i],vv[i]);
			r2.add(vv[i],uu[i]);
			in[vv[i]]++;
//			printf("%d->%d\n",uu[i],vv[i]);
		}
	}
	topsort();
//	for(int i=n;i>1;i--) printf("%d:%d\n",num[i],dis[num[i]]);
	for(int i=20;i>=0;i--) fa[s][i]=s;
	for(int i=2;i<=n;i++)
	{
		int now=num[i];
		int dead=r2.to[r2.head[now]];
//		printf("%d:",num[i]);
		for(int j=r2.head[now];j;j=r2.nxt[j])
		dead=lca(dead,r2.to[j]);
		dep[now]=dep[dead]+1;
//		printf("%d   %d\n",dead,dep[now]);
		fa[now][0]=dead;
		for(int j=1;j<=20;j++)
		fa[now][j]=fa[fa[now][j-1]][j-1];
	}
	for(int i=n;i>1;i--) die[fa[num[i]][0]]+=++die[num[i]];
	int ans=0;
	for(int i=2;i<=n;i++) ans=max(ans,die[num[i]]);
	printf("%d\n",ans);
	return 0;
}