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

const int N=1000005;
int n,k,l;
char s[N];
int a[N],sum[N];
ll res,dp[N];
int dep[N];
int calc(int C)
{
	for(int i=1;i<l;++i)
	{
		if(sum[i]<=C)
		{
			dp[i]=sum[i];
			dep[i]=0;
		}
		else
		{
			dp[i]=C;
			dep[i]=1;		
		}
	}
	for(int i=l;i<=n;++i)
	{
		if(dp[i-1]+a[i]<dp[i-l]+C||(dp[i-1]+a[i]==dp[i-l]+C&&dep[i-1]<dep[i-l]+1))
		{
			dp[i]=dp[i-1]+a[i];
			dep[i]=dep[i-1];
		}
		else
		{
			dp[i]=dp[i-l]+C;
			dep[i]=dep[i-l]+1;
		}
	}
	res=dp[n];
	return dep[n];
}
int main()
{
	read(n,k,l);
	read_str(s+1);
	for(int i=1;i<=n;++i)
	{
		a[i]=s[i]>=97&&s[i]<=122;
		sum[i]=sum[i-1]+a[i];
	}
	int l=0,r=1000000;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(calc(mid)<=k) r=mid;
		else l=mid+1;
	}
	calc(l);
	ll ans=res-1ll*l*k;
	for(int i=1;i<=n;++i)
	{
		a[i]=!(s[i]>=97&&s[i]<=122);
		sum[i]=sum[i-1]+a[i];
	}
	l=0,r=1000000;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(calc(mid)<=k) r=mid;
		else l=mid+1;
	}
	calc(l);
	chmin(ans,res-1ll*l*k);
	printf("%lld\n",ans);
	return 0;
}