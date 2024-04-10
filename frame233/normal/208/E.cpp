// luogu-judger-enable-o2
// Author -- Frame
 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<chrono>
 
#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-8;
 
uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
 
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
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
 
const int N=100005;
struct edge{
	int v,nxt;
}c[N];
int front[N],cnt;
int root[N];
int now,dep[N];
int siz[N],dfn[N],id;
std::vector<int> nd[N];
Finline void add(const int &u,const int &v){c[++cnt]=(edge){v,front[u]},front[u]=cnt;}
void dfs(int x,int fa)
{
	dfn[x]=++id;
	siz[x]=1;
	root[x]=now;
	dep[x]=dep[fa]+1;
	nd[dep[x]].emplace_back(dfn[x]);
	for(int i=front[x];i;i=c[i].nxt)
	{
		dfs(c[i].v,x);
		siz[x]+=siz[c[i].v];
	}
}
struct qry{
	int l,r,id;
}q[N];
int _dep[N];
std::vector<qry> v[N];
int a[N],pos;
struct kth{
	int k,id;
};
std::vector<kth> p[N];
void _dfs(int x)
{
	a[++pos]=x;
	for(auto it:p[x])
	{
		if(pos>it.k)
		{
			q[it.id].l=a[pos-it.k];
		}
	}
	for(int i=front[x];i;i=c[i].nxt)
	{
		_dfs(c[i].v);
	}
	--pos;
}
struct BIT{
	int c[N];
	Finline void add(int x,const int &C){for(;x<=1e5;x+=lowbit(x))c[x]+=C;}
	Finline int sum(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
}tr;
int ans[N];
int main()
{
	int n;
	read(n);
	int x;
	for(int i=1;i<=n;++i)
	{
		read(x);
		if(x) add(x,i);
		else root[i]=i;
	}
	for(int i=1;i<=n;++i)
	{
		if(root[i]==i)
		{
			now=i;
			dfs(i,0);
		}
	}
	int _;
	read(_);
	for(int i=1;i<=_;++i)
	{
		read(q[i].l,q[i].r);
		q[i].id=i,_dep[i]=dep[q[i].l];
		p[q[i].l].emplace_back((kth){q[i].r,i});
	}
	for(int i=1;i<=n;++i)
	{
		if(root[i]==i)
		{
			_dfs(i);
		}
	}
	for(int i=1;i<=_;++i)
	{
		q[i].r=dfn[q[i].l]+siz[q[i].l]-1;
		q[i].l=dfn[q[i].l];
		v[_dep[i]].emplace_back(q[i]);
	}
	for(int i=1;i<=n;++i)
	{
		for(auto it:nd[i])
		{
			tr.add(it,1);
		}
		for(auto it:v[i])
		{
			ans[it.id]=tr.sum(it.r)-tr.sum(it.l-1);
		}
		for(auto it:nd[i])
		{
			tr.add(it,-1);
		}
	}
	for(int i=1;i<=_;++i) printf("%d ",ans[i]-1);
	printf("\n");
    return 0;
}