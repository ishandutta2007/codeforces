//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int n,m,S,T;
int head[1111],to[60011],nxt[60011],cost[60011],tot=1;
bool vis[1111];
int p[1111],id[1111],lv[1111],pe[1111];
void dfs(int x,int pre=-1)
{
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(i==pre)continue;
		int u=to[i];
		if(vis[u])continue;
		lv[u]=lv[x]+1;
		p[u]=x;
		pe[u]=i;
		dfs(u,i^1);
	}
}
int bane,dfn[1111],dtot,low[1111],p2[1111],pe2[1111];
bool f[1111];
int dfs2(int x,int pre=-1)
{
	dfn[x]=low[x]=++dtot;
	for(int i=head[x];i;i=nxt[i])
	{
		if(i==pre||i/2==bane/2)continue;
		int u=to[i];
		if(!dfn[u])
		{
			p2[u]=x;
			pe2[u]=i;
			dfs2(u,i^1);
			low[x]=min(low[x],low[u]);
		}
		else
		{
			low[x]=min(low[x],dfn[u]);
		}
	}
	if(low[x]==dfn[x])f[x]=1;else f[x]=0;
}
int main()
{
	getii(n,m);
	getii(S,T);
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		getiii(x,y,w);
		nxt[++tot]=head[x];
		head[x]=tot;
		to[tot]=y;
		cost[tot]=w;
		nxt[++tot]=head[y];
		head[y]=tot;
		to[tot]=x;
		cost[tot]=w;
	}
	dfs(S);
	if(!vis[T])
	{
		puts("0");
		puts("0");
		return 0;
	}
	pair<int,pair<int,int> > ans=MP(Imx,MP(0,0));
	int it=T;
	while(it!=S)
	{
		bane=pe[it];
		memset(dfn,0,sizeof(dfn));
		memset(f,0,sizeof(f));
		dtot=0;
		dfs2(S);
		if(dfn[T])
		{
			int it2=T;
			while(it2!=S)
			{
				if(f[it2])
				{
					ans=min(ans,MP(cost[pe[it]]+cost[pe2[it2]],MP(pe[it]>>1,pe2[it2]>>1)));
				}
				it2=p2[it2];
			}
		}
		else
		{
			ans=min(ans,MP(cost[pe[it]],MP(pe[it]>>1,0)));
		}
		it=p[it];
	}
	if(ans.FF==Imx)puts("-1");
	else
	{
		cout<<ans.FF<<endl;
		cout<<(ans.SS.FF!=0)+(ans.SS.SS!=0)<<endl;
		if(ans.SS.FF)cout<<ans.SS.FF<<" ";
		if(ans.SS.SS)cout<<ans.SS.SS<<" ";
	}
	return 0;
}