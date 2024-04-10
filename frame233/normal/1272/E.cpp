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
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
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

const int N=200005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
int a[N];
Finline void add(int u,int v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
int dis1[N],dis2[N];
int n;
int _q[N],_l,_r;
void bfs1()
{
	memset(dis1,255,sizeof(dis1));
	_l=1,_r=0;
	for(int i=1;i<=n;++i)
	{
		if(!(a[i]&1))
		{
			dis1[i]=0;
			_q[++_r]=i;
		}
	}
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		for(int i=front[x];i;i=c[i].nxt)
		{
			if(!~dis1[c[i].v])
			{
				dis1[c[i].v]=dis1[x]+1;
				_q[++_r]=c[i].v;
			}
		}
	}
}
void bfs2()
{
	memset(dis2,255,sizeof(dis2));
	_l=1,_r=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]&1)
		{
			dis2[i]=0;
			_q[++_r]=i;
		}
	}
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		for(int i=front[x];i;i=c[i].nxt)
		{
			if(!~dis2[c[i].v])
			{
				dis2[c[i].v]=dis2[x]+1;
				_q[++_r]=c[i].v;
			}
		}
	}
}

int main()
{
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<=n;++i)
	{
		if(i-a[i]>=1)
		{
			add(i-a[i],i);
		}
		if(i+a[i]<=n)
		{
			add(i+a[i],i);
		}
	}
	bfs1();
	bfs2();
	for(int i=1;i<=n;++i)
	{
		if(a[i]&1)
		{
			printf("%d ",dis1[i]);
		}
		else
		{
			printf("%d ",dis2[i]);
		}
	}
	printf("\n");
    return 0;
}