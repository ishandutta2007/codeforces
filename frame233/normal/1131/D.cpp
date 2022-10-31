#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
inline int abs(int a){return a>0?a:-a;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline void swap(int &a,int &b){int tmp=a;a=b,b=tmp;}
const int N=2005;
struct edge{
	int v,nxt,w;
}c[3000005];
int front[N],cnt,x[3000005],y[3000005];
int _q[N<<3],_l,_r,tot,f[N],dg[N];
bool dis[N][N];
inline void add(int u,int v,int w){c[++cnt]=(edge){v,front[u],w},front[u]=cnt,x[cnt]=u,y[cnt]=v;}
inline void add_e(int u,int v,int w){c[++cnt]=(edge){v,front[u],w},front[u]=cnt;}
int dfn[N],low[N],bel[N],col,id,a[N],pos;
int _st[N],_t;
bool vis[N];
void tarjan(int x)
{
	dfn[x]=low[x]=++id;
	vis[x]=1,_st[++_t]=x;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!dfn[c[i].v])
		{
			tarjan(c[i].v);
			low[x]=min(low[x],low[c[i].v]);
		}
		else if(vis[c[i].v])
		{
			low[x]=min(low[x],dfn[c[i].v]);
		}
	}
	if(dfn[x]==low[x])
	{
		bel[x]=++col;
		vis[x]=0;
		a[pos=1]=x;
		while(_st[_t]!=x)
		{
			int tmp=_st[_t];
			vis[tmp]=0;
			bel[tmp]=col;
			a[++pos]=tmp;
			--_t;
		}
		--_t;
		for(int i=1;i<=pos;++i)
		{
			for(int j=1;j<=pos;++j)
			{
				if(dis[a[i]][a[j]])
				{
					printf("No\n");
					exit(0);
				}
			}
		}
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	tot=n+m;
	char ch;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			ch=getchar();
			while(ch!='='&&ch!='<'&&ch!='>') ch=getchar();
			if(ch=='=') add(i,j+n,0),add(j+n,i,0);
			else if(ch=='<')
			{
				add(i,j+n,1);
				dis[i][j+n]=1;
			}
			else
			{
				dis[j+n][i]=1;
				add(j+n,i,1);
			}
		}
	}
	for(int i=1;i<=tot;++i)
	{
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	int tmp=cnt;
	cnt=0;
	memset(front,0,sizeof(front));
	for(int i=1;i<=tmp;++i)
	{
		if(bel[x[i]]!=bel[y[i]])
		{
			add_e(bel[x[i]],bel[y[i]],1);
			++dg[bel[y[i]]];
		}
	}
	_l=1,_r=0;
	for(int i=1;i<=col;++i)
	{
		if(!dg[i])
		{
			_q[++_r]=i;
			f[i]=1;
		}
	}
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		for(int i=front[x];i;i=c[i].nxt)
		{
			f[c[i].v]=max(f[x]+1,f[c[i].v]);
			--dg[c[i].v];
			if(!dg[c[i].v])
			{
				_q[++_r]=c[i].v;
			}
		}
	}
	printf("Yes\n");
	for(int i=1;i<=n;++i) printf("%d ",f[bel[i]]);
	printf("\n");
	for(int i=1;i<=m;++i) printf("%d ",f[bel[i+n]]);
	printf("\n");
	return 0;
}