// luogu-judger-enable-o2
// Author -- Frame
 
#pragma GCC optimize(2)
 
#include<cstdio>
#include<cstring>
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
template <typename _Tp>Finline bool ismax(_Tp &a,const _Tp &b){return a>b?1:a=b,0;}
template <typename _Tp>Finline bool ismin(_Tp &a,const _Tp &b){return a<b?1:a=b,0;}
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
const int block_size=500;
struct block{
	int a[505];
	int tag;
	int l,r;
}f[505];
int block_tot;
int a[N];
int bel[N];
void build(int n)
{
	int tmp=block_size,cur=0;
	for(int i=1;i<=n;++i)
	{
		++tmp;
		if(tmp>block_size)
		{
			f[cur].r=i-1;
			tmp=1;
			f[++cur].l=i;
		}
		bel[i]=cur;
		f[cur].a[tmp]=a[i];
	}
	f[cur].r=n;
	block_tot=cur;
}
void Update1(int cur,int p,int x)
{
	int pos=0;
	a[p]=x;
	for(int i=f[cur].l;i<=f[cur].r;++i)
	{
		++pos;
		if(i!=p)
		{
			a[i]=f[cur].a[pos]=max(a[i],f[cur].tag);
		}
		else
		{
			f[cur].a[pos]=x;
		}
	}
	f[cur].tag=0;
}
void Update2(int x)
{
	for(int i=1;i<=block_tot;++i)
	{
		chmax(f[i].tag,x);
	}
}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	build(n);
	int _;
	read(_);
	int opt,p,x;
	while(_--)
	{
		read(opt);
		if(opt==1)
		{
			read(p,x);
			Update1(bel[p],p,x);
		}
		else
		{
			read(x);
			Update2(x);
		}
	}
	for(int i=1;i<=block_tot;++i)
	{
		int pos=0;
		for(int j=f[i].l;j<=f[i].r;++j)
		{
			++pos;
			printf("%d ",max(f[i].a[pos],f[i].tag));
		}
	}
	printf("\n");
	return 0;
}