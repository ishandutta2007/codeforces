//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
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
int n;
int a[300111],b[300111];
bool np[300111];
int gcd_conv(int a[],int b[],int t[],int n)
{
	static ll c[300111];
	for(int i=1;i<=n;i++)
	{
		int sa=0,sb=0;
		for(int j=i;j<=n;j+=i)sa+=a[j],sb+=b[j];
		c[i]=1ll*sa*sb;
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=i+i;j<=n;j+=i)
		{
			c[i]-=c[j];
		}
		t[i]=c[i]!=0;
	}
}
int main()
{
	geti(n);
	int g=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		geti(x);
		a[x]=1;
		b[x]=1;
		g=__gcd(g,x);
	}
	if(g>1)
	{
		puts("-1");
		return 0;
	}
	int ans=1;
	while(true)
	{
		if(b[1])
		{
			cout<<ans<<endl;
			return 0;
		}
		gcd_conv(a,b,b,300000);
		ans++;
	}
	return 0;
}