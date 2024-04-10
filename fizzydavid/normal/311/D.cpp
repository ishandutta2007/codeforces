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
const int mod=95542721;
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
int ts[48];
struct node
{
	int lz;
	int s[48];
	void apply(int x)
	{
		x%=48;
		for(int i=0;i<48;i++)ts[(i+48-x)%48]=s[i];
		swap(ts,s);
	}
}a[400111];
#define ls p<<1
#define rs p<<1|1
void update(int p)
{
	for(int i=0;i<48;i++)a[p].s[i]=(a[ls].s[i]+a[rs].s[i])%mod;
}
void pushdown(int p)
{
	if(a[p].lz)
	{
		a[ls].apply(a[p].lz);
		a[rs].apply(a[p].lz);
		a[ls].lz+=a[p].lz;
		a[rs].lz+=a[p].lz;
		a[p].lz=0;
	}
}
int ia[100111];
void build(int l,int r,int p=1)
{
	if(l==r)
	{
		a[p].lz=0;
		a[p].s[0]=ia[l]%mod;
		for(int i=1;i<48;i++)a[p].s[i]=1ll*a[p].s[i-1]*a[p].s[i-1]%mod*a[p].s[i-1]%mod;
		return;
	}
	int m=l+r>>1;
	build(l,m,ls);
	build(m+1,r,rs);
	update(p);
}
void add(int x,int y,int l,int r,int p=1)
{
	if(x<=l&&r<=y)
	{
		a[p].lz++;
		a[p].apply(1);
		return;
	}
	pushdown(p);
	int m=l+r>>1;
	if(x<=m)add(x,y,l,m,ls);
	if(m<y)add(x,y,m+1,r,rs);
	update(p);
}
int query(int x,int y,int l,int r,int p=1)
{
	if(x<=l&&r<=y)return a[p].s[0];
	pushdown(p);
	int m=l+r>>1,ret=0;
	if(x<=m)ret=(ret+query(x,y,l,m,ls))%mod;
	if(m<y)ret=(ret+query(x,y,m+1,r,rs))%mod;
	return ret;
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)geti(ia[i]);
	int q;
	geti(q);
	build(1,n);
	while(q--)
	{
		int t,l,r;
		getiii(t,l,r);
		if(t==1)
		{
			putsi(query(l,r,1,n));
		}
		else
		{
			add(l,r,1,n);
		}
	}
	return 0;
}