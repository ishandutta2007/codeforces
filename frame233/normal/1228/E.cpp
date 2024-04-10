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

const int N=255;
const int mod=1000000007;
int C[N][N];
int f[N][N];
int pw1[N],pw2[N];
Finline void add(int &a,const int &b)
{
	(a+=b)>=mod&&(a-=mod);
}
int main()
{
	int n,c;
	read(n,c);
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=n;++i)
	{
		pw1[i]=1ll*pw1[i-1]*c%mod;
		pw2[i]=1ll*pw2[i-1]*(c-1)%mod;
	}
	for(int i=0;i<=n;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
		{
			C[i][j]=C[i-1][j-1];
			add(C[i][j],C[i-1][j]);
		}
	}
	f[0][0]=1;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<=n;++j)
		{
			if(f[i][j])
			{
				for(int k=0;k<=n-j;++k)
				{
					if(!k) add(f[i+1][j+k],1ll*f[i][j]*(pw1[j]-pw2[j]+mod)%mod*pw2[n-j]%mod);
					else add(f[i+1][j+k],1ll*f[i][j]*C[n-j][k]%mod*pw2[n-k-j]%mod*pw1[j]%mod);
				}
			}
		}
	}
	printf("%d\n",f[n][n]);
    return 0;
}