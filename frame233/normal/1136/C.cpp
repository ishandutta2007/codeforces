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
 
const int N=505;
int t[500005],pos;
int a[N][N],b[N][N];
std::vector<int> v1[500005],v2[500005];
int main()
{
	int n,m;
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			read(a[i][j]);
			t[++pos]=a[i][j];
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			read(b[i][j]);
			t[++pos]=b[i][j];
		}
	}
	std::sort(t+1,t+pos+1);
	int len=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			a[i][j]=std::lower_bound(t+1,t+len+1,a[i][j])-t;
			b[i][j]=std::lower_bound(t+1,t+len+1,b[i][j])-t;
			v1[a[i][j]].push_back(i+j);
			v2[b[i][j]].push_back(i+j);
		}
	}
	for(int i=1;i<=len;++i)
	{
		std::sort(v1[i].begin(),v1[i].end());
		std::sort(v2[i].begin(),v2[i].end());
		if(v1[i].size()!=v2[i].size())
		{
			printf("NO\n");
			return 0;
		}
		for(int j=0;j<(int)v1[i].size();++j)
		{
			if(v1[i][j]!=v2[i][j])
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
    return 0;
}