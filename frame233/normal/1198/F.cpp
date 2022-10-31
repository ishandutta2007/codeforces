// luogu-judger-enable-o2
// Author -- Frame
 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<ctime>
#include<map>
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
 
const int N=100005;
struct node{
	int val,id;
}a[N],b[N];
std::map<int,int> mp;
std::set<int> S;
int ans[N];
int main()
{
	int n;
	read(n);
	int g=0,Pos=0;
	for(int i=1;i<=n;++i)
	{
		read(a[i].val);
		g=gcd(g,a[i].val);
		a[i].id=i;
		++mp[a[i].val];
	}
	if(g!=1)
	{
		printf("NO\n");
		return 0;
	}
	int GG=0;
	for(int i=1;i<=n;++i)
	{
		if(mp[a[i].val]>1)
		{
			GG=gcd(GG,a[i].val);
			if(S.find(a[i].val)==S.end())
			{
				S.insert(a[i].val);
				ans[a[i].id]=1;
			}
			else
			{
				ans[a[i].id]=0;
			}
		}
		else
		{
			b[++Pos]=a[i];
		}
	}
	while((double)clock()/CLOCKS_PER_SEC<0.48)
	{
		std::random_shuffle(b+1,b+Pos+1);
		int g=GG;
		int pos=Pos+1;
		for(int i=1;i<=Pos;++i)
		{
			if(g==1)
			{
				pos=i;
				break;
			}
			g=gcd(g,b[i].val);
		}
		if(g==1)
		{
			int G=GG;
			for(int i=pos;i<=Pos;++i)
			{
				G=gcd(G,b[i].val);
			}
			if(G==1)
			{
				printf("YES\n");
				for(int i=1;i<pos;++i)
				{
					ans[b[i].id]=1;
				}
				for(int i=1;i<=n;++i)
				{
					printf("%d ",ans[i]+1);
				}
				printf("\n");
				return 0;
			}
		}
	}
	printf("NO\n");
    return 0;
}
//