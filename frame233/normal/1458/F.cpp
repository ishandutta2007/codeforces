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

const int N=200005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
inline void addedge(int u,int v){c[++edge_cnt]=(edge){v,front[u]},front[u]=edge_cnt;}
int anc[N][18],dep[N],Fa[N],son[N],top[N];
struct info{int u,b,d;};
bool vis[N];
int minn,S,rt,siz[N];
void dfs1(int x,int fa)
{
	siz[x]=1,dep[x]=dep[fa]+1,anc[x][0]=fa,Fa[x]=fa;
	for(int i=1;i<=17;++i) anc[x][i]=anc[anc[x][i-1]][i-1];
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
	top[x]=topf;
	if(!son[x]) return;
	dfs2(son[x],topf);
	for(int i=front[x];i;i=c[i].nxt) if(!top[c[i].v]) dfs2(c[i].v,c[i].v);
}
int lca(int x,int y)
{
	while(top[x]!=top[y]) dep[top[x]]>=dep[top[y]]?x=Fa[top[x]]:y=Fa[top[y]];
	return dep[x]<dep[y]?x:y;
}
int getrt(int x,int fa)
{
	int siz=1,maxx=0;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa||vis[v]) continue;
		int tmp=getrt(v,x);
		siz+=tmp,chmax(maxx,tmp);
	}
	chmax(maxx,S-siz);
	if(maxx<minn) minn=maxx,rt=x;
	return siz;
}
std::vector<info> p[N];
int qwq;
void dfs(int x,int fa,int dis)
{
	siz[x]=1,p[x].pb({rt,qwq,++dis});
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa||vis[v]) continue;
		dfs(v,x,dis),siz[x]+=siz[v];
	}
}
void solve(int x)
{
	S=siz[x],rt=0,minn=inf,getrt(x,0),vis[rt]=true;
	for(int i=front[rt];i;i=c[i].nxt) if(!vis[c[i].v]) ++qwq,dfs(c[i].v,rt,0);
	for(int i=front[rt];i;i=c[i].nxt) if(!vis[c[i].v]) solve(c[i].v);
}
ll s0[N],s1[N],t0[N],t1[N];
void upd(int x,int C){s0[x]+=C;for(auto it:p[x])s0[it.u]+=C,s1[it.u]+=C*it.d,t0[it.b]+=C,t1[it.b]+=C*it.d;}
ll ask(int x){ll ans=s1[x];for(auto it:p[x])ans+=(s0[it.u]-t0[it.b])*it.d+(s1[it.u]-t1[it.b]);return ans;}
inline int getdis(int x,int y){return dep[x]+dep[y]-(dep[lca(x,y)]<<1);}
inline int LOG2(uint x)
{
    static const int tb[32]={31,0,27,1,28,18,23,2,29,21,19,12,24,9,14,3,30,26,17,22,20,11,8,13,25,16,10,7,15,6,5,4};
    return tb[x*263572066>>27];
}
int jump(int x,int k)
{
	while(k) x=anc[x][LOG2(lowbit(k))],k&=(k-1);
	return x;
}
struct C{int v,r;};
inline bool check(const C &a,const C &b){return getdis(a.v,b.v)<=a.r-b.r;}
inline C merge(const C &a,const C &b)
{
	int L=lca(a.v,b.v),dis=dep[a.v]+dep[b.v]-dep[L]*2;
	if(dis<=a.r-b.r) return a;
	if(dis<=b.r-a.r) return b;
	int r=(a.r+b.r+dis)>>1;
	return dep[a.v]-dep[L]>=r-a.r?(C){jump(a.v,r-a.r),r}:(C){jump(b.v,r-b.r),r};
}
ll ans,suf[N];
C _[N];
void sol(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)>>1;
	sol(l,mid),sol(mid+1,r);
	int p1=mid,p2=mid+1;
	_[mid+1]=(C){mid+1,0},suf[r+1]=0;
	for(int i=mid+2;i<=r;++i) _[i]=merge(_[i-1],(C){i,0});
	for(int i=r;i>=mid+1;--i) suf[i]=suf[i+1]+_[i].r;
	C cur=(C){mid,0};
	for(int i=mid;i>=l;--i)
	{
		cur=merge(cur,(C){i,0});
		while(p1<r&&check(cur,_[p1+1])) upd(_[++p1].v,-1);
		while(p2<=p1||(p2<=r&&!check(_[p2],cur))) upd(_[p2++].v,1);
		ans+=suf[p2]+1LL*(p1-mid)*cur.r;
		ans+=(1LL*cur.r*(p2-1-p1)+(suf[p1+1]-suf[p2])+ask(cur.v))>>1;
	}
	for(int i=p1+1;i<p2;++i) upd(_[i].v,-1);
}
int main()
{
	int n;read(n);
	int x,y;
	for(int i=1;i<n;++i) read(x,y),addedge(x,n+i),addedge(n+i,x),addedge(y,n+i),addedge(n+i,y);
	dfs1(1,0),dfs2(1,1),solve(1);for(int i=1;i<=n;++i) p[i].shrink_to_fit();
	sol(1,n);
	printf("%lld\n",ans);
	return 0;
}