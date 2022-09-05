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
const int maxn=100111;
vector<int> con[maxn];
int sz[maxn],lv[maxn],dfn[maxn],arr[maxn],dfnr[maxn],fa[maxn],top[maxn],son[maxn],dn,bot[maxn];
struct SGT
{
	struct node
	{
		bool del;
		int lz,v;
		int sz,bcnt;
		int addlz(int Lz)
		{
			lz+=Lz;
			int dlt=min(sz,bcnt+Lz)-bcnt;
			bcnt+=dlt;
			v+=Lz-dlt;
			return dlt;
		}
		void adddel()
		{
			del=1;
			lz=v=bcnt=0;
		}
	}a[400111];
	#define ls p<<1
	#define rs p<<1|1
	void update(int p)
	{
		a[p].bcnt=a[ls].bcnt+a[rs].bcnt;
	}
	void pushdown(int p)
	{
		if(a[p].del)
		{
			a[ls].adddel();
			a[rs].adddel();
			a[p].del=0;
		}
		if(a[p].lz)
		{
			int lz=a[p].lz;
			lz-=a[ls].addlz(lz);
			lz-=a[rs].addlz(lz);
			a[p].lz=0;
		}
	}
	void build(int l,int r,int p)
	{
		a[p].lz=a[p].v=a[p].bcnt=a[p].del=0;
		a[p].sz=r-l+1;
		if(l==r)return;
		int m=l+r>>1;
		build(l,m,ls);
		build(m+1,r,rs);
	}
	void add(int x,int y,int &v,int l,int r,int p)
	{
		if(!v)return;
		if(x<=l&&r<=y)
		{
			v-=a[p].addlz(v);
			return;
		}
		pushdown(p);
		int m=l+r>>1;
		if(x<=m)add(x,y,v,l,m,ls);
		if(m<y)add(x,y,v,m+1,r,rs);
		update(p);
	}
	void del(int x,int y,int l,int r,int p)
	{
		if(x<=l&&r<=y)
		{
			a[p].adddel();
			return;
		}
		pushdown(p);
		int m=l+r>>1;
		if(x<=m)del(x,y,l,m,ls);
		if(m<y)del(x,y,m+1,r,rs);
		update(p);
	}
	int queryv(int x,int l,int r,int p)
	{
		if(x==l&&x==r)return a[p].v;
		pushdown(p);
		int m=l+r>>1;
		if(x<=m)return queryv(x,l,m,ls);
		else return queryv(x,m+1,r,rs);
	}
	int queryb(int x,int l,int r,int p)
	{
		if(x==l&&x==r)return a[p].bcnt;
		pushdown(p);
		int m=l+r>>1;
		if(x<=m)return queryb(x,l,m,ls);
		else return queryb(x,m+1,r,rs);
	}
}yxg;
int n,m;
void dfs(int x)
{
	sz[x]=1;
	for(auto u:con[x])
	{
		lv[u]=lv[x]+1;
		dfs(u);
		sz[x]+=sz[u];
		if(sz[u]>sz[son[x]])son[x]=u;
	}
}
void dfs2(int x,int tp)
{
	dfn[x]=++dn;arr[dn]=x;
	top[x]=tp;bot[tp]=x;
	if(son[x])dfs2(son[x],tp);
	for(auto u:con[x])
	{
		if(u==son[x])continue;
		dfs2(u,u);
	}
	dfnr[x]=dn;
}
int getlmost(set<int> &s,int x)
{
	auto it=s.lower_bound(x);
	if(it==s.end())return 233333333;
	else return *it;
}
set<int> st_slz;
int slz[100111];
void go(int tp,int T)
{
	if(fa[tp]>0)
	{
		int dlt=yxg.queryv(dfn[fa[tp]],1,n,1)-slz[tp];
		if(slz[tp]==0&&dlt>0)st_slz.insert(dfn[tp]);
		slz[tp]+=dlt;
		yxg.add(dfn[tp],dfn[bot[tp]],dlt,1,n,1);
	}
}
void access(int x)
{
	vector<pair<int,int> > v;
	int p=x;
	while(p)
	{
		v.PB(MP(p,top[p]));
		p=fa[top[p]];
	}
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		go(v[i].SS,v[i].FF);
	}
}
void clear(int u)
{
	yxg.del(dfn[u],dfnr[u],1,n,1);
	while(true)
	{
		int x=getlmost(st_slz,dfn[u]+1);
		if(x<=dfnr[u])
		{
			st_slz.erase(x);
			x=arr[x];
			slz[x]=0;
		}
		else break;
	}
}
int main()
{
	getii(n,m);
	yxg.build(1,n,1);
	for(int i=2;i<=n;i++)
	{
		geti(fa[i]);
		con[fa[i]].PB(i);
	}
	lv[1]=1;
	dfs(1);
	dfs2(1,1);
	for(int i=1;i<=m;i++)
	{
		int t,x;
		getii(t,x);
		access(x);
		int v=1;
		if(t==1)yxg.add(dfn[x],dfn[bot[top[x]]],v,1,n,1);
		else if(t==2)clear(x);
		else if(t==3)
		{
			int col=yxg.queryb(dfn[x],1,n,1);
			puts(col?"black":"white"); 
		}
//		for(int j=1;j<=n;j++)cerr<<lz[j]<<" ";cerr<<endl;
//		for(int j=1;j<=n;j++)cerr<<yxg.queryb(dfn[j],1,n,1)<<" ";cerr<<endl;
		
//		system("pause");
	}
	return 0;
}