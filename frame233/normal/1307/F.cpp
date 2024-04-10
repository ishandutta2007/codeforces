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

const int N=400005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
Finline void add(int u,int v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
int f[N][21],dep[N];
void dfs(int x,int fa)
{
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	for(int i=1;i<=20;++i)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			dfs(c[i].v,x);
		}
	}
}
int jump(int x,int k)
{
	for(int i=20;i>=0;--i)
	{
		if((k>>i)&1)
		{
			x=f[x][i];
		}
	}
	return x;
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) std::swap(x,y);
	for(int i=20;i>=0;--i)
	{
		if(dep[f[x][i]]>=dep[y])
		{
			x=f[x][i];
		}
	}
	if(x==y) return x;
	for(int i=20;i>=0;--i)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int get(int x,int y,int k,int l)
{
	if(dep[x]-dep[l]>=k) return jump(x,k);
	k-=dep[x]-dep[l];
	return jump(y,dep[y]-dep[l]-k);
}
struct node{
	int x,dep;
}_q[N];
int _l,_r;
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main()
{
	int n,k,r;
	read(n,k,r);
	int node_cnt=n;
	int x,y;
	for(int i=1;i<n;++i)
	{
		++node_cnt;
		read(x,y);
		add(x,node_cnt);
		add(node_cnt,x);
		add(node_cnt,y);
		add(y,node_cnt);
	}
	dfs(1,0);
	_l=1,_r=0;
	for(int i=1;i<=r;++i)
	{
		read(x);
		_q[++_r]=(node){x,0};
		fa[x]=x;
	}
	while(_l!=_r+1)
	{
		node x=_q[_l++];
		if(x.dep>=k) break;
		for(int i=front[x.x];i;i=c[i].nxt)
		{
			if(!fa[c[i].v])
			{
				fa[c[i].v]=fa[x.x];
				_q[++_r]=(node){c[i].v,x.dep+1};
			}
			else
			{
				fa[find(c[i].v)]=find(x.x);
			}
		}
	}
	int _;
	read(_);
	while(_--)
	{
		read(x,y);
		int l=lca(x,y);
		if(dep[x]+dep[y]-(dep[l]<<1)<=(k<<1))
		{
			printf("YES\n");
			continue;
		}
		int a=get(x,y,k,l);
		int b=get(y,x,k,l);
		if(!fa[a]||!fa[b])
		{
			printf("NO\n");
			continue;
		}
		if(find(a)==find(b))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}