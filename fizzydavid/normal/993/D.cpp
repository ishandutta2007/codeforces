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
int n;
pair<ll,ll> a[55];
pair<ll,double> b[55];
double dp[55][55];
void updmn(double &x,double v){x=min(x,v);}
bool check(double c)
{
	for(int i=1;i<=n;i++)b[i]=MP(a[i].FF,a[i].FF-a[i].SS*c);
	sort(b+1,b+n+1);
	reverse(b+1,b+n+1);
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=(i==0&&j==0?0:4e18);
	for(int i=1;i<=n;)
	{
		int r=i;
		while(r<=n&&b[i].FF==b[r].FF)r++;
		for(int j=0;j<=n;j++)
		{
			double w=0;
			for(int k=i;k<r;k++)w+=b[k].SS;
			for(int k=i;k<=r&&k-i<=j;k++)
			{
				updmn(dp[r-1][j-(k-i)+(r-k)],dp[i-1][j]+w);
				w-=b[k].SS;
			}
		}
		i=r;
	}
	/*
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)cerr<<dp[i][j]<<" ";
		cerr<<endl;
	}*/
	double ret=4e18;
	for(int i=0;i<=n;i++)ret=min(ret,dp[n][i]);
//	cerr<<"ret="<<ret<<endl;
//	system("pause");
	return ret<0;
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)geti(a[i].FF);
	for(int i=1;i<=n;i++)geti(a[i].SS);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	double l=0,r=1e9;
	for(int i=0;i<=50;i++)
	{
		double m=(l+r)/2;
		if(check(m))r=m;else l=m;
	}
//	cerr<<l<<endl;
	cout<<ll(l*1000+1-1e-8)<<endl;
	return 0;
}