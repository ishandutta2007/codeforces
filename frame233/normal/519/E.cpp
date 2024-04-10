// luogu-judger-enable-o2
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
const ll INF=0x7ffffffffffffff;
const double eps=1e-8;
 
uint seed=19260817;
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
    while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}
 
const int N=100005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
int n;
int siz[N],dep[N],fa[N],son[N],top[N];
int f[N][19];
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
void dfs1(int x,int Fa)
{
	fa[x]=Fa,siz[x]=1;
	dep[x]=dep[Fa]+1;
	f[x][0]=Fa;
	for(int i=1;i<=17;++i)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=Fa)
		{
			dfs1(c[i].v,x);
			siz[x]+=siz[c[i].v];
			if(siz[c[i].v]>siz[son[x]])
			{
				son[x]=c[i].v;
			}
		}
	}
}
void dfs2(int x,int topf)
{
	top[x]=topf;
	if(!son[x]) return;
	dfs2(son[x],topf);
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!top[c[i].v])
		{
			dfs2(c[i].v,c[i].v);
		}
	}
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) y=fa[top[y]];
		else x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
int solve(int x,int y)
{
	if(x==y) return n;
	int _l=lca(x,y);
	int dis=dep[x]+dep[y]-(dep[_l]<<1);
	if(dis&1) return 0;
	int hf=dis>>1;
	if(dep[x]-dep[_l]<hf)
	{
		std::swap(x,y);
	}
	if(dep[x]<dep[y]) std::swap(x,y);
	if(dep[x]==dep[y])
	{
		for(int i=17;i>=0;--i)
		{
			if(f[x][i]!=f[y][i])
			{
				x=f[x][i];
				y=f[y][i];
			}
		}
		return n-siz[x]-siz[y];
	}
	int cur=x;
	for(int i=17;i>=0;--i)
	{
		if(f[cur][i]&&dep[f[cur][i]]>=dep[_l]&&dep[x]-dep[f[cur][i]]<hf)
		{
			cur=f[cur][i];
		}
	}
	return siz[fa[cur]]-siz[cur];
}
int main()
{
	int x,y;
	read(n);
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	int _;
	read(_);
	while(_--)
	{
		read(x,y);
		printf("%d\n",solve(x,y));
	}
    return 0;
}
//