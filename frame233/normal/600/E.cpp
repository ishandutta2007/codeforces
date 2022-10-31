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
int a[N];
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt_;
Finline void add(const int &u,const int &v)
{
	c[++cnt_]=(edge){v,front[u]},front[u]=cnt_;
}
int siz[N],son[N];
void _(int x,int fa)
{
	siz[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			_(c[i].v,x);
			siz[x]+=siz[c[i].v];
			if(siz[c[i].v]>siz[son[x]])
			{
				son[x]=c[i].v;
			}
		}
	}
}
ll res;
int maxx;
int cnt[N],ccnt[N];
int Son;
ll sum[N],ans[N];
void Upd(int x,int fa)
{
	--ccnt[cnt[a[x]]];
	sum[cnt[a[x]]]-=a[x];
	++cnt[a[x]];
	sum[cnt[a[x]]]+=a[x];
	++ccnt[cnt[a[x]]];
	chmax(maxx,cnt[a[x]]);
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa&&c[i].v!=Son)
		{
			Upd(c[i].v,x);
		}
	}
}
void del(int x,int fa)
{
	--ccnt[cnt[a[x]]];
	sum[cnt[a[x]]]-=a[x];
	--cnt[a[x]];
	sum[cnt[a[x]]]+=a[x];
	++ccnt[cnt[a[x]]];
	if(!ccnt[maxx]) --maxx;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			del(c[i].v,x);
		}
	}
}
void dfs(int x,int fa,bool keep)
{
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa&&c[i].v!=son[x])
		{
			dfs(c[i].v,x,0);
		}
	}
	if(son[x]) dfs(son[x],x,1),Son=son[x];
	Upd(x,fa),Son=0;
	ans[x]=sum[maxx];
	if(!keep) del(x,fa);
}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	_(1,0);
	dfs(1,0,0);
	for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
	printf("\n");
    return 0;
}

// I A K I O I