// Author -- Frame
 
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
 
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
 
#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;
 
uint seed=19260817;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool ismax(_Tp &a,const _Tp &b){return a>b?1:a=b,0;}
template <typename _Tp>Finline bool ismin(_Tp &a,const _Tp &b){return a<b?1:a=b,0;}
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
 
const int N=3005;
int h[N][N];
int _q[N],_l,_r;
int minn[N][N];
void gene(int n,int m)
{
	ll g0,x,y,z;
	read(g0,x,y,z);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			h[i][j]=g0;
			g0=(g0*x+y)%z;
		}
	}
}
int main()
{
	int n,m,a,b;
	read(n,m,a,b);
	gene(n,m);
	for(int i=1;i<=n;++i)
	{
		_l=1,_r=0;
		for(int j=1;j<b;++j)
		{
			while(_l<=_r&&h[i][_q[_r]]>h[i][j]) --_r;
			_q[++_r]=j;
		}
		for(int j=b;j<=m;++j)
		{
			while(_l<=_r&&h[i][_q[_r]]>h[i][j]) --_r;
			_q[++_r]=j;
			while(_l<=_r&&j-_q[_l]>=b) ++_l;
			minn[i][j]=h[i][_q[_l]];
		}
	}
	ll ans=0;
	for(int i=b;i<=m;++i)
	{
		_l=1,_r=0;
		for(int j=1;j<a;++j)
		{
			while(_l<=_r&&minn[_q[_r]][i]>minn[j][i]) --_r;
			_q[++_r]=j;
		}
		for(int j=a;j<=n;++j)
		{
			while(_l<=_r&&minn[_q[_r]][i]>minn[j][i]) --_r;
			_q[++_r]=j;
			while(_l<=_r&&j-_q[_l]>=a) ++_l;
			ans+=minn[_q[_l]][i];
		}
	}
	printf("%lld\n",ans);
	return 0;
}