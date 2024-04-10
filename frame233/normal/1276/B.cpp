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

const int N=500005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
Finline void add(int u,int v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
std::vector<int> v[N];
int dfn[N],low[N],id;
int st[N],top,node_cnt;
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++id;
	st[++top]=x;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			if(!dfn[c[i].v])
			{
				tarjan(c[i].v,x);
				chmin(low[x],low[c[i].v]);
				if(low[c[i].v]>=dfn[x])
				{
					++node_cnt;
					int tmp=0;
					while(tmp!=c[i].v)
					{
						tmp=st[top];
						--top;
						v[node_cnt].push_back(tmp);
						v[tmp].push_back(node_cnt);
					}
					v[node_cnt].push_back(x);
					v[x].push_back(node_cnt);
				}
			}
			else
			{
				chmin(low[x],dfn[c[i].v]);
			}
		}
	}
}
int siz[N];
int _n;
int Fa[N];
void dfs(int x,int fa)
{
	siz[x]=(x<=_n);
	Fa[x]=fa;
	for(auto it:v[x])
	{
		if(it!=fa)
		{
			dfs(it,x);
			siz[x]+=siz[it];
		}
	}
}
void MAIN()
{
	int n,m,a,b;
	read(n,m,a,b);
	_n=n;
	memset(dfn,0,8*(n+3));
	memset(low,0,8*(n+3));
	memset(siz,0,8*(n+3));
	id=0;
	top=0;
	node_cnt=n;
	cnt=0;
	memset(front,0,8*(n+3));
	for(int i=1;i<=n<<1;++i) v[i].clear();
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;++i)
	{
		if(!dfn[i])
		{
			top=0;
			tarjan(i,0);
		}
	}
	dfs(a,0);
	int cur=b;
	while(Fa[cur]!=a) cur=Fa[cur];
	printf("%lld\n",1ll*(siz[b]-1)*(n-siz[cur]-1));
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
    return 0;
}