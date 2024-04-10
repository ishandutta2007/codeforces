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
 
const int N=200005;
struct edge{
	int v,nxt,w;
}c[805];
struct E{
	int x,y,z;
	Finline bool operator < (const E &o)const{return z<o.z;}
}a[N];
int front[N],cnt;
int n,k;
Finline void add(const int &u,const int &v,const int &w){c[++cnt]=(edge){v,front[u],w},front[u]=cnt;}
struct node{
	int u;
	ll d;
	Finline bool operator < (const node &o)const{return d>o.d;}
};
ll dis[N];
std::priority_queue<ll> ans;
void dij(int s)
{
	memset(dis,127,sizeof(dis));
	dis[s]=0;
	std::priority_queue<node> q;
	q.push((node){s,0});
	while(!q.empty())
	{
		node x=q.top();
		q.pop();
		if(dis[x.u]!=x.d) continue;
		for(int i=front[x.u];i;i=c[i].nxt)
		{
			if(dis[c[i].v]>dis[x.u]+c[i].w)
			{
				dis[c[i].v]=dis[x.u]+c[i].w;
				q.push((node){c[i].v,dis[c[i].v]});
			}
		}
	}
	for(int i=s+1;i<=n;++i)
	{
		if(dis[i]<INF)
		{
			ans.push(dis[i]);
			while((int)ans.size()>k) ans.pop();
		}
	}
}
int main()
{
	int m,x,y,z;
	read(n,m,k);
	for(int i=1;i<=m;++i)
	{
		read(x,y,z);
		a[i]=(E){x,y,z};
	}
	std::sort(a+1,a+m+1);
	std::vector<int> nd;
	for(int i=1;i<=m&&i<=k;++i)
	{
		add(a[i].x,a[i].y,a[i].z);
		add(a[i].y,a[i].x,a[i].z);
		nd.push_back(a[i].x);
		nd.push_back(a[i].y);
	}
	std::sort(nd.begin(),nd.end());
	int len=std::unique(nd.begin(),nd.end())-nd.begin();
	for(int i=0;i<len;++i) dij(nd[i]);
	printf("%lld\n",ans.top());
	return 0;//
}