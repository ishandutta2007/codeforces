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

const int N=5005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
int a[N],b[N];
int f[N][N],g[N][N];
int dfs(int x)
{
	f[x][1]=a[x]-b[x];
	g[x][1]=a[x];
	g[x][0]=0;
	int siz=1,tmp;
	for(int i=front[x];i;i=c[i].nxt)
	{
		tmp=dfs(c[i].v);
		for(int j=siz;j>=0;--j)
		{
			for(int k=0;k<=tmp;++k)
			{
				chmin(f[x][j+k],f[x][j]+min(f[c[i].v][k],g[c[i].v][k]));
				chmin(g[x][j+k],g[x][j]+g[c[i].v][k]);
			}
		}
		siz+=tmp;
	}
	return siz;
}
int main()
{
	memset(f,63,sizeof(f));
	memset(g,63,sizeof(g));
	int n,m;
	read(n,m);
	read(a[1],b[1]);
	int x;
	for(int i=2;i<=n;++i)
	{
		read(a[i],b[i]);
		read(x);
		add(x,i);
	}
	dfs(1);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(f[1][i]<=m||g[1][i]<=m)
		{
			ans=i;
		}
	}
	printf("%d\n",ans);
    return 0;
}
// I A K I O I