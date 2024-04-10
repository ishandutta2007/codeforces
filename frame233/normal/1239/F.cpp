// Author -- xyr2005

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

Finline uint rnd(){static uint seed=416;return seed+=0x71dad4bfu,seed^=seed>>5,seed+=0xc6f74d88u,seed^=seed<<17,seed+=0x25e6561u,seed^=seed>>13;}
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

const int N=500005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int dg[N],pre[N];
int _q[N],_l,_r;
bool vis[N],mark[N],__[N];
int st[N],top,n;
bool flag;
int Fa[N],fir,ban;
int dfn[N],tree_id;
int dep[N];
int minn,id,tar;
void dfs(int x,int fa)
{
	Fa[x]=fa,dfn[x]=++tree_id;
	dep[x]=dep[fa]+1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa||dg[v]==1) continue;
		if(!dfn[v]) dfs(v,x);
		else if(dfn[v]<dfn[x]&&dep[x]-dep[v]<minn) minn=dep[x]-dep[v],id=x,tar=v;
	}
}
std::vector<int> res;
void dfs0(int x,int fa)
{
	vis[x]=true,Fa[x]=fa;
	if(__[x]&&ban!=x&&res.empty())
	{
		int cur=x;
		while(cur!=fir)
		{
			res.pb(cur);
			cur=Fa[cur];
		}
	}
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa||dg[v]==1) continue;
		dfs0(v,x);
	}
}
void MAIN()
{
	edge_cnt=0;
	int m;read(n,m);
	memset(dg,0,(n+3)<<2);
	memset(front,0,(n+3)<<2);
	memset(vis,0,n+3);
	memset(mark,0,n+3);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		++dg[x],++dg[y];
		addedge(x,y),addedge(y,x);
	}
	if(n==1) return (void)puts("No");
	for(int i=1;i<=n;++i) dg[i]%=3;
	std::vector<int> nd1;
	for(int i=1;i<=n;++i)
	{
		if(!dg[i])
		{
			printf("Yes\n%d\n",n-1);
			for(int j=1;j<=n;++j) if(i!=j) printf("%d ",j);
			printf("\n");
			return;
		}
		if(dg[i]==1) nd1.pb(i);
	}
	if(SZ(nd1)>=2)
	{
		int s=nd1[0];
		_q[_l=_r=1]=s;
		vis[s]=true;
		while(_l!=_r+1)
		{
			int x=_q[_l++];
			for(int i=front[x];i;i=c[i].nxt)
			{
				int v=c[i].v;
				if(vis[v]) continue;
				pre[v]=x,vis[v]=true;
				if(dg[v]==1)
				{
					int cur=v;
					while(cur!=s)
					{
						mark[cur]=true;
						cur=pre[cur];
					}
					mark[s]=true;
					std::vector<int> ans;
					for(int i=1;i<=n;++i) if(!mark[i]) ans.pb(i);
					if(ans.empty()) return (void)puts("No\n");
					printf("Yes\n%d\n",SZ(ans));
					for(auto it:ans) printf("%d ",it);
					printf("\n");
					return;
				}
				_q[++_r]=v;
			}
		}
		assert(0);
	}
	memset(dfn,0,(n+3)<<2);
	tree_id=0;
	memset(mark,0,n+3);
	top=0,flag=false;
	minn=inf,id=0,tar=0;
	for(int i=1;i<=n;++i) if(dg[i]==2&&!dfn[i]) dfs(i,0);
	if(id)
	{
		int cur=id;
		while(cur!=tar)
		{
			mark[cur]=true;
			cur=Fa[cur];
		}
		mark[tar]=true;
		std::vector<int> ans;
		for(int i=1;i<=n;++i) if(!mark[i]) ans.pb(i);
		if(ans.empty()) return (void)puts("No");
		printf("Yes\n%d\n",SZ(ans));
		for(auto it:ans) printf("%d ",it);
		printf("\n");
		return;
	}
	if(nd1.empty()) return (void)puts("No");
	int nd=nd1[0];
	memset(vis,0,n+3);
	memset(mark,0,n+3);
	memset(__,0,n+3);
	for(int i=front[nd];i;i=c[i].nxt) __[c[i].v]=true;
	int cnt=0;
	for(int i=front[nd];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(vis[v]) continue;
		res.clear(),fir=nd,ban=v;dfs0(v,nd);
		++cnt;
		if(cnt<=2) for(auto it:res) mark[it]=true;
	}
	mark[nd]=true;
	std::vector<int> ans;
	for(int i=1;i<=n;++i) if(!mark[i]) ans.pb(i);
	if(ans.empty()) return (void)puts("No");
	printf("Yes\n%d\n",SZ(ans));
	for(auto it:ans) printf("%d ",it);
	printf("\n");
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}