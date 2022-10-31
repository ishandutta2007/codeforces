// luogu-judger-enable-o2
// Author -- Frame
 
#pragma GCC optimize(2)
 
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
 
const int N=105;
int dis[N][N];
int mp[N][N];
int a[1000005];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			scanf("%1d",&mp[i][j]);
			if(!mp[i][j])
			{
				mp[i][j]=inf;
			}
			dis[i][j]=mp[i][j];
		}
		dis[i][i]=0;
	}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				chmin(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int m;
	read(m);
	for(int i=1;i<=m;++i) read(a[i]);
	std::vector<int> ans;
	ans.push_back(a[1]);
	for(int i=1;i<m;)
	{
		for(int j=min(m,i+n+1);j>i;--j)
		{
			if(dis[a[i]][a[j]]==j-i)
			{
				ans.push_back(a[j]);
				i=j;
				break;
			}
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto it:ans) printf("%d ",it);
	printf("\n");
    return 0;
}