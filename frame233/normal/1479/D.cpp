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

const int N=600005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
inline void addedge(int u,int v){c[++edge_cnt]=(edge){v,front[u]},front[u]=edge_cnt;}
int a[N],siz[N],son[N],dep[N],Fa[N],top[N];
int t[N],p,in[N],out[N],rev[N];
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1,Fa[x]=fa,siz[x]=1;
	t[++p]=x,rev[p]=x,in[x]=p;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa) continue;
		dfs1(v,x),siz[x]+=siz[v];
		if(siz[v]>siz[son[x]]) son[x]=v;
	}
	t[++p]=x,rev[p]=x,out[x]=p;
}
void dfs2(int x,int topf)
{
	top[x]=topf;
	if(!son[x]) return;
	dfs2(son[x],topf);
	for(int i=front[x];i;i=c[i].nxt) if(!top[c[i].v]) dfs2(c[i].v,c[i].v);
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]>dep[top[y]]) x=Fa[top[x]];
		else y=Fa[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
const int S=700;
struct qry{
	int l,r,a,b,block,id,L;
	inline bool operator < (const qry &o)const
	{
		return block==o.block?((block&1)?r>o.r:r<o.r):block<o.block;
	}
}q[N];
int n,ans[N];
struct DS{
	int a[N/S+5],b[N],R[N];
	void build(){for(int i=1;i<=n;++i)R[i/S]=i;}
	inline void upd(int x,int C){a[x/S]+=C,b[x]+=C;}
	inline int ask(int x)
	{
		for(int i=x,B=x/S;i<=R[B];++i)if(b[i])return i;
		for(int i=x/S+1,ed=n/S;i<=ed;++i)if(a[i])for(int j=R[i-1]+1;j<=R[i];++j)if(b[j])return j;
		return -1;
	}
}ds;
int cnt[N];
void upd(int x)
{
	x=rev[x];
	if(cnt[a[x]]&1)ds.upd(a[x],-1);
	else ds.upd(a[x],1);
	cnt[a[x]]^=1;
}
int main()
{
	int Q;read(n,Q);
	for(int i=1;i<=n;++i) read(a[i]);
	int x,y;
	for(int i=1;i<n;++i) read(x,y),addedge(x,y),addedge(y,x);
	dfs1(1,0),dfs2(1,1);
	int pos=0,a,b;
	for(int i=1;i<=Q;++i)
	{
		read(x,y,a,b);
		int l=lca(x,y);
		if(x==l||y==l) q[++pos]=(qry){min(in[x],in[y]),max(in[x],in[y]),a,b,min(in[x],in[y])/S,i,0};
		else
		{
			if(in[x]>in[y]) std::swap(x,y);
			q[++pos]=(qry){out[x],in[y],a,b,out[x]/S,i,in[l]};
		}
	}
	std::sort(q+1,q+pos+1);
	int l=1,r=0;
	ds.build();
	for(int i=1;i<=pos;++i)
	{
		while(l>q[i].l) upd(--l);
		while(r<q[i].r) upd(++r);
		while(l<q[i].l) upd(l++);
		while(r>q[i].r) upd(r--);
		if(q[i].L)upd(q[i].L);
		int tmp=ds.ask(q[i].a);
		if(tmp>=q[i].a&&tmp<=q[i].b)ans[q[i].id]=tmp;
		else ans[q[i].id]=-1;
		if(q[i].L)upd(q[i].L);
	}
	for(int i=1;i<=Q;++i) printf("%d\n",ans[i]);
	return 0;
}