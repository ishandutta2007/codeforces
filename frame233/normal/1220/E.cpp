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
 
const int N=200005;
struct edge{
	int v,nxt;
}c[N<<1];
std::vector<int> v[N];
int front[N],cnt;
int fa[N];
int w[N];
int dg[N];
int id[N];
ll val[N];
ll ans;
int find(const int &x){return x==fa[x]?x:fa[x]=find(fa[x]);}
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
	++dg[v];
}
int siz[N];
bool F[N];
ll res;
bool dfs1(int x,int fa)
{
	bool flag=F[x];
	for(auto it:v[x])
	{
		if(it!=fa)
		{
			flag|=dfs1(it,x);
		}
	}
	if(flag)
	{
		res+=val[x];
		val[x]=0;
	}
	return flag;
}
void dfs2(int x,int fa,ll len)
{
	len+=val[x];
	chmax(ans,len);
	for(auto it:v[x])
	{
		if(it!=fa)
		{
			dfs2(it,x,len);
		}
	}
}
bool inloop[N];
int _q[N],_l,_r;
int main()
{
	int n,m,x,y;
	read(n,m);
	for(int i=1;i<=n;++i) read(w[i]),fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	_l=1,_r=0;
	for(int i=1;i<=n;++i)
	{
		inloop[i]=1;
		if(dg[i]==1)
		{
			_q[++_r]=i;
		}
	}
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		inloop[x]=0;
		for(int i=front[x];i;i=c[i].nxt)
		{
			if(--dg[c[i].v]==1)
			{
				_q[++_r]=c[i].v;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(inloop[i])
		{
			for(int j=front[i];j;j=c[j].nxt)
			{
				if(inloop[c[j].v])
				{
					fa[find(i)]=find(c[j].v);
				}
			}
		}
	}
	int col=0;
	for(int i=1;i<=n;++i)
	{
		if(fa[i]==i)
		{
			id[i]=++col;
		}
		++siz[find(i)];
	}
	res=0;
	for(int i=1;i<=n;++i)
	{
		id[i]=id[find(i)];
		if(siz[find(i)]==1)
		{
			val[id[find(i)]]=w[i];
		}
		else
		{
			res+=w[i];
			F[id[find(i)]]=1;
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=front[i];j;j=c[j].nxt)
		{
			if(id[i]!=id[c[j].v])
			{
				v[id[i]].emplace_back(id[c[j].v]);
				v[id[c[j].v]].emplace_back(id[i]);
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		std::sort(v[i].begin(),v[i].end());
		v[i].erase(std::unique(v[i].begin(),v[i].end()),v[i].end());
	}
	read(x);
	dfs1(id[find(x)],0);
	dfs2(id[find(x)],0,0);
	printf("%lld\n",ans+res);
    return 0;
}