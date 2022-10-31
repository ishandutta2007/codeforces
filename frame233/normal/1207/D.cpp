// luogu-judger-enable-o2
// Author -- Frame
 
#pragma GCC optimize(2)
 
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
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
 
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
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
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}
 
const int N=300005,mod=998244353;
struct node{
	int x,y;
}a[N];
ll fac[N];
Finline bool cmp1(const node &a,const node &b){return a.x==b.x?a.y<b.y:a.x<b.x;}
Finline bool cmp2(const node &a,const node &b){return a.y==b.y?a.x<b.x:a.y<b.y;}
Finline void add(ll &a,const ll &b){(a+=b)>=mod&&(a-=mod);}
Finline void sub(ll &a,const ll &b){(a-=b)<0&&(a+=mod);}
int main()
{
	
	int n;
	read(n);
	fac[0]=1;
	for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
	for(int i=1;i<=n;++i)
	{
		read(a[i].x,a[i].y);
	}
	std::sort(a+1,a+n+1,cmp1);
	ll ans=fac[n];
	ll res=1;
	for(int i=1;i<=n;++i)
	{
		int j=i;
		while(j<n&&a[j+1].x==a[i].x) ++j;
		res=res*fac[j-i+1]%mod;
		i=j;
	}
	sub(ans,res);
	std::sort(a+1,a+n+1,cmp2);
	res=1;
	for(int i=1;i<=n;++i)
	{
		int j=i;
		while(j<n&&a[j+1].y==a[i].y) ++j;
		res=res*fac[j-i+1]%mod;
		i=j;
	}
	sub(ans,res);
	std::sort(a+1,a+n+1,cmp1);
	for(int i=1;i<n;++i)
	{
		if(a[i].y>a[i+1].y)
		{
			printf("%lld\n",ans);
			exit(0);
		}
	}
	res=1;
	for(int i=1;i<=n;++i)
	{
		int j=i;
		while(j<n&&a[j+1].x==a[i].x&&a[j+1].y==a[i].y) ++j;
		res=res*fac[j-i+1]%mod;
		i=j;
	}
	add(ans,res);
	printf("%lld\n",ans);
    return 0;
}