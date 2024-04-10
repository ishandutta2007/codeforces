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
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&((a=b),0);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&((a=b),0);}
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
 
const int N=3005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
Finline void add(int u,int v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
int m;
int b[N],w[N];
struct node{
	int a;
	ll b;
	Finline bool operator < (const node &o)const
	{
		return a==o.a?b<o.b:a<o.a;
	}
	Finline node operator + (const node &o)const
	{
		return (node){a+o.a,b+o.b};
	}
	Finline node get()
	{
		return (node){a+(b>0),0};
	}
}f[N][N];
node t[N];
int dfs(int x,int fa)
{
	f[x][0]=(node){0,w[x]-b[x]};
	int siz=1,tmp;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			tmp=dfs(c[i].v,x);
			for(int j=0;j<siz+tmp;++j) t[j]=(node){0,-0x7ffffffffffffff7};
			for(int j=siz-1;j>=0;--j)
			{
				for(int k=tmp;k>=0;--k)
				{
					chmax(t[j+k],f[x][j]+f[c[i].v][k]);
				}
			}
			siz+=tmp;
			for(int j=0;j<siz;++j) f[x][j]=t[j];
		}
	}
	if(!fa) return siz;
	f[x][siz]=(node){0,-0x7ffffffffffffff7};
	for(int i=siz-1;i>=0;--i)
	{
		chmax(f[x][i+1],f[x][i].get());
	}
	return siz;
}
void MAIN()
{
	int n;
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=m;++j)
		{
			f[i][j]=(node){0,-0x7ffffffffffffff7};
		}
	}
	cnt=0;
	memset(front,0,4*(n+3));
	for(int i=1;i<=n;++i)
	{
		read(b[i]);
	}
	for(int i=1;i<=n;++i)
	{
		read(w[i]);
	}
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	dfs(1,0);
	printf("%d\n",f[1][m-1].get().a);
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
    return 0;
}
//