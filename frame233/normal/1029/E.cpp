// luogu-judger-enable-o2
// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>

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

const int N=200005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
int dep[N];
struct node{
	int x,dep;
	Finline bool operator < (const node &o)const
	{
		return dep<o.dep;
	}
};
std::priority_queue<node> q;
bool used[N];
int fa[N];
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
void dfs(int x,int Fa)
{
	dep[x]=dep[Fa]+1,fa[x]=Fa;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=Fa)
		{
			dfs(c[i].v,x);
		}
	}
}
int main()
{
	int n,x,y;
	read(n);
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	dep[0]=-1;
	dfs(1,0);
	for(int i=1;i<=n;++i)
	{
		if(dep[i]>2)
		{
			q.push((node){i,dep[i]});
		}
		else
		{
			used[i]=1;
		}
	}
	int ans=0;
	while(!q.empty())
	{
		node x=q.top();
		q.pop();
		while(!q.empty()&&used[x.x]) x=q.top(),q.pop();
		if(used[x.x]) break;
		++ans;
		int tmp=fa[x.x];
		used[tmp]=1;
		for(int i=front[tmp];i;i=c[i].nxt)
		{
			used[c[i].v]=1;
		}
	}
	printf("%d\n",ans);
    return 0;
}