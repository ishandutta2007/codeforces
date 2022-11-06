#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=1e5+5;
int n,mod,jc[N],inv[N],tot[N],dp[505][505];

inline void init();
inline int q_pow(int a,int b);
inline int C(int n,int m);

signed main()
{
	n=read();mod=read();
	init();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			tot[i]=(tot[i]+C(i-1,i-j))%mod;
	dp[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=i&&k<=j;++k)
				dp[i+1][j]=(dp[i+1][j]+dp[i-k][j-k]*tot[k]%mod*C(j,k)%mod)%mod;
	int ans=0,now=1;
	for(int i=1;i<=n;++i)
		ans=(ans+dp[n+1][i])%mod;
	printf("%lld\n",ans);
	return 0;
}

inline void init()
{
	jc[0]=1;
	for(int i=1;i<=100000;++i)
		jc[i]=jc[i-1]*i%mod;
	inv[100000]=q_pow(jc[100000],mod-2);
	for(int i=99999;i>=0;--i)
		inv[i]=inv[i+1]*(i+1)%mod;
}

inline int q_pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c%mod;
		a=a*a%mod;b>>=1;
	}
	return c;
}

inline int C(int n,int m)
{
	return n<m?0:jc[n]*inv[m]%mod*inv[n-m]%mod;
}