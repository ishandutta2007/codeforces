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
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
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

const int N=1005;
char s[N];
int lcp[N][N];
struct node{
	int l,r;
	Finline bool operator < (const node &o)
	{
		int L=lcp[l][o.l];
		chmin(L,r-l+1);
		chmin(L,o.r-o.l+1);
		char a=l+L>r?0:s[l+L];
		char b=o.l+L>o.r?0:s[o.l+L];
		return a>b;
	}
}a[N*N];
int pos;
int n,m;
ll sum[N][N],dp[N][N];
ll calc(int l,int r)
{
	sum[n+1][0]=1;
	for(int i=n;i>=1;--i)
	{
		int L=lcp[i][l];
		chmin(L,n-i+1);
		chmin(L,r-l+1);
		int pos=i+L;
		int _pos=l+L;
		char a=pos<=n?s[pos]:0;
		char b=_pos<=r?s[_pos]:0;
		for(int j=1;j<=n;++j)
		{
			if(a>b)
			{
				dp[i][j]=sum[pos+1][j-1];
			}
			else
			{
				dp[i][j]=0;
			}
			sum[i][j]=sum[i+1][j]+dp[i][j];
			chmin(sum[i][j],3000000000000000000LL);
		}
		sum[i][0]=1;
	}
	return dp[1][m];
}
int main()
{
	ll k;
	read(n,m,k);
	read_str(s+1);
	for(int i=n;i>=1;--i)
	{
		for(int j=n;j>=1;--j)
		{
			if(s[i]==s[j]) lcp[i][j]=lcp[i+1][j+1]+1;
			else lcp[i][j]=0;
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			a[++pos]=(node){i,j};
		}
	}
	std::sort(a+1,a+pos+1);
	int l=1,r=pos;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(calc(a[mid].l,a[mid].r)<k) l=mid;
		else r=mid-1;
	}
	for(int i=a[l].l;i<=a[l].r;++i) putchar(s[i]);
	putchar('\n');
	return 0;
}