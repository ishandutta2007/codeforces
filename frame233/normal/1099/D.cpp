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
struct edge{
	int v,nxt;
}c[N];
int front[N],cnt;
int s[N];
int a[N];
int minn[N];
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
void dfs(int x,int dep)
{
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(dep==1)
		{
			if(minn[c[i].v]>=inf)
			{
				s[c[i].v]=s[x];
			}
			else
			{
				s[c[i].v]=max(s[x],minn[c[i].v]);
			}
			a[c[i].v]=s[c[i].v]-s[x];
		}
		else
		{
			if(s[c[i].v]<s[x])
			{
				printf("-1\n");
				exit(0);
			}
			a[c[i].v]=s[c[i].v]-s[x];
		}
		dfs(c[i].v,dep^1);
	}
}
int main()
{
	memset(minn,63,sizeof(minn));
	int n,x;
	read(n);
	for(int i=2;i<=n;++i)
	{
		read(x);
		add(x,i);
	}
	for(int i=1;i<=n;++i)
	{
		read(s[i]);
	}
	for(int i=1;i<=n;++i)
	{
		if(s[i]==-1)
		{
			for(int _=front[i];_;_=c[_].nxt)
			{
				chmin(minn[i],s[c[_].v]);
			}
		}
	}
	a[1]=s[1];
	dfs(1,1);
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		ans+=a[i];
	}
	printf("%lld\n",ans);
    return 0;
}