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

const int N=4015;
const int s=4001,t=4002;
struct edge{
	int v,nxt,w;
}c[N<<5];
int front[N],cnt=-1;
int cur[N],dep[N];
Finline void add(int u,int v,int w)
{
	c[++cnt]=(edge){v,front[u],w},front[u]=cnt;
	c[++cnt]=(edge){u,front[v],0},front[v]=cnt;
}
int _q[N],_l,_r;
bool bfs()
{
	memset(dep,255,sizeof(dep));
	memcpy(cur,front,sizeof(cur));
	_q[_l=_r=1]=s;
	dep[s]=0;
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		for(int i=front[x];~i;i=c[i].nxt)
		{
			if(c[i].w&&!~dep[c[i].v])
			{
				dep[c[i].v]=dep[x]+1;
				_q[++_r]=c[i].v;
			}
		}
	}
	return ~dep[t];
}
int dfs(int x,int flow)
{
	if(x==t||!flow) return flow;
	int f=0,rf;
	for(int &i=cur[x];~i;i=c[i].nxt)
	{
		if(dep[c[i].v]==dep[x]+1&&(rf=dfs(c[i].v,min(flow,c[i].w))))
		{
			flow-=rf,f+=rf;
			c[i].w-=rf,c[i^1].w+=rf;
			if(!flow) return f;
		}
	}
	return f;
}
int dinic()
{
	int ans=0;
	while(bfs())
	{
		ans+=dfs(s,inf);
	}
	return ans;
}
int qwq[N];
int main()
{
	memset(front,255,sizeof(front));
	int n,a,b;
	read(n);
	read(a);
	int x;
	for(int i=2;i<=a;++i)
	{
		read(x);
		add(x,i,inf);
		add(s,i,1);
	}
	for(int i=1;i<=n;++i)
	{
		read(qwq[i]);
	}
	read(b);
	for(int i=2;i<=b;++i)
	{
		read(x);
		add(i+a,x+a,inf);
		add(i+a,t,1);
	}
	for(int i=1;i<=n;++i)
	{
		read(x);
		add(qwq[i],x+a,inf);
	}
	printf("%d\n",a+b-dinic()-2);
    return 0;
}