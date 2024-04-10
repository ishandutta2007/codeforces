// luogu-judger-enable-o2
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
const ll INF=0x7ffffffffffffff;
const double eps=1e-8;

uint seed=19260817;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
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
    while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=100005;
int n,L;
ll S;
int w[N];
struct edge{
	int v,nxt;
}c[N];
int front[N],cnt;
int f[N][19];
ll W[N][19];
int dep[N];
int path[N];
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
void dfs(int x,int Fa)
{
	dep[x]=dep[Fa]+1;
	f[x][0]=Fa;
	for(int i=1;i<=18;++i)
	{
		f[x][i]=f[f[x][i-1]][i-1];
		W[x][i]=W[x][i-1]+W[f[x][i-1]][i-1];
	}
	for(int i=front[x];i;i=c[i].nxt)
	{
		W[c[i].v][0]=w[x];
		dfs(c[i].v,x);
	}
}
int GetPath(int x)
{
	ll rest=S-w[x];
	int tmp=x;
	for(int i=18;i>=0;--i)
	{
		if(f[x][i]&&dep[tmp]-dep[f[x][i]]<L&&rest>=W[x][i])
		{
			rest-=W[x][i];
			x=f[x][i];
		}
	}
	return x;
}
Finline bool cmp(const int &a,const int &b){return dep[a]>dep[b];}
int ans;
void Dfs(int x)
{
	int id=0,minn=inf;
	for(int i=front[x];i;i=c[i].nxt)
	{
		Dfs(c[i].v);
		if(!path[c[i].v]) continue;
		if(dep[path[c[i].v]]<minn)
		{
			minn=dep[path[c[i].v]];
			id=c[i].v;
		}
	}
	if(id)
	{
		path[x]=path[id];
		if(path[x]==x) path[x]=0;
	}
	else
	{
		++ans;
		path[x]=GetPath(x);
		if(path[x]==x) path[x]=0;
	}
}
int main()
{
	read(n,L,S);
	for(int i=1;i<=n;++i)
	{
		read(w[i]);
		if(w[i]>S)
		{
			printf("-1\n");
			return 0;
		}
	}
	int x;
	for(int i=2;i<=n;++i)
	{
		read(x);
		add(x,i);
	}
	dfs(1,0);
	Dfs(1);
	printf("%d\n",ans);
    return 0;
}