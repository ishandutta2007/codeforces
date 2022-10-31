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
    while(ch!='.'&&ch!='#') ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while(ch=='#'||ch=='.') *(++tar)=ch,ch=getchar();
    return tar-s+1;
}
 
const int N=53;
int f[N][N][N][N];
char s[N][N];
int sum[N][N];
Finline int Query(const int &x1,const int &y1,const int &x2,const int &y2)
{
	return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read_str(s[i]+1);
		for(int j=1;j<=n;++j)
		{
			f[i][j][i][j]=s[i][j]=='#';
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(s[i][j]=='#');
		}
	}
	for(int l1=1;l1<=n;++l1)
	{
		for(int l2=1;l2<=n;++l2)
		{
			if(l1==1&&l2==1) continue;
			for(int x1=1,x2=l1;x2<=n;++x1,++x2)
			{
				for(int y1=1,y2=l2;y2<=n;++y1,++y2)
				{
					if(Query(x1,y1,x2,y2))
					{
						f[x1][y1][x2][y2]=max(x2-x1+1,y2-y1+1);
					}
					for(int i=x1;i<x2;++i)
					{
						chmin(f[x1][y1][x2][y2],f[x1][y1][i][y2]+f[i+1][y1][x2][y2]);
					}
					for(int i=y1;i<y2;++i)
					{
						chmin(f[x1][y1][x2][y2],f[x1][y1][x2][i]+f[x1][i+1][x2][y2]);
					}
				}
			}
		}
	}
	printf("%d\n",f[1][1][n][n]);
    return 0;
}
//