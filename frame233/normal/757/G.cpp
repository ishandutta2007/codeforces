// Author -- xyr2005
#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
#pragma GCC optimize("-fno-math-errno")
#pragma GCC optimize("-funsafe-math-optimizations")
#pragma GCC optimize("-freciprocal-math")
#pragma GCC optimize("-fno-trapping-math")
#pragma GCC optimize("-ffinite-math-only")
#pragma GCC optimize("-ftree-vectorize")
#pragma GCC target ("avx2","sse4.2","fma")
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

const int N=200005;
int p[N];
struct edge{
	int v,nxt,w;
}c[N<<1];
int front[N],edge_cnt;
Finline void addedge(int u,int v,int w)
{
	c[++edge_cnt]=(edge){v,front[u],w};
	front[u]=edge_cnt;
}
int dep[N],Fa[N],son[N],siz[N],top[N],dfn[N],tree_id,rev[N],val[N];
ll dis[N];
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1,siz[x]=1,Fa[x]=fa;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa) continue;
		dis[v]=dis[x]+c[i].w;
		val[v]=c[i].w;
		dfs1(v,x);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]]) son[x]=v;
	}
}
void dfs2(int x,int topf)
{
	top[x]=topf,dfn[x]=++tree_id,rev[tree_id]=x;
	if(!son[x]) return;
	dfs2(son[x],topf);
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(!top[v]) dfs2(v,v);
	}
}
int limit;
const int MAXN=N*190;
struct seg_tr{
	int ls[MAXN],rs[MAXN],tag[MAXN];
	ll sum[MAXN];
	int node_cnt;
	int build(int l,int r)
	{
		int cur=++node_cnt;
		ls[cur]=rs[cur]=tag[cur]=sum[cur]=0;
		if(l==r) return cur;
		int mid=(l+r)>>1;
		ls[cur]=build(l,mid);
		rs[cur]=build(mid+1,r);
		return cur;
	}
	int Update(int rt,int L,int R,int opt,int l,int r)
	{
		int cur=rt>limit?rt:++node_cnt;
		ls[cur]=ls[rt],rs[cur]=rs[rt],tag[cur]=tag[rt],sum[cur]=sum[rt]+(dis[rev[R]]-dis[rev[L]]+val[rev[L]])*opt;
		if(L<=l&&r<=R)
		{
			tag[cur]+=opt;
			return cur;
		}
		int mid=(l+r)>>1;
		if(L<=mid&&R>mid)
		{
			ls[cur]=Update(ls[cur],L,mid,opt,l,mid);
			rs[cur]=Update(rs[cur],mid+1,R,opt,mid+1,r);
		}
		else if(L<=mid) ls[cur]=Update(ls[cur],L,R,opt,l,mid);
		else rs[cur]=Update(rs[cur],L,R,opt,mid+1,r);
		return cur;
	}
	ll Query(int u,int v,int L,int R,int l,int r,int _)
	{
		if(L<=l&&r<=R) return sum[v]-sum[u]+1ll*_*(dis[rev[r]]-dis[rev[l]]+val[rev[l]]);
		_+=tag[v]-tag[u];int mid=(l+r)>>1;
		return (L<=mid?Query(ls[u],ls[v],L,R,l,mid,_):0)+(R>mid?Query(rs[u],rs[v],L,R,mid+1,r,_):0);
	}
}tr;
int root[N],n;
void Update(int x,int opt)
{
	int id=x;
	x=p[x];
	while(x)
	{
		root[id]=tr.Update(root[id],dfn[top[x]],dfn[x],opt,1,n);
		x=Fa[top[x]];
	}
}
ll Query(int l,int r,int x)
{
	ll ans=0;
	while(x)
	{
		ans+=tr.Query(root[l-1],root[r],dfn[top[x]],dfn[x],1,n,0);
		x=Fa[top[x]];
	}
	return ans;
}
ll sum[N];
int main()
{
	int q;read(n,q);
	for(int i=1;i<=n;++i) read(p[i]);
	int x,y,z;
	for(int i=1;i<n;++i)
	{
		read(x,y,z);
		addedge(x,y,z),addedge(y,x,z);
	}
	dfs1(1,0),dfs2(1,1);
	root[0]=tr.build(1,n);
	for(int i=1;i<=n;++i) limit=tr.node_cnt,root[i]=root[i-1],Update(i,1),sum[i]=sum[i-1]+dis[p[i]];
	limit=tr.node_cnt;
	int opt,l,r;
	ll lastans=0;
	while(q--)
	{
		read(opt);
		if(opt==1)
		{
			read(l,r,x),l^=lastans,r^=lastans,x^=lastans;
			lastans=dis[x]*(r-l+1)+(sum[r]-sum[l-1])-(Query(l,r,x)<<1);
			printf("%lld\n",lastans);
			lastans&=((1<<30)-1);
		}
		else
		{
			read(x),x^=lastans;
			sum[x]-=dis[p[x]];
			Update(x,-1);
			std::swap(p[x],p[x+1]);
			Update(x,1);
			sum[x]+=dis[p[x]];
			if(tr.node_cnt>=MAXN-5000)
			{
				tr.node_cnt=0;
				root[0]=tr.build(1,n);
				for(int i=1;i<=n;++i) limit=tr.node_cnt,root[i]=root[i-1],Update(i,1);
				limit=tr.node_cnt;
			}
		}
	}
	return 0;
}