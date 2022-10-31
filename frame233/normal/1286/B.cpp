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

const int N=2005;
struct edge{
	int v,nxt;
}c[N];
int front[N],cnt;
Finline void add(int u,int v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
int a[N];
int _q[N],_l,_r;
int tmp[N];
int siz[N];
int Fa[N];
int val[N];
int D;
int _cnt;
void dfs(int x)
{
	if(val[x]<D) ++_cnt;
	for(int i=front[x];i;i=c[i].nxt)
	{
		dfs(c[i].v);
	}
}
bool check(int nd,int x,int v)
{
	_cnt=-1;
	D=x;
	dfs(nd);
	return _cnt>=v;
}
int main()
{
	int n;
	read(n);
	int x;
	for(int i=1;i<=n;++i)
	{
		read(x,a[i]);
		Fa[i]=x;
		++tmp[x];
		if(x) add(x,i);
	}
	_l=1,_r=0;
	for(int i=1;i<=n;++i)
	{
		siz[i]=1;
		if(!tmp[i])
		{
			_q[++_r]=i;
		}
	}
	tmp[0]=inf;
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		int l=1,r=n;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(check(x,mid,a[x])) r=mid;
			else l=mid+1;
		}
		if(!check(x,l,a[x]))
		{
			printf("NO\n");
			return 0;
		}
		for(int i=1;i<=n;++i)
		{
			if(val[i]>=l)
			{
				++val[i];
			}
		}
		val[x]=l;
		siz[Fa[x]]+=siz[x];
		if(!--tmp[Fa[x]])
		{
			_q[++_r]=Fa[x];
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;++i)
	{
		printf("%d ",val[i]);
	}
    return 0;
}