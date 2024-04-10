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
const double eps=1e-10;
 
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
 
const int N=13;
double f[N][N];
double g[N][N];
int a[N][N];
void next(int &x,int &y,int k)
{
	if(x&1)
	{
		y-=k;
		if(y<1) y=1-y,--x;
	}
	else
	{
		y+=k;
		if(y>10) y=21-y,--x;
	}
}
int main()
{
	for(int i=1;i<=10;++i)
	{
		for(int j=1;j<=10;++j)
		{
			f[i][j]=g[i][j]=1e18;
		}
	}
	for(int i=1;i<=10;++i)
	{
		for(int j=1;j<=10;++j)
		{
			read(a[i][j]);
		}
	}
	g[1][1]=0;
	g[1][2]=6;
	g[1][3]=6;
	g[1][4]=6;
	g[1][5]=6;
	g[1][6]=6;
	for(int i=1;i<=10;++i)
	{
		if(i&1)
		{
			for(int j=1;j<=10;++j)
			{
				if(i==1&&j<=6) continue;
				if(a[i][j])
				{
					f[i][j]=g[i-a[i][j]][j];
				}
				g[i][j]=1;
				for(int k=1;k<=6;++k)
				{
					int x=i,y=j;
					next(x,y,k);
					g[i][j]+=min(f[x][y],g[x][y])/6.0;
				}
				
			}
		}
		else
		{
			for(int j=10;j>=1;--j)
			{
				if(i==1&&j<=6) continue;
				if(a[i][j])
				{
					f[i][j]=g[i-a[i][j]][j];
				}
				g[i][j]=1;
				for(int k=1;k<=6;++k)
				{
					int x=i,y=j;
					next(x,y,k);
					g[i][j]+=min(f[x][y],g[x][y])/6.0;
				}
			}
		}
	}
	printf("%.18lf\n",g[10][1]);
    return 0;
}