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
#define INF 0x3f3f3f3f3f3f3f3f

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
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=3005;
int n,k,dp[N],dp2[N],len[N],a[N][N],ans;

void merge(int l,int r)
{
	if(l==r)
	{
		for(int i=k-len[l];i<=k;++i)
			ans=max(ans,dp[i]+a[l][k-i]);
		return;
	}
	int tmp[N];
	for(int i=1;i<=k;++i)
		tmp[i]=dp[i];
	for(int i=mid+1;i<=r;++i)
		for(int j=k;j>=len[i];--j)
			dp[j]=max(dp[j],dp[j-len[i]]+a[i][len[i]]);
	merge(l,mid);
	for(int i=1;i<=k;++i)
		dp[i]=tmp[i];
	for(int i=l;i<=mid;++i)
		for(int j=k;j>=len[i];--j)
			dp[j]=max(dp[j],dp[j-len[i]]+a[i][len[i]]);
	merge(mid+1,r);
}

signed main()
{
	memset(dp,-0x3f,sizeof(dp));
	n=read();k=read();
	for(int i=1;i<=n;++i)
	{
		int tmp=read();
		len[i]=min(tmp,k);
		for(int j=1;j<=len[i];++j)
			a[i][j]=a[i][j-1]+read();
		for(int j=len[i]+1;j<=tmp;++j)
			read();
	}
	dp[0]=0;
	merge(1,n);
	write(ans);
	return 0;
}