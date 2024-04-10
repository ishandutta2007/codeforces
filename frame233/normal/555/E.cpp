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

const int N=200005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt=-1;
Finline void add(int u,int v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
int dfn[N],low[N],id;
int st[N],_top;
int bel[N],col;
std::vector<int> v[N];
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++id;
	st[++_top]=x;
	for(int i=front[x];~i;i=c[i].nxt)
	{
		if(i!=(fa^1))
		{
			if(!dfn[c[i].v])
			{
				tarjan(c[i].v,i);
				chmin(low[x],low[c[i].v]);
			}
			else if(!bel[c[i].v])
			{
				chmin(low[x],dfn[c[i].v]);
			}
		}
	}
	if(dfn[x]==low[x])
	{
		bel[x]=++col;
		while(st[_top]!=x)
		{
			bel[st[_top]]=col;
			--_top;
		}
		--_top;
	}
}
int E[N][2];
int dep[N],Fa[N],siz[N],son[N];
int top[N];
int _bel[N],_id;
void dfs1(int x,int fa)
{
	_bel[x]=_id;
	dep[x]=dep[fa]+1;
	Fa[x]=fa,siz[x]=1;
	for(auto it:v[x])
	{
		if(it!=fa)
		{
			dfs1(it,x);
			siz[x]+=siz[it];
			if(siz[it]>siz[son[x]])
			{
				son[x]=it;
			}
		}
	}
}
void dfs2(int x,int topf)
{
	top[x]=topf;
	if(!son[x]) return;
	dfs2(son[x],topf);
	for(auto it:v[x])
	{
		if(!top[it])
		{
			dfs2(it,it);
		}
	}
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]>dep[top[y]]) x=Fa[top[x]];
		else y=Fa[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
int d1[N],d2[N];
void dfs3(int x,int fa)
{
	for(auto it:v[x])
	{
		if(it!=fa)
		{
			dfs3(it,x);
			d1[x]+=d1[it];
			d2[x]+=d2[it];
		}
	}
	if(d1[x]&&d2[x])
	{
		printf("No\n");
		exit(0);
	}
}
int main()
{
	memset(front,255,sizeof(front));
	int n,m,q;
	read(n,m,q);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
		E[i][0]=x,E[i][1]=y;
	}
	for(int i=1;i<=n;++i)
	{
		if(!dfn[i])
		{
			tarjan(i,-233);
		}
	}
	for(int i=1;i<=m;++i)
	{
		if(bel[E[i][0]]!=bel[E[i][1]])
		{
			v[bel[E[i][0]]].push_back(bel[E[i][1]]);
			v[bel[E[i][1]]].push_back(bel[E[i][0]]);
		}
	}
	for(int i=1;i<=col;++i)
	{
		std::sort(v[i].begin(),v[i].end());
		v[i].erase(std::unique(v[i].begin(),v[i].end()),v[i].end());
	}
	std::vector<int> _v;
	for(int i=1;i<=col;++i)
	{
		if(!dep[i])
		{
			++_id;
			dfs1(i,0);
			dfs2(i,i);
			_v.push_back(i);
		}
	}
	while(q--)
	{
		read(x,y);
		x=bel[x],y=bel[y];
		if(_bel[x]!=_bel[y])
		{
			printf("No\n");
			return 0;
		}
		int l=lca(x,y);
		++d1[x],--d1[l];
		++d2[y],--d2[l];
	}
	for(auto it:_v) dfs3(it,0);
	printf("Yes\n");
    return 0;
}