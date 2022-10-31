// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
{
	register char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=150005;
const int mod=998244353;
template <typename _Tp1,typename _Tp2>Finline void Add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
ll ksm(ll a,int b=mod-2)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
Finline void add(int u,int v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
std::vector<int> v[N];
struct node{
	int l,r,siz;
};
std::vector<node> S[N];
int dfn[N],id,siz[N];
void dfs1(int x,int fa)
{
	// dfn[x]=++id;
	siz[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			v[x].push_back(c[i].v);
			dfs1(c[i].v,x);
			siz[x]+=siz[c[i].v];
		}
	}
}
void dfs2(int x)
{
	dfn[x]=++id;
	for(auto it:v[x])
	{
		dfs2(it);
	}
}
const int T=400;
int bel[N];
int D[405];
int sum[N];
void Upd(int l,int r,int C)
{
	if(l>r) return;
	Add(D[bel[l]],C);
	Add(D[bel[r]],mod-C);
	if(bel[l-1]==bel[l]) Add(sum[l-1],mod-C);
	Add(sum[r],C);
}
int Qry(int x)
{
	int ans=sum[x];
	for(int i=1;i<=bel[x];++i) Add(ans,D[i]);
	while(bel[x+1]==bel[x])
	{
		++x;
		Add(ans,sum[x]);
	}
	return ans;
}
void build(int n)
{
	int tmp=T,cur=0;
	for(int i=1;i<=n;++i)
	{
		++tmp;
		if(tmp>T)
		{
			tmp=1;
			++cur;
		}
		bel[i]=cur;
	}
}
int main()
{
	int n,q;
	read(n,q);
	build(n);
	ll inv=ksm(n);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	dfs1(1,0);
	for(int i=1;i<=n;++i)
	{
		std::sort(v[i].begin(),v[i].end(),[](const int &a,const int &b)->bool{return siz[a]<siz[b];});
	}
	dfs2(1);
	for(int i=1;i<=n;++i)
	{
		if(v[i].empty()) continue;
		int last=siz[v[i][0]];
		int l=dfn[v[i][0]];
		for(auto it:v[i])
		{
			if(siz[it]!=last)
			{
				S[i].push_back({l,dfn[it]-1,last});
				last=siz[it];
				l=dfn[it];
			}
		}
		S[i].push_back({l,dfn[i]+siz[i]-1,last});
	}
	int opt;
	while(q--)
	{
		read(opt);
		if(opt==1)
		{
			read(x,y);
			Upd(dfn[x],dfn[x]+siz[x]-1,1ll*n*y%mod);
			for(auto it:S[x])
			{
				Upd(it.l,it.r,mod-1ll*it.siz*y%mod);
			}
			Upd(1,dfn[x]-1,1ll*siz[x]*y%mod);
			Upd(dfn[x]+siz[x],n,1ll*siz[x]*y%mod);
		}
		else
		{
			read(x);
			printf("%lld\n",inv*Qry(dfn[x])%mod);
		}
	}
	return 0;
}