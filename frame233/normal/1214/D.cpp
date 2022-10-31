// luogu-judger-enable-o2
// Author -- Frame
 
#pragma GCC optimize(2)
 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<cctype>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
#include<functional>
#include<queue>
 
#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define PUT(x) std::cerr<<"@ "<<(x)<<std::endl;
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-12;
 
uint seed=19260817u+std::chrono::steady_clock::now().time_since_epoch().count();
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
template <typename _Tp>Finline void read_arr(_Tp *arr,const int &n)
{
	for(int i=1;i<=n;++i)
	{
		read(arr[i]);
	}
}
struct custom_hash{
    Finline static uint64_t splitmix64(uint64_t x)
    {
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    Finline size_t operator()(uint64_t x)const
    {
        static const uint64_t FIXED_RANDOM=std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+FIXED_RANDOM);
    }
};
const int N=2000005;
char a[N];
int n,m;
struct edge{
	int v,nxt,w;
}c[N<<3];
int front[N],cnt=-1;
int cur[N],dep[N],s,t;
int _q[N],_l,_r;
Finline int id(const int &x,const int &y)
{
	return (x-1)*m+y;
}
Finline void add(const int &u,const int &v,const int &w)
{
	c[++cnt]=(edge){v,front[u],w},front[u]=cnt;
	c[++cnt]=(edge){u,front[v],0},front[v]=cnt;
}
bool bfs()
{
	memset(dep,255,sizeof(dep));
	memcpy(cur,front,sizeof(cur));
	dep[s]=0;
	_q[_l=_r=1]=s;
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
int dfs(const int &x,int flow)
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
		if(ans>=2) return ans;
	}
	return ans;
}
int main()
{
	memset(front,255,sizeof(front));
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		read_str(a+(i-1)*m+1);
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(a[id(i,j)]=='.')
			{
				if(i!=n&&a[id(i+1,j)]=='.')
				{
					add(id(i,j)+1e6,id(i+1,j),inf);
				}
				if(j!=m&&a[id(i,j+1)]=='.')
				{
					add(id(i,j)+1e6,id(i,j+1),inf);
				}
			}
		}
	}
	s=1,t=id(n,m)+1e6;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			add(id(i,j),id(i,j)+1e6,1);
		}
	}
	add(s,s+1e6,inf);
	add(t-1e6,t,inf);
	printf("%d\n",dinic());
    return 0;
}