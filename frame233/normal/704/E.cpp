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

const int N=100005;
const double eps=1e-8;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
inline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int dep[N],Fa[N],siz[N],son[N],top[N];
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
double now;
struct info{
	double s,t,c,u;
	inline bool operator < (const info &o)const
	{
		return u+(now-s)*c<o.u+(now-o.s)*o.c;
	}
};
std::vector<info> H[N],L[N];
inline info trans(double s,int c,int u,int v)
{
	if(u<=v) return {s,(double)(v-u)/c+s,(double)c,(double)u};
	else return {s,(double)(u-v)/c+s,-(double)c,(double)u};
}
void push(int x,int y,int t,int c)
{
	int c1=0,c2=0,len=dep[x]+dep[y]-(dep[lca(x,y)]<<1);
	while(top[x]!=top[y])
	{
		if(dep[top[x]]>dep[top[y]])
		{
			H[top[x]].pb(trans((double)c1/c+t,c,dep[x]-dep[top[x]],0));
			c1+=dep[x]-dep[top[x]],x=top[x];
			L[x].pb(trans((double)c1/c+t,c,0,1));
			++c1,x=Fa[x];
		}
		else
		{
			c2+=dep[y]-dep[top[y]];
			H[top[y]].pb(trans((double)(len-c2)/c+t,c,0,dep[y]-dep[top[y]]));
			y=top[y],++c2;
			L[y].pb(trans((double)(len-c2)/c+t,c,1,0));
			y=Fa[y];
		}
	}
	if(dep[x]<=dep[y]) H[top[x]].pb(trans((double)c1/c+t,c,dep[x]-dep[top[x]],dep[y]-dep[top[y]]));
	else H[top[y]].pb(trans((double)c1/c+t,c,dep[x]-dep[top[x]],dep[y]-dep[top[y]]));
}
double ans=1e18;
std::multiset<info> S;
void calc(const info &a,const info &b)
{
	double x;
	if(abs(a.c-b.c)<=eps)
	{
		if(abs((a.u-a.s*a.c)-(b.u-b.s*b.c))<=eps) x=max(a.s,b.s);
		else return;
	}
	else x=(double)(b.u-a.u+a.s*a.c-b.s*b.c)/(a.c-b.c);
	if(x>=a.s&&x<=a.t&&x>=b.s&&x<=b.t) chmin(ans,x);
}
struct eve{
	double s;
	info o;
	int opt;
	inline bool operator < (const eve &o)const
	{
		return s<o.s;
	}
};
void solve(std::vector<info> o)
{
	S.clear();
	std::vector<eve> v;
	for(auto it:o) v.pb({it.s,it,1}),v.pb({it.t+5*eps,it,-1});
	std::sort(v.begin(),v.end());
	for(auto cur:v)
	{
		if(cur.s>=ans-eps) return;
		now=cur.s;
		if(cur.opt==1)
		{
			auto it=S.insert(cur.o);
			if(it!=S.begin()){auto tmp=it;calc(*--tmp,*it);}
			if(++it!=S.end()){auto tmp=it;calc(*--tmp,*it);}
		}
		else
		{
			auto it=S.find(cur.o);
			if(it!=S.begin()&&++it!=S.end()){auto tmp=it;calc(*--(--tmp),*it);}
			S.erase(S.find(cur.o));
		}
	}
}
int main()
{
	int n,m;read(n,m);
	int t,c,x,y;
	for(int i=1;i<n;++i) read(x,y),addedge(x,y),addedge(y,x);
	dfs1(1,0),dfs2(1,1);
	while(m--) read(t,c,x,y),push(x,y,t,c);
	for(int i=1;i<=n;++i) solve(H[i]),solve(L[i]);
	if(ans>1e17) puts("-1");
	else printf("%.12lf\n",ans);
	return 0;
}