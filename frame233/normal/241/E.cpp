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
}e1[N],e2[N];
struct Edge{
	int v,nxt,w;
}c[N<<1];
int front[N],cnt_;
Finline void add(const int &u,const int &v,const int &w)
{
	c[++cnt_]=(Edge){v,front[u],w},front[u]=cnt_;
}
int head1[N],cnt1;
int head2[N],cnt2;
Finline void add1(const int &u,const int &v)
{
	e1[++cnt1]=(edge){v,head1[u]},head1[u]=cnt1;
}
Finline void add2(const int &u,const int &v)
{
	e2[++cnt2]=(edge){v,head2[u]},head2[u]=cnt2;
}
int E[N][2];
int _q[N*N],_l,_r;
bool vis1[N],vis2[N];
void bfs1(int s)
{
	_q[_l=_r=1]=s;
	vis1[s]=1;
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		for(int i=head1[x];i;i=e1[i].nxt)
		{
			if(!vis1[e1[i].v])
			{
				vis1[e1[i].v]=1;
				_q[++_r]=e1[i].v;
			}
		}
	}
}

void bfs2(int s)
{
	_q[_l=_r=1]=s;
	vis2[s]=1;
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		for(int i=head2[x];i;i=e2[i].nxt)
		{
			if(!vis2[e2[i].v])
			{
				vis2[e2[i].v]=1;
				_q[++_r]=e2[i].v;
			}
		}
	}
}
bool valid[N];
bool inq[N];
int dis[N];
int _cnt[N];
int n;
bool spfa(int s)
{
	memset(dis,63,sizeof(dis));
	_q[_l=_r=1]=s;
	dis[s]=0;
	_cnt[s]=0;
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		inq[x]=0;
		for(int i=front[x];i;i=c[i].nxt)
		{
			if(dis[c[i].v]>dis[x]+c[i].w)
			{
				dis[c[i].v]=dis[x]+c[i].w;
				_cnt[c[i].v]=_cnt[x]+1;
				if(_cnt[c[i].v]>n) return true;
				if(!inq[c[i].v])
				{
					inq[c[i].v]=1;
					_q[++_r]=c[i].v;
				}
			}
		}
	}
	return false;
}
int main()
{
	int m;
	read(n,m);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		add1(x,y),add2(y,x);
		E[i][0]=x,E[i][1]=y;
	}
	bfs1(1);
	bfs2(n);
	for(int i=1;i<=n;++i)
	{
		valid[i]=vis1[i]&&vis2[i];
	}
	if(!valid[1]||!valid[n])
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=m;++i)
	{
		if(valid[E[i][0]]&&valid[E[i][1]])
		{
			add(E[i][1],E[i][0],-1);
			add(E[i][0],E[i][1],2);
		}
	}
	if(spfa(1))
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(int i=1;i<=m;++i)
	{
		if(valid[E[i][0]]&&valid[E[i][1]])
		{
			printf("%d\n",dis[E[i][1]]-dis[E[i][0]]);
		}
		else
		{
			printf("1\n");
		}
	}
    return 0;
}