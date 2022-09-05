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
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn=200111;
int n,q;
int f[maxn];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void vis(int x)
{
	int y=x+1;
	f[gf(x)]=gf(y);
}
int a[maxn];
vector<int> v[maxn];
void failed()
{
	puts("NO");
	exit(0);
}
int main()
{
	getii(n,q);
	for(int i=1;i<=n+1;i++)f[i]=i;
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
		v[a[i]].PB(i);
	}
	if(v[q].size()==0)
	{
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				flag=1;
				a[i]=q;
				vis(i);
				break;
			}
		}
		if(!flag)failed();
	}
	for(int i=q;i>=1;i--)
	{
		if(!v[i].size())continue;
		int mn=n+1,mx=0;
		for(int j=0;j<v[i].size();j++)
		{
			if(a[v[i][j]]!=0&&a[v[i][j]]<i)failed();
			mn=min(mn,v[i][j]);
			mx=max(mx,v[i][j]);
		}
		for(int j=gf(mn);j<=mx;j=gf(j))
		{
			if(a[j]!=0&&a[j]<i)failed();
			a[j]=i;
			vis(j);
		}
	}
	for(int i=1;i<=n;i++)if(a[i]==0)a[i]=1;
	puts("YES");
	for(int i=1;i<=n;i++)puti(a[i]);
	return 0;
}