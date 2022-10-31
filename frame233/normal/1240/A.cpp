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

const int N=200005;
ll p[N];
ll n,x,a,y,b;
ll k,lcm;
bool check(int mid)
{
	int t=mid/lcm;
	ll ans=0;
	for(int i=1;i<=t;++i)
	{
		ans+=(x+y)*p[i];
	}
	int t1=mid/a-t;
	int t2=mid/b-t;
	if(x>y)
	{
		for(int i=1;i<=t1;++i)
		{
			if(t<n)
			{
				ans+=x*p[++t];
			}
		}
		for(int i=1;i<=t2;++i)
		{
			if(t<n)
			{
				ans+=y*p[++t];
			}
		}
	}
	else
	{
		for(int i=1;i<=t2;++i)
		{
			if(t<n)
			{
				ans+=y*p[++t];
			}
		}
		for(int i=1;i<=t1;++i)
		{
			if(t<n)
			{
				ans+=x*p[++t];
			}
		}
	}
	return ans>=k;
}
void MAIN()
{
	
	read(n);
	for(int i=1;i<=n;++i) read(p[i]),p[i]/=100;
	std::sort(p+1,p+n+1);
	std::reverse(p+1,p+n+1);
	read(x,a,y,b);
	read(k);
	lcm=1ll*a*b/gcd(a,b);
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(check(l)) printf("%d\n",l);
	else printf("-1\n");
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
    return 0;
}