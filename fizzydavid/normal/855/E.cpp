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
ll f[11][66][11];
int q;
ll b;
ll a[66];
bool hs[11];
ll solve(ll lim)
{
	if(lim==0)return 0;
	memset(a,0,sizeof(a));
	for(int i=0;i<64;i++)
	{
		a[i]=lim%b;
		lim/=b;
	}
	int len=64;
	while(a[len-1]==0)len--;
//	for(int i=0;i<len;i++)cerr<<a[i];cerr<<endl;
	ll ans=0;
	for(int i=len-1;i>=1;i--)
	{
		ans+=(b-1)*f[b][i-1][1];
	}
	memset(hs,0,sizeof(hs));
	int hscnt=0;
	for(int i=len-1;i>=0;i--)
	{
		for(int j=(i==len-1);j<a[i];j++)
		{
			ans+=f[b][i][hscnt+1-hs[j]*2];
		}
		hscnt-=hs[a[i]];
		hs[a[i]]^=1;
		hscnt+=hs[a[i]];
	}
//	cerr<<"hscnt="<<hscnt<<endl;
	if(hscnt==0)ans++;
	return ans;
}
int main()
{
	for(int i=2;i<=10;i++)
	{
		for(int j=0;j<=64;j++)
		{
			for(int k=0;k<=i;k++)
			{
				if(j==0)f[i][j][k]=k==0;
				else
				{
					f[i][j][k]=f[i][j-1][k-1]*k+f[i][j-1][k+1]*(i-k);
				}
			}
		}
	}
	geti(q);
	for(int i=1;i<=q;i++)
	{
		ll l,r;
		getiii(b,l,r);
		ll ans=solve(r);
		ans-=solve(l-1);
		putsi(ans);
	}
	return 0;
}