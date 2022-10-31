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
 
const int N=500005;
struct edge{
	int v,nxt,w;
}c[N<<1];
int front[N],cnt;
bool used[N];
Finline void add(const int &u,const int &v,const int &id)
{
	c[++cnt]=(edge){v,front[u],id},front[u]=cnt;
}
void MAIN()
{
	int n,m,x,y;
	read(n,m);
	memset(front,0,12*(n+3));
	memset(used,0,3*(n+3));
	cnt=0;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		add(x,y,i),add(y,x,i);
	}
	std::vector<int> ed;
	for(int i=1;i<=n*3;++i)
	{
		if(!used[i])
		{
			for(int _=front[i];_;_=c[_].nxt)
			{
				if(!used[c[_].v])
				{
					used[i]=1;
					used[c[_].v]=1;
					ed.push_back(c[_].w);
					break;
				}
			}
		}
	}
	if((int)ed.size()>=n)
	{
		printf("Matching\n");
		for(int i=0;i<n;++i)
		{
			printf("%d ",ed[i]);
		}
		printf("\n");
	}
	else
	{
		printf("IndSet\n");
		int cnt=0;
		for(int i=1;i<=n*3;++i)
		{
			if(!used[i])
			{
				printf("%d ",i);
				if(++cnt==n) break;
			}
		}
		printf("\n");
	}
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
    return 0;
}
//