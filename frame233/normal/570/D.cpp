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
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
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

const int N=500005;
struct edge{
	int v,nxt;
}c[N];
int front[N],cnt;
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
char s[N];
struct qry{
	int dep,id;
};
std::vector<qry> v[N];
int ans[N],siz[N],dep[N];
int son[N];
void _(int x)
{
	siz[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		dep[c[i].v]=dep[x]+1;
		_(c[i].v);
		siz[x]+=siz[c[i].v];
		if(siz[c[i].v]>siz[son[x]])
		{
			son[x]=c[i].v;
		}
	}
}
int a[N],Son;
void Upd(int x)
{
	a[dep[x]]^=1<<s[x];
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=Son)
		{
			Upd(c[i].v);
		}
	}
}
void dfs(int x,bool keep)
{
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=son[x])
		{
			dfs(c[i].v,0);
		}
	}
	if(son[x]) dfs(son[x],1),Son=son[x];
	Upd(x);
	Son=0;
	for(auto it:v[x])
	{
		ans[it.id]=__builtin_popcount(a[it.dep])<=1;
	}
	if(!keep) Upd(x);
}
int main()
{
	int n,m;
	read(n,m);
	int x,y;
	for(int i=2;i<=n;++i)
	{
		read(x);
		add(x,i);
	}
	read_str(s+1);
	dep[1]=1;
	_(1);
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		v[x].push_back((qry){y,i});
	}
	dfs(1,0);
	for(int i=1;i<=m;++i)
	{
		if(ans[i])
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
    return 0;
}
//  I A K I O I