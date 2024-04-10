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
#define lowbit(x) (x&(-x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define max Max
#define min Min
#define abs Abs

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

const int N=105;
int n,a[N],b[N],all,dp[2][N][N*N],ok[2][N][N*N];

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read(),b[i]=read(),all+=b[i];
	ok[0][0][0]=1;
	for(int i=1,p=0;i<=n;p+=b[i],++i)
	{
		for(int j=0;j<=i-1;++j)
			for(int k=0;k<=p;++k)
				if(ok[(i-1)&1][j][k])
				{
					dp[i&1][j+1][k+b[i]]=max(dp[i&1][j+1][k+b[i]],dp[(i-1)&1][j][k]+a[i]-b[i]);
					ok[i&1][j+1][k+b[i]]=1;
					dp[i&1][j][k]=max(dp[i&1][j][k],dp[(i-1)&1][j][k]);
					ok[i&1][j][k]=1;
				}
				
		for(int j=0;j<=i-1;++j)
			for(int k=0;k<=p;++k)
				dp[(i-1)&1][j][k]=0,ok[(i-1)&1][j][k]=0;
	}
	for(int i=1;i<=n;++i)
	{
		double ans=0;
		for(int j=0;j<=10000;++j)
			if(ok[n&1][i][j]!=0)
				ans=max(ans,j+min(dp[n&1][i][j]+0.0,(all-j)/2.0));
		printf("%.6lf ",ans);
	}
		
		
	return 0;
}