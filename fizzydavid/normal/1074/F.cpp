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
struct SGT
{
	struct node
	{
		int lz,mn,mnc;
		void addlz(int l)
		{
			lz+=l;
			mn+=l;
		}
	}a[maxn*4];
	#define ls p<<1
	#define rs p<<1|1
	void update(int p)
	{
		if(a[ls].mn<a[rs].mn)
		{
			a[p].mn=a[ls].mn;
			a[p].mnc=a[ls].mnc;
		}
		else if(a[rs].mn<a[ls].mn)
		{
			a[p].mn=a[rs].mn;
			a[p].mnc=a[rs].mnc;
		}
		else
		{
			a[p].mn=a[ls].mn;
			a[p].mnc=a[ls].mnc+a[rs].mnc;
		}
	}
	void pushdown(int p)
	{
		if(a[p].lz)
		{
			a[ls].addlz(a[p].lz);
			a[rs].addlz(a[p].lz);
			a[p].lz=0;
		}
	}
	void add(int x,int y,int v,int l,int r,int p)
	{
		if(r<x||l>y)return;
		if(x<=l&&r<=y)
		{
			a[p].addlz(v);
			return;
		}
		pushdown(p);
		int m=l+r>>1;
		add(x,y,v,l,m,ls);
		add(x,y,v,m+1,r,rs);
		update(p);
	}
	void build(int l,int r,int p)
	{
		a[p].lz=0;
		a[p].mn=0;
		a[p].mnc=r-l+1;
		if(l==r)return;
		int m=l+r>>1;
		build(l,m,ls);
		build(m+1,r,rs);
	}
	int query(){return a[1].mn>0?0:a[1].mnc;}
}yxg;
int n,q;
vector<int> con[maxn];
int sz[maxn],fa[maxn],son[maxn],top[maxn],lv[maxn],dfn[maxn],dtot,dfnr[maxn],arr[maxn];
void addseg(int x,int y,int v)
{
	yxg.add(x,y,v,1,n,1);
}
int getlca(int x,int y)
{
	while(true)
	{
		if(top[x]==top[y])
		{
			return arr[min(dfn[x],dfn[y])];
		}
		else
		{
			if(lv[top[x]]<lv[top[y]])swap(x,y);
			x=fa[top[x]];
		}
	}
}
int getson(int x,int p)
{
	while(true)
	{
		if(top[x]==top[p])
		{
			return arr[dfn[x]+1];
		}
		else
		{
			if(fa[top[p]]==x)return top[p];
			else p=fa[top[p]];
		}
	}
}
void dfs(int x)
{
	sz[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==fa[x])continue;
		fa[u]=x;
		lv[u]=lv[x]+1;
		dfs(u);
		sz[x]+=sz[u];
		if(sz[u]>sz[son[x]])son[x]=u;
	}
}
void dfs2(int x,int tp)
{
	top[x]=tp;dfn[x]=++dtot;arr[dtot]=x;
	if(son[x])dfs2(son[x],tp);
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==fa[x]||u==son[x])continue;
		dfs2(u,u);
	}
	dfnr[x]=dtot;
}
map<pair<int,int>,int> mp;
void add(int x,int y,int v)
{
	if(lv[x]>lv[y])swap(x,y);
	int p=getlca(x,y);
	if(p==x)
	{
		int q=getson(p,y);
		addseg(dfn[q],dfnr[q],v);
		addseg(dfn[y],dfnr[y],-v);
	}
	else
	{
		addseg(1,n,v);
		addseg(dfn[x],dfnr[x],-v);
		addseg(dfn[y],dfnr[y],-v);
	}
}
int main()
{
	getii(n,q);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	lv[1]=1;dfs(1);
	dfs2(1,1);
	yxg.build(1,n,1);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		getii(x,y);
		if(x>y)swap(x,y);
		if(mp[MP(x,y)])
		{
			add(x,y,-1);
			mp[MP(x,y)]=0;
		}
		else
		{
			add(x,y,1);
			mp[MP(x,y)]=1;
		}
		putsi(yxg.query());
	}
	return 0;
}