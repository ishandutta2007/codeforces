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
int m,n;
bitset<1011> a[10011];
bool fix[1011];
ll pw2[200111];
ll qpow(ll x,ll k){return k==0?1:qpow(x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int comb_mx=200111;
ll inv[comb_mx],fac[comb_mx],ifac[comb_mx];
ll C(ll x,ll y){return fac[x]*ifac[y]%mod*ifac[x-y]%mod;}
void comb_init()//mod should be prime
{
	pw2[0]=1;
	for(int i=1;i<comb_mx;i++)pw2[i]=pw2[i-1]*2%mod;
	fac[0]=1;
	for(int i=1;i<comb_mx;i++)fac[i]=fac[i-1]*i%mod;
	ifac[comb_mx-1]=qpow(fac[comb_mx-1],mod-2);
	for(int i=comb_mx-2;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
	inv[1]=1;
	for(int i=2;i<comb_mx;i++)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
}
ll dp[1011];
int main()
{
	comb_init();
	dp[0]=1;
	for(int i=1;i<=1000;i++)
	{
		for(int j=0;j<i;j++)
		{
			dp[i]+=dp[i-j-1]*C(i-1,j)%mod;
		}
		dp[i]%=mod;
	}
	getii(m,n);
	for(int i=0;i<m;i++)a[0][i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			char c=getreal();
			a[i][j]=c-'0';
		}
	}
	int ans=0;
	while(true)
	{
		bool f=0;
		for(int i=0;i<=n&&!f;i++)
		{
			if(!a[i].any())continue;
			for(int j=i+1;j<=n&&!f;j++)
			{
				if(!a[j].any())continue;
				if((a[i]&a[j]).any())
				{
					f=1;
					a[++n]=a[i]&a[j];
					a[i]&=~a[n];
					a[j]&=~a[n];
				}
			}
		}
		if(!f)break;
	}
	ll prod=1;
	for(int i=0;i<=n;i++)
	{
		int cnt=0;
		for(int j=0;j<m;j++)
		{
//			cerr<<a[i][j];
			cnt+=a[i][j];
		}
//		cerr<<endl;
		prod=prod*dp[cnt]%mod;
	}
	cout<<prod<<endl;

	return 0;
}