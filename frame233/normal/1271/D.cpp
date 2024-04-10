// Author -- Frame
 
#pragma GCC optimize(2)
 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<bitset>
#include<queue>
 
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
int v[N];
int rest[N],sum[N];
struct node{
	int a,b,c,id;
	Finline bool operator < (const node &o)const
	{
		return c==o.c?v[id]>v[o.id]:c>o.c;
	}
}a[N];
int A[N],B[N],C[N];
int main()
{
	int n,m,k;
	read(n,m,k);
	for(int i=1;i<=n;++i)
	{
		read(a[i].a,a[i].b,a[i].c);
		a[i].id=i;
		v[i]=i;
		A[i]=a[i].a,B[i]=a[i].b,C[i]=a[i].c;
	}
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		chmax(v[y],x);
	}
	int cur=k;
	for(int i=1;i<=n;++i)
	{
		if(cur<a[i].a)
		{
			printf("-1\n");
			return 0;
		}
		cur+=a[i].b;
		rest[i]=cur;
	}
	int ans=0;
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		bool flag=1;
		for(int j=v[a[i].id];j<=n;++j)
		{
			if(rest[j]<=A[j+1])
			{
				flag=0;
				break;
			}
		}
		if(!flag) continue;
		for(int j=v[a[i].id];j<=n;++j)
		{
			--rest[j];
		}
		ans+=a[i].c;
	}
	printf("%d\n",ans);
    return 0;
}