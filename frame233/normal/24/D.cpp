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

const int N=1005;
double a[N][4],b[N];
void guass(int n)
{
	for(int i=1;i<n;++i)
	{
		for(int j=3;j>=1;--j)
		{
			a[i][j]/=a[i][1];
		}
		a[i+1][3]-=a[i+1][0]*a[i][3];
		a[i+1][1]-=a[i+1][0]*a[i][2];
		a[i+1][0]=0;
	}
	a[n][3]/=a[n][1];
	a[n][1]=1;
	for(int i=n-1;i>=1;--i)
	{
		a[i][3]-=a[i+1][3]*a[i][2];
		a[i][2]=0;
	}
}
int main()
{
	int n,m;
	read(n,m);
	int x,y;
	read(x,y);
	if(m==1)
	{
		double ans=0;
		for(int i=n-1;i>=x;--i)
		{
			ans+=2.0;
		}
		printf("%.12lf\n",ans);
		return 0;
	}
	for(int i=n-1;i>=x;--i)
	{
		for(int j=2;j<m;++j)
		{
			a[j][1]=3;
			a[j][0]=-1;
			a[j][2]=-1;
			a[j][3]=4+b[j];
		}
		a[1][1]=2;
		a[1][2]=-1;
		a[1][3]=b[1]+3;
		a[m][1]=2;
		a[m][0]=-1;
		a[m][3]=b[m]+3;
		guass(m);
		for(int j=1;j<=m;++j)
		{
			b[j]=a[j][3];
		}
	}
	printf("%.12lf\n",b[y]);
    return 0;
}
/*
4dp[j]=(dp[j]+dp[j-1]+dp[j+1]+f[j]) + 4
3dp[j]=dp[j]+dp[j+1]+f[j]+3

*/