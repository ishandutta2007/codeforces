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

const int N=300005;
int a[N][9],b[257];
int n,m;
bool check(int x)
{
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;++i)
	{
		int st=0;
		for(int j=0;j<m;++j)
		{
			st|=(a[i][j]>=x)<<j;
		}
		b[st]=i;
	}
	for(int i=0;i<1<<m;++i)
	{
		for(int j=0;j<1<<m;++j)
		{
			if(b[i]&&b[j]&&((i|j)==(1<<m)-1))
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<m;++j)
		{
			read(a[i][j]);
		}
	}
	int l=0,r=1000000001;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	for(int i=1;i<=n;++i)
	{
		int st=0;
		for(int j=0;j<m;++j)
		{
			st|=(a[i][j]>=l)<<j;
		}
		b[st]=i;
	}
	for(int i=0;i<1<<m;++i)
	{
		for(int j=0;j<1<<m;++j)
		{
			if(b[i]&&b[j]&&((i|j)==(1<<m)-1))
			{
				printf("%d %d\n",b[i],b[j]);
				return 0;
			}
		}
	}
    return 0;
}