// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
{
	register char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
struct edge{
	int v,nxt,w;
}c[N<<1];
int front[N],cnt;
Finline void add(int u,int v,int w)
{
	c[++cnt]=(edge){v,front[u],w},front[u]=cnt;
}
bool vis[N];
int l,w;
int S,root,_maxx;
int siz[N];
void getrt(int x,int fa)
{
	siz[x]=1;
	int maxx=0;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa&&!vis[c[i].v])
		{
			getrt(c[i].v,x);
			siz[x]+=siz[c[i].v];
			chmax(maxx,siz[c[i].v]);
		}
	}
	chmax(maxx,S-siz[x]);
	if(maxx<_maxx)
	{
		_maxx=maxx;
		root=x;
	}
}
struct node{
	int l,w;
	Finline bool operator < (const node &o)const
	{
		return w<o.w;
	}
	Finline node operator + (const int &o)const
	{
		return (node){l+1,w+o};
	}
}a[N],b[N];
int pos;
void getdis(int x,int fa,node cur)
{
	if(cur.l>l||cur.w>w) return;
	a[++pos]=cur;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa&&!vis[c[i].v])
		{
			getdis(c[i].v,x,cur+c[i].w);
		}
	}
}
struct BIT{
	int c[N];
	Finline void add(int x,int C){for(;x<N;x+=lowbit(x))c[x]+=C;}
	Finline int sum(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
}tr;
ll calc(node *a,int n)
{
	std::sort(a+1,a+n+1);
	int pos1=0,pos2=n+1;
	ll ans=0;
	for(int i=1;i<=n;++i) tr.add(a[i].l,1);
	for(int i=1;i<=n;++i)
	{
		while(pos1<i&&pos1+1<pos2)
		{
			++pos1;
			tr.add(a[pos1].l,-1);
		}
		while(pos2>1&&pos1<pos2-1&&a[pos2-1].w+a[i].w>w)
		{
			--pos2;
			tr.add(a[pos2].l,-1);
		}
		ans+=tr.sum(l-a[i].l);
	}
	for(int i=pos+1;i<=n;++i) tr.add(a[i].l,-1);
	return ans;
}
ll ans;
void solve(int x)
{
	int _pos=0;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!vis[c[i].v])
		{
			getdis(c[i].v,x,(node){1,c[i].w});
			ans-=calc(a,pos);
			while(pos) b[++_pos]=a[pos--];
		}
	}
	ans+=calc(b,_pos);
	ans+=_pos;
}
void dfs(int x)
{
	vis[x]=true;
	solve(x);
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!vis[c[i].v])
		{
			S=siz[c[i].v],_maxx=inf,root=0;
			getrt(c[i].v,x);
			dfs(root);
		}
	}
}
int main()
{
	int n;
	read(n,l,w);
	int x,y;
	for(int i=2;i<=n;++i)
	{
		read(x,y);
		add(x,i,y);
		add(i,x,y);
	}
	S=n,_maxx=inf,root=0;
	getrt(1,0);
	dfs(root);
	printf("%lld\n",ans);
	return 0;
}