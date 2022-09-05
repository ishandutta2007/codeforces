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
int q;
map<ll,int> mpid;
int tot;
int getid(ll x)
{
	int &id=mpid[x];
	if(id==0)id=++tot;
	return id;
}
const int maxn=500111;
int f[maxn],fv[maxn];
int gf(int x)
{
	if(f[x]==x)return x;
	else
	{
		int fa=gf(f[x]);
		fv[x]^=fv[f[x]];
		f[x]=fa;
		return fa;
	}
}
void change(int x,int y,int v)
{
	if(gf(x)!=gf(y))
	{
		v^=fv[x];
		v^=fv[y];
		x=gf(x);
		y=gf(y);
		f[x]=y;
		fv[x]^=v;
	}
}
int query(int x,int y)
{
	if(gf(x)!=gf(y))return -1;
	else
	{
		gf(x);gf(y);
		return fv[x]^fv[y];
	}
}
int main()
{
	for(int i=0;i<maxn;i++)f[i]=i,fv[i]=0;
	geti(q);
	int last=0;
	for(int i=1;i<=q;i++)
	{
		int t;
		geti(t);
		if(t==1)
		{
			int l,r,x;
			getiii(l,r,x);
			l^=last;
			r^=last;
			x^=last;
			if(l>r)swap(l,r);
			change(getid(l),getid(ll(r)+1),x);
		}
		else
		{
			ll l,r;
			getii(l,r);
			l^=last;
			r^=last;
			if(l>r)swap(l,r);
			last=query(getid(l),getid(ll(r)+1));
			putsi(last);
			if(last<0)last=1;
		}
	}
	return 0;
}