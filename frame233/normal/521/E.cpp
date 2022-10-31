// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define Finline __inline__ __attribute__ ((always_inline))
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

Finline uint rnd(){static uint seed=416;return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=200005;
struct edge{
	int v,nxt,id;
}c[N<<1];
int front[N],edge_cnt;
Finline void addedge(int u,int v,int id)
{
	c[++edge_cnt]=(edge){v,front[u],id};
	front[u]=edge_cnt;
}
int E[N][2];
int dfn[N],id,siz[N];
int a[N],Fa[N],dep[N];
bool mark[N];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	dfn[x]=++id,Fa[x]=fa,siz[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa) continue;
		if(!dfn[v]) mark[c[i].id]=true,dfs(v,x),a[x]+=a[v],siz[x]+=siz[v];
		else if(dfn[v]<dfn[x]) ++a[x],--a[v];
	}
}
std::vector<int> getpath(int id)
{
	int x=E[id][0],y=E[id][1];
	std::vector<int> nd;
	while(y!=x) nd.pb(y),y=Fa[y];
	return nd.pb(x),nd;
}
bool _[N];
void print(const std::vector<int> &o)
{
	printf("%d ",SZ(o));
	for(auto it:o) printf("%d ",it);
	printf("\n");
}
int main()
{
	int n,m;read(n,m);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);E[i][0]=x,E[i][1]=y;
		addedge(x,y,i),addedge(y,x,i);
	}
	for(int i=1;i<=n;++i) if(!dfn[i]) dfs(i,0);
	int nd=0;
	for(int i=1;i<=n;++i) if(a[i]>=2) nd=i;
	if(!nd) return puts("NO"),0;
	puts("YES");
	int a=nd,b=Fa[nd];
	for(int i=1;i<=m;++i) if(dep[E[i][0]]>dep[E[i][1]]) std::swap(E[i][0],E[i][1]);
	int fir=0,sec=0;
	for(int i=1;i<=m;++i)
	{
		if(!mark[i])
		{
			x=E[i][0],y=E[i][1];
			if(dfn[b]>=dfn[x]&&dfn[b]<dfn[x]+siz[x]&&dfn[y]>=dfn[a]&&dfn[y]<dfn[a]+siz[a])
			{
				if(fir) sec=i;
				else fir=i;
			}
		}
	}
	assert(fir&&sec);
	std::vector<int> v1=getpath(fir),v2=getpath(sec),v3;
	for(auto it:v1) _[it]=true;
	for(auto it:v2) if(_[it]) v3.pb(it);
	assert(!v3.empty());
	memset(_,0,sizeof(_));
	for(auto it:v3) _[it]=true;
	print(v3);
	auto solve=[&](std::vector<int> v)
	{
		std::vector<int> qwq;
		for(auto it:v)
		{
			qwq.pb(it);
			if(_[it]) break;
		}
		std::reverse(qwq.begin(),qwq.end());
		std::reverse(v.begin(),v.end());
		for(auto it:v)
		{
			qwq.pb(it);
			if(_[it]) break;
		}
		print(qwq);
	};
	solve(v1),solve(v2);
	return 0;
}