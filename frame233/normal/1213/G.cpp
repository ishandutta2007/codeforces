// luogu-judger-enable-o2
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
const double eps=1e-8;
 
uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
 
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
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
 
const int N=200005;
struct edge{
	int u,v,w;
	Finline bool operator < (const edge &o)const
	{
		return w<o.w;
	}
}c[N];
struct qry{
	int x,id;
	Finline bool operator < (const qry &o)const
	{
		return x<o.x;
	}
}q[N];
int fa[N],siz[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
ll ans,res[N];
void merge(int a,int b)
{
	int x=find(a),y=find(b);
	if(x!=y)
	{
		ans+=1ll*siz[x]*siz[y];
		fa[x]=y;
		siz[y]+=siz[x];
	}
}
int main()
{
	int n,m;
	read(n,m);
	for(int i=1;i<=n;++i) fa[i]=i,siz[i]=1;
	for(int i=1;i<n;++i)
	{
		read(c[i].u,c[i].v,c[i].w);
	}
	std::sort(c+1,c+n);
	int pos=0;
	for(int i=1;i<=m;++i)
	{
		read(q[i].x);
		q[i].id=i;
	}
	std::sort(q+1,q+m+1);
	for(int i=1;i<=m;++i)
	{
		while(pos<n-1&&c[pos+1].w<=q[i].x)
		{
			++pos;
			merge(c[pos].u,c[pos].v);
		}
		res[q[i].id]=ans;
	}
	for(int i=1;i<=m;++i) printf("%lld ",res[i]);
	printf("\n");
    return 0;
}