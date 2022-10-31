// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<functional>

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

const int N=(1<<19)+5;
int r[N];
int poly_init(int len)
{
	int limit=1;
	while(limit<len) limit<<=1;
	for(int i(0);i<limit;++i) r[i]=(r[i>>1]>>1)|((i&1)?(limit>>1):0);
	return limit;
}
namespace poly1
{
	const int mod=998244353; // 119*2^23+1
	const int inv2=499122177;
	const int G=3,Gi=332748118;
	const int _inv2[24]={1,499122177,748683265,873463809,935854081,967049217,982646785,990445569,994344961,996294657,997269505,997756929,998000641,998122497,998183425,998213889,998229121,998236737,998240545,998242449,998243401,998243877,998244115,998244234};
	ull *_G[24];
	ull *_Gi[24];
	bool seted_G[27];
	bool seted_Gi[27];
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
	void DFT(int *a,int limit)
	{
		static ull A[N];
		for(int i=0;i<limit;++i) A[i]=a[r[i]];
		ull tmp;
		for(int len(2),t=1;len<=limit;len<<=1,++t)
		{
			setG(t,len);
			for(int pos=0;pos<limit;pos+=len)
			{
				ull *w=_G[t];
				for(register int i=pos;i<pos+(len>>1);++i,++w)
				{
					tmp=*w*A[i+(len>>1)]%mod;
					A[i+(len>>1)]=A[i]+mod-tmp;
					A[i]+=tmp;
				}
			}
		}
		for(int i(0);i<limit;++i) a[i]=A[i]%mod;
	}
	void IDFT(int *a,int limit)
	{
		static ull A[N];
		for(int i=0;i<limit;++i) A[i]=a[r[i]];
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
					tmp=*w*A[i+(len>>1)]%mod;
					A[i+(len>>1)]=A[i]+mod-tmp;
					A[i]+=tmp;
				}
			}
		}
		ll inv=_inv2[t-1];
		for(int i(0);i<limit;++i) a[i]=A[i]%mod*inv%mod;
	}
}
namespace poly2
{
	const int mod=469762049; // 7*2^26+1
	const int inv2=234881025;
	const int G=3,Gi=156587350;
	const int _inv2[27]={1,234881025,352321537,411041793,440401921,455081985,462422017,466092033,467927041,468844545,469303297,469532673,469647361,469704705,469733377,469747713,469754881,469758465,469760257,469761153,469761601,469761825,469761937,469761993,469762021,469762035,469762042};
	ull *_G[27];
	ull *_Gi[27];
	bool seted_G[27];
	bool seted_Gi[27];
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
	void DFT(int *a,int limit)
	{
		static ull A[N];
		for(int i=0;i<limit;++i) A[i]=a[r[i]];
		ull tmp;
		for(int len(2),t=1;len<=limit;len<<=1,++t)
		{
			setG(t,len);
			for(int pos=0;pos<limit;pos+=len)
			{
				ull *w=_G[t];
				for(register int i=pos;i<pos+(len>>1);++i,++w)
				{
					tmp=*w*A[i+(len>>1)]%mod;
					A[i+(len>>1)]=A[i]+mod-tmp;
					A[i]+=tmp;
				}
			}
		}
		for(int i(0);i<limit;++i) a[i]=A[i]%mod;
	}
	void IDFT(int *a,int limit)
	{
		static ull A[N];
		for(int i=0;i<limit;++i) A[i]=a[r[i]];
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
					tmp=*w*A[i+(len>>1)]%mod;
					A[i+(len>>1)]=A[i]+mod-tmp;
					A[i]+=tmp;
				}
			}
		}
		ll inv=_inv2[t-1];
		for(int i(0);i<limit;++i) a[i]=A[i]%mod*inv%mod;
	}
}
int p[N];
char s[N],t[N];
int a[N],b[N],c[N];
int qwq[N];
int limit,n,m;
void solve1(std::function<int(int)> f,std::function<int(int)> g)
{
	memset(a+n,0,(limit-n)<<2);
	memset(b+m,0,(limit-m)<<2);
	for(int i=0;i<n;++i) a[i]=f(i);
	for(int i=0;i<m;++i) b[i]=g(i);
	poly1::DFT(a,limit);
	poly1::DFT(b,limit);
	for(int i=0;i<limit;++i) poly1::add(c[i],1ll*a[i]*b[i]%poly1::mod);
}
void solve2(std::function<int(int)> f,std::function<int(int)> g)
{
	memset(a+n,0,(limit-n)<<2);
	memset(b+m,0,(limit-m)<<2);
	for(int i=0;i<n;++i) a[i]=f(i);
	for(int i=0;i<m;++i) b[i]=g(i);
	poly2::DFT(a,limit);
	poly2::DFT(b,limit);
	for(int i=0;i<limit;++i) poly2::add(c[i],1ll*a[i]*b[i]%poly2::mod);
}
bool ans[N];
int main()
{
	for(int i=1;i<=26;++i) read(p[i]);
	n=read_str(s);
	std::reverse(s,s+n);
	m=read_str(t);
	for(int i=0;i<n;++i) s[i]-=96;
	for(int i=0;i<m;++i) t[i]-=96;
	limit=poly_init(n+m);
	
	solve1([](int i)->int{return (s[i])*(s[i]);},[](int i)->int{return (t[i])*(t[i]);});
	solve1([](int i)->int{return (p[(int)s[i]])*(p[(int)s[i]]);},[](int i)->int{return (t[i])*(t[i]);});
	solve1([](int i)->int{return 4*(s[i])*(p[(int)s[i]]);},[](int i)->int{return (t[i])*(t[i]);});
	solve1([](int i)->int{return (-2*(s[i])*(s[i])*(p[(int)s[i]])+poly1::mod);},[](int i)->int{return (t[i]);});
	solve1([](int i)->int{return (-2*(s[i])*(p[(int)s[i]])*(p[(int)s[i]])+poly1::mod);},[](int i)->int{return (t[i]);});
	solve1([](int i)->int{return (-2*(s[i])+poly1::mod);},[](int i)->int{return (t[i])*(t[i])*(t[i]);});
	solve1([](int i)->int{return (-2*(p[(int)s[i]])+poly1::mod);},[](int i)->int{return (t[i])*(t[i])*(t[i]);});
	
	poly1::IDFT(c,limit);
	int sum=0;
	for(int i=0;i<n;++i) poly1::add(sum,(s[i])*(s[i])*(p[(int)s[i]])*(p[(int)s[i]]));
	for(int i=0;i<m;++i)
	{
		qwq[i]=(t[i])*(t[i])*(t[i])*(t[i]);
		i&&(poly1::add(qwq[i],qwq[i-1]),1);
	}
	for(int i=0;i<n+m-1;++i)
	{
		poly1::add(c[i],sum);
		poly1::add(c[i],qwq[i]);
		if(i>=n) poly1::sub(c[i],qwq[i-n]);
	}
	for(int i=0;i<m;++i)
	{
		ans[i]=!(c[i+n-1]);
	}
	
	memset(c,0,sizeof(c));
	
	solve2([](int i)->int{return (s[i])*(s[i]);},[](int i)->int{return (t[i])*(t[i]);});
	solve2([](int i)->int{return (p[(int)s[i]])*(p[(int)s[i]]);},[](int i)->int{return (t[i])*(t[i]);});
	solve2([](int i)->int{return 4*(s[i])*(p[(int)s[i]]);},[](int i)->int{return (t[i])*(t[i]);});
	solve2([](int i)->int{return (-2*(s[i])*(s[i])*(p[(int)s[i]])+poly2::mod);},[](int i)->int{return (t[i]);});
	solve2([](int i)->int{return (-2*(s[i])*(p[(int)s[i]])*(p[(int)s[i]])+poly2::mod);},[](int i)->int{return (t[i]);});
	solve2([](int i)->int{return (-2*(s[i])+poly2::mod);},[](int i)->int{return (t[i])*(t[i])*(t[i]);});
	solve2([](int i)->int{return (-2*(p[(int)s[i]])+poly2::mod);},[](int i)->int{return (t[i])*(t[i])*(t[i]);});
	
	poly2::IDFT(c,limit);
	sum=0;
	for(int i=0;i<n;++i) poly2::add(sum,(s[i])*(s[i])*(p[(int)s[i]])*(p[(int)s[i]]));
	for(int i=0;i<m;++i)
	{
		qwq[i]=(t[i])*(t[i])*(t[i])*(t[i]);
		i&&(poly2::add(qwq[i],qwq[i-1]),1);
	}
	for(int i=0;i<n+m-1;++i)
	{
		poly2::add(c[i],sum);
		poly2::add(c[i],qwq[i]);
		if(i>=n) poly2::sub(c[i],qwq[i-n]);
	}
	for(int i=0;i<m;++i) ans[i]&=!(c[i+n-1]);
	for(int i=0;i<=m-n;++i) printf("%d",(int)ans[i]);
	printf("\n");
	return 0;
}