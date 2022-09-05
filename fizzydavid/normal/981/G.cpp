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
const int mod=998244353;
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
#define ls p<<1
#define rs p<<1|1
namespace T1
{
	struct node
	{
		int v;
	}a[maxn*4];
	void pushdown(int p)
	{
		if(a[p].v!=-1)
		{
			a[ls].v=a[rs].v=a[p].v;
		}
	}
	void update(int p)
	{
		if(a[ls].v!=a[rs].v)a[p].v=-1;
		else a[p].v=a[ls].v;
	}
	void modify(int x,int y,int v,int l,int r,int p=1)
	{
		if(x<=l&&r<=y)
		{
			a[p].v=v;
			return;
		}
		pushdown(p);
		int m=l+r>>1;
		if(x<=m)modify(x,y,v,l,m,ls);
		if(m<y)modify(x,y,v,m+1,r,rs);
		update(p);
	}
	int query(int x,int v,int l,int r,int p=1)
	{
		if(x<=l)
		{
			if(a[p].v!=-1)
			{
				if(a[p].v!=v)return -1;
				return r;
			}
			else
			{
				assert(l<r);
				int m=l+r>>1;
				int ret=query(x,v,l,m,ls);
				if(ret<m)return ret;
				else return max(m,query(x,v,m+1,r,rs));
			}
		}
		pushdown(p);
		int m=l+r>>1;
		if(x<=m)
		{
			int ret=query(x,v,l,m,ls);
			if(ret<m)return ret;
			else return max(m,query(x,v,m+1,r,rs));
		}
		else return query(x,v,m+1,r,rs);
	}
	void clear()
	{
		a[1].v=0;
	}
};
namespace T2
{
	struct node
	{
		ll sum;
		pair<ll,ll> lz;
		node(){sum=0;lz=MP(1,0);}
		void addlz(pair<ll,ll> nlz,int sz)
		{
			sum=(sum*nlz.FF+nlz.SS*sz)%mod;
			lz=MP(lz.FF*nlz.FF%mod,(lz.SS*nlz.FF+nlz.SS)%mod);
		}
	}a[maxn*4];
	void pushdown(int p,int l,int m,int r)
	{
		a[ls].addlz(a[p].lz,m-l+1);
		a[rs].addlz(a[p].lz,r-m);
		a[p].lz=MP(1,0);
	}
	void modify(int x,int y,pair<ll,ll> t,int l,int r,int p)
	{
		if(x<=l&&r<=y)
		{
			a[p].addlz(t,r-l+1);
			return;
		}
		int m=l+r>>1;
		pushdown(p,l,m,r);
		if(x<=m)modify(x,y,t,l,m,ls);
		if(m<y)modify(x,y,t,m+1,r,rs);
		a[p].sum=a[ls].sum+a[rs].sum;
	}
	ll query(int x,int y,int l,int r,int p)
	{
		if(x<=l&&r<=y)return a[p].sum;
		ll ret=0;
		int m=l+r>>1;
		pushdown(p,l,m,r);
		if(x<=m)ret+=query(x,y,l,m,ls);
		if(m<y)ret+=query(x,y,m+1,r,rs);
		return ret%mod;
	}
};
int n,q;
vector<pair<pair<int,int>,int> > qr[maxn];
struct query
{
	int op,l,r;//1:+1  2:*2  3: query
	query(int Op=0,int L=0,int R=0){op=Op;l=L;r=R;}
};
vector<query> all_qr[maxn];
int main()
{
	/*
	T1::clear();
	cout<<T1::query(1,0,1,4,1)<<endl;
	cout<<T1::query(1,1,1,4,1)<<endl;
	T1::modify(1,2,1,1,4,1);
	cout<<T1::query(1,0,1,4,1)<<endl;
	cout<<T1::query(1,1,1,4,1)<<endl;
	cout<<T1::query(2,0,1,4,1)<<endl;
	cout<<T1::query(2,1,1,4,1)<<endl;
	return 0;*/
	getii(n,q);
	for(int i=1;i<=q;i++)
	{
		int op,x,y,v;
		getiii(op,x,y);
		if(op==1)
		{
			geti(v);
			qr[v].PB(MP(MP(x,y),i));
		}
		else all_qr[i].PB(query(3,x,y));
	}
	for(int i=1;i<=n;i++)
	{
		T1::clear();
//		cerr<<"i="<<i<<endl;
		for(int j=0;j<qr[i].size();j++)
		{
			int id=qr[i][j].SS;
			int l=qr[i][j].FF.FF,r=qr[i][j].FF.SS;
			int pre_l=l;
//			cerr<<l<<","<<r<<" "<<id<<endl;
			while(l<=r)
			{
				int it;
				it=min(r,T1::query(l,0,1,n,1));
				if(it!=-1)
				{
//					cerr<<"+"<<1<<" "<<l<<" "<<it<<endl;
					all_qr[id].PB(query(1,l,it));
					l=it+1;
				}
				if(l>r)break;
				it=min(r,T1::query(l,1,1,n,1));
				if(it!=-1)
				{
//					cerr<<"+"<<2<<" "<<l<<" "<<it<<endl;
					all_qr[id].PB(query(2,l,it));
					l=it+1;
				}
			}
			assert(l==r+1);
			T1::modify(pre_l,r,1,1,n,1);
		}
	}
	for(int i=1;i<=q;i++)
	{
		for(int j=0;j<all_qr[i].size();j++)
		{
			int op=all_qr[i][j].op;
			int l=all_qr[i][j].l;
			int r=all_qr[i][j].r;
//			cerr<<op<<" "<<l<<","<<r<<endl;
			if(op==1)
			{
				T2::modify(l,r,MP(1,1),1,n,1);
			}
			else if(op==2)
			{
				T2::modify(l,r,MP(2,0),1,n,1);
			}
			else
			{
				putsi((T2::query(l,r,1,n,1)%mod+mod)%mod);
			}
		}
	}
	return 0;
}