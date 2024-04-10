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
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
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

const int N=5005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
Finline void add(int u,int v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
struct node{
	int x,y,d;
	Finline bool operator < (const node &o)const
	{
		return d<o.d;
	}
}a[N];
int Fa[N],dep[N];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	Fa[x]=fa;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			dfs(c[i].v,x);
		}
	}
}
int v[N];
bool check(int m)
{
	for(int i=1;i<=m;++i)
	{
		int x=a[i].x,y=a[i].y;
		int ans=inf;
		if(dep[x]<dep[y]) std::swap(x,y);
		while(dep[x]>dep[y])
		{
			chmin(ans,v[x]);
			x=Fa[x];
		}
		while(x!=y)
		{
			chmin(ans,v[x]);
			chmin(ans,v[y]);
			x=Fa[x],y=Fa[y];
		}
		if(ans!=a[i].d) return false;
	}
	return true;
}
int E[N][2];
int main()
{
	int n;
	read(n);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
		E[i][0]=x,E[i][1]=y;
	}
	dfs(1,0);
	for(int i=1;i<n;++i)
	{
		if(dep[E[i][0]]>dep[E[i][1]])
		{
			std::swap(E[i][0],E[i][1]);
		}
	}
	int m;
	read(m);
	for(int i=1;i<=m;++i)
	{
		read(a[i].x,a[i].y,a[i].d);
	}
	std::sort(a+1,a+m+1);
	for(int i=1;i<=n;++i) v[i]=1000000;
	for(int i=1;i<=m;++i)
	{
		int x=a[i].x,y=a[i].y;
		if(dep[x]<dep[y]) std::swap(x,y);
		while(dep[x]>dep[y])
		{
			v[x]=a[i].d;
			x=Fa[x];
		}
		while(x!=y)
		{
			v[x]=a[i].d;
			v[y]=a[i].d;
			x=Fa[x],y=Fa[y];
		}
	}
	if(check(m))
	{
		for(int i=1;i<n;++i)
		{
			printf("%d ",v[E[i][1]]);
		}
		printf("\n");
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}