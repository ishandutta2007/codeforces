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

const int N=(1<<20)+1;
const int mod=1000000007;
int a[N];
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
void FWT(int *a,int limit)
{
	for(int len=2;len<=limit;len<<=1)
	{
		for(int pos=0;pos<limit;pos+=len)
		{
			for(int i=pos;i<pos+(len>>1);++i)
			{
				add(a[i],a[i+(len>>1)]);
			}
		}
	}
}
void IFWT(int *a,int limit)
{
	for(int len=2;len<=limit;len<<=1)
	{
		for(int pos=0;pos<limit;pos+=len)
		{
			for(int i=pos;i<pos+(len>>1);++i)
			{
				sub(a[i],a[i+(len>>1)]);
			}
		}
	}
}
ll ksm(ll a,int b=mod-2)
{
	a=(a%mod+mod)%mod;
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
int main()
{
	int n;
	read(n);
	int x;
	for(int i=1;i<=n;++i)
	{
		read(x);
		++a[x];
	}
//	FWT(a,1<<20);
	for(int i=0;i<20;++i)
	{
		for(int j=(1<<20)-1;j>=0;--j)
		{
			if(!((j>>i)&1))
			{
				a[j]+=a[j|(1<<i)];
			}
		}
	}
	for(int i=0;i<1<<20;++i)
	{
		a[i]=ksm(2,a[i]);
	}
	IFWT(a,1<<20);
	printf("%d\n",a[0]);
    return 0;
}