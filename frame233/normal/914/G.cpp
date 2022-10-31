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

const int N=(1<<17)+1;
const int mod=1000000007;
const ll inv2=500000004;
int a[18][N],b[N],c[N],d[18][N],e[N];
int cnt[N],fib[N];
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
void init()
{
	for(int i=0;i<N;++i)
	{
		cnt[i]=cnt[i>>1]+(i&1);
	}
	fib[1]=1;
	for(int i=2;i<N;++i)
	{
		fib[i]=fib[i-2];
		add(fib[i],fib[i-1]);
	}
}
void FWT_or(int *a,int limit)
{
	for(int len=2;len<=limit;len<<=1)
	{
		for(int pos=0;pos<limit;pos+=len)
		{
			for(int i=pos;i<pos+(len>>1);++i)
			{
				add(a[i+(len>>1)],a[i]);
			}
		}
	}
}
void FWT_and(int *a,int limit)
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
void FWT_xor(int *a,int limit)
{
	for(int len=2;len<=limit;len<<=1)
	{
		for(int pos=0;pos<limit;pos+=len)
		{
			for(int i=pos;i<pos+(len>>1);++i)
			{
				int tmp=a[i];
				a[i]=(tmp+a[i+(len>>1)])%mod;
				a[i+(len>>1)]=(tmp-a[i+(len>>1)]+mod)%mod;
			}
		}
	}
}
void IFWT_or(int *a,int limit)
{
	for(int len=2;len<=limit;len<<=1)
	{
		for(int pos=0;pos<limit;pos+=len)
		{
			for(int i=pos;i<pos+(len>>1);++i)
			{
				sub(a[i+(len>>1)],a[i]);
			}
		}
	}
}
void IFWT_and(int *a,int limit)
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
void IFWT_xor(int *a,int limit)
{
	for(int len=2;len<=limit;len<<=1)
	{
		for(int pos=0;pos<limit;pos+=len)
		{
			for(int i=pos;i<pos+(len>>1);++i)
			{
				int tmp=a[i];
				a[i]=inv2*(tmp+a[i+(len>>1)])%mod;
				a[i+(len>>1)]=inv2*(tmp-a[i+(len>>1)]+mod)%mod;
			}
		}
	}
}
int main()
{
	init();
	int n,x;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(x);
		++a[cnt[x]][x];
		++b[x],++c[x];
	}
	for(int i=0;i<=17;++i)
	{
		FWT_or(a[i],1<<17);
	}
	for(int i=0;i<=17;++i)
	{
		for(int j=0;j<=i;++j)
		{
			for(int st=0;st<1<<17;++st)
			{
				add(d[i][st],1ll*a[i-j][st]*a[j][st]%mod);
			}
		}
		IFWT_or(d[i],1<<17);
		for(int st=0;st<1<<17;++st)
		{
			if(cnt[st]!=i)
			{
				d[i][st]=0;
			}
		}
	}
	for(int i=0;i<1<<17;++i) e[i]=1ll*d[cnt[i]][i]*fib[i]%mod;
	FWT_xor(c,1<<17);
	for(int i=0;i<1<<17;++i) c[i]=1ll*c[i]*c[i]%mod;
	IFWT_xor(c,1<<17);
	for(int i=0;i<1<<17;++i) c[i]=1ll*c[i]*fib[i]%mod;
	for(int i=0;i<1<<17;++i) b[i]=1ll*b[i]*fib[i]%mod;
	FWT_and(b,1<<17);
	FWT_and(c,1<<17);
	FWT_and(e,1<<17);
	for(int i=0;i<1<<17;++i) b[i]=1ll*b[i]*c[i]%mod*e[i]%mod;
	IFWT_and(b,1<<17);
	int ans=0;
	for(int i=0;i<17;++i)
	{
		add(ans,b[1<<i]);
	}
	printf("%d\n",ans);
	return 0;
}