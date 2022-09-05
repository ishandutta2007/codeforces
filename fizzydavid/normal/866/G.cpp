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
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}
int n,m,p[11],B[111];
int ta[505];
void multi(int a[],int b[],int c[])
{
	memset(ta,0,sizeof(ta));
	for(int i=0;i<=250;i++)
	{
		if(!a[i])continue;
		for(int j=0;j<=250;j++)
		{
			ta[i+j]=(ta[i+j]+1ll*a[i]*b[j])%mod;
		}
	}
	for(int i=500;i>250;i--)
	{
		if(!ta[i])continue;
		for(int j=1;j<=m;j++)ta[i-B[j]]=(ta[i-B[j]]+ta[i])%mod;
		ta[i]=0;
	}
	for(int i=0;i<=250;i++)c[i]=ta[i];
}
int tb[555];
void qpow(int a[],ll k)
{
	memset(tb,0,sizeof(tb));
	tb[0]=1;
	while(k)
	{
		if(k&1)multi(tb,a,tb);
		multi(a,a,a);
		k>>=1;
	}
	for(int i=0;i<=250;i++)a[i]=tb[i];
}
ll K;
int a[555],aa[555];
int main()
{
	cin>>n>>m>>K;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=m;i++)cin>>B[i];
	for(int i=1;i<=n;i++)
	{
		memset(a,0,sizeof(a));
		a[1]=1;
		qpow(a,p[i]);
		for(int j=0;j<=250;j++)aa[j]=(aa[j]+a[j])%mod;
	}
	qpow(aa,K);
	for(int i=250;i>0;i--)
	{
		for(int j=1;j<=m;j++)if(B[j]<=i)aa[i-B[j]]=(aa[i-B[j]]+aa[i])%mod;
		aa[i]=0;
	}
	cout<<aa[0]<<endl;
	return 0;
}