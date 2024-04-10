// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
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
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=200005;
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int col[N];
void dfs(int x,int fa)
{
	col[x]=col[fa]^1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v!=fa)
		{
			dfs(v,x);
		}
	}
}
int siz[N],Fa[N],dep[N],son[N];
int top[N],dfn[N],tree_id;
void dfs1(int x,int fa)
{
	siz[x]=1,Fa[x]=fa;
	dep[x]=dep[fa]+1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
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
	dfn[x]=++tree_id;
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
		if(dep[top[x]]>dep[top[y]]) x=Fa[top[x]];
		else y=Fa[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
Finline int getdis(int x,int y)
{
	return dep[x]+dep[y]-(dep[lca(x,y)]<<1);
}
std::vector<int> cur,res;
int tar;
void getpath(int x,int fa)
{
	cur.pb(x);
	if(x==tar) res=cur;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa) getpath(c[i].v,x);
	}
	cur.pop_back();
}
int main()
{
	int n,m,k;
	read(n,m,k);
	std::vector<pi> v;
	int x,y;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		if(find(x)!=find(y)) fa[find(x)]=find(y),addedge(x,y),addedge(y,x);
		else v.pb(mkpr(x,y));
	}
	if(m==n-1)
	{
		dfs(1,0);
		std::vector<int> v1,v2;
		for(int i=1;i<=n;++i)
		{
			if(col[i])  v1.pb(i);
			else v2.pb(i);
		}
		if(SZ(v1)<SZ(v2)) std::swap(v1,v2);
		printf("1\n");
		for(int i=0;i<(k+1)>>1;++i) printf("%d ",v1[i]);
		printf("\n");
		return 0;
	}
	dfs1(1,0);
	dfs2(1,1);
	int minn=inf;
	pi pos=mkpr(0,0);
	for(auto it:v)
	{
		int dis=getdis(it.first,it.second);
		if(dis<minn) minn=dis,pos=it;
	}
	tar=pos.second;
	getpath(pos.first,0);
	if(SZ(res)<=k)
	{
		printf("2\n");
		printf("%d\n",SZ(res));
		for(auto it:res) printf("%d ",it);
		printf("\n");
		return 0;
	}
	else
	{
		printf("1\n");
		for(int i=0;i<(k+1)>>1;++i) printf("%d ",res[i<<1]);
		printf("\n");
		return 0;
	}
	return 0;
}