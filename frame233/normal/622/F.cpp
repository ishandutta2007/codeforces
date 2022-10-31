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

const int N=1000005,mod=1000000007;
int inv[N];
int pre_mul[N],suf_mul[N];
Finline void _add(int &a,const int &b){(a+=b)>=mod&&(a-=mod);}
ll ksm(ll a,int b=mod-2)
{
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
	int n,k;
	read(n,k);
	inv[0]=inv[1]=1;
	for(int i=2;i<=k+2;++i)
	{
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	}
	for(int i=1;i<=k+2;++i)
	{
		inv[i]=1ll*inv[i]*inv[i-1]%mod;
	}
	pre_mul[0]=1;
	for(int i=1;i<=k+2;++i)
	{
		pre_mul[i]=1ll*pre_mul[i-1]*(n-i)%mod;
	}
	suf_mul[k+3]=1;
	for(int i=k+2;i>=1;--i)
	{
		suf_mul[i]=1ll*suf_mul[i+1]*(n-i)%mod;
	}
	int y=0;
	int ans=0;
	for(int i=1;i<=k+2;++i)
	{
		_add(y,ksm(i,k));
		ans+=(((k+2-i)&1)?-1ll:1ll)*y*inv[i-1]%mod*inv[k+2-i]%mod*pre_mul[i-1]%mod*suf_mul[i+1]%mod;
		ans%=mod;
		ans=(ans+mod)%mod;
	}
	printf("%d\n",ans);
    return 0;
}