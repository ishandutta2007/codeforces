// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=4000005;
const int mod=998244353;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
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
ll fac[N],inv[N],ifac[N];
void init()
{
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<N;++i)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
		ifac[i]=ifac[i-1]*inv[i]%mod;
	}
}
Finline ll C(int n,int m)
{
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
ll f[N],a[N],b[N];
ll s1[N],s2[N],s3[N];
int main()
{
	init();
	ll n,m;read(n,m);
	ll mul=1;for(int i=1;i<=n;++i) a[i]=mod+1-m*fac[n-i]%mod*ifac[n+m]%mod*C(n+m,m+i)%mod*fac[m+i-1]%mod,mul=mul*a[i]%mod;
	mul=ksm(mul);for(int i=n;i>=1;--i) b[i]=mul,mul=mul*a[i]%mod;
	mul=1;for(int i=1;i<=n;++i) b[i]=b[i]*mul%mod,mul=mul*a[i]%mod;
	s1[0]=fac[m-1];
	for(int i=1;i<=n;++i)
	{
		s1[i]=s1[i-1],add(s1[i],fac[m+i-1]*ifac[i]%mod);
		s2[i]=s2[i-1],add(s2[i],fac[m+i-1]*ifac[i-1]%mod);
		ll _=m*fac[i]%mod*fac[n-i]%mod*ifac[n+m]%mod;
		ll tmp=_*C(n+m+1,m+i+1)%mod*(s1[i]*(i+1)%mod-s2[i]+mod)%mod;
		f[i]=(tmp+_*C(n+m,m+i)%mod*s3[i]%mod)*b[i]%mod;
		s3[i+1]=s3[i],add(s3[i+1],fac[m+i-1]*ifac[i]%mod*f[i]%mod);
	}
	printf("%lld\n",f[n]);
	return 0;
}