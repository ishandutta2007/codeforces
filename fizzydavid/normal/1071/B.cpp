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
int n,K;
char s[2011][2011];
int dis[2011][2011];
int getmn(int sum)
{
	int mn=233333333;
	for(int i=0;i<sum;i++)
	{
		int j=sum-i;
		if(i>=0&&i<=n&&j>=0&&j<=n)
		{
			mn=min(mn,dis[i][j]);
		}
	}
	return mn;
}
char getmnc(int sum,int mn)
{
	char c='z';
	for(int i=0;i<sum;i++)
	{
		int j=sum-i;
		if(i>=0&&i<=n&&j>=0&&j<=n&&dis[i][j]<=mn)
		{
			if(s[i+1][j])c=min(c,s[i+1][j]);
			if(s[i][j+1])c=min(c,s[i][j+1]);
		}
	}
	return c;
}
void upd(int &x,int v){x=min(x,v);}
void go(int sum,char c)
{
	for(int i=0;i<sum;i++)
	{
		int j=sum-i;
		if(i>=0&&i<=n&&j>=0&&j<=n&&dis[i][j]<=K)
		{
			if(s[i+1][j])upd(dis[i+1][j],dis[i][j]+(s[i+1][j]>c));
			if(s[i][j+1])upd(dis[i][j+1],dis[i][j]+(s[i][j+1]>c));
		}
	}
}
void out()
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cerr<<dis[i][j]<<" ";
		}
		cerr<<endl;
	}
}
int main()
{
	getii(n,K);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			s[i][j]=getreal();
		}
	}
	memset(dis,20,sizeof(dis));
	dis[0][1]=0;
	string S="";
	for(int i=1;i<n+n;i++)
	{
		char c;
		int d=getmn(i);
//		cerr<<"d="<<d<<endl;
//		out();
		if(d<K)c='a';
		else c=getmnc(i,d);
		go(i,c);
		S+=c;
	}
	cout<<S;
	return 0;
}