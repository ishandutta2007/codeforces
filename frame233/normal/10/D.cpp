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

const int N=505;
int f[N][N];
int a[N],b[N];
int opt[N][N];
void print(int i,int j)
{
	if(!i||!j) return;
	print(i-1,opt[i][j]);
	if(j!=opt[i][j])
	{
		printf("%d ",b[j]);
	}
}
int main()
{
	int n,m;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	read(m);
	for(int i=1;i<=m;++i) read(b[i]);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(a[i]==b[j])
			{
				f[i][j]=1;
				opt[i][j]=0;
				for(int k=1;k<j;++k)
				{
					if(a[i]>b[k])
					{
						if(f[i-1][k]+1>f[i][j])
						{
							f[i][j]=f[i-1][k]+1;
							opt[i][j]=k;
						}
					}
				}
			}
			if(f[i-1][j]>f[i][j])
			{
				f[i][j]=f[i-1][j];
				opt[i][j]=j;
			}
		}
	}
	int ans=0,pos=0;
	for(int i=1;i<=m;++i)
	{
		if(f[n][i]>ans)
		{
			ans=f[n][i];
			pos=i;
		}
	}
	printf("%d\n",ans);
	print(n,pos);
    return 0;
}