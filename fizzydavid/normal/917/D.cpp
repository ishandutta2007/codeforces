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
ll fpow(ll x,ll k){return k==0?1:fpow(x*x%mod,k>>1)*(k&1?x:1)%mod;}
ll a[111][111];
ll calcdet(int n)
{
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=(a[i][j]%mod+mod)%mod;
	ll ret=1;
	for(int i=1;i<=n;i++)
	{
		int pivot=-1;
		for(int j=i;j<=n;j++)
		{
			if(a[j][i]!=0)
			{
				pivot=j;
				break;
			}
		}
		if(pivot==-1)
		{
			ret=0;
			continue;
		}
		for(int j=1;j<=n+1;j++)swap(a[pivot][j],a[i][j]);
		if(pivot!=i)ret*=-1;
		ll inv=fpow(a[i][i],mod-2);
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			ll tmp=inv*a[j][i]%mod;
			for(int k=i;k<=n+1;k++)a[j][k]=(a[j][k]-a[i][k]*tmp)%mod;
		}
		ret=ret*a[i][i]%mod;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n+1;j++)a[i][j]=(a[i][j]%mod+mod)%mod;
	return (ret%mod+mod)%mod;
}
int n,K;
int w[111][111];
ll f[111];
int ex[111],ey[111];
int main()
{
	geti(n);
	for(int i=2;i<=n;i++)
	{
		int x,y;
		getii(x,y);
		ex[i]=x;ey[i]=y;
	}
	K=n;
	for(int i=1;i<=n;i++)
	{
		for(int x=1;x<=n;x++)
		{
			for(int y=1;y<=n;y++)
			{
				if(x!=y)w[x][y]=i;
			}
		}
		for(int i=2;i<=n;i++)w[ex[i]][ey[i]]=w[ey[i]][ex[i]]=1;
		for(int x=1;x<=n;x++)for(int y=1;y<=n;y++)a[x][y]=-w[x][y];
		for(int x=1;x<=n;x++)for(int y=x;y<=n;y++)a[x][x]+=w[x][y],a[y][y]+=w[x][y];
//		outa();
		ll ans=calcdet(n-1);
//		cout<<"DET="<<ans<<endl;
		f[i]=ans;
	}
	for(int i=1;i<=n;i++)
	{
		a[i][1]=1;
		for(int j=2;j<=n;j++)a[i][j]=a[i][j-1]*i%mod;
		a[i][n+1]=f[i];
	}
//	outa();
	assert(calcdet(n)!=0);
//	outa();
//	for(int i=1;i<=K+1;i++)ans+=a[i][n+1]*fpow(a[i][i],mod-2)%mod;
	for(int i=K;i>=1;i--)cout<<a[i][n+1]*fpow(a[i][i],mod-2)%mod<<endl;
	return 0;
}