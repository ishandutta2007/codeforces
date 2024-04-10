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

const int N=400005;
int ch[N][2],fa[N];
int siz[N],lsiz[N];
ll ssiz[N],lssiz[N];
bool tag[N];
Finline void pushup(int x)
{
	siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+lsiz[x];
	ssiz[x]=lssiz[x]+1ll*siz[ch[x][0]]*siz[ch[x][0]]+1ll*siz[ch[x][1]]*siz[ch[x][1]];
}
Finline bool nroot(int x){return ch[fa[x]][0]==x||ch[fa[x]][1]==x;}
Finline void rotate(int x)
{
	int y=fa[x],z=fa[y],k=x==ch[y][1],w=ch[x][!k];
	ch[x][!k]=y,ch[y][k]=w,nroot(y)&&(ch[z][y==ch[z][1]]=x);
	fa[x]=z,fa[y]=x,w&&(fa[w]=y);
	pushup(y),pushup(x);
}
Finline void flip(int x){x&&(std::swap(ch[x][0],ch[x][1]),tag[x]^=1);}
Finline void pushdown(int x){tag[x]&&(flip(ch[x][0]),flip(ch[x][1]),tag[x]=0);}
void splay(int x)
{
	static int st[N];
	int top,y;st[top=1]=y=x;
	while(nroot(y)) st[++top]=y=fa[y];
	while(top) pushdown(st[top--]);
	while(nroot(x))
	{
		y=fa[x];
		nroot(y)&&(rotate((y==ch[fa[y]][1])==(x==ch[y][1])?y:x),0);
		rotate(x);
	}
}
void access(int x)
{
	for(int y=0;x;x=fa[y=x])
	{
		splay(x);
		lsiz[x]-=siz[y];
		lssiz[x]-=1ll*siz[y]*siz[y];
		lsiz[x]+=siz[ch[x][1]];
		lssiz[x]+=1ll*siz[ch[x][1]]*siz[ch[x][1]];
		ch[x][1]=y;
		pushup(x);
	}
}
Finline void makeroot(int x)
{
	access(x),splay(x),flip(x);
}
int findroot(int x)
{
	access(x),splay(x);
	while(ch[x][0]) pushdown(x),x=ch[x][0];
	return splay(x),x;
}
Finline void link(int x,int y)
{
	access(x),splay(x);
	access(y),splay(y);
	fa[x]=y;
	lsiz[y]+=siz[x],lssiz[y]+=1ll*siz[x]*siz[x];
	pushup(y);
}
Finline void cut(int x,int y)
{
	access(x),splay(y);
	fa[x]=0,ch[y][1]=0;
	pushup(y);
}
int a[N];
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int Fa[N];
void dfs(int x,int fa)
{
	Fa[x]=fa;
	::fa[x]=fa,siz[x]=1,ssiz[x]=0;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v!=fa) dfs(v,x),siz[x]+=siz[v],ssiz[x]+=1ll*siz[v]*siz[v];
	}
	lsiz[x]=siz[x],lssiz[x]=ssiz[x];
}
struct qry{
	int t,id;
	Finline bool operator < (const qry &o)const
	{
		return t<o.t;
	}
};
std::vector<qry> v[N];
ll ans[N];
Finline ll calc(int x)
{
	x=findroot(x);
	splay(x);
	return ssiz[x];
}
int main()
{
	int n,q;read(n,q);
	for(int i=1;i<=n;++i) read(a[i]),v[a[i]].pb((qry){0,-i});
	int x,y;
	for(int i=1;i<n;++i) read(x,y),addedge(x,y),addedge(y,x);
	addedge(n+1,1);
	dfs(n+1,0);
	--lsiz[n+1],--siz[n+1];
	for(int i=1;i<=q;++i)
	{
		read(x,y);
		if(a[x]==y) continue;
		v[a[x]].pb((qry){i,x});
		v[y].pb((qry){i,-x});
		a[x]=y;
	}
	for(int col=1;col<=n;++col)
	{
		std::vector<qry> Q(v[col]);
		std::sort(Q.begin(),Q.end());
		ll res=1ll*n*n;
		ans[0]+=res;
		makeroot(n+1);
		for(auto it:Q)
		{
			x=abs(it.id);
			ll last=res;
			if(it.id<0)
			{
				res-=calc(x);
				cut(x,Fa[x]);
				res+=calc(x)+calc(Fa[x]);
			}
			else
			{
				res-=calc(x)+calc(Fa[x]);
				link(x,Fa[x]);
				res+=calc(x);
			}
			ans[it.t]+=res-last;
		}
		std::reverse(Q.begin(),Q.end());
		for(auto it:Q)
		{
			x=abs(it.id);
			if(it.id<0) link(x,Fa[x]);
			else cut(x,Fa[x]);
		}
	}
	for(int i=1;i<=q;++i) ans[i]+=ans[i-1];
	for(int i=0;i<=q;++i) printf("%lld\n",1ll*n*n*n-ans[i]);
	return 0;
}