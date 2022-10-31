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
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

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

const int N=200005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
Finline void add(int u,int v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
int a[N];
int dp1[N];
int qwq[N];
void dfs1(int x,int fa)
{
	dp1[x]=a[x];
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			dfs1(c[i].v,x);
			dp1[x]+=qwq[c[i].v];
		}
	}
	qwq[x]=max(0,dp1[x]);
}
int dp2[N];
void dfs2(int x,int fa)
{
	if(fa) dp2[x]=max(0,dp2[fa]-qwq[x])+dp1[x];
	else dp2[x]=dp1[x];
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			dfs2(c[i].v,x);
		}
	}
}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		if(!a[i]) a[i]=-1;
	}
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;++i) printf("%d ",dp2[i]);
	printf("\n");
	return 0;
}