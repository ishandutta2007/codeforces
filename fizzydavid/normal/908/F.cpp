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
int n;
ll a[300111];
int ty[300111];
int tl[300111][3],tr[300111][3];
ll gor(int x,int msk)
{
	ll ret=mod;
	if(msk&1)ret=min(ret,a[tr[x][0]]);
	if((msk>>1)&1)ret=min(ret,a[tr[x][1]]);
	if((msk>>2)&1)ret=min(ret,a[tr[x][2]]);
	return ret;
}
ll gol(int x,int msk)
{
	ll ret=0;
	if(msk&1)ret=max(ret,a[tl[x][0]]);
	if((msk>>1)&1)ret=max(ret,a[tl[x][1]]);
	if((msk>>2)&1)ret=max(ret,a[tl[x][2]]);
	return ret;
}
bool vis[300111];
ll solve(int l,int r)
{
	if(vis[l])return 0;
	vis[l]=1;
	if(r==l+1)return a[r]-a[l];
	ll ret1=(a[r]-a[l])*2;
	ll ret2=(a[r]-a[l])*3;
	ll mx0=0,mx1=0;
	for(int i=l;i<r;i++)mx0=max(mx0,gor(i+1,1+4)-gol(i,1+4));
	for(int i=l;i<r;i++)mx1=max(mx1,gor(i+1,2+4)-gol(i,2+4));
//	cerr<<"mx0="<<mx0<<" mx1="<<mx1<<endl;
	return min(ret1,ret2-mx0-mx1);
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
		char c=getreal();
		if(c=='R')ty[i]=0;
		if(c=='B')ty[i]=1;
		if(c=='G')ty[i]=2;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			tl[i][j]=ty[i]==j?i:tl[i-1][j];
		}
	}
	a[n+1]=2*mod;
	tr[n+1][0]=tr[n+1][1]=tr[n+1][2]=n+1;
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<3;j++)
		{
			tr[i][j]=ty[i]==j?i:tr[i+1][j];
		}
	}
	if(tl[n][2]==0)
	{
		ll ans=0;
		if(tl[n][0])ans+=a[tl[n][0]]-a[tr[1][0]];
		if(tl[n][1])ans+=a[tl[n][1]]-a[tr[1][1]];
		cout<<ans<<endl;
	}
	else
	{
		ll ans=0;
		for(int i=1;i<n;i++)
			if(tl[i][2]&&tr[i+1][2]<=n)
				ans+=solve(tl[i][2],tr[i+1][2]);
		ans+=gor(1,4)-gor(1,4+1);
		ans+=gor(1,4)-gor(1,4+2);
		ans+=gol(n,4+1)-gol(n,4);
		ans+=gol(n,4+2)-gol(n,4);
		cout<<ans<<endl;
	}
	return 0;
}