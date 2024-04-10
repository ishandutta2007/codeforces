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
const int maxn=200111;
const int maxh=18;
struct SGT
{
	struct node
	{
		int sum;
		ll hsum,lz;
		void addlz(int LZ)
		{
			lz+=LZ;
			hsum+=1ll*LZ*sum;
		}
	}a[maxn*4];
	#define ls p<<1
	#define rs p<<1|1
	void update(int p){a[p].sum=a[ls].sum+a[rs].sum;a[p].hsum=a[ls].hsum+a[rs].hsum;}
	void pushdown(int p)
	{
		if(a[p].lz!=0)
		{
			a[ls].addlz(a[p].lz);
			a[rs].addlz(a[p].lz);
			a[p].lz=0;
		}
	}
	void modify(int x,int v,int l,int r,int p)
	{
		if(l==r)
		{
			a[p].sum=v;
			return;
		}
		pushdown(p);
		int m=l+r>>1;
		if(x<=m)modify(x,v,l,m,ls);
		else modify(x,v,m+1,r,rs);
		update(p);
	}
	void add(int x,int y,int l,int r,int p)
	{
		if(x<=l&&r<=y)
		{
			a[p].addlz(1);
			return;
		}
		if(y<l||r<x)return;
		pushdown(p);
		int m=l+r>>1;
		add(x,y,l,m,ls);
		add(x,y,m+1,r,rs);
		update(p);
	}
	ll query(int x,int y,int l,int r,int p)
	{
		if(x<=l&&r<=y)return a[p].hsum;
		if(y<l||r<x)return 0;
		pushdown(p);
		int m=l+r>>1;
		return query(x,y,l,m,ls)+query(x,y,m+1,r,rs);
	}
}sgt;
int lg2[maxn];
struct STtable
{
	int tab[maxh][maxn];
	int C;
	void init(int a[],int n,int c)//1=max -1=min
	{
		C=c;
		for(int i=0;i<=n;i++)tab[0][i]=a[i]*c;
		for(int i=1;i<maxh;i++)
		{
			for(int j=0;j<=n-(1<<i)+1;j++)
			{
				tab[i][j]=max(tab[i-1][j],tab[i-1][j+(1<<i-1)]);
			}
		}
	}
	int query(int l,int r)
	{
		int t=lg2[r-l+1];
		return max(tab[t][l],tab[t][r-(1<<t)+1])*C;
	}
}STb_mn,STb_mx;
int n,a[maxn],b[maxn];
int gl[maxn],gr[maxn];
int L[maxn],R[maxn];
int f[maxn];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
ll ANS[maxn];
vector<pair<int,int> > qry[maxn];
void solve()
{
	static int st[maxn],stn;
	for(int i=1;i<=n;i++)f[i]=i;
	stn=0;st[0]=0;
	for(int i=2;i<=n;i++)
	{
		if(gr[i-1]>i)st[++stn]=i-1;
		sgt.modify(i-1,1,1,n,1);
		if(gl[i-1]<i-1)
		{
			for(int j=gf(i-1);j>gl[i-1];j=gf(j))
			{
				f[j]=gf(j-1);
				sgt.modify(j,0,1,n,1);
			}
		}
		while(stn>0&&gr[st[stn]]<=i)stn--;
		sgt.add(st[stn]+1,i-1,1,n,1);
		for(int j=0;j<qry[i].size();j++)
		{
			ANS[qry[i][j].SS]+=sgt.query(qry[i][j].FF,i,1,n,1);
		}
	}
}
int main()
{
	for(int i=2;i<maxn;i++)lg2[i]=lg2[i>>1]+1;
	geti(n);
	for(int i=1;i<=n;i++)geti(a[i]),b[a[i]]=i;
	STb_mn.init(b,n,-1);
	STb_mx.init(b,n,1);
	for(int i=1;i<n;i++)
	{
		int l=a[i],r=a[i+1];
		if(l>r)swap(l,r);
		gl[i]=STb_mn.query(l,r);
		gr[i]=STb_mx.query(l,r);
	}
	int q;
	geti(q);
	for(int i=0;i<q;i++)
	{
		int l,r;
		getii(l,r);
		qry[r].PB(MP(l,i));
		ANS[i]+=r-l+1;
	}
	solve();
	for(int i=0;i<q;i++)putsi(ANS[i]);
	return 0;
}