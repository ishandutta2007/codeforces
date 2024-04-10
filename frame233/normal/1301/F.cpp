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

const int N=1005;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int a[N][N];
struct node{
	int x,y;
};
std::vector<node> v[45];
bool used[45];
node _q[N*N];
int _l,_r;
int dis[45][N][N];
bool vis[N][N];
int n,m;
void bfs(int c)
{
	memset(vis,0,sizeof(vis));
	memset(used,0,sizeof(used));
	_l=1,_r=0;
	for(auto it:v[c])
	{
		_q[++_r]=it;
		vis[it.x][it.y]=1;
	}
	used[c]=1;
	while(_l!=_r+1)
	{
		node x=_q[_l++];
		for(int dir=0;dir<4;++dir)
		{
			int u=x.x+dx[dir],v=x.y+dy[dir];
			if(u>=1&&u<=n&&v>=1&&v<=m&&!vis[u][v])
			{
				vis[u][v]=1;
				dis[c][u][v]=dis[c][x.x][x.y]+1;
				_q[++_r]={u,v};
			}
		}
		if(!used[a[x.x][x.y]])
		{
			used[a[x.x][x.y]]=1;
			for(auto it:v[a[x.x][x.y]])
			{
				if(!vis[it.x][it.y])
				{
					vis[it.x][it.y]=1;
					dis[c][it.x][it.y]=dis[c][x.x][x.y]+1;
					_q[++_r]=it;
				}
			}
		}
	}
}
int main()
{
	int k;
	read(n,m,k);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			read(a[i][j]);
			v[a[i][j]].push_back({i,j});
		}
	}
	for(int i=1;i<=k;++i) bfs(i);
	int _;
	read(_);
	int x1,y1,x2,y2;
	while(_--)
	{
		read(x1,y1,x2,y2);
		if(x1==x2&&y1==y2)
		{
			printf("0\n");
			continue;
		}
		if(a[x1][y1]==a[x2][y2])
		{
			printf("1\n");
			continue;
		}
		int ans=abs(x1-x2)+abs(y1-y2);
		for(int i=1;i<=k;++i)
		{
			chmin(ans,dis[i][x1][y1]+dis[i][x2][y2]+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}