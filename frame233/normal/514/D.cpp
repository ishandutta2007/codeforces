// luogu-judger-enable-o2
// Author -- Frame
 
#pragma GCC optimize(2)
 
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
 
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
 
const int N=100005;
int a[N][7];
std::multiset<int> s[7];
int n,m,k;
Finline bool check()
{
	int tmp=0;
	for(int i=1;i<=m;++i)
	{
		tmp+=*--s[i].end();
	}
	return tmp<=k;
}
Finline void del(int pos)
{
	for(int i=1;i<=m;++i)
	{
		s[i].erase(s[i].find(a[pos][i]));
	}
}
Finline void add(int pos)
{
	for(int i=1;i<=m;++i)
	{
		s[i].insert(a[pos][i]);
	}
}
int main()
{
	read(n,m,k);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			read(a[i][j]);
		}
	}
	int l=1;
	int ans=0;
	int r1=0,r2=0;
	for(int i=1;i<=n;++i)
	{
		add(i);
		while(l<=i&&!check())
		{
			del(l++);
		}
		if(ans<i-l+1)
		{
			r1=l,r2=i;
			ans=i-l+1;
		}
	}
	for(int i=1;i<=m;++i)
	{
		int tmp=0;
		for(int j=r1;j<=r2;++j)
		{
			chmax(tmp,a[j][i]);
		}
		printf("%d ",tmp);
	}
	printf("\n");
	return 0;
}