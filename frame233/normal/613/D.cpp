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

const int N=100005;
struct edge{
	int v,nxt;
}c[N<<1],e[N<<1];
int head[N],CNT;
Finline void _add(const int &u,const int &v)
{
	e[++CNT]=(edge){v,head[u]},head[u]=CNT;
}
int front[N],cnt;
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
int dep[N],Fa[N],siz[N],son[N],top[N],dfn[N],id;
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1;
	Fa[x]=fa,siz[x]=1;
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
	dfn[x]=++id;
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
int nd[N];
Finline bool cmp(const int &a,const int &b){return dfn[a]<dfn[b];}
int st[N],_top;
int t[N],pos;
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]>dep[top[y]]) x=Fa[top[x]];
		else y=Fa[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
void insert(int x)
{
	if(!_top||(dfn[x]>=dfn[st[_top]]&&dfn[x]<dfn[st[_top]]+siz[st[_top]]))
	{
		st[++_top]=x;
		t[++pos]=x;
		return;
	}
	int l=lca(x,st[_top]);
	while(_top>1&&dfn[st[_top-1]]>=dfn[l])
	{
		_add(st[_top-1],st[_top]);
		--_top;
	}
	if(st[_top]!=l) _add(l,st[_top]),st[_top]=l,t[++pos]=l;
	st[++_top]=x;
	t[++pos]=x;
}
bool mark[N];
int dp[N][2];
void dfs(int x)
{
	if(mark[x])
	{
		dp[x][0]=dp[x][1]=0;
		for(int i=head[x];i;i=e[i].nxt)
		{
			dfs(e[i].v);
			dp[x][0]+=dp[e[i].v][0];
			dp[x][1]+=dp[e[i].v][0];
		}
		++dp[x][0];
	}
	else
	{
		int a=0,b=0;
		int minn=inf;
		for(int i=head[x];i;i=e[i].nxt)
		{
			dfs(e[i].v);
			a+=dp[e[i].v][0];
			b+=min(dp[e[i].v][0],dp[e[i].v][1]);
			chmin(minn,dp[e[i].v][1]-dp[e[i].v][0]);
		}
		dp[x][0]=min(a,b+1);
		dp[x][1]=a+minn;
	}
}
int main()
{
	int n;
	read(n);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	int _,k;
	read(_);
	while(_--)
	{
		_top=0,CNT=0;
		read(k);
		for(int i=1;i<=k;++i)
		{
			read(nd[i]);
			mark[nd[i]]=1;
		}
		bool flag=0;
		for(int i=1;i<=k;++i)
		{
			if(mark[Fa[nd[i]]])
			{
				printf("-1\n");
				flag=1;
				break;
			}
		}
		if(flag)
		{
			while(k) mark[nd[k--]]=0;
			continue;
		}
		std::sort(nd+1,nd+k+1,cmp);
		for(int i=1;i<=k;++i)
		{
			insert(nd[i]);
		}
		while(_top>1)
		{
			_add(st[_top-1],st[_top]);
			--_top;
		}
		int minn=inf,_nd=0;
		for(int i=1;i<=pos;++i)
		{
			if(dfn[t[i]]<minn)
			{
				minn=dfn[t[i]];
				_nd=t[i];
			}
		}
		dfs(_nd);
		printf("%d\n",min(dp[_nd][0],dp[_nd][1]));
		while(pos) head[t[pos--]]=0;
		while(k) mark[nd[k--]]=0;
	}
    return 0;
}