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
const int mod=998244353;
const int proot=3;
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
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}

int n,g[50111],g0[50111],g1[50111],g2[50111];
int f0[50111],f1[50111],f2[50111];

const int FFTmx=150111;
const int FFTpmx=131072;
int bitrev_pre[FFTmx],bitrev[FFTmx],fsz;
int w_pre[FFTmx],w[FFTmx];
void FFTinit(int sz)
{
	fsz=1;
	while(fsz<sz)fsz<<=1;
	int tmp=__builtin_ctz(FFTpmx/fsz);
	for(int i=0;i<fsz;i++)bitrev[i]=bitrev_pre[i]>>tmp;
}
ll qpow(ll x,ll k){return k==0?1:qpow(x*x%mod,k>>1)*(k&1?x:1)%mod;}
void FFT(int a[],int coef)
{
	for(int i=0;i<fsz;i++)if(i<bitrev[i])swap(a[i],a[bitrev[i]]);
	for(int l=1;l<fsz;l<<=1)
	{
		int l2=l+l,u=FFTpmx/l2;
		if(coef==1)for(int j=0;j<l;j++)w[j]=w_pre[u*j];
		else for(int j=0;j<l;j++)w[j]=w_pre[FFTpmx-u*j];
		for(int i=0;i<fsz;i+=l2)
		{
			for(int j=0;j<l;j++)
			{
				int tmp=1ll*a[i+l+j]*w[j]%mod;
				a[i+l+j]=a[i+j]-tmp<0?a[i+j]-tmp+mod:a[i+j]-tmp;
				a[i+j]=a[i+j]+tmp>=mod?a[i+j]+tmp-mod:a[i+j]+tmp;
			}
		}
	}
	if(coef==-1)
	{
		ll inv=qpow(fsz,mod-2);
		for(int i=0;i<fsz;i++)a[i]=a[i]*inv%mod;
	}
}
void FFTprecalc()
{
	for(int i=1;i<FFTpmx;i++)bitrev_pre[i]=bitrev_pre[i>>1]>>1|(i&1?FFTpmx>>1:0);
	w_pre[0]=1;
	int ww=qpow(proot,(mod-1)/FFTpmx);
	for(int i=1;i<=FFTpmx;i++)w_pre[i]=1ll*w_pre[i-1]*ww%mod;
}
int ta[FFTmx],tb[FFTmx],tc[FFTmx];
void push(int a[],int asz,int b[],int bsz,int c[],int cl,int cr)
{
	FFTinit(asz+bsz);
	for(int i=0;i<fsz;i++)ta[i]=i<asz?a[i]:0;
	for(int i=0;i<fsz;i++)tb[i]=i<bsz?b[i]:0;
	FFT(ta,1);
	FFT(tb,1);
	for(int i=0;i<fsz;i++)tc[i]=1ll*ta[i]*tb[i]%mod;
	FFT(tc,-1);
	assert(cr<=fsz);
	for(int i=cl;i<=cr;i++)c[i]=c[i]+tc[i]>=mod?c[i]+tc[i]-mod:c[i]+tc[i];
}
void solve(int l,int r)
{
//	cerr<<"solve:"<<l<<","<<r<<endl;
	if(r-l<=500)
	{
		for(int i=l;i<=r;i++)
		{
			for(int j=l;j<i;j++)
			{
				f0[i]=(f0[i]+1ll*f0[j]*g0[i-j]+1ll*f1[j]*g1[i-j])%mod;
				f1[i]=(f1[i]+1ll*f0[j]*g1[i-j]+1ll*f1[j]*g2[i-j])%mod;
				f2[i]=(f2[i]+1ll*f2[j]*g2[i-j]+1ll*f1[j]*g1[i-j])%mod;
			}
			f0[i]=(f0[i]+g0[i])%mod;
			f1[i]=(f1[i]+g1[i])%mod;
			f2[i]=(f2[i]+g2[i])%mod;
		}
		return;
	}
	int m=l+r>>1;
	solve(l,m);
	push(f0+l,m+1-l,g0,r+1-l,f0+l,m+1-l,r-l);
	push(f1+l,m+1-l,g1,r+1-l,f0+l,m+1-l,r-l);
	push(f0+l,m+1-l,g1,r+1-l,f1+l,m+1-l,r-l);
	push(f1+l,m+1-l,g2,r+1-l,f1+l,m+1-l,r-l);
	push(f2+l,m+1-l,g2,r+1-l,f2+l,m+1-l,r-l);
	push(f1+l,m+1-l,g1,r+1-l,f2+l,m+1-l,r-l);
	solve(m+1,r);
}
int main()
{
	FFTprecalc();
	cin>>n;
//	n=50000;
	g[0]=g[2]=1;
	for(int i=4;i<=n;i+=2)g[i]=(g[i-2]+g[i-4])%mod;
	for(int i=1;i<=n;i++)
	{
		g0[i+1]=1ll*g[i]*i*i%mod;
		g1[i+1]=1ll*g[i-1]*i*i%mod;
		if(i>=2)g2[i+1]=1ll*g[i-2]*i*i%mod;
	}
	solve(0,n);
	ll ans=0;
	ans=1ll*(g[n-1]+g[n-3])*n%mod*(n-1)%mod*(n-1)%mod;
	for(int i=2;i<n;i++)
	{
		int l=i,r=n-i;
		ll curans=0;
		curans+=1ll*g[l-1]*f0[r]%mod;
		curans+=1ll*g[l-2]*f1[r]%mod;
		curans+=1ll*g[l-2]*f1[r]%mod;
		if(l>=3)curans+=1ll*g[l-3]*f2[r]%mod;
		curans=curans%mod*(i-1)%mod*(i-1)%mod;
		ans+=1ll*curans*i%mod;
	}
	cout<<ans%mod<<endl;
	return 0;
}