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
int n,sa,sb,a[100111];
int tmx[20][100111],tmn[20][100111];
pair<int,int> pp[100111];
set<pair<int,int> >st;
int rr[100111];
bool check(int lim)
{
	int rr=1;
	for(int i=1;i<=n;i++)
	{
		int r=i;
		for(int j=19;j>=0;j--)
		{
			if(r+(1<<j)<=n&&tmx[j][r+1]<=a[i]+lim&&tmn[j][r+1]>=a[i]-lim)
			{
				r+=(1<<j);
			}
		}
		rr=max(rr,r);
		if(i==n)return true;
		if(rr==i)return false;
	}
}
int main()
{
	getiii(n,a[1],a[2]);
	for(int i=1;i<=n;i++)
	{
		geti(a[i+2]);
	}
	n+=2;
	for(int i=1;i<=n;i++)tmn[0][i]=tmx[0][i]=a[i];
	for(int i=1;i<20;i++)
	{
		for(int j=1;j<=n-(1<<i)+1;j++)
		{
			tmn[i][j]=min(tmn[i-1][j],tmn[i-1][j+(1<<i-1)]);
			tmx[i][j]=max(tmx[i-1][j],tmx[i-1][j+(1<<i-1)]);
		}
	}
	int l=0,r=mod;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}