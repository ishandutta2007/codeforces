//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
ll kissme(ll x,ll k)
{
	ll ans=1;
	while(k>0)
	{
		if(k&1)ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
int n,m,ta[100111],b[102][100111];
ll fac[200111],ifac[200111];
ll C(int x,int y){return x>=y?fac[x]*ifac[y]%mod*ifac[x-y]%mod:0;}
int main()
{
	fac[0]=1;
	for(int i=1;i<200100;i++)fac[i]=fac[i-1]*i%mod;
	ifac[200099]=kissme(fac[200099],mod-2);
	for(int i=200098;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
	getii(n,m);
	for(int i=1;i<=n;i++)geti(ta[i]);
	for(int i=1;i<=m;i++)
	{
		int l,r,k;
		getiii(l,r,k);
		b[k+1][l]++;
		for(int j=1;j<=k+1;j++)
		{
			b[j][r+1]=(b[j][r+1]-C(k-j+r-l+1,k+1-j))%mod;
		}
	}
	for(int i=100;i>=0;i--)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			sum=(sum+b[i+1][j])%mod;
			b[i][j]=(b[i][j]+sum)%mod;
		}
	}
	for(int i=1;i<=n;i++)puti(((ta[i]+b[0][i])%mod+mod)%mod);
	return 0;
}