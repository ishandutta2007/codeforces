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
const ll INF=0x7fffffffffffffff;
const double eps=1e-8;
 
uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
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
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}
 
const int N=200005;
struct edge{
	int v,nxt;
}c[N<<1],e[N<<1];
int front[N],cnt;
int dg[N];
int _q[N],_l,_r;
char f[N];
int head[N],CNT;
Finline void add_(const int &u,const int &v)
{
	e[++CNT]=(edge){v,head[u]},head[u]=CNT;
	++dg[v];
}
int dfn[N],low[N],id;
int bel[N],col;
int st[N],top;
bool vis[N];
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
void tarjan(int x)
{
	dfn[x]=low[x]=++id;
	st[++top]=x,vis[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!dfn[c[i].v])
		{
			tarjan(c[i].v);
			chmin(low[x],low[c[i].v]);
		}
		else if(vis[c[i].v])
		{
			chmin(low[x],dfn[c[i].v]);
		}
	}
	if(dfn[x]==low[x])
	{
		bel[x]=++col;
		vis[x]=0;
		while(st[top]!=x)
		{
			bel[st[top]]=col;
			vis[st[top--]]=0;
		}
		--top;
	}
}
int main()
{
	int n,k;
	read(n,k);
	int last,x;
	read(last);
	for(int i=1;i<n;++i)
	{
		read(x);
		add(last,x);
		last=x;
	}
	read(last);
	for(int i=1;i<n;++i)
	{
		read(x);
		add(last,x);
		last=x;
	}
	for(int i=1;i<=n;++i)
	{
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int _=front[i];_;_=c[_].nxt)
		{
			if(bel[i]!=bel[c[_].v])
			{
				add_(bel[i],bel[c[_].v]);
			}
		}
	}
	for(int i=1;i<=col;++i)
	{
		if(!dg[i])
		{
			_q[++_r]=i;
			f[i]='a';
		}
	}
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		for(int i=head[x];i;i=e[i].nxt)
		{
			f[e[i].v]=min('z',(char)(f[x]+1));
			if(!--dg[e[i].v])
			{
				_q[++_r]=e[i].v;
			}
		}
	}
	char maxx=0;
	for(int i=1;i<=col;++i) chmax(maxx,f[i]);
	if(maxx-'a'+1>=k)
	{
		printf("YES\n");
		for(int i=1;i<=n;++i)
		{
			putchar(f[bel[i]]);
		}
		printf("\n");
	}
	else
	{
		printf("NO\n");
	}
    return 0;
}