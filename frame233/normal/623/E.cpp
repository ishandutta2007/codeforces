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
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
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
const int mod=1000000007;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}

const int mod1=998244353;
const int G1=3,Gi1=332748118;
const ull _inv21[24]={1,499122177,748683265,873463809,935854081,967049217,982646785,990445569,994344961,996294657,997269505,997756929,998000641,998122497,998183425,998213889,998229121,998236737,998240545,998242449,998243401,998243877,998244115,998244234};

const int mod2=469762049;
const int G2=3,Gi2=156587350;
const ull _inv22[25]={1,234881025,352321537,411041793,440401921,455081985,462422017,466092033,467927041,468844545,469303297,469532673,469647361,469704705,469733377,469747713,469754881,469758465,469760257,469761153,469761601,469761825,469761937,469761993,469762021};
	
const int mod3=167772161;
const int G3=3,Gi3=55924054;
const ull _inv23[24]={1,83886081,125829121,146800641,157286401,162529281,165150721,166461441,167116801,167444481,167608321,167690241,167731201,167751681,167761921,167767041,167769601,167770881,167771521,167771841,167772001,167772081,167772121,167772141};
	
const int inv_1=208783132;
const int inv_12=29562547;
ll ksm(ll a,ll b,ll mod)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}

struct Triple{
	ull a,b,c;
	Finline Triple operator + (const Triple &o)const
	{
		return (Triple){(a+o.a)%mod1,(b+o.b)%mod2,(c+o.c)%mod3};
	}
	Finline Triple operator - (const Triple &o)const
	{
		return (Triple){(a+mod1-o.a)%mod1,(b+mod2-o.b)%mod2,(c+mod3-o.c)%mod3};
	}
	Finline Triple operator * (const int &o)const
	{
		return (Triple){a*o%mod1,b*o%mod2,c*o%mod3};
	}
	Finline Triple operator * (const Triple &o)const
	{
		return (Triple){a*o.a%mod1,b*o.b%mod2,c*o.c%mod3};
	}
	Finline void operator += (const Triple &o)
	{
		(a+=o.a);
		(b+=o.b);
		(c+=o.c);
	}
	Finline void operator -= (const Triple &o)
	{
		a=a+mod1-o.a;
		b=b+mod2-o.b;
		c=c+mod3-o.c;
	}
	Finline void operator *= (const ll &o)
	{
		a=a*o%mod1;
		b=b*o%mod2;
		c=c*o%mod3;
	}
	Finline void operator *= (const Triple &o)
	{
		a=a*o.a%mod1;
		b=b*o.b%mod2;
		c=c*o.c%mod3;
	}
	Finline void update()
	{
		a%=mod1;
		b%=mod2;
		c%=mod3;
	}
	Finline int getans(int _mod)
	{
		ll A=a,B=b,C=c;
		ll x=((B-A)%mod2+mod2)*inv_1%mod2*mod1+A;
		return (((C-x)%mod3+mod3)*inv_12%mod3*mod1%_mod*mod2%_mod+x)%_mod;
	}
};
Triple *_G[24],*_Gi[24];
bool Seted_G[24],Seted_Gi[24];
int r[N];
int poly_init(int len)
{
	int limit=1;
	while(limit<len) limit<<=1;
	for(int i=0;i<limit;++i) r[i]=(r[i>>1]>>1)|((i&1)?(limit>>1):0);
	return limit;
}
void SetG(int limit,int pos)
{
	if(Seted_G[pos]) return;
	Seted_G[pos]=true;
	_G[pos]=(Triple *)(malloc(((limit>>1)+1)*sizeof(Triple)));
	Triple mul=(Triple){(ull)ksm(G1,(mod1-1)>>pos,mod1),(ull)ksm(G2,(mod2-1)>>pos,mod2),(ull)ksm(G3,(mod3-1)>>pos,mod3)};
	_G[pos][0]=(Triple){1,1,1};
	for(int i=1;i<limit>>1;++i)
	{
		_G[pos][i]=_G[pos][i-1]*mul;
	}
}
void SetGi(int limit,int pos)
{
	if(Seted_Gi[pos]) return;
	Seted_Gi[pos]=true;
	_Gi[pos]=(Triple *)(malloc(((limit>>1)+1)*sizeof(Triple)));
	Triple mul=(Triple){(ull)ksm(Gi1,(mod1-1)>>pos,mod1),(ull)ksm(Gi2,(mod2-1)>>pos,mod2),(ull)ksm(Gi3,(mod3-1)>>pos,mod3)};
	_Gi[pos][0]=(Triple){1,1,1};
	for(int i=1;i<limit>>1;++i)
	{
		_Gi[pos][i]=_Gi[pos][i-1]*mul;
	}
}
void DFT(Triple *a,int limit)
{
	for(int i=0;i<limit;++i)
	{
		if(i<r[i])
		{
			std::swap(a[i],a[r[i]]);
		}
	}
	for(int len=2,t=1;len<=limit;len<<=1,++t)
	{
		SetG(len,t);
		for(int pos=0;pos<limit;pos+=len)
		{
			Triple *w=_G[t];
			for(int i=pos;i<pos+(len>>1);++i,++w)
			{
				Triple tmp=*w*a[i+(len>>1)];
				a[i+(len>>1)]=a[i]-tmp;
				a[i]+=tmp;
			}
		}
	}
	for(int i=0;i<limit;++i) a[i].update();
}
void IDFT(Triple *a,int limit)
{
	for(int i=0;i<limit;++i)
	{
		if(i<r[i])
		{
			std::swap(a[i],a[r[i]]);
		}
	}
	int t(1);
	for(int len=2;len<=limit;len<<=1,++t)
	{
		SetGi(len,t);
		for(int pos=0;pos<limit;pos+=len)
		{
			Triple *w=_Gi[t];
			for(int i=pos;i<pos+(len>>1);++i,++w)
			{
				Triple tmp=*w*a[i+(len>>1)];
				a[i+(len>>1)]=a[i]-tmp;
				a[i]+=tmp;
			}
		}
	}
	Triple inv=(Triple){_inv21[t-1],_inv22[t-1],_inv23[t-1]};
	for(int i=0;i<limit;++i)
	{
		a[i].update();
		a[i]*=inv;
	}
}
ll fac[N],inv[N];
void init(ll n)
{
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
}
Finline ll C(int n,int m)
{
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
ll n,k;
int qwq;
struct poly{
	int *a,n;
	Finline poly(int *p=NULL,int len=0):a(p),n(len){};
	Finline void init(int len)
	{
		a=(int *)calloc(len,4);
		n=len;
	}
	Finline void clear()
	{
		free(a);
		a=NULL;
		n=0;
	}
	void print()
	{
		DEBUG;
		for(int i=0;i<n;++i) printf("%d ",a[i]);
		printf("\n");
	}
	poly operator * (const poly &o)const
	{
		static Triple f[N],g[N];
		int limit=poly_init(n+o.n-1);
		for(int i=0;i<n;++i)
		{
		 	ull x=inv[i]*ksm(2,1ll*i*qwq,mod)%mod*a[i]%mod;
			f[i]=(Triple){x,x,x};
		}
		for(int i=0;i<o.n;++i)
		{
			ull x=inv[i]*o.a[i]%mod;
			g[i]=(Triple){x,x,x};
		}
		memset(f+n,0,sizeof(Triple)*(limit-n));
		memset(g+o.n,0,sizeof(Triple)*(limit-o.n));
		DFT(f,limit);
		DFT(g,limit);
		for(int i=0;i<limit;++i) f[i]=f[i]*g[i];
		IDFT(f,limit);
		int len=min((int)k+1,n+o.n-1);
		poly c((int *)calloc(len,4),len);
		for(int i=0;i<len;++i) c.a[i]=f[i].getans(mod)*fac[i]%mod;
		return c;
	}
};
poly _ksm(ll n)
{
	poly res,a;
	res.init(1);
	res.a[0]=1;
	a.init(k+1);
	for(int i=1;i<=k;++i) a.a[i]=1;
	qwq=1;
	while(n)
	{
		if(n&1) res=res*a;
		a=a*a,n>>=1;
		qwq<<=1;
	}
	return res;
}
int main()
{
	read(n,k);
	if(n>k)
	{
		printf("0\n");
		return 0;
	}
	init(N-1);
	poly tmp=_ksm(n);
	ll ans=0;
	for(int i=0;i<=k;++i)
	{
		add(ans,tmp.a[i]*C(k,i)%mod);
	}
	printf("%lld\n",ans);
	return 0;
}