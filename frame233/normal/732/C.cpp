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
const ll INF=0x7fffffffffffffff;
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
ll a[3],b[3];
ll calc(int x,int y)
{
	b[0]=a[0],b[1]=a[1],b[2]=a[2];
	for(int i=x;i<=2;++i)
	{
		--b[i];
	}
	for(int i=0;i<=y;++i)
	{
		--b[i];
	}
	ll ans=0;
	if(b[0]<0)
	{
		ans+=-b[0];
		b[0]=0;
	}
	if(b[1]<0)
	{
		ans+=-b[1];
		b[1]=0;
	}
	if(b[2]<0)
	{
		ans+=-b[2];
		b[2]=0;
	}
	ll tmp=max(b[0],max(b[1],b[2]));
	return ans+tmp*3-b[0]-b[1]-b[2];
}
int main()
{
	read(a[0],a[1],a[2]);
	if(a[0]<=1&&a[1]<=1&&a[2]<=1)
	{
		printf("0\n");
		return 0;
	}
	ll ans=INF;
	for(int i=0;i<=2;++i)
	{
		for(int j=0;j<=2;++j)
		{
			chmin(ans,calc(i,j));
		}
	}
	printf("%lld\n",ans);
    return 0;
}