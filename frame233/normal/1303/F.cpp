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

const int N=2000005,MAXN=305;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
int col[MAXN][MAXN];
struct node{
	int x,y,c,last;
}a[N];
int n,m;
int ans[N];
int fa[N<<2];
int id[MAXN][MAXN];
int cnt;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	fa[x]=y;
	--cnt;
}
void qwq(int x,int y)
{
	for(int dir=0;dir<4;++dir)
	{
		int u=x+dx[dir],v=y+dy[dir];
		if(u>=1&&u<=n&&v>=1&&v<=m&&col[u][v]==col[x][y])
		{
			merge(id[x][y],id[u][v]);
		}
	}
}
int node_cnt;
void solve1(int q)
{
	for(int i=1;i<=q;++i)
	{
		if(a[i].c==a[i].last) continue;
		col[a[i].x][a[i].y]=a[i].c;
		id[a[i].x][a[i].y]=++node_cnt;
		fa[node_cnt]=node_cnt;
		cnt=1;
		qwq(a[i].x,a[i].y);
		ans[i]+=cnt;
	}
}
void solve2(int q)
{
	for(int i=q;i>=1;--i)
	{
		if(a[i].c==a[i].last) continue;
		col[a[i].x][a[i].y]=a[i].last;
		id[a[i].x][a[i].y]=++node_cnt;
		fa[node_cnt]=node_cnt;
		cnt=1;
		qwq(a[i].x,a[i].y);
		ans[i]-=cnt;
	}
}
int main()
{
	int q;
	read(n,m,q);
	int x,y,z;
	for(int i=1;i<=q;++i)
	{
		read(x,y,z);
		a[i]={x,y,z,col[x][y]};
		col[x][y]=z;
	}
	memset(col,0,sizeof(col));
	solve1(q);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			id[i][j]=++node_cnt;
			fa[node_cnt]=node_cnt;
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			qwq(i,j);
		}
	}
	solve2(q);
	ans[0]=1;
	for(int i=1;i<=q;++i)
	{
		ans[i]+=ans[i-1];
		printf("%d\n",ans[i]);
	}
	return 0;
}