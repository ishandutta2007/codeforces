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
const ll INF=0x7ffffffffffffff;
const double eps=1e-8;
 
uint seed=19260817;
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
    while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}
 
const int N=200005;
int a[N],ans[N];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	std::vector<int> v1,v2;
	for(int i=1;i<=n;++i)
	{
		bool f1=0,f2=0;
		if(!v1.size())
		{
			f1=1;
		}
		else if(a[i]>a[*--v1.end()])
		{
			f1=1;
		}
		if(!v2.size())
		{
			f2=1;
		}
		else if(a[i]<a[*--v2.end()])
		{
			f2=1;
		}
		if(!f1&&!f2)
		{
			printf("NO\n");
			return 0;
		}
		if(!f1||!f2)
		{
			if(f1)
			{
				v1.push_back(i);
			}
			else
			{
				v2.push_back(i);
			}
		}
		else
		{
			if(a[i]<a[i+1])
			{
				v1.push_back(i);
			}
			else
			{
				v2.push_back(i);
			}
		}
	}
	for(auto it:v2) ans[it]=1;
	printf("YES\n");
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	printf("\n");
    return 0;
}
///