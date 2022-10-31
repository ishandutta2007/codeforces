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

const int N=20005;
int dp[N];
int sum[55][N];
int f[N][16];
int f1[N][16];
int f2[N][16];
int Log[N];
Finline int Query(int l,int r)
{
	int k=Log[r-l+1];
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
Finline int Query1(int l,int r)
{
	int k=Log[r-l+1];
	return max(f1[l][k],f1[r-(1<<k)+1][k]);
}
Finline int Query2(int l,int r)
{
	int k=Log[r-l+1];
	return max(f2[l][k],f2[r-(1<<k)+1][k]);
}
int main()
{
	int n,m,k;
	read(n,m,k);
	for(int i=2;i<=m;++i) Log[i]=Log[i>>1]+1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			read(sum[i][j]);
			sum[i][j]+=sum[i][j-1];
		}
	}
	for(int i=1;i<=m-k+1;++i)
	{
		dp[i]=sum[1][i+k-1]-sum[1][i-1]+sum[2][i+k-1]-sum[2][i-1];
	}
	for(int i=2;i<=n;++i)
	{
		for(int j=0;j<=m;++j)
		{
			for(int k=0;k<=15;++k)
			{
				f[j][k]=-inf;
			}
		}
		for(int j=m-k+1;j>=1;--j)
		{
			f[j][0]=dp[j];
			f1[j][0]=dp[j]-sum[i][j+k-1];
			f2[j][0]=dp[j]+sum[i][j-1];
			for(int k=1;k<=15&&j+(1<<(k-1))<=m-k+1;++k)
			{
				f[j][k]=max(f[j][k-1],f[j+(1<<(k-1))][k-1]);
				f1[j][k]=max(f1[j][k-1],f1[j+(1<<(k-1))][k-1]);
				f2[j][k]=max(f2[j][k-1],f2[j+(1<<(k-1))][k-1]);
			}
		}
		for(int j=1;j<=m-k+1;++j)
		{
			dp[j]=0;
			if(j-k>=1)
			{
				chmax(dp[j],Query(1,j-k)+sum[i][j+k-1]-sum[i][j-1]+sum[i+1][j+k-1]-sum[i+1][j-1]);
			}
			if(j+k<=m-k+1)
			{
				chmax(dp[j],Query(j+k,m-k+1)+sum[i][j+k-1]-sum[i][j-1]+sum[i+1][j+k-1]-sum[i+1][j-1]);
			}
			if(max(1,j-k+1)<=j-1)
			{
				chmax(dp[j],Query1(max(1,j-k+1),j-1)+sum[i][j+k-1]+sum[i+1][j+k-1]-sum[i+1][j-1]);
			}
			chmax(dp[j],Query2(j,min(j+k-1,m-k+1))-sum[i][j-1]+sum[i+1][j+k-1]-sum[i+1][j-1]);
		}
	}
	int ans=0;
	for(int i=1;i<=m-k+1;++i) chmax(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}