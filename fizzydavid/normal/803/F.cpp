//by yjz
#include<bits/stdc++.h>
#include<bitset>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbg=2e18;
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
int n,a[100111],coef[100111],cnt[100111];
ll pw2[100111];
int main()
{
	pw2[0]=1;
	for(int i=1;i<=100000;i++)coef[i]=1,pw2[i]=pw2[i-1]*2%mod;
	for(int i=2;i<=100000;i++)
	{
		if(!coef[i])continue;
		for(int j=2;i*j<=100000;j++)coef[i*j]-=coef[i];
		coef[i]=-coef[i];
	}
	geti(n);
	for(int i=1;i<=n;i++)
	{
		int x;
		geti(x);
		cnt[x]++;
	}
	ll ans=0;
	for(int i=1;i<=100000;i++)
	{
		int sum=0;
		for(int j=1;i*j<=100000;j++)
		{
			sum+=cnt[i*j];
		}
		ans=(ans+(coef[i]+mod)*(pw2[sum]+mod-1))%mod;
	}
	cout<<ans<<endl;
	return 0;
}