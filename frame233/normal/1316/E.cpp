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

const int N=100005;
struct node{
	int a;
	int s[7];
	Finline bool operator < (const node &o)const
	{
		return a>o.a;
	}
}a[N];
ll dp[N][1<<7];
int cnt[1<<7];
int main()
{
	memset(dp,-63,sizeof(dp));
	for(int i=0;i<128;++i) cnt[i]=cnt[i>>1]+(i&1);
	int n,p,k;
	read(n,p,k);
	for(int i=1;i<=n;++i) read(a[i].a);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<p;++j)
		{
			read(a[i].s[j]);
		}
	}
	std::sort(a+1,a+n+1);
	dp[0][0]=0;
	for(int i=1;i<=n;++i)
	{
		for(int st=0;st<1<<p;++st)
		{
			if(cnt[st]>i)
			{
				continue;
			}
			for(int j=0;j<p;++j)
			{
				if((st>>j)&1)
				{
					chmax(dp[i][st],dp[i-1][st^(1<<j)]+a[i].s[j]);
				}
			}
			int rest=k-(i-cnt[st]);
			if(rest>=0) chmax(dp[i][st],dp[i-1][st]+a[i].a);
			else chmax(dp[i][st],dp[i-1][st]);
		}
	}
	printf("%lld\n",dp[n][(1<<p)-1]);
	return 0;
}