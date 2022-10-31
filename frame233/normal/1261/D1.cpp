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

const int N=200005;
const int mod=998244353;
int fac[N],inv[N];
int a[N];
ll ksm(ll a,ll b=mod-2)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
template<typename _Tp>Finline void add(_Tp &a,_Tp b){(a+=b)>=mod&&(a-=mod);}
Finline ll C(int n,int m)
{
	if(n<m) return 0;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
	int n,k;
	read(n,k);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
	}
	a[n+1]=a[1];
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		cnt+=a[i]==a[i+1];
	}
	ll ans=0,mul=ksm(k,cnt);
	n-=cnt;
	fac[0]=fac[1]=1;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i)
	{
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	}
	for(int i=2;i<=n;++i) inv[i]=1ll*inv[i-1]*inv[i]%mod;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<i&&j<=n-i;++j)
		{
			add(ans,C(n,i)*C(n-i,j)%mod*ksm(k-2,n-i-j)%mod);
		}
	}
	printf("%lld\n",ans*mul%mod);
    return 0;
}