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

const int N=500005;
int p[N];
struct node{
	int x,y,w;
	inline bool operator < (const node &o)const
	{
		return w>o.w;
	}
}a[N];
int opt[N],X[N];
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
inline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int dfn[N],id,siz[N],rev[N],anc[N][21],w[N];
void dfs(int x)
{
	for(int i=1;i<=20;++i) anc[x][i]=anc[anc[x][i-1]][i-1];
	dfn[x]=++id,siz[x]=1,rev[id]=x;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		anc[v][0]=x;
		dfs(v),siz[x]+=siz[v];
	}
}
int jump(int x,int k)
{
	for(int i=20;i>=0;--i) if(w[anc[x][i]]>=k) x=anc[x][i];
	return x;
}
struct info{
	int maxx,id;
	inline bool operator < (const info &o)const
	{
		return maxx<o.maxx;
	}
};
struct seg_tr{
	struct Node{
		int ls,rs;
		info val;
	}f[N<<1];
	int node_cnt;
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].val={p[rev[l]],l};
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		f[cur].val=max(f[f[cur].ls].val,f[f[cur].rs].val);
		return cur;
	}
	void Update(int pos,int l,int r,int cur)
	{
		if(l==r)
		{
			f[cur].val={0,l};
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(pos,l,mid,f[cur].ls);
		else Update(pos,mid+1,r,f[cur].rs);
		f[cur].val=max(f[f[cur].ls].val,f[f[cur].rs].val);
	}
	info Query(int L,int R,int l,int r,int cur)
	{
		if(L<=l&&r<=R) return f[cur].val;
		int mid=(l+r)>>1;
		if(L<=mid&&R>mid) return max(Query(L,R,l,mid,f[cur].ls),Query(L,R,mid+1,r,f[cur].rs));
		return L<=mid?Query(L,R,l,mid,f[cur].ls):Query(L,R,mid+1,r,f[cur].rs);
	}
}tr;
int main()
{
	int n,m,q;read(n,m,q);
	for(int i=1;i<=n;++i) read(p[i]);
	for(int i=1;i<=m;++i) read(a[i].x,a[i].y),a[i].w=inf;
	for(int i=1;i<=q;++i)
	{
		read(opt[i],X[i]);
		if(opt[i]==2) a[X[i]].w=i;
	}
	std::sort(a+1,a+m+1);
	int node_cnt=n;
	std::iota(fa+1,fa+n+1,1);
	for(int i=1;i<=m;++i)
	{
		int x=a[i].x,y=a[i].y,w=a[i].w;
		int a=find(x),b=find(y);
		if(a!=b)
		{
			int cur=++node_cnt;
			fa[a]=fa[b]=fa[cur]=cur;
			::w[cur]=w;
			addedge(cur,a),addedge(cur,b);
		}
	}
	for(int i=1;i<=node_cnt;++i) if(fa[i]==i) dfs(i);
	tr.build(1,id);
	for(int i=1;i<=q;++i)
	{
		if(opt[i]==1)
		{
			int x=jump(X[i],i);
			int l=dfn[x],r=dfn[x]+siz[x]-1;
			info qwq=tr.Query(l,r,1,id,1);
			tr.Update(qwq.id,1,id,1);
			printf("%d\n",qwq.maxx);
		}
	}
	return 0;
}