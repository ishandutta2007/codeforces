// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<unordered_map>

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

const int N=100005;
struct edge{
	int v,nxt;
}c[N];
int front[N],cnt;
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
std::string s[N],t[N];
int a[N];
int Fa[N];
std::vector<std::pair<int,int> > v[N];
int dep[N],siz[N],son[N];
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
int Son;
std::unordered_map<int,int> mp[N];
int ans[N];
void Upd(int x)
{
	++mp[dep[x]][a[x]];
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=Son)
		{
			Upd(c[i].v);
		}
	}
}
void del(int x)
{
	--mp[dep[x]][a[x]];
	if(!mp[dep[x]][a[x]])
	{
		mp[dep[x]].erase(mp[dep[x]].find(a[x]));
	}
	for(int i=front[x];i;i=c[i].nxt)
	{
		del(c[i].v);
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
	Upd(x),Son=0;
	for(auto it:v[x])
	{
		if(it.first<=100000)
		{
			ans[it.second]=mp[it.first].size();
		}
	}
	if(!keep) del(x);
}
int main()
{
	int n,x;
	read(n);
	for(int i=1;i<=n;++i)
	{
		std::cin>>s[i];
		read(x);
		if(x) add(x,i);
		Fa[i]=x;
		t[i]=s[i];
	}
	std::sort(t+1,t+n+1);
	int len=std::unique(t+1,t+n+1)-t-1;
	for(int i=1;i<=n;++i)
	{
		a[i]=std::lower_bound(t+1,t+len+1,s[i])-t;
	}
	for(int i=1;i<=n;++i)
	{
		if(!Fa[i])
		{
			_(i);
		}
	}
	int q;
	read(q);
	int y;
	for(int i=1;i<=q;++i)
	{
		read(x,y);
		v[x].emplace_back(std::make_pair(y+dep[x],i));
	}
	for(int i=1;i<=n;++i)
	{
		if(!Fa[i])
		{
			dfs(i,0);
		}
	}
	for(int i=1;i<=q;++i)
	{
		printf("%d\n",ans[i]);
	}
    return 0;
}