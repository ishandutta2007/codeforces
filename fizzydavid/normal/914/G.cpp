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
const int mod=1e9+7;
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
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
//combinatorial
void FMT(int a[],int n,int coef)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(1<<n);j++)
		{
			if(!((j>>i)&1))a[j+(1<<i)]=(a[j+(1<<i)]+(coef==1?a[j]:mod-a[j]))%mod;
		}
	}
}
void FWT(int a[],int n,int coef)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(1<<n);j++)
		{
			if(!((j>>i)&1))
			{
				int tmp=a[j+(1<<i)];
				a[j+(1<<i)]=(a[j]-a[j+(1<<i)]+mod)%mod;
				a[j]=(a[j]+tmp)%mod;
			}
		}
	}
	ll inv=qpow(1<<n,mod-2);
	if(coef==-1)for(int i=0;i<(1<<n);i++)a[i]=a[i]*inv%mod;
}
//polynomial
const int mxn=17;
const int mxsz=1<<mxn;
void FMTp(int a[][mxn+1],int n,int coef)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(1<<n);j++)
		{
			if(!((j>>i)&1))
			{
				for(int t=0;t<=n;t++)a[j+(1<<i)][t]=(a[j+(1<<i)][t]+(coef==1?a[j][t]:mod-a[j][t]))%mod;
			}
		}
	}
}
int _ta[mxsz][mxn+1],_tb[mxsz][mxn+1],_cnt1[mxsz];
void subsetconv(int a[],int b[],int c[],int n)
{
	for(int i=1;i<(1<<n);i++)_cnt1[i]=_cnt1[i-(i&(-i))]+1;
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)_ta[i][j]=_tb[i][j]=0;
		_ta[i][_cnt1[i]]=a[i];
		_tb[i][_cnt1[i]]=b[i];
	}
	FMTp(_ta,n,1);
	FMTp(_tb,n,1);
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=n;j>=0;j--)
		{
			ll sum=0;
			for(int k=0;k<=j;k++)
			{
				sum=(sum+1ll*_ta[i][k]*_tb[i][j-k])%mod;
			}
			_ta[i][j]=(sum%mod+mod)%mod;
		}
	}
	FMTp(_ta,n,-1);
	for(int i=0;i<(1<<n);i++)c[i]=_ta[i][_cnt1[i]];
}
int n;
int cnt[mxsz];
int a[mxsz];
int b[mxsz];
int c[mxsz];
struct fib
{
	ll a,b;//a+bx
	fib(ll X=0,ll Y=0){a=X;b=Y;}
	fib operator*(const fib &t)
	{
		ll x=b*t.b%mod;
		return fib((x+a*t.a)%mod,(x+b*t.a+a*t.b)%mod);
	}
	fib operator*(const int &t)
	{
		return fib((a*t)%mod,(b*t)%mod);
	}
	
	fib operator+(const fib &t){return fib((a+t.a)%mod,(b+t.b)%mod);}
	fib operator-(const fib &t){return fib((a-t.a+mod)%mod,(b-t.b+mod)%mod);}
};
fib F[mxsz];
int A[mxsz],B[mxsz],C[mxsz];
int main()
{
	F[0]=fib(1,0);F[1]=fib(0,1);
	for(int i=2;i<mxsz;i++)F[i]=F[i-1]*F[1];
	geti(n);
	for(int i=1;i<=n;i++)
	{
		int x;
		geti(x);
		cnt[x]++;
	}
	subsetconv(cnt,cnt,a,17);
	for(int i=0;i<mxsz;i++)b[i]=cnt[i];
	FWT(cnt,17,1);
	for(int i=0;i<mxsz;i++)c[i]=1ll*cnt[i]*cnt[i]%mod;
	FWT(c,17,-1);
//	for(int i=0;i<8;i++)cerr<<a[i]<<" ";cerr<<endl;
//	for(int i=0;i<8;i++)cerr<<b[i]<<" ";cerr<<endl;
//	for(int i=0;i<8;i++)cerr<<c[i]<<" ";cerr<<endl;
	
	for(int i=0;i<mxsz;i++)A[mxsz-i-1]=F[i].b*a[i]%mod;
	for(int i=0;i<mxsz;i++)B[mxsz-i-1]=F[i].b*b[i]%mod;
	for(int i=0;i<mxsz;i++)C[mxsz-i-1]=F[i].b*c[i]%mod;
	/*
	for(int i=0;i<8;i++)cerr<<A[i].a<<","<<A[i].b<<" ";cerr<<endl;
	for(int i=0;i<8;i++)cerr<<B[i].a<<","<<B[i].b<<" ";cerr<<endl;
	for(int i=0;i<8;i++)cerr<<C[i].a<<","<<C[i].b<<" ";cerr<<endl;
	*/
	
	FMT(A,17,1);
	FMT(B,17,1);
	FMT(C,17,1);
	for(int i=0;i<mxsz;i++)A[i]=1ll*A[i]*B[i]%mod*C[i]%mod;
	FMT(A,17,-1);
	
//	for(int i=0;i<8;i++)cerr<<A[mxsz-i-1].a<<","<<A[mxsz-i-1].b<<" ";cerr<<endl;
	
	ll ans=0;
	for(int i=0;i<17;i++)
	{
		ans+=A[mxsz-(1<<i)-1];
	}
	ans=(ans%mod+mod)%mod;
	cout<<ans<<endl;
	return 0;
}