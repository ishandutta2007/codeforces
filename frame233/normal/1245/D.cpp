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
 
const int N=2005;
struct node{
	int x,y;
	ll cost;
	Finline bool operator < (const node &o)const
	{
		return cost<o.cost;
	}
}a[N*N];
ll x[N],y[N],k[N];
int fa[N];
int find(const int &x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(x[i],y[i]);
	}
	int _;
	int pos=0;
	for(int i=1;i<=n;++i)
	{
		read(_);
		a[++pos]=(node){i,0,_};
	}
	for(int i=1;i<=n;++i)
	{
		read(k[i]);
		for(int j=1;j<i;++j)
		{
			a[++pos]=(node){j,i,(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]))};
		}
	}
	for(int i=0;i<=n;++i) fa[i]=i;
	std::sort(a+1,a+pos+1);
	ll ans=0;
	std::vector<int> v;
	std::vector<std::pair<int,int> > _v;
	for(int i=1;i<=pos;++i)
	{
		int _x=find(a[i].x),_y=find(a[i].y);
		if(_x!=_y)
		{
			ans+=a[i].cost;
			fa[_x]=_y;
			if(a[i].y)
			{
				_v.push_back(std::make_pair(a[i].x,a[i].y));
			}
			else
			{
				v.push_back(a[i].x);
			}
		}
	}
	printf("%lld\n",ans);
	printf("%d\n",(int)v.size());
	for(auto it:v) printf("%d ",it);
	printf("\n");
	printf("%d\n",(int)_v.size());
	for(auto it:_v) printf("%d %d\n",it.first,it.second);
    return 0;
}