//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
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
ll pos[maxn];
struct SGT
{
	ll a[maxn<<4],b[maxn<<4];
	#define ls p<<1
	#define rs p<<1|1
	void modify(int x,ll v,int l,int r,int p)
	{
		if(l==r)
		{
			a[p]=v;
			b[p]=pos[l]*v%mod;
			return;
		}
		int m=l+r>>1;
		if(x<=m)modify(x,v,l,m,ls);
		else modify(x,v,m+1,r,rs);
		a[p]=a[ls]+a[rs];
		b[p]=(b[ls]+b[rs])%mod;
	}
	ll query(int x,int y,int l,int r,int p)
	{
		if(x>y)return 0;
		if(x<=l&&r<=y)return a[p];
		int m=l+r>>1;
		ll ret=0;
		if(x<=m)ret+=query(x,y,l,m,ls);
		if(m<y)ret+=query(x,y,m+1,r,rs);
		return ret;
	}
	ll queryb(int x,int y,int l,int r,int p)
	{
		if(x>y)return 0;
		if(x<=l&&r<=y)return b[p];
		int m=l+r>>1;
		ll ret=0;
		if(x<=m)ret+=queryb(x,y,l,m,ls);
		if(m<y)ret+=queryb(x,y,m+1,r,rs);
		return ret%mod;
	}
	int querylft(int x,int y,ll &v,int l,int r,int p)
	{
		if(x<=l&&r<=y)
		{
			if(v>a[p])
			{
				v-=a[p];
				return r+1;
			}
			else
			{
				if(l==r)return l;
				int m=l+r>>1;
				if(v<=a[ls])return querylft(x,y,v,l,m,ls);
				else
				{
					v-=a[ls];
					return querylft(x,y,v,m+1,r,rs);
				}
			}
		}
		int m=l+r>>1;
		if(x<=m&&m<y)
		{
			int t=querylft(x,y,v,l,m,ls);
			if(t==m+1)return querylft(x,y,v,m+1,r,rs);
			else return t;
		}
		else if(x<=m)return querylft(x,y,v,l,m,ls);
		else return querylft(x,y,v,m+1,r,rs);
	}
}sgt;
ll w[maxn],w2[maxn];
ll solve(int l,int r)
{
//	cerr<<"solve:"<<l<<","<<r<<endl;
	ll sum=sgt.query(l,r,1,n,1);
	ll cur=(sum+1)/2;
	int p=sgt.querylft(l,r,cur,1,n,1);
	assert(p>=l&&p<=r);
	ll ANS=sgt.queryb(p+1,r,1,n,1)-sgt.queryb(l,p,1,n,1);
	ll cnt=(-sgt.query(p+1,r,1,n,1)+sgt.query(l,p,1,n,1))%mod;
//	cerr<<"p="<<p<<" "<<ANS<<" "<<cnt<<endl;
//	cerr<<sgt.queryb(p+1,r,1,n,1)<<endl;
//	cerr<<sgt.queryb(l,p,1,n,1)<<endl;
	return ((ANS+cnt*pos[p]%mod)%mod+mod)%mod;
}
int main()
{
	getii(n,q);
	for(int i=1;i<=n;i++)
	{
		geti(pos[i]);
		pos[i]-=i;
	}
	for(int i=1;i<=n;i++)
	{
		geti(w[i]);
		sgt.modify(i,w[i],1,n,1);
	}
	for(int i=1;i<=q;i++)
	{
		ll x,y;
		getii(x,y);
		if(x>0)
		{
			putsi(solve(x,y));
		}
		else
		{
			x=-x;
			w[x]=y;
			sgt.modify(x,y,1,n,1);
		}
	}
	return 0;
}