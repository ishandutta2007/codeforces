// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=900005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt=-1;
inline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int dfn[N],low[N],id,st[N],top,bel[N],col;
int __[N];
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++id,st[++top]=x;
	for(int i=front[x];~i;i=c[i].nxt)
	{
		if((i^1)==fa) continue;
		int v=c[i].v;
		if(!dfn[v]) tarjan(v,i),chmin(low[x],low[v]);
		else chmin(low[x],dfn[v]);
	}
	if(dfn[x]==low[x])
	{
		bel[x]=++col;
		while(st[top]!=x) bel[st[top--]]=col;
		--top;
	}
}
int E[N][2];
std::vector<int> e[N];
int Dfn[N],Bel[N],tree_id,cur_id;
int siz[N],dep[N],Fa[N],son[N],Top[N];
void dfs1(int x,int fa)
{
	siz[x]=1,Fa[x]=fa,dep[x]=dep[fa]+1;
	for(auto v:e[x])
	{
		if(v==fa) continue;
		dfs1(v,x),siz[x]+=siz[v];
		if(siz[v]>siz[son[x]]) son[x]=v;
	}
}
void dfs2(int x,int topf)
{
	Top[x]=topf,Dfn[x]=++tree_id,Bel[x]=cur_id;
	if(!son[x]) return;
	dfs2(son[x],topf);
	for(auto v:e[x]) if(!Top[v]) dfs2(v,v);
}
int lca(int x,int y)
{
	while(Top[x]!=Top[y])
	{
		if(dep[Top[x]]>dep[Top[y]]) x=Fa[Top[x]];
		else y=Fa[Top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
inline bool cmp(int a,int b){return Dfn[a]<Dfn[b];}
int t[N],nd[N],p;
void insert(int x)
{
	nd[++p]=x;
	if(!top||(Dfn[x]>=Dfn[st[top]]&&Dfn[x]<Dfn[st[top]]+siz[st[top]]))
	{
		st[++top]=x;
		return;
	}
	int L=lca(x,st[top]);
	while(top>1&&Dfn[st[top-1]]>=Dfn[L]) addedge(st[top-1],st[top]),addedge(st[top],st[top-1]),--top;
	if(st[top]!=L) addedge(L,st[top]),addedge(st[top],L),st[top]=L,nd[++p]=L;
	st[++top]=x;
}
ll R;
int n,orig[N];
inline int $(int x){return (x+R-1)%n+1;}
int main()
{
	memset(front,255,sizeof(front));
	int m,q;read(n,m,q);
	int x,y;
	for(int i=1;i<=m;++i) read(x,y),addedge(x,y),addedge(y,x),E[i][0]=x,E[i][1]=y;
	for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i,inf);
	for(int i=1;i<=m;++i)
	{
		x=bel[E[i][0]],y=bel[E[i][1]];
		if(x!=y) e[x].pb(y),e[y].pb(x);
	}
	for(int i=1;i<=col;++i) e[i].erase(std::unique(e[i].begin(),e[i].end()),e[i].end());
	for(int i=1;i<=n;++i) __[i]=bel[i];
	for(int i=1;i<=col;++i) if(!Dfn[i]) ++cur_id,dfs1(i,0),dfs2(i,i);
	memset(front,255,sizeof(front));
	for(int ___=1;___<=q;++___)
	{
		edge_cnt=-1,p=0;
		int a,b;read(a,b);
		int origa=a;
		for(int i=0;i<a;++i) read(t[i]),t[i]=$(t[i]),orig[i]=__[t[i]];
		while(b--)
		{
			read(x,y),x=$(x),y=$(y),t[a++]=x,t[a++]=y;
			if(__[x]!=__[y]) addedge(__[x],__[y]),addedge(__[y],__[x]);
		}
		for(int i=0;i<a;++i) t[i]=__[t[i]];
		std::sort(t,t+a,cmp);
		a=std::unique(t,t+a)-t;
		for(int i=0;i<a;++i)
		{
			int j=i;
			while(j+1<a&&Bel[t[i]]==Bel[t[j+1]]) ++j;
			top=0;
			for(int k=i;k<=j;++k) insert(t[k]);
			while(top>1) addedge(st[top-1],st[top]),addedge(st[top],st[top-1]),--top;
			i=j;
		}					
		top=id=col=0;
		for(int i=1;i<=p;++i) dfn[nd[i]]=low[nd[i]]=bel[nd[i]]=0;
		for(int i=1;i<=p;++i) if(!dfn[nd[i]]) tarjan(nd[i],inf);
		bool flag=true;
		for(int i=1;i<origa;++i) flag&=bel[orig[i]]==bel[orig[0]];
		if(flag) puts("YES"),R+=___;
		else puts("NO");
		while(p) front[nd[p--]]=-1;
	}
	return 0;
}