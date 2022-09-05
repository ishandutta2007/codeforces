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


//Template: Polynomial
//Author: FizzyDavid
//Last edit: 2018/04/17
/*
You should INITIALIZE with comb_init() and FFTprecalc() before you use the polynomial functions.
Mod should be prime.
You should choose NTT head or FFT head.
The input numbers should be in range (-mod,mod).
The result nubmers are in range (-mod,mod).
*/
const int mod=998244353;
ll qpow(ll x,ll k){return k==0?1:qpow(x*x%mod,k>>1)*(k&1?x:1)%mod;}


const int proot=3;//for NTT only
const int FFTbitn=18;
const int FFTpmx=1<<FFTbitn;
const int FFTmx=FFTpmx+233;//should be slightly larger than FFTpmx
const int FFTbit=15;//for FFT only  max_value=2^(2*FFTbit)
#define useNTT //if you use the NTT head

const int comb_mx=FFTmx;
ll inv[comb_mx],fac[comb_mx],ifac[comb_mx];
//use comb_init() before FFT
//mod should be prime
void comb_init()
{
	fac[0]=1;
	for(int i=1;i<comb_mx;i++)fac[i]=fac[i-1]*i%mod;
	ifac[comb_mx-1]=qpow(fac[comb_mx-1],mod-2);
	for(int i=comb_mx-2;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
	inv[1]=1;
	for(int i=2;i<comb_mx;i++)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
}
int uptopow(int x)
{
	while(x!=(x&(-x)))x+=x&(-x);
	return x;
}
#ifdef useNTT
//-----------------NTT head-----------------
int fsz,w_pre[FFTmx];
void FFTinit(int sz)
{
	fsz=uptopow(sz);
	assert(fsz<=FFTpmx);
}
typedef unsigned long long ull;
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
void FFTprecalc()
{
	w_pre[0]=1;
	int ww=qpow(proot,(mod-1)/FFTpmx);
	for(int i=1;i<=FFTpmx;i++)w_pre[i]=1ll*w_pre[i-1]*ww%mod;
}
//Multiply polynomial a[0...an-1] and b[0...bn-1]  Store in c[0...cn-1]
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
//---------------NTT head end---------------
#else
//-----------------FTT head-----------------
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
int fsz;
point w_pre[FFTmx];
void FFTprecalc()
{
	for(int i=0;i<=FFTpmx;i++)w_pre[i]=point(cos(2.0/FFTpmx*i*pi),sin(2.0/FFTpmx*i*pi));
}
void FFTinit(int n)
{
	fsz=uptopow(n);
	assert(fsz<=FFTpmx);
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
//Multiply polynomial a[0...an-1] and b[0...bn-1]  Store in c[0...cn-1]
void polymul(int a[],int an,int b[],int bn,int c[],int cn=-1)
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
//---------------FTT head end---------------
#endif

//Basic operations
void dotmul(int a[],int an,int b[],int bn,int c[],int cn)
{
	for(int i=0;i<cn;i++)c[i]=1ll*(i<an?a[i]:0)*(i<bn?b[i]:0)%mod;
}
void dotmul(int a[],int b[],int c[],int sz){dotmul(a,sz,b,sz,c,sz);}

void polyadd(int a[],int an,int b[],int bn,int c[],int cn)
{
	for(int i=0;i<cn;i++)c[i]=((i<an?a[i]:0)+(i<bn?b[i]:0))%mod;
}
void polyadd(int a[],int b[],int c[],int sz){polyadd(a,sz,b,sz,c,sz);}

void polysub(int a[],int an,int b[],int bn,int c[],int cn)
{
	for(int i=0;i<cn;i++)c[i]=((i<an?a[i]:0)-(i<bn?b[i]:0)+mod)%mod;
}
void polysub(int a[],int b[],int c[],int sz){polysub(a,sz,b,sz,c,sz);}

void polyaddinv(int a[],int an,int b[],int bn)
{
	for(int i=0;i<bn;i++)b[i]=(mod-(i<an?a[i]:0))%mod;
}
void polyaddinv(int a[],int n,int b[]){polyaddinv(a,n,b,n);}
void polyaddinv(int a[],int n){polyaddinv(a,n,a,n);}

void polyclear(int a[],int n){for(int i=0;i<n;i++)a[i]=0;}
void polyclear(int a[],int l,int r){for(int i=l;i<r;i++)a[i]=0;}

void polyset(int a[],int an,int b[],int bn){for(int i=0;i<bn;i++)b[i]=i<an?a[i]:0;}

void polymulnum(int a[],int an,int b,int c[],int cn)
{
	for(int i=0;i<cn;i++)c[i]=1ll*(i<an?a[i]:0)*b%mod;
}
void polymulnum(int a[],int b,int c[],int n){polymulnum(a,n,b,c,n);}
void polymulnum(int a[],int b,int n){polymulnum(a,n,b,a,n);}

void polydrv(int a[],int an,int b[],int bn)
{
	for(int i=0;i<bn;i++)b[i]=1ll*(i+1<an?a[i+1]:0)*(i+1)%mod;
}
void polydrv(int a[],int n,int b[]){polydrv(a,n,b,n);}
void polydrv(int a[],int n){polydrv(a,n,a,n);}

void polyitg(int a[],int an,int b[],int bn)
{
	for(int i=bn-1;i>0;i--)b[i]=1ll*(i-1<an?a[i-1]:0)*inv[i]%mod;
	b[0]=0;
}
void polyitg(int a[],int n,int b[]){polyitg(a,n,b,n);}
void polyitg(int a[],int n){polyitg(a,n,a,n);}

//Calc the kth pow of a[0..an-1]  Store in b[0...bn-1]
//if an*k<=bn then O(bn log bn) else O(bn log bn log K)
void polyqpow(int a[],int an,int k,int b[],int bn=-1)
{
	if(bn==-1)bn=(an-1)*k+1;
	static int pow_ans[FFTmx],pow_x[FFTmx];
	copy(a,a+an,pow_x);
	pow_ans[0]=1;
	int ansn=1;
	while(k>0)
	{
		if(k&1)
		{
			polymul(pow_ans,ansn,pow_x,an,pow_ans);
			ansn=min(ansn+an,bn);
		}
		polymul(pow_x,an,pow_x,an,pow_x);
		an=min(an+an,bn);
		k>>=1;
	}
	for(int i=0;i<bn;i++)b[i]=i<ansn?pow_ans[i]:0;
}

//Inverse
void polyinv_s(int a[],int n,int b[])
{
	static int inv_a[FFTmx],inv_b[FFTmx];
	assert(a!=b);
	if(n==1)
	{
		assert(a[0]!=0);
		b[0]=qpow(a[0],mod-2);
		return;
	}
	int nn=n>>1;
	polyinv_s(a,nn,b);
#ifdef useNTT
	FFTinit(n+n);
	polyset(b,nn,inv_a,fsz);
	FFT(inv_a,1);
	polyset(a,n,inv_b,fsz);
	FFT(inv_b,1);
	for(int i=0;i<fsz;i++)inv_a[i]=1ll*(2ll-1ll*inv_a[i]*inv_b[i]%mod+mod)*inv_a[i]%mod;
	FFT(inv_a,-1);
	polyset(inv_a,fsz,b,n);
#else
	polymul(b,nn,a,n,inv_a,n);
	polyaddinv(inv_a,n);
	inv_a[0]=(inv_a[0]+2)%mod;
	polymul(b,nn,inv_a,n,b,n);
#endif
}
//Calculate the inverse of a[0...n-1]  a[0] SHOULDN'T BE 0   fsz>=2n
//O(n log n)
void polyinv(int a[],int an,int b[],int bn)
{
	static int inv_ta[FFTmx],inv_tb[FFTmx];
	int sz=uptopow(bn);
	polyset(a,an,inv_ta,sz);
	polyinv_s(inv_ta,sz,inv_tb);
	polyset(inv_tb,sz,b,bn);
}
void polyinv(int a[],int n,int b[]){polyinv(a,n,b,n);}
void polyinv(int a[],int n){polyinv(a,n,a,n);}

//Divide  need: Inverse
//Calc C(x)  A(x)=B(x)*C(x)+r(x)  B(x) SOULDNT'T be 0  fsz>=2(an-bn)  Store in c[0...an-bn]  return max(0,an-bn+1)
//n=an-bn  O(an+bn+nlogn) 
int polydiv(int a[],int an,int b[],int bn,int c[])
{
	static int div_a[FFTmx],div_b[FFTmx];
	int cn=an-bn+1;
	if(cn<=0)return 0;
	for(int i=0;i<bn;i++)div_b[i]=b[bn-i-1];
	polyinv(div_b,bn,div_a,cn);
	for(int i=0;i<an;i++)div_b[i]=a[an-i-1];
	polymul(div_b,cn,div_a,cn,c,cn);
	for(int i=0;i<cn-i;i++)swap(c[i],c[cn-i-1]);
	return cn;
}

//Modulo  need: Divide
//Calc r(x)  A(x)=B(x)*C(x)+r(x)  B(x) SOULDNT'T be 0  fsz>=2max(an,bn)  Store in c[0...bn-2]  return bn-1
//n=max(an-bn,bn)  O(n log n)
int polymod(int a[],int an,int b[],int bn,int c[])
{
	static int mod_a[FFTmx];
	assert(bn>0);
	int rn=bn-1;
	int cn=polydiv(a,an,b,bn,mod_a);
	polymul(mod_a,cn,b,bn,mod_a,rn);
	polysub(a,mod_a,c,rn);
	return rn;
}

//Ln  need: Inverse
//Calc ln(A(x))  a[0] SHOULD be 1   store in b[0...bn-1]
//n=bn  O(n log n)  
void polyln(int a[],int an,int b[],int bn)
{
	static int ln_a[FFTmx],ln_b[FFTmx];
	assert((a[0]%mod+mod)%mod==1);
	polydrv(a,an,ln_a,bn);
	polyinv(a,an,ln_b,bn);
	polymul(ln_a,bn,ln_b,bn,b,bn);
	polyitg(b,bn);
}
void polyln(int a[],int n,int b[]){polyln(a,n,b,n);}
void polyln(int a[],int n){polyln(a,n,a,n);}

//Exp  need: Ln
void polyexp_s(int a[],int n,int b[])
{
	static int ex_a[FFTmx];
	assert(a!=b);
	if(n==1)
	{
		assert(a[0]==0);
		b[0]=1;
		return;
	}
	int nn=n>>1;
	polyexp_s(a,nn,b);
	polyln(b,nn,ex_a,n);
	polyaddinv(ex_a,n);
	polyadd(ex_a,a,ex_a,n);
	ex_a[0]=(ex_a[0]+1)%mod;
	polymul(ex_a,n,b,nn,b,n);
}
//Calc exp(A(x))  A[0] SHOULD be 0  fsz>=2n
//O(n log n)
void polyexp(int a[],int an,int b[],int bn)
{
	static int exp_ta[FFTmx],exp_tb[FFTmx];
	int sz=uptopow(bn);
	polyset(a,an,exp_ta,sz);
	polyexp_s(exp_ta,sz,exp_tb);
	polyset(exp_tb,sz,b,bn);
}
void polyexp(int a[],int n,int b[]){polyexp(a,n,b,n);}
void polyexp(int a[],int n){polyexp(a,n,a,n);}

//Pow   need: Exp
//Calc the kth power of A(x)  Store in c[0...cn-1]
//O(n log n)
void polypow(int a[],int n,ll K,int c[],int cn)
{
	if(K==0)
	{
		for(int i=0;i<cn;i++)c[i]=0;c[0]=1;
		return;
	}
	n=min(n,cn);
	int t=0;
	while(t<n&&a[t]%mod==0)t++;
	if(1.0*t*K>10*cn||1ll*t*K>=cn)
	{
		for(int i=0;i<cn;i++)c[i]=0;
		return;
	}
	static int pow_a[FFTmx];
	polyset(a+t,n-t,pow_a,cn-t);
	int sz=cn-t;
	ll coef=pow_a[0];
	polymulnum(pow_a,sz,qpow(coef,mod-2),pow_a,sz);
	polyln(pow_a,sz);
	polymulnum(pow_a,sz,K%mod,pow_a,sz);
	polyexp(pow_a,sz);
	polymulnum(pow_a,sz,qpow(coef,K),pow_a,sz);
	ll cnt0=t*K;
	polyclear(c,cnt0);
	polyset(pow_a,sz,c+cnt0,cn-cnt0);
}

//Sqrt  need: Inverse
void polysqrt_s(int a[],int n,int b[])
{
	static int sqrt_a[FFTmx];
	assert(a!=b);
	if(n==1)
	{
		assert((a[0]%mod+mod)%mod==1);
		b[0]=1;
		return;
	}
	int nn=n>>1;
	polysqrt_s(a,nn,b);
	polyinv(b,nn,sqrt_a,n);
	polymul(sqrt_a,n,a,n,sqrt_a,n);
	polyadd(b,nn,sqrt_a,n,sqrt_a,n);
	polymulnum(sqrt_a,n,qpow(2,mod-2),b,n);
}
//Calc sqrt(A(x))  A[0] SHOULD be 1   fsz>=2n
//O(n log n)
void polysqrt(int a[],int an,int b[],int bn)
{
	static int sqrt_ta[FFTmx],sqrt_tb[FFTmx];
	int sz=uptopow(bn);
	polyset(a,an,sqrt_ta,sz);
	polysqrt_s(sqrt_ta,sz,sqrt_tb);
	polyset(sqrt_tb,sz,b,bn);
}
void polysqrt(int a[],int n,int b[]){polysqrt(a,n,b,n);}
void polysqrt(int a[],int n){polysqrt(a,n,a,n);}

//Evaluate  need: Modulo
int ev_tab[FFTbitn][FFTmx<<1];
int ev_ans[FFTbitn][FFTmx<<1];
void eval_prework(int lv,int a[],int l,int r)
{
	assert(lv<FFTbitn);
	if(l==r)
	{
		ev_tab[lv][l*2]=mod-a[l]%mod;
		ev_tab[lv][l*2+1]=1;
		return;
	}
	int m=l+r>>1;
	eval_prework(lv+1,a,l,m);
	eval_prework(lv+1,a,m+1,r);
	polymul(ev_tab[lv+1]+l*2,m-l+2,ev_tab[lv+1]+(m+1)*2,r-(m+1)+2,ev_tab[lv]+l*2,r-l+2);
}
void eval_solve(int lv,int a[],int an,int l,int r,int ans[])
{
	assert(lv<FFTbitn);
	int sz=polymod(a,an,ev_tab[lv]+l*2,r-l+2,ev_ans[lv]+l);
	if(l==r)
	{
		ans[l]=ev_ans[lv][l];
		return;
	}
	int m=l+r>>1;
	eval_solve(lv+1,ev_ans[lv]+l,sz,l,m,ans);
	eval_solve(lv+1,ev_ans[lv]+l,sz,m+1,r,ans);
}
//Evaluate A with size n at points b_i (0<=i<m) and store in c
void polyeval(int a[],int n,int b[],int m,int c[])
{
	eval_prework(0,b,0,m-1);
	eval_solve(0,a,n,0,m-1,c);
}

//Interpolate   need: Evaluate
int it_f[FFTmx],it_c[FFTmx];
int it_ta[FFTmx],it_tb[FFTmx];
void itpl_solve(int lv,int c[],int l,int r,int a[])
{
	if(l==r)
	{
		a[l]=1ll*qpow(it_c[l],mod-2)*c[l]%mod;
		return;
	}
	int m=l+r>>1;
	itpl_solve(lv+1,c,l,m,a);
	itpl_solve(lv+1,c,m+1,r,a);
	polymul(a+l,m+1-l,ev_tab[lv+1]+(m+1)*2,r-(m+1)+2,it_ta,r-l+1);
	polymul(a+m+1,r-m,ev_tab[lv+1]+l*2,m-l+2,it_tb,r-l+1);
	polyadd(it_ta,it_tb,a+l,r-l+1);
}
//Interpolate A with n points (b_i,c_i) (0<=i<n) and store in a
void polyitpl(int b[],int n,int c[],int a[])
{
	eval_prework(0,b,0,n-1);
	polydrv(ev_tab[0],n+1,it_f);
	eval_solve(0,it_f,n,0,n-1,it_c);
	itpl_solve(0,c,0,n-1,a);
}

vector<int> con[100111];
ll ANS;
int n,K;
int SZ[100111],SZ_pre[100111];
int getsz(int x,int to){return SZ_pre[to]==x?SZ[to]:n-SZ[x];}
void dfs_sz(int x,int pre=-1)
{
	SZ[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		SZ_pre[u]=x;
		dfs_sz(u,x);
		SZ[x]+=SZ[u];
	}
}
int cur_lv,cur_rt;
int dlv[100111];
int sz[100111],an,arr[100111];
void pdfs(int x,int pre=-1)
{
	dlv[x]=cur_lv+1;
	sz[x]=1;
	arr[an++]=x;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre||dlv[u]<cur_lv)continue;
		pdfs(u,x);
		sz[x]+=sz[u];
	}
}
int findrt(int x)
{
	an=0;
	pdfs(x);
	int ret=x;
	for(int i=0;i<an;i++)if(sz[arr[i]]*2>=sz[x]&&sz[arr[i]]<sz[ret])ret=arr[i];
	return ret;
}
ll ans[100111],sans[100111];

void eval_prework2(int lv,int a[],int l,int r)
{
	assert(lv<FFTbitn);
	if(l==r)
	{
		ev_tab[lv][l*2]=1;
		ev_tab[lv][l*2+1]=a[l];
		return;
	}
	int m=l+r>>1;
	eval_prework2(lv+1,a,l,m);
	eval_prework2(lv+1,a,m+1,r);
	polymul(ev_tab[lv+1]+l*2,m-l+2,ev_tab[lv+1]+(m+1)*2,r-(m+1)+2,ev_tab[lv]+l*2,r-l+2);
}
int A[FFTmx],nA[FFTmx];
void mult(int sz,int c)
{
	for(int i=0;i<=sz;i++)nA[i]=0;
	for(int i=0;i<=sz;i++)
	{
		nA[i]=(nA[i]+A[i])%mod;
		nA[i+1]=(nA[i+1]+1ll*A[i]*c)%mod;
	}
	for(int i=0;i<=sz;i++)A[i]=nA[i];
}
void divi(int sz,int c)//div cx+1
{
	for(int i=0;i<=sz;i++)nA[i]=0;
	ll inv=qpow(c,mod-2);
	for(int i=sz;i>0;i--)
	{
		ll k=A[i]*inv%mod;
		nA[i-1]=k;
		A[i-1]=(A[i-1]-k+mod)%mod;
	}
	for(int i=0;i<=sz;i++)A[i]=nA[i];
}
ll calc_arr(int a[],int sz)
{
	ll ret=0;
	for(int i=0;i<=min(K,sz);i++)
	{
		ll coef=1ll*fac[K]*ifac[K-i]%mod;
		ret=(ret+coef*a[i])%mod;
	}
	return ret;
}
ll calc(vector<int> &v)
{
	ll ret=0;
	int sz=v.size();
	if(sz==0)return 1;
	static int calc_a[FFTmx];
	for(int i=0;i<sz;i++)calc_a[i]=v[i];
	eval_prework2(0,calc_a,0,sz-1);
	ret=calc_arr(ev_tab[0],min(sz,K));
/*	memset(A,0,sizeof(A));
	cerr<<"calc:"<<endl;
	for(int i=0;i<v.size();i++)cerr<<v[i]<<" ";cerr<<endl;
	A[0]=1;
	for(int i=0;i<sz;i++)mult(sz,v[i]);
	for(int i=0;i<=sz;i++)cerr<<A[i]<<" ";cerr<<endl;
	ret=calc_arr(A,sz);
	cerr<<"ret="<<ret<<endl;*/
	return ret;
}
ll dfs(int x,int pre)
{
	ll ret=0;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre||dlv[u]<cur_lv)continue;
		ret=(ret+dfs(u,x))%mod;
	}
	static vector<int> v;
	v.clear();
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		v.PB(getsz(x,u));
	}
	ans[x]=calc(v);
	return (ret+ans[x])%mod;
}
map<int,int> mp;
void clear_ans()
{
	mp.clear();
}
int get_ans(int sz,int x)
{
	if(mp.find(x)!=mp.end())return mp[x];
	int &ret=mp[x];
	divi(sz,x);
	ret=calc_arr(A,sz);
	mult(sz,x);
	return ret;
}
void solve(int _x,int lv)
{
	cur_lv=lv;
	int rt=findrt(_x);
	dlv[rt]=lv;
	
//	cerr<<"solve:"<<rt<<" "<<lv<<endl;
//	for(int i=1;i<=n;i++)cerr<<dlv[i]<<" ";cerr<<endl;
	
	ll SUM=0;
	for(int i=0;i<con[rt].size();i++)
	{
		int u=con[rt][i];
		if(dlv[u]<lv)continue;
		sans[u]=dfs(u,rt);
		SUM=(SUM+sans[u])%mod;
	}
//	for(int i=1;i<=n;i++)cerr<<ans[i]<<" ";cerr<<endl;
	
	vector<int> v;
	for(int i=0;i<con[rt].size();i++)
	{
		int u=con[rt][i];
//		if(dlv[u]<lv)continue;
		v.PB(getsz(rt,u));
	}
	calc(v);
	int vsz=v.size();
//	cerr<<"v:"<<endl;
//	for(int i=0;i<vsz;i++)cerr<<v[i]<<" ";cerr<<endl;
	for(int i=0;i<=vsz;i++)A[i]=ev_tab[0][i];
//	cerr<<"A:"<<endl;
//	for(int i=0;i<=vsz;i++)cerr<<A[i]<<" ";cerr<<endl; 
	
	clear_ans();
	for(int i=0;i<con[rt].size();i++)
	{
		int u=con[rt][i];
		if(dlv[u]<lv)continue;
		ll cur_ans=get_ans(vsz,getsz(rt,u));
//		cerr<<u<<":"<<cur_ans<<endl;
		ANS=(ANS+sans[u]*((SUM-sans[u])*qpow(2,mod-2)%mod+mod+cur_ans)%mod)%mod;
	}
//	cerr<<"ANS="<<ANS<<endl;
	
	for(int i=0;i<con[rt].size();i++)
	{
		int u=con[rt][i];
		if(dlv[u]<lv)continue;
		solve(u,lv+1);
	}
}
int main()
{
	FFTprecalc();
	comb_init();
	getii(n,K);
	if(K==1)
	{
		cout<<(1ll*n*(n-1)/2)%mod<<endl;
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	dfs_sz(1);
	solve(1,0);
	cout<<ANS<<endl;
	return 0;
}