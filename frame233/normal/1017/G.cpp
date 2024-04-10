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
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=100005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
inline void addedge(int u,int v){c[++edge_cnt]=(edge){v,front[u]},front[u]=edge_cnt;}
int dep[N],siz[N],Fa[N],son[N],top[N],dfn[N],tree_id,rev[N],n;
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1,Fa[x]=fa,siz[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa) continue;
		dfs1(v,x),siz[x]+=siz[v];
		if(siz[v]>siz[son[x]]) son[x]=v;
	}
}
void dfs2(int x,int topf)
{
	top[x]=topf,dfn[x]=++tree_id,rev[tree_id]=x;
	if(!son[x])return;
	dfs2(son[x],topf);
	for(int i=front[x];i;i=c[i].nxt) if(!top[c[i].v]) dfs2(c[i].v,c[i].v);
}
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
int tag1[N<<2],minn[N<<2],orig[N<<2];
bool tag2[N<<2];
void build(int l,int r,int cur)
{
	if(l==r){orig[cur]=minn[cur]=-dep[rev[l]];return;}
	int mid=(l+r)>>1;build(l,mid,ls(cur)),build(mid+1,r,rs(cur));
	orig[cur]=minn[cur]=min(minn[ls(cur)],minn[rs(cur)]);
}
inline void upd1(int cur,int C){tag1[cur]+=C,minn[cur]+=C;}
inline void upd2(int cur){tag1[cur]=0,tag2[cur]=true,minn[cur]=orig[cur];}
inline void pushdown(int cur)
{
	if(tag2[cur]) upd2(ls(cur)),upd2(rs(cur)),tag2[cur]=false;
	if(tag1[cur]) upd1(ls(cur),tag1[cur]),upd1(rs(cur),tag1[cur]),tag1[cur]=0;
}
void Update1(int L,int R,int C,int l,int r,int cur)
{
	if(L<=l&&r<=R) return upd1(cur,C);
	pushdown(cur);int mid=(l+r)>>1;
	if(L<=mid) Update1(L,R,C,l,mid,ls(cur));
	if(R>mid) Update1(L,R,C,mid+1,r,rs(cur));
	minn[cur]=min(minn[ls(cur)],minn[rs(cur)]);
}
void Update2(int L,int R,int l,int r,int cur)
{
	if(L<=l&&r<=R) return upd2(cur);
	pushdown(cur);int mid=(l+r)>>1;
	if(L<=mid) Update2(L,R,l,mid,ls(cur));
	if(R>mid) Update2(L,R,mid+1,r,rs(cur));
	minn[cur]=min(minn[ls(cur)],minn[rs(cur)]);
}
int Query(int L,int R,int l,int r,int cur)
{
	if(L<=l&&r<=R) return minn[cur];
	pushdown(cur);int mid=(l+r)>>1;
	if(L<=mid&&R>mid) return min(Query(L,R,l,mid,ls(cur)),Query(L,R,mid+1,r,rs(cur)));
	return L<=mid?Query(L,R,l,mid,ls(cur)):Query(L,R,mid+1,r,rs(cur));
}
int ask(int x)
{
	int tmp=Query(dfn[x],dfn[x],1,n,1),ans=0;
	while((x=Fa[x])) chmin(ans,Query(dfn[top[x]],dfn[x],1,n,1)),x=top[x];
	return tmp-ans;
}
int main()
{
	int q;read(n,q);
	int opt,x;
	for(int i=2;i<=n;++i) read(x),addedge(x,i);
	dfs1(1,0),dfs2(1,1),build(1,n,1);
	while(q--)
	{
		read(opt,x);
		if(opt==1) Update1(dfn[x],dfn[x]+siz[x]-1,1,1,n,1);
		else if(opt==2) Update2(dfn[x],dfn[x]+siz[x]-1,1,n,1),Update1(dfn[x],dfn[x]+siz[x]-1,dep[x]-1,1,n,1),Update1(dfn[x],dfn[x]+siz[x]-1,-ask(x)-1,1,n,1);
		else puts(ask(x)>=0?"black":"white");
	}
	return 0;
}