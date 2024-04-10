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
 
const int N=100005,mod=100000000;
int f[105][105][13][2];
Finline void add(int &a,const int &b){(a+=b)>=mod&&(a-=mod);}
int main()
{
	int n1,n2,k1,k2;
	read(n1,n2,k1,k2);
	f[1][0][1][0]=1;
	f[0][1][1][1]=1;
	for(int i=2;i<=n1+n2;++i)
	{
		for(int j=0;j<=i&&j<=n1;++j)
		{
			int a=j,b=i-j;
			if(a>n1||b>n2) continue;
			for(int k=1;k<=k1;++k)
			{
				if(a) add(f[a][b][k][0],f[a-1][b][k-1][0]);
				if(b) add(f[a][b][1][1],f[a][b-1][k][0]);
			}
			for(int k=1;k<=k2;++k)
			{
				if(a) add(f[a][b][1][0],f[a-1][b][k][1]);
				if(b) add(f[a][b][k][1],f[a][b-1][k-1][1]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=k1;++i)
	{
		add(ans,f[n1][n2][i][0]);
	}
	for(int i=0;i<=k2;++i)
	{
		add(ans,f[n1][n2][i][1]);
	}
	printf("%d\n",ans);
    return 0;
}