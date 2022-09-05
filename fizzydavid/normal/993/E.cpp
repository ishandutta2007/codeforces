//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}

/*
	Template: Polynomial V2(Simplified)
	Author: FizzyDavid
	Last edit: 2018/05/28
*/
//Settings
//#define useNTT //if you use the NTT head
const ll mod=1e18;
const int proot=3;//for NTT only
const int FFTbitn=20;
const int FFTpmx=1<<FFTbitn;
const int FFTmx=FFTpmx+233;
const int FFTbit=15;//for FFT only  max_value=2^(2*FFTbit)
const int comb_mx=FFTmx;

//Prerequisite
typedef unsigned long long ull;
ll qpow(ll x,ll k){return k==0?1:qpow(x*x%mod,k>>1)*(k&1?x:1)%mod;}
const double pi=acos(-1);
struct point
{
	double x,y;
	point(double _x=0,double _y=0){x=_x;y=_y;}
	point operator+(const point &t)const{return point(x+t.x,y+t.y);}
	point operator-(const point &t)const{return point(x-t.x,y-t.y);}
	point operator*(const point &t)const{return point(x*t.x-y*t.y,x*t.y+y*t.x);}
	point conj()const{return point(x,-y);}
};

//Comb
ll inv[comb_mx],fac[comb_mx],ifac[comb_mx];
void comb_init()
{
	assert(comb_mx<=mod);
	fac[0]=1;
	for(int i=1;i<comb_mx;i++)fac[i]=fac[i-1]*i%mod;
	ifac[comb_mx-1]=qpow(fac[comb_mx-1],mod-2);
	for(int i=comb_mx-2;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
	inv[1]=1;
	for(int i=2;i<comb_mx;i++)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
}

//FFT
int fsz;
int uptopow(int x){while(x!=(x&(-x)))x+=x&(-x);return x;}
void FFTinit(int sz){fsz=uptopow(sz);assert(fsz<=FFTpmx);}
void FFTprecalc();
#ifdef useNTT
void FFT(int a[],int coef);
#else
void FFT(point a[],int coef);
#endif

//Mul
void polymul(ll a[],int an,ll b[],int bn,ll c[],int cn);

//Basic
void polyclear(int a[],int n){for(int i=0;i<n;i++)a[i]=0;}
void polyclear(int a[],int l,int r){for(int i=l;i<r;i++)a[i]=0;}

void polyset(int a[],int an,int b[],int bn){for(int i=0;i<bn;i++)b[i]=i<an?a[i]:0;}

void polyadd(int a[],int an,int b[],int bn,int c[],int cn){for(int i=0;i<cn;i++)c[i]=((i<an?a[i]:0)+(i<bn?b[i]:0))%mod;}
void polyadd(int a[],int b[],int c[],int sz){polyadd(a,sz,b,sz,c,sz);}

void polysub(int a[],int an,int b[],int bn,int c[],int cn){for(int i=0;i<cn;i++)c[i]=((i<an?a[i]:0)-(i<bn?b[i]:0)+mod)%mod;}
void polysub(int a[],int b[],int c[],int sz){polysub(a,sz,b,sz,c,sz);}

void polyaddinv(int a[],int an,int b[],int bn){for(int i=0;i<bn;i++)b[i]=(mod-(i<an?a[i]:0))%mod;}
void polyaddinv(int a[],int n,int b[]){polyaddinv(a,n,b,n);}
void polyaddinv(int a[],int n){polyaddinv(a,n,a,n);}

void polymulnum(int a[],int an,int b,int c[],int cn){for(int i=0;i<cn;i++)c[i]=1ll*(i<an?a[i]:0)*b%mod;}
void polymulnum(int a[],int b,int c[],int n){polymulnum(a,n,b,c,n);}
void polymulnum(int a[],int b,int n){polymulnum(a,n,b,a,n);}

int n;
int a[200111],X;
ll A[FFTmx],B[FFTmx];
ll ANS[FFTmx];
int main()
{
	FFTprecalc();
	comb_init();
	getii(n,X);
	ANS[0]=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		geti(x);
		a[i]=a[i-1]+(x<X);
	}
	int pre=a[1]!=a[0];
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			ANS[0]+=1ll*(i-pre)*(i-pre-1)/2;
			pre=i;
		}
	}
	ANS[0]+=1ll*(n+1-pre)*(n+1-pre-1)/2;
	
	for(int i=0;i<=n;i++)
	{
		A[a[i]+n]++;
	}
	for(int i=0;i<=n;i++)
	{
		B[-a[i]+n]++;
	}
	polymul(A,n+n+1,B,n+n+1,A,n+n+n+1);
	for(int i=1;i<=n;i++)
	{
		ANS[i]=A[n+n+i];
	}
	for(int i=0;i<=n;i++)puti(ANS[i]);
	return 0;
}

//===========================================================================

//Head
#ifdef useNTT
	int w_pre[FFTmx];
	void FFTprecalc()
	{
		w_pre[0]=1;
		int ww=qpow(proot,(mod-1)/FFTpmx);
		for(int i=1;i<=FFTpmx;i++)w_pre[i]=1ll*w_pre[i-1]*ww%mod;
	}
	void FFT(int a[],int coef)
	{
		static ull f_a[FFTmx];
		static int w[FFTmx];
		for(int i=0,j=0;i<fsz;i++)
		{
			f_a[j]=a[i]<0?a[i]+mod:a[i];
			for(int l=fsz>>1;(j^=l)<l;l>>=1);
		}
		const ull md2=1ull*mod*mod;
		for(int l=1;l<fsz;l<<=1)
		{
			int l2=l<<1,u=FFTpmx/l2;
			if(coef==1)for(int j=0,j2=0;j<l;j++,j2+=u)w[j]=w_pre[j2];
			else for(int j=0,j2=FFTpmx;j<l;j++,j2-=u)w[j]=w_pre[j2];
			for(int i=0;i<fsz;i+=l2)
			{
				for(int j=0;j<l;j++)
				{
					ull tmp=f_a[i+j+l]%mod*w[j];
					f_a[i+j+l]=f_a[i+j]+md2-tmp;
					f_a[i+j]+=tmp;
				}
			}
			if(l==(1<<16))for(int j=0;j<fsz;j++)f_a[j]%=mod;
		}
		for(int i=0;i<fsz;i++)a[i]=f_a[i]%mod;
		if(coef==-1)
		{
			int inv=qpow(fsz,mod-2);
			for(int i=0;i<fsz;i++)a[i]=1ll*a[i]*inv%mod;
		}
	}
	void polymul(int a[],int an,int b[],int bn,int c[],int cn=-1)
	{
		static int mul_a[FFTmx],mul_b[FFTmx];
		if(cn==-1)cn=an+bn;
		an=min(an,cn);bn=min(bn,cn);
		if(1ll*an*bn<=4096)
		{
			for(int i=0;i<an+bn;i++)mul_a[i]=0;
			for(int i=0;i<an;i++)
				for(int j=0;j<bn;j++)
					mul_a[i+j]=(mul_a[i+j]+1ll*a[i]*b[j])%mod;
			for(int i=0;i<cn;i++)c[i]=mul_a[i];
			return;
		}
		FFTinit(an+bn);
		for(int i=0;i<fsz;i++)mul_a[i]=i<an?a[i]:0;
		for(int i=0;i<fsz;i++)mul_b[i]=i<bn?b[i]:0;
		FFT(mul_a,1);
		FFT(mul_b,1);
		for(int i=0;i<fsz;i++)mul_a[i]=1ll*mul_a[i]*mul_b[i]%mod;
		FFT(mul_a,-1);
		for(int i=0;i<cn;i++)c[i]=mul_a[i];
	}
#else
	point w_pre[FFTmx];
	void FFTprecalc()
	{
		for(int i=0;i<=FFTpmx;i++)w_pre[i]=point(cos(2.0/FFTpmx*i*pi),sin(2.0/FFTpmx*i*pi));
	}
	void FFT(point a[],int coef)
	{
		static point w[FFTmx];
		for(int i=0,j=0;i<fsz;i++)
		{
			if(i<j)swap(a[i],a[j]);
			for(int l=fsz>>1;(j^=l)<l;l>>=1);
		}
		for(int l=1;l<fsz;l<<=1)
		{
			int l2=l<<1,u=FFTpmx/l2;
			if(coef==1)for(int j=0,j2=0;j<l;j++,j2+=u)w[j]=w_pre[j2];
			else for(int j=0,j2=FFTpmx;j<l;j++,j2-=u)w[j]=w_pre[j2];
			for(int i=0;i<fsz;i+=l2)
			{
				for(int j=0;j<l;j++)
				{
					point tmp=a[i+l+j]*w[j];
					a[i+l+j]=a[i+j]-tmp;
					a[i+j]=a[i+j]+tmp;
				}
			}
		}
		if(coef==-1)
		{
			for(int i=0;i<fsz;i++)a[i]=a[i]*(1.0/fsz);
		}
	}
	void polymul(ll a[],int an,ll b[],int bn,ll c[],int cn=-1)
	{
		static point tl[FFTmx],tr[FFTmx],ta[FFTmx],tb[FFTmx];
		if(cn==-1)cn=an+bn;
		an=min(an,cn);bn=min(bn,cn);
		FFTinit(an+bn);
		int msk=(1<<FFTbit)-1;
		for(int i=0;i<fsz;i++)
		{
			ta[i]=i<an?point((a[i]>=0?a[i]:a[i]+mod)&msk,(a[i]>=0?a[i]:a[i]+mod)>>FFTbit):0;
			tb[i]=i<bn?point((b[i]>=0?b[i]:b[i]+mod)&msk,(b[i]>=0?b[i]:b[i]+mod)>>FFTbit):0;
		}
		FFT(ta,1);ta[fsz]=ta[0];
		FFT(tb,1);tb[fsz]=tb[0];
		for(int i=0;i<fsz;i++)
		{
			point a0=(ta[i]+ta[fsz-i].conj())*point(+0.5,0),a1=(ta[i]-ta[fsz-i].conj())*point(0,-0.5);
			point b0=(tb[i]+tb[fsz-i].conj())*point(+0.5,0),b1=(tb[i]-tb[fsz-i].conj())*point(0,-0.5);
			tl[i]=a0*b0+a0*b1*point(0,1);
			tr[i]=a1*b0+a1*b1*point(0,1);
		}
		FFT(tl,-1);
		FFT(tr,-1);
		for(int i=0;i<fsz;i++)
		{
			c[i]=(ll(tl[i].x+0.5)+
			    ((ll(tr[i].y+0.5)%mod)<<(FFTbit+FFTbit))+
		       (((ll(tl[i].y+0.5)+ll(tr[i].x+0.5))%mod)<<FFTbit))%mod;
		}
	}
#endif