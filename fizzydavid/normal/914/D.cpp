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
const int B=524288;
pair<int,ll> a[B+B];
ll mygcd(ll x,ll y)
{
	return y==0?x:mygcd(y,x%y);
}
pair<int,ll> merge(pair<int,ll> l,pair<int,ll> r)
{
	pair<int,ll> ret;
	ret.FF=__gcd(l.FF,r.FF);
	ll x=mygcd(l.SS,r.FF),y=mygcd(r.SS,l.FF);
	if(x==0||y==0)ret.SS=0;
	else ret.SS=x*y/mygcd(x,y);
	return ret;
}
int n,q;
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)geti(a[B+i].FF);
	for(int i=B-1;i>=1;i--)a[i]=merge(a[i<<1],a[i<<1|1]);
	int q;
	geti(q);
	while(q--)
	{
		int op,l,r,x;
		getiii(op,l,r);
		if(op==1)
		{
			geti(x);
			l+=B-1;
			r+=B+1;
			pair<int,ll> ans=MP(0,0);
			while(l^r^1)
			{
				if(~l&1)ans=merge(ans,a[l^1]);
				if( r&1)ans=merge(ans,a[r^1]);
				l>>=1;r>>=1;
			}
//			cerr<<ans.FF<<" "<<ans.SS<<endl;
			if(ans.SS%x==0)puts("YES");else puts("NO");
		}
		else
		{
			l+=B;
			a[l]=MP(r,0);
			for(int i=l>>1;i;i>>=1)a[i]=merge(a[i<<1],a[i<<1|1]);
		}
	}
	return 0;
}