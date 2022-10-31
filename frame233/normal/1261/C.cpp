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
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
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

const int N=1000005;
char *s[N];
int *sum[N],*dis[N],*d[N];
Finline int Query(int x1,int y1,int x2,int y2)
{
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int n,m;
bool check(int x)
{
	for(int i=0;i<=n+1;++i)
	{
		memset(d[i],0,4*(m+3));
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(dis[i][j]>=x)
			{
				++d[i-x][j-x];
				--d[i+x+1][j-x];
				--d[i-x][j+x+1];
				++d[i+x+1][j+x+1];
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			d[i][j]=d[i][j]+d[i-1][j]+d[i][j-1]-d[i-1][j-1];
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if((s[i][j]=='X'&&!d[i][j])||(s[i][j]=='.'&&d[i][j]))
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	read(n,m);
	for(int i=0;i<=n+1;++i)
	{
		s[i]=(char *)malloc(m+3);
		sum[i]=(int *)malloc(4*(m+3));
		dis[i]=(int *)malloc(4*(m+3));
		d[i]=(int *)malloc(4*(m+3));
		memset(sum[i],0,4*(m+3));
	}
	for(int i=1;i<=n;++i)
	{
		read_str(s[i]+1);
		for(int j=1;j<=m;++j)
		{
			sum[i][j]=sum[i-1][j]+sum[i][j-1]+(s[i][j]=='.')-sum[i-1][j-1];
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]=='X')
			{
				int l=0,r=min(min(i-1,j-1),min(n-i,m-j));
				while(l<r)
				{
					int mid=(l+r+1)>>1;
					if(!Query(i-mid,j-mid,i+mid,j+mid))
					{
						l=mid;
					}
					else
					{
						r=mid-1;
					}
				}
				dis[i][j]=l;
			}
			else
			{
				dis[i][j]=-1;
			}
		}
	}
	int l=0,r=min(n,m);
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	int T=l;
	printf("%d\n",T);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(dis[i][j]>=T)
			{
				putchar('X');
			}
			else
			{
				putchar('.');
			}
		}
		putchar('\n');
	}
    return 0;
}