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
int mod;

const int FFTpsz=1<<19;
const int FFTmx=FFTpsz+233;
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int FFTsz;
const double pi=acos(-1);
struct point
{
	double x,y;
	point(double X=0,double Y=0){x=X;y=Y;}
	point operator+(const point &t)const{return point(x+t.x,y+t.y);}
	point operator-(const point &t)const{return point(x-t.x,y-t.y);}
	point operator*(const point &t)const{return point(x*t.x-y*t.y,x*t.y+y*t.x);}
	point operator*(const double &t)const{return point(x*t,y*t);}
	point conj()const{return point(x,-y);}
};
point w_pre[FFTmx];
int uptopow(int n)
{
	int ret=1;
	while(ret<n)ret<<=1;
	return ret;
}
void FFTprecalc()
{
	for(int i=0;i<=FFTpsz;i++)w_pre[i]=point(cos(2*pi/FFTpsz*i),sin(2*pi/FFTpsz*i));
}
void FFTinit(int n)
{
	FFTsz=uptopow(n);
}
void FFT(point a[],int coef)
{
	for(int i=0,j=0;i<FFTsz;i++)
	{
		if(i<j)swap(a[i],a[j]);
		for(int t=FFTsz>>1;(j^=t)<t;t>>=1);
	}
	static point w[FFTmx];
	for(int l=1;l<FFTsz;l<<=1)
	{
		int l2=l<<1;
		if(coef==1)for(int j=0;j<l;j++)w[j]=w_pre[FFTpsz/l2*j];
		else for(int j=0;j<l;j++)w[j]=w_pre[FFTpsz-FFTpsz/l2*j];
		for(int i=0;i<FFTsz;i+=l2)
		{
			for(int j=0;j<l;j++)
			{
				point tmp=a[i+j+l]*w[j];
				a[i+j+l]=a[i+j]-tmp;
				a[i+j]=a[i+j]+tmp;
			}
		}
	}
	if(coef==-1)
	{
		for(int i=0;i<FFTsz;i++)a[i]=a[i]*(1.0/FFTsz);
	}
}
void FFT2(point a[],point b[],int coef)
{
	static point A[FFTmx];
	if(coef==1)
	{
		for(int i=0;i<FFTsz;i++)A[i]=point(a[i].x,b[i].x);
		FFT(A,1);
		A[FFTsz]=A[0];
		for(int i=0;i<FFTsz;i++)
		{
			a[i]=(A[i]+A[FFTsz-i].conj())*point(0.5,0);
			b[i]=(A[i]-A[FFTsz-i].conj())*point(0,-0.5);
		}
	}
	else
	{
		for(int i=0;i<FFTsz;i++)A[i]=a[i]+b[i]*point(0,1);
		FFT(A,-1);
		for(int i=0;i<FFTsz;i++)a[i]=point(A[i].x,0),b[i]=point(A[i].y,0);
	}
}
void polymul(int a[],int an,int b[],int bn,int c[],int cn,int md)
{
	mod=md;
	if(1ll*an*bn<10000)
	{
		static int mul_t[FFTmx];
		for(int i=0;i<cn;i++)mul_t[i]=0;
		for(int i=0;i<an;i++)
		{
			for(int j=0;j<bn&&i+j<cn;j++)
			{
				mul_t[i+j]=(mul_t[i+j]+1ll*a[i]*b[j])%mod;
			}
		}
		for(int i=0;i<cn;i++)c[i]=(mul_t[i]%mod+mod)%mod;
		return;
	}
	static point mul_a0[FFTmx],mul_a1[FFTmx];
	static point mul_b0[FFTmx],mul_b1[FFTmx];
	FFTinit(an+bn);
	for(int i=0;i<FFTsz;i++)mul_a0[i]=point(i<an?((a[i]%mod+mod)%mod)&32767:0,0);
	for(int i=0;i<FFTsz;i++)mul_a1[i]=point(i<an?((a[i]%mod+mod)%mod)>>15:0,0);
	for(int i=0;i<FFTsz;i++)mul_b0[i]=point(i<bn?((b[i]%mod+mod)%mod)&32767:0,0);
	for(int i=0;i<FFTsz;i++)mul_b1[i]=point(i<bn?((b[i]%mod+mod)%mod)>>15:0,0);	
	FFT2(mul_a0,mul_a1,1);
	FFT2(mul_b0,mul_b1,1);
	for(int i=0;i<FFTsz;i++)
	{
		point t0=mul_a0[i]*mul_b0[i];
		point t1=mul_a0[i]*mul_b1[i]+mul_a1[i]*mul_b0[i];
		point t2=mul_a1[i]*mul_b1[i];
		mul_a0[i]=t0;
		mul_a1[i]=t1;
		mul_b0[i]=t2;
	}
	FFT2(mul_a0,mul_a1,-1);
	FFT(mul_b0,-1);
	for(int i=0;i<cn;i++)
	{
		if(i<FFTsz)
		{
			ll t0=ll(mul_a0[i].x+0.5)%mod;
			ll t1=ll(mul_a1[i].x+0.5)%mod;
			ll t2=ll(mul_b0[i].x+0.5)%mod; 
			c[i]=((t0+(t1<<15)+(t2<<30))%mod+mod)%mod;
		}
		else c[i]=0;
	}
}
void CZT(int a[],int N,int w,int md,int coef)//here w should be the sqrt of original w  md should be prime
{
	mod=md;
	if(coef==-1)w=qpow(w,mod-2);
	static int CZT_f[FFTmx],CZT_g[FFTmx],CZT_a[FFTmx];
	for(int i=0;i<N;i++)CZT_f[i]=1ll*a[i]%mod*qpow(w,1ll*i*i%(mod-1))%mod;
	for(int i=0;i<N+N;i++)CZT_g[i]=qpow(w,mod-1-1ll*(N-i)*(N-i)%(mod-1))%mod;
	polymul(CZT_f,N,CZT_g,N+N,CZT_a,N+N,mod);
	for(int i=0;i<N;i++)a[i]=1ll*qpow(w,1ll*i*i%(mod-1))*(CZT_a[i+N])%mod;
	if(coef==-1)
	{
		ll inv=qpow(N,mod-2);
		for(int i=0;i<N;i++)a[i]=a[i]*inv%mod;
	}
}
bool isp(int x)
{
	for(int i=2;1ll*i*i<=x;i++)if(x%i==0)return false;
	return true;
}
pair<int,int> calc_mod(int l)
{
	int md=l+1;
	while(md<2333333||!isp(md))md+=l;
	mod=md;
	for(int pr=2;pr<md;pr++)
	{
		bool ok=1;
		for(int j=2;j<=md-1;j++)
		{
			j=(md-1)/((md-1)/j);
			if((md-1)%j==0)
			{
				if(qpow(pr,(md-1)/j)==1)
				{
					ok=0;
					break;
				}
			}
		}
		if(ok)return MP(pr,md);
	}
	assert(false);
}
int n,b0[FFTmx];
int b[FFTmx],c[FFTmx],da[FFTmx],dc[FFTmx],sa[FFTmx];
int main()
{
	FFTprecalc();
	geti(n);
	for(int i=0;i<n;i++)geti(b0[i]);
	for(int i=0;i<n;i++)b[i]=b0[(n-i)%n];
	for(int i=0;i<n;i++)geti(c[i]);c[n]=c[0];
	for(int i=0;i<n;i++)dc[i]=(c[i+1]-c[i])/(-2);
	pair<int,int> pp=calc_mod(2*n);
	int w=pp.FF,md=pp.SS;
//	cerr<<"w="<<w<<" md="<<md<<endl;
	mod=md;
	w=qpow(w,(md-1)/2/n);
	CZT(dc,n,w,md,1);
	CZT(b,n,w,md,1);
	for(int i=0;i<n;i++)da[i]=1ll*dc[i]*qpow(b[i],mod-2)%mod;
	CZT(da,n,w,md,-1);
	for(int i=0;i<n;i++)
	{
		if(da[i]>mod/2)da[i]=da[i]-mod;
	}
//	cerr<<"da:"<<endl;
//	for(int i=0;i<n;i++)cerr<<da[i]<<" ";cerr<<endl;
	for(int i=1;i<n;i++)
	{
		sa[i]=sa[i-1]+da[i-1];
		if(sa[i]<-5000||sa[i]>5000)
		{
			puts("0");
			return 0;
		}
	}
	ll C2=0,C1=0,C0=-c[0];
	for(int i=0;i<n;i++)
	{
		ll tmp=b0[i]-sa[i];
		C2++;
		C1+=(-2)*tmp;
		C0+=tmp*tmp;
	}
	vector<int> v;
	for(int i=-5000;i<=5000;i++)if(C2*i*i+C1*i+C0==0)v.PB(i);
	putsi(v.size());
	for(int i=0;i<v.size();i++)
	{
		puti(v[i]);
		for(int j=1;j<n;j++)puti(v[i]+sa[j]);
		puts("");
	}
	return 0;
}