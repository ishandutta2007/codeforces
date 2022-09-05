#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
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
int calcphi(int x)
{
	int ret=1;
	for(int i=2;1ll*i*i<=x;i++)
	{
		if(x%i==0)
		{
			ret=ret*(i-1);x/=i;
			while(x%i==0)x/=i,ret*=i;
		}
	}
	if(x>1)ret=ret*(x-1);
	return ret;
}
int n,m,a[100111];
int md[233],mdn;
int qpow(int x,int k,int md){return k==0?1:1ll*qpow(1ll*x*x%md,k>>1,md)*(k&1?x:1)%md;}
int pw[31][31];
int tol[100111],tor[100111];
int calc2(int l,int r)
{
	r=min(r,tor[l]-1);
	if(l>r)return 1;
	else
	{
		int ret=1;
		r=tol[r];
		while(r>=l)
		{
			ret=pw[min(30,a[r])][ret];
			if(ret==30)return 30;
			r=tol[r-1];
		}
		return ret;
	}
}
int calc(int l,int r,int lv)
{
	if(l==r)return a[l]%md[lv];
	if(md[lv]==1)return 0;
	int t=calc(l+1,r,lv+1);
	int lim=calc2(l+1,r);
//	int g=__gcd(a[l],md[lv]);
//	int nxt=qpow(a[l]/g,t,md[lv]);
	if(t<lim)return qpow(a[l],t+md[lv+1],md[lv]);
	else return qpow(a[l],t,md[lv]);
}
int main()
{
	for(int i=0;i<=30;i++)
	{
		pw[i][0]=1;
		for(int j=1;j<=30;j++)pw[i][j]=min(30,pw[i][j-1]*i);
	}
	getii(n,m);
	while(true)
	{
		md[mdn++]=m;
		if(m==1)break;
		m=calcphi(m);
	}
//	for(int i=0;i<mdn;i++)cerr<<md[i]<<" ";cerr<<endl;
	for(int i=1;i<=n;i++)geti(a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)tol[i]=i;else tol[i]=tol[i-1];
	}
	tor[n+1]=n+1;
	for(int i=n;i>=1;i--)
	{
		if(a[i]==1)tor[i]=i;else tor[i]=tor[i+1];
	}
	
	assert(mdn<200);
	int q;
	geti(q);
	for(int i=1;i<=q;i++)
	{
		int l,r;
		getii(l,r);
		putsi(calc(l,r,0));
	}
	return 0;
}