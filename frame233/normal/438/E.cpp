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

const int N=400105;
namespace poly
{
	
	const int mod=998244353; // 119*2^23+1
	const int inv2=499122177;
	const int G=3,Gi=332748118;
	const int _G[24]={1,998244352,911660635,372528824,929031873,452798380,922799308,781712469,476477967,166035806,258648936,584193783,63912897,350007156,666702199,968855178,629671588,24514907,996173970,363395222,565042129,733596141,267099868,15311432};
	const int _Gi[24]={1,998244352,86583718,509520358,337190230,87557064,609441965,135236158,304459705,685443576,381598368,335559352,129292727,358024708,814576206,708402881,283043518,3707709,121392023,704923114,950391366,428961804,382752275,469870224};
	
//	const int mod=469762049; // 28*2^24+1
//	const int inv2=234881025;
//	const int G=3,Gi=156587350;
//	const int _G[25]={1,469762048,450151958,129701348,426037461,244709223,210853138,189158148,338628632,25153357,110059487,165447688,244412522,62025685,19512135,372627191,386080322,321129726,422997289,49553715,197868229,297449090,391371999,385303873,320192759};
//	const int _Gi[25]={1,469762048,19610091,26623616,358191614,278703339,58439238,230980285,215855482,436579181,458753944,63413564,309717554,318475127,317243944,271119509,380600599,417932558,44275780,96523612,256026808,131257384,426545640,300035530,49490419};
	
//	const int mod=167772161; // 20*2^23+1
//	const int inv2=83886081;
//	const int G=3,Gi=55924054;
//	const int _G[24]={1,167772160,65249968,71493608,116878283,17334830,54112143,370529,26238939,57844624,134785078,83629286,150794572,42000181,129200985,34951379,48967582,51958270,87327368,127218630,88009046,147771621,98217575,131341181};
//	const int _Gi[24]={1,167772160,102522193,137365239,127635702,7847275,17519876,13908831,31840780,64014230,111398802,63739760,102971782,31279966,68476275,66832766,14997684,9639726,150281339,67941598,75955219,148642633,85248894,16470339};
	
//	const int mod=1004535809; // 479*2^21+1
//	const int inv2=502267905;
//	const int G=3,Gi=334845270;
//	const int _G[22]={1,1004535808,483363861,395918948,691095095,67253981,89059135,337291080,317143553,8295483,327081633,714163887,295244910,2062645,524615618,333849333,50393163,925609281,615614863,862977694,848723745,702606812};
//	const int _Gi[22]={1,1004535808,521171948,181280972,440257849,236219887,412852222,174881506,581383828,870703586,216733913,278605116,200320826,58507845,191870395,411091405,755911120,816727090,689146186,353531124,97543274,700146880};
	
	template<typename _Tp>Finline void swap(_Tp &a,_Tp &b)
	{
		_Tp tmp=a;
		a=b,b=tmp;
	}
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
	ll ksm(ll a,int b,ll mod)
	{
		ll res=1;
		while(b)
		{
			if(b&1) res=res*a%mod;
			a=a*a%mod,b>>=1;
		}
		return res;
	}
	int inv[N];
	int maxx=2;
	void _init(int n)
	{
		inv[0]=inv[1]=1;
		for(int i=maxx;i<=n;++i)
		{
			inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		}
		chmax(maxx,n+1);
	}
	Finline void derivative(int *a,int n)
	{
		for(int i=0;i<n-1;++i)
		{
			a[i]=1ll*a[i+1]*(i+1)%mod;
		}
		a[n-1]=0;
	}
	Finline void integral(int *a,int n)
	{
		_init(n);
		for(int i=n;i>=1;--i)
		{
			a[i]=1ll*a[i-1]*inv[i]%mod;
		}
		a[0]=0;
	}
	Finline void derivative(int *a,int *b,int n)
	{
		for(int i=0;i<n-1;++i)
		{
			b[i]=1ll*a[i+1]*(i+1)%mod;
		}
		b[n-1]=0;
	}
	Finline void integral(int *a,int *b,int n)
	{
		_init(n);
		for(int i=n;i>=1;--i)
		{
			b[i]=1ll*a[i-1]*inv[i]%mod;
		}
		b[0]=0;
	}
	Finline void reverse(int *a,int n)
	{
		static int tmp[N];
		memcpy(tmp,a,4*n);
		for(int i=0;i<n;++i)
		{
			a[i]=tmp[n-i-1];
		}
	}
	Finline void reverse(int *a,int *b,int n)
	{
		for(int i=0;i<n;++i)
		{
			b[i]=a[n-i-1];
		}
	}
	int r[N];
	int init(int len)
	{
		int limit=1;
		while(limit<len) limit<<=1;
		for(int i=0;i<limit;++i) r[i]=(r[i>>1]>>1)|((i&1)?(limit>>1):0);
		return limit;
	}
	void DFT(int *a,int limit)
	{
		for(int i=0;i<limit;++i)
		{
			if(i<r[i])
			{
				swap(a[i],a[r[i]]);
			}
		}
		int w,Wn,tmp;
		for(int len=2,t=1;len<=limit;len<<=1,++t)
		{
			Wn=_G[t];
			for(int pos=0;pos<limit;pos+=len)
			{
				w=1;
				for(int i=pos;i<pos+(len>>1);++i,w=1ll*w*Wn%mod)
				{
					tmp=1ll*w*a[i+(len>>1)]%mod;
					a[i+(len>>1)]=(a[i]-tmp+mod)%mod;
					add(a[i],tmp);
				}
			}
		}
	}
	void IDFT(int *a,int limit)
	{
		for(int i=0;i<limit;++i)
		{
			if(i<r[i])
			{
				swap(a[i],a[r[i]]);
			}
		}
		int w,Wn,tmp;
		for(int len=2,t=1;len<=limit;len<<=1,++t)
		{
			Wn=_Gi[t];
			for(int pos=0;pos<limit;pos+=len)
			{
				w=1;
				for(int i=pos;i<pos+(len>>1);++i,w=1ll*w*Wn%mod)
				{
					tmp=1ll*w*a[i+(len>>1)]%mod;
					a[i+(len>>1)]=(a[i]-tmp+mod)%mod;
					add(a[i],tmp);
				}
			}
		}
		ll inv=ksm(limit);
		for(int i=0;i<limit;++i) a[i]=inv*a[i]%mod;
	}
	void brute(int *a,int *b,int *c,int n,int m)
	{
		memset(c,0,4*(n+m-1));
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				add(c[i+j],1ll*a[i]*b[j]%mod);
			}
		}
	}
	void brute(int *a,int *b,int *c,int *d,int n,int m,int p)
	{
		memset(d,0,4*(n+m+p-2));
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				for(int k=0;k<p;++k)
				{
					add(d[i+j+k],1ll*a[i]*b[j]%mod*c[k]%mod);
				}
			}
		}
	}
	void poly_mul(int *a,int *b,int *c,int n,int m)
	{
		static int f[N],g[N];
		int limit=init(n+m);
		memcpy(f,a,4*n);
		memset(f+n,0,4*(limit-n));
		memcpy(g,b,4*m);
		memset(g+m,0,4*(limit-m));
		if(n+m<=100)
		{
			memset(c,0,4*(n+m-1));
			for(int i=0;i<n;++i)
			{
				for(int j=0;j<m;++j)
				{
					add(c[i+j],1ll*f[i]*g[j]%mod);
				}
			}
			return;
		}
		DFT(f,limit);
		DFT(g,limit);
		for(int i=0;i<limit;++i) f[i]=1ll*f[i]*g[i]%mod;
		IDFT(f,limit);
		memcpy(c,f,4*(n+m-1));
	}
	void poly_mul(int *a,int *b,int *c,int *d,int n,int m,int p)
	{
		static int f[N],g[N],q[N];
		int limit=init(n+m+p);
		memcpy(f,a,4*n);
		memset(f+n,0,4*(limit-n));
		memcpy(g,b,4*m);
		memset(g+m,0,4*(limit-m));
		memcpy(q,c,4*p);
		memset(q+p,0,4*(limit-p));
		if(n+m+p<=100)
		{
			memset(d,0,4*(n+m+p-2));
			for(int i=0;i<n;++i)
			{
				for(int j=0;j<m;++j)
				{
					for(int k=0;k<p;++k)
					{
						add(d[i+j+k],1ll*f[i]*g[j]%mod*q[k]%mod);
					}
				}
			}
			return;
		}
		DFT(f,limit);
		DFT(g,limit);
		DFT(q,limit);
		for(int i=0;i<limit;++i) f[i]=1ll*f[i]*g[i]%mod*q[i]%mod;
		IDFT(f,limit);
		memcpy(d,f,4*(n+m+p-2));
	}
	const int mod1=998244353;
	const int G1=3,Gi1=332748118;
	const int _G1[24]={1,998244352,911660635,372528824,929031873,452798380,922799308,781712469,476477967,166035806,258648936,584193783,63912897,350007156,666702199,968855178,629671588,24514907,996173970,363395222,565042129,733596141,267099868,15311432};
	const int _Gi1[24]={1,998244352,86583718,509520358,337190230,87557064,609441965,135236158,304459705,685443576,381598368,335559352,129292727,358024708,814576206,708402881,283043518,3707709,121392023,704923114,950391366,428961804,382752275,469870224};
	
	const int mod2=469762049;
	const int G2=3,Gi2=156587350;
	const int _G2[25]={1,469762048,450151958,129701348,426037461,244709223,210853138,189158148,338628632,25153357,110059487,165447688,244412522,62025685,19512135,372627191,386080322,321129726,422997289,49553715,197868229,297449090,391371999,385303873,320192759};
	const int _Gi2[25]={1,469762048,19610091,26623616,358191614,278703339,58439238,230980285,215855482,436579181,458753944,63413564,309717554,318475127,317243944,271119509,380600599,417932558,44275780,96523612,256026808,131257384,426545640,300035530,49490419};
	
	const int mod3=167772161;
	const int G3=3,Gi3=55924054;
	const int _G3[24]={1,167772160,65249968,71493608,116878283,17334830,54112143,370529,26238939,57844624,134785078,83629286,150794572,42000181,129200985,34951379,48967582,51958270,87327368,127218630,88009046,147771621,98217575,131341181};
	const int _Gi3[24]={1,167772160,102522193,137365239,127635702,7847275,17519876,13908831,31840780,64014230,111398802,63739760,102971782,31279966,68476275,66832766,14997684,9639726,150281339,67941598,75955219,148642633,85248894,16470339};
	
	const int inv_1=208783132;
	const int inv_12=29562547;
	
	struct Triple{
		ll a,b,c;
		Finline Triple operator + (const Triple &o)const
		{
			return (Triple){(a+o.a)%mod1,(b+o.b)%mod2,(c+o.c)%mod3};
		}
		Finline Triple operator - (const Triple &o)const
		{
			return (Triple){(a-o.a+mod1)%mod1,(b-o.b+mod2)%mod2,(c-o.c+mod3)%mod3};
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
			(a+=o.a)>=mod1&&(a-=mod1);
			(b+=o.b)>=mod2&&(b-=mod2);
			(c+=o.c)>=mod3&&(c-=mod3);
		}
		Finline void operator -= (const Triple &o)
		{
			(a-=o.a)<0&&(a+=mod1);
			(b-=o.b)<0&&(b+=mod2);
			(c-=o.c)<0&&(c+=mod3);
		}
		Finline void operator *= (const int &o)
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
		Finline int getans(int _mod)
		{
			ll x=((b-a)%mod2+mod2)*inv_1%mod2*mod1+a;
			return (((c-x)%mod3+mod3)*inv_12%mod3*mod1%_mod*mod2%_mod+x)%_mod;
		}
	};
	void DFT(Triple *a,int limit)
	{
		for(int i=0;i<limit;++i)
		{
			if(i<r[i])
			{
				swap(a[i],a[r[i]]);
			}
		}
		Triple w,Wn,tmp;
		for(int len=2,t=1;len<=limit;len<<=1,++t)
		{
			Wn=(Triple){_G1[t],_G2[t],_G3[t]};
			for(int pos=0;pos<limit;pos+=len)
			{
				w=(Triple){1,1,1};
				for(int i=pos;i<pos+(len>>1);++i,w*=Wn)
				{
					tmp=w*a[i+(len>>1)];
					a[i+(len>>1)]=a[i]-tmp;
					a[i]+=tmp;
				}
			}
		}
	}
	void IDFT(Triple *a,int limit)
	{
		for(int i=0;i<limit;++i)
		{
			if(i<r[i])
			{
				swap(a[i],a[r[i]]);
			}
		}
		Triple w,Wn,tmp;
		for(int len=2,t=1;len<=limit;len<<=1,++t)
		{
			Wn=(Triple){_Gi1[t],_Gi2[t],_Gi3[t]};
			for(int pos=0;pos<limit;pos+=len)
			{
				w=(Triple){1,1,1};
				for(int i=pos;i<pos+(len>>1);++i,w*=Wn)
				{
					tmp=w*a[i+(len>>1)];
					a[i+(len>>1)]=a[i]-tmp;
					a[i]+=tmp;
				}
			}
		}
		Triple inv=(Triple){ksm(limit,mod1-2,mod1),ksm(limit,mod2-2,mod2),ksm(limit,mod3-2,mod3)};
		for(int i=0;i<limit;++i)
		{
			a[i]*=inv;
		}
	}
	void brute(int *a,int *b,int *c,int n,int m,int mod)
	{
		static int f[205],g[205];
		memcpy(f,a,4*n);
		memcpy(g,b,4*m);
		memset(c,0,4*(n+m-1));
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				(c[i+j]+=1ll*f[i]*g[j]%mod)>=mod&&(c[i+j]-=mod);
			}
		}
	}
	void brute(int *a,int *b,int *c,int *d,int n,int m,int p,int mod)
	{
		static int f[205],g[205],q[205];
		memcpy(f,a,4*n);
		memcpy(g,b,4*m);
		memcpy(q,c,4*p);
		memset(d,0,4*(n+m+p-2));
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				for(int k=0;k<p;++k)
				{
					(d[i+j+k]+=1ll*f[i]*g[j]%mod*q[k]%mod)>=mod&&(d[i+j+k]-=mod);
				}
			}
		}
	}
	void poly_mul(int *a,int *b,int *c,int n,int m,int _mod)
	{
		if(n+m<=100)
		{
			brute(a,b,c,n,m,_mod);
			return;
		}
		static Triple f[N],g[N];
		int limit=init(n+m);
		for(int i=0;i<n;++i)
		{
			f[i]=(Triple){a[i],a[i],a[i]};
		}
		memset(f+n,0,sizeof(Triple)*(limit-n));
		for(int i=0;i<m;++i)
		{
			g[i]=(Triple){b[i],b[i],b[i]};
		}
		memset(g+m,0,sizeof(Triple)*(limit-m));
		DFT(f,limit);
		DFT(g,limit);
		for(int i=0;i<limit;++i) f[i]=f[i]*g[i];
		IDFT(f,limit);
		for(int i=0;i<n+m-1;++i)
		{
			c[i]=f[i].getans(_mod);
		}
	}
	void poly_mul(int *a,int *b,int *c,int *d,int n,int m,int p,int _mod)
	{
		if(n+m+p<=100)
		{
			brute(a,b,c,d,n,m,p,_mod);
			return;
		}
		static Triple f[N],g[N],q[N];
		int limit=init(n+m+p);
		for(int i=0;i<n;++i)
		{
			f[i]=(Triple){a[i],a[i],a[i]};
		}
		memset(f+n,0,sizeof(Triple)*(limit-n));
		for(int i=0;i<m;++i)
		{
			g[i]=(Triple){b[i],b[i],b[i]};
		}
		memset(g+m,0,sizeof(Triple)*(limit-m));
		for(int i=0;i<p;++i)
		{
			q[i]=(Triple){c[i],c[i],c[i]};
		}
		memset(q+p,0,sizeof(Triple)*(limit-p));
		DFT(f,limit);
		DFT(g,limit);
		DFT(q,limit);
		for(int i=0;i<limit;++i) f[i]=f[i]*g[i]*q[i];
		IDFT(f,limit);
		for(int i=0;i<n+m+p-2;++i)
		{
			d[i]=f[i].getans(_mod);
		}
	}
	void poly_inv(int *a,int *b,int n)
	{
		static int f[N],t[N],ans[N];
		int limit=1;
		while(limit<n) limit<<=1;
		memcpy(f,a,4*n);
		memset(f+n,0,4*(limit-n));
		memset(ans,0,4*(limit));
		ans[0]=ksm(f[0]);
		for(int len=2;len<=limit;len<<=1)
		{
			poly_mul(ans,ans,f,t,len>>1,len>>1,len);
			for(int i=len>>1;i<len;++i)
			{
				ans[i]=((ans[i]<<1)-t[i]+mod)%mod;
			}
		}
		memcpy(b,ans,4*n);
	}
	void poly_div(int *a,int *b,int *c,int *d,int n,int m)
	{
		static int f[N],g[N];
		memset(f,0,4*(n+m));
		memset(g,0,4*(n+m));
		
		reverse(a,f,n);
		reverse(b,g,m);
		poly_inv(g,g,n-m+1);
		poly_mul(f,g,f,n-m+1,n-m+1);
		reverse(f,c,n-m+1);
		
		poly_mul(b,c,g,m,n-m+1);
		for(int i=0;i<m-1;++i)
		{
			d[i]=(a[i]-g[i]+mod)%mod;
		}
	}
	void poly_sqrt(int *a,int *b,int n)
	{
		static int f[N],t[N],ans[N];
		int limit=1;
		while(limit<n) limit<<=1;
		memcpy(f,a,4*n);
		memset(f+n,0,4*(limit-n));
		memset(ans,0,4*(limit));
		ans[0]=1;
		for(int len=2;len<=limit;len<<=1)
		{
			poly_inv(ans,t,len);
			poly_mul(f,t,t,len,len);
			for(int i=len>>1;i<len;++i)
			{
				ans[i]=1ll*(t[i]+ans[i])*inv2%mod;
			}
		}
		memcpy(b,ans,4*n);
	}
	void poly_ln(int *a,int *b,int n)
	{
		static int t[N],ans[N];
		derivative(a,t,n);
		poly_inv(a,ans,n);
		poly_mul(t,ans,ans,n-1,n);
		integral(ans,b,n);
	}
	void poly_exp(int *a,int *b,int n)
	{
		static int f[N],t[N],ans[N];
		int limit=1;
		while(limit<n) limit<<=1;
		memcpy(f,a,4*n);
		memset(f+n,0,4*(limit-n));
		memset(ans,0,4*(limit));
		ans[0]=1;
		for(int len=2;len<=limit;len<<=1)
		{
			poly_ln(ans,t,len);
			for(int i=0;i<len;++i)
			{
				t[i]=(f[i]-t[i]+mod)%mod;
			}
			add(t[0],1);
			poly_mul(t,ans,ans,len,len>>1);
			memset(ans+len,0,4*(len+2));
		}
		memcpy(b,ans,4*n);
	}
	void poly_ksm(int *a,int *b,int k,int n)
	{
		static int t[N];
		poly_ln(a,t,n);
		for(int i=0;i<n;++i) t[i]=1ll*t[i]*k%mod;
		poly_exp(t,b,n);
	}
}
using namespace poly;
int a[N],b[N],c[N];
int main()
{
	int n,m;
	read(n,m);
	++m;
	int x;
	for(int i=1;i<=n;++i)
	{
		read(x);
		a[x]=mod-4;
	}
	a[0]=1;
	poly_sqrt(a,b,m);
	add(b[0],1);
	poly_inv(b,c,m);
	for(int i=1;i<m;++i) printf("%d\n",(c[i]<<1)%mod);
    return 0;
}