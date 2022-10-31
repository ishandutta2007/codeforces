// Author -- Frame
 
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
 
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
 
const int N=100005;
bool check(int x)
{
	for(int i=2;i*i<=x;++i)
	{
		if(!(x%i))
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n;
	read(n);
	std::vector<std::pair<int,int> > ans;
	ans.push_back(std::make_pair(1,n));
	for(int i=2;i<=n;++i)
	{
		ans.push_back(std::make_pair(i-1,i));
	}
	int sum=n;
	std::vector<std::pair<int,int> > gp;
	int i;
	for(i=1;i+3<=n;i+=4)
	{
		gp.push_back(std::make_pair(i,i+2));
		gp.push_back(std::make_pair(i+1,i+3));
	}
	if(i+2<=n)
	{
		gp.push_back(std::make_pair(i,i+2));
	}
	int pos=-1;
	while(!check(sum))
	{
		++sum;
		++pos;
		if(pos==(int)gp.size())
		{
			printf("-1\n");
			return 0;
		}
		ans.push_back(gp[pos]);
	}
	printf("%d\n",ans.size());
	for(auto it:ans) printf("%d %d\n",it.first,it.second);
	return 0;
}