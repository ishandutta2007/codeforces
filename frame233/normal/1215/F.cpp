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
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
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

const int N=2000005;
struct edge{
	int v,nxt;
}c[N<<3];
int front[N],cnt;
Finline void add(int u,int v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
int dfn[N],low[N],id;
int st[N],top;
int bel[N],col;
void tarjan(int x)
{
	dfn[x]=low[x]=++id;
	st[++top]=x;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!dfn[c[i].v])
		{
			tarjan(c[i].v);
			chmin(low[x],low[c[i].v]);
		}
		else if(!bel[c[i].v])
		{
			chmin(low[x],dfn[c[i].v]);
		}
	}
	if(dfn[x]==low[x])
	{
		bel[x]=++col;
		while(st[top]!=x)
		{
			bel[st[top]]=col;
			--top;
		}
		--top;
	}
}
int L[N],R[N];
int main()
{
	int m1,n,M,m2;
	read(m1,n,M,m2);
	int tot=n+M+1;
	int node_cnt=tot<<1;
	int x,y;
	for(int i=1;i<=m1;++i)
	{
		read(x,y);
		add(x+tot,y);
		add(y+tot,x);
	}
	for(int i=1;i<=n;++i)
	{
		read(x,y);
		L[i]=x,R[i]=y;
	}
	for(int i=1;i<=m2;++i)
	{
		read(x,y);
		add(x,y+tot);
		add(y,x+tot);
	}
	add(n+1,n+1+tot);
	for(int i=0;i<M;++i)
	{
		add(n+i+1,n+i+1+1);
		add(n+i+1+1+tot,n+i+1+tot);
	}
	for(int i=1;i<=n;++i)
	{
		add(i,n+R[i]+1);
		add(i,n+L[i]+tot);
		add(n+L[i],i+tot);
		add(n+R[i]+1+tot,i+tot);
	}
	for(int i=1;i<=node_cnt;++i)
	{
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	for(int i=1;i<=tot;++i)
	{
		if(bel[i]==bel[i+tot])
		{
			printf("-1\n");
			return 0;
		}
	}
	std::vector<int> v;
	for(int i=1;i<=n;++i)
	{
		if(bel[i]<bel[i+tot])
		{
			v.push_back(i);
		}
	}
	int f=0;
	for(int i=0;i<=M;++i)
	{
		if(bel[i+n+1]<bel[i+n+tot+1])
		{
			f=i;
			break;
		}
	}
	printf("%d %d\n",(int)v.size(),f);
	for(auto it:v) printf("%d ",it);
	printf("\n");
	return 0;
}