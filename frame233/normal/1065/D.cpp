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
Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool ismax(_Tp &a,const _Tp &b){return a>=b?1:a=b,0;}
template <typename _Tp>Finline bool ismin(_Tp &a,const _Tp &b){return a<=b?1:a=b,0;}
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

const int N=35005;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
const int Dx[]={1,1,-1,-1};
const int Dy[]={-1,1,-1,1};
const int DX[]={1,1,2,2,-1,-1,-2,-2};
const int DY[]={2,-2,1,-1,2,-2,1,-1};
struct edge{
	int v,nxt,w1,w2;
}c[N<<8];
int front[N],cnt;
int a[13][13],n;
std::pair<int,int> dis[N];
struct node{
	int u;
	std::pair<int,int> d;
	Finline bool operator < (const node &o)const
	{
		return d>o.d;
	}
};
std::priority_queue<node> q;
Finline void add(const int &u,const int &v,const int &w1,const int &w2)
{
	c[++cnt]=(edge){v,front[u],w1,w2},front[u]=cnt;
}
Finline int id(const int &x,const int &y)
{
	return (x-1)*n+y;
}
Finline int id(const int &x,const int &y,const int &k,const int &type)
{
	return (type-1)*(n*n*n*n)+(k-1)*(n*n)+id(x,y);
}
std::pair<int,int> dij(int s,int t)
{
	memset(dis,63,sizeof(dis));
	dis[s]=std::make_pair(0,0);
	q.push((node){s,dis[s]});
	while(!q.empty())
	{
		node x=q.top();
		q.pop();
		if(dis[x.u]!=x.d) continue;
		for(int i=front[x.u];i;i=c[i].nxt)
		{
			if(dis[c[i].v]>std::make_pair(dis[x.u].first+c[i].w1,dis[x.u].second+c[i].w2))
			{
				dis[c[i].v]=std::make_pair(dis[x.u].first+c[i].w1,dis[x.u].second+c[i].w2);
				q.push((node){c[i].v,dis[c[i].v]});
			}
		}
	}
	return dis[t];
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			read(a[i][j]);
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			for(int k=1;k<n*n;++k)
			{
				add(id(i,j,k,1),id(i,j,k,2),1,1);
				add(id(i,j,k,1),id(i,j,k,3),1,1);
				add(id(i,j,k,2),id(i,j,k,1),1,1);
				add(id(i,j,k,2),id(i,j,k,3),1,1);
				add(id(i,j,k,3),id(i,j,k,1),1,1);
				add(id(i,j,k,3),id(i,j,k,2),1,1);
				int u=i,v=j;
				for(int dir=0;dir<4;++dir)
				{
					u=i,v=j;
					while(u+dx[dir]>=1&&u+dx[dir]<=n&&v+dy[dir]>=1&&v+dy[dir]<=n)
					{
						u+=dx[dir];
						v+=dy[dir];
						if(a[u][v]==k+1) add(id(i,j,k,1),id(u,v,k+1,1),1,0);
						else add(id(i,j,k,1),id(u,v,k,1),1,0);
					}
				}
				for(int dir=0;dir<4;++dir)
				{
					u=i,v=j;
					while(u+Dx[dir]>=1&&u+Dx[dir]<=n&&v+Dy[dir]>=1&&v+Dy[dir]<=n)
					{
						u+=Dx[dir];
						v+=Dy[dir];
						if(a[u][v]==k+1) add(id(i,j,k,2),id(u,v,k+1,2),1,0);
						else add(id(i,j,k,2),id(u,v,k,2),1,0);
					}
				}
				for(int dir=0;dir<8;++dir)
				{
					if(i+DX[dir]>=1&&i+DX[dir]<=n&&j+DY[dir]>=1&&j+DY[dir]<=n)
					{
						u=i+DX[dir],v=j+DY[dir];
						if(a[u][v]==k+1) add(id(i,j,k,3),id(u,v,k+1,3),1,0);
						else add(id(i,j,k,3),id(u,v,k,3),1,0);
					}
				}
			}
		}
	}
	int s=id(n,n,n*n,3)+1;
	int t=s+1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(a[i][j]==1)
			{
				add(s,id(i,j,1,1),0,0);
				add(s,id(i,j,1,2),0,0);
				add(s,id(i,j,1,3),0,0);
			}
			if(a[i][j]==n*n)
			{
				add(id(i,j,n*n,1),t,0,0);
				add(id(i,j,n*n,2),t,0,0);
				add(id(i,j,n*n,3),t,0,0);
			}
		}
	}
	std::pair<int,int> ans=dij(s,t);
	printf("%d %d\n",ans.first,ans.second);
    return 0;
}