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

const int N=(1<<18)+5;
namespace poly
{
	
	const int mod=998244353; // 119*2^23+1
	const int inv2=499122177;
	const int G=3,Gi=332748118;
	const int _inv2[24]={1,499122177,748683265,873463809,935854081,967049217,982646785,990445569,994344961,996294657,997269505,997756929,998000641,998122497,998183425,998213889,998229121,998236737,998240545,998242449,998243401,998243877,998244115,998244234};
	ull *_G[24];
	ull *_Gi[24];
	template <typename _Tp>Finline void swap(_Tp &a,_Tp &b)
	{
		_Tp tmp=a;
		a=b,b=tmp;
	}
	template <typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
	template <typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
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
	int r[N];
	int poly_init(int len)
	{
		int limit=1;
		while(limit<len) limit<<=1;
		for(int i(0);i<limit;++i) r[i]=(r[i>>1]>>1)|((i&1)?(limit>>1):0);
		return limit;
	}
	bool seted_G[27];
	bool seted_Gi[27];
	void setG(int pos,int limit)
	{
		if(seted_G[pos]) return;
		seted_G[pos]=true;
		_G[pos]=(ull *)(malloc((limit<<2)+8));
		ll Wn=ksm(G,(mod-1)>>pos);
		_G[pos][0]=1;
		for(int i=1;i<(limit>>1);++i)
		{
			_G[pos][i]=_G[pos][i-1]*Wn%mod;
		}
	}
	void setGi(int pos,int limit)
	{
		if(seted_Gi[pos]) return;
		seted_Gi[pos]=true;
		_Gi[pos]=(ull *)(malloc((limit<<2)+8));
		ll Wn=ksm(Gi,(mod-1)>>pos);
		_Gi[pos][0]=1;
		for(int i=1;i<(limit>>1);++i)
		{
			_Gi[pos][i]=_Gi[pos][i-1]*Wn%mod;
		}
	}
	void DFT(ull *a,int limit)
	{
		for(int i(0);i<limit;++i)
		{
			if(i<r[i])
			{
				swap(a[i],a[r[i]]);
			}
		}
		ull tmp;
		for(int len(2),t=1;len<=limit;len<<=1,++t)
		{
			setG(t,len);
			for(int pos=0;pos<limit;pos+=len)
			{
				ull *w=_G[t];
				for(register int i=pos;i<pos+(len>>1);++i,++w)
				{
					tmp=*w*a[i+(len>>1)]%mod;
					a[i+(len>>1)]=a[i]+mod-tmp;
					a[i]+=tmp;
				}
			}
		}
		for(int i(0);i<limit;++i) a[i]%=mod;
	}
	void IDFT(ull *a,int limit)
	{
		for(int i(0);i<limit;++i)
		{
			if(i<r[i])
			{
				swap(a[i],a[r[i]]);
			}
		}
		ull tmp;
		int t(1);
		for(int len(2);len<=limit;len<<=1,++t)
		{
			setGi(t,len);
			for(int pos=0;pos<limit;pos+=len)
			{
				ull *w=_Gi[t];
				for(register int i=pos;i<pos+(len>>1);++i,++w)
				{
					tmp=*w*a[i+(len>>1)]%mod;
					a[i+(len>>1)]=a[i]+mod-tmp;
					a[i]+=tmp;
				}
			}
		}
		ll inv=_inv2[t-1];
		for(int i(0);i<limit;++i) a[i]=a[i]%mod*inv%mod;
	}
	void poly_mul(int *a,int *b,int *c,int n,int m)
	{
		static ull f[N],g[N];
		int limit=poly_init(n+m);
		for(int i(0);i<n;++i) f[i]=a[i];
		for(int i(0);i<m;++i) g[i]=b[i];
		memset(f+n,0,8*(limit-n));
		memset(g+m,0,8*(limit-m));
		if(n+m<=100)
		{
			memset(c,0,4*(n+m-1));
			for(int i(0);i<n;++i)
			{
				for(int j(0);j<m;++j)
				{
					add(c[i+j],f[i]*g[j]%mod);
				}
			}
			return;
		}
		DFT(f,limit);
		DFT(g,limit);
		for(int i(0);i<limit;++i) f[i]=f[i]*g[i]%mod;
		IDFT(f,limit);
		for(int i(0);i<n+m-1;++i) c[i]=f[i];
	}
}
using namespace poly;
int a[N],b[N],c[N];
ll fac[N],inv[N];
int main()
{
	int n;
	ll m;
	read(n,m);
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	}
	for(int i=2;i<=n;++i)
	{
		inv[i]=inv[i-1]*inv[i]%mod;
	}
	for(int i=0;i<=n;++i)
	{
		read(a[i]);
		a[i]=fac[i]*a[i]%mod;
		b[i]=inv[i];
	}
	std::reverse(a,a+n+1);
	poly_mul(a,b,c,n+1,n+1);
	for(int i=0;i<=n;++i) a[i]=inv[i]*c[n-i]%mod;
	for(int i=0;i<=n;++i)
	{
		a[i]=1ll*a[i]*ksm(ksm(i+1,m))%mod*fac[i]%mod;
		b[i]=inv[i];
		if(i&1) b[i]=(mod-b[i])%mod;
	}
	std::reverse(a,a+n+1);
	poly_mul(a,b,c,n+1,n+1);
	for(int i=0;i<=n;++i) printf("%lld ",inv[i]*c[n-i]%mod);
	printf("\n");
	return 0;
}