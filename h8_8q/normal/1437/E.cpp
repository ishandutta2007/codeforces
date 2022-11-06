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
#define mp(x,y) make_pair(x,y)
#define lc (x<<1)
#define rc (x<<1|1)
#define fi first
#define se second
#define mid ((l+r)>>1)
#define fan(x) (((x-1)^1)+1)
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

const int N=5e5+5;
int n,m,k,a[N],b[N],c[N],d[N],dp[N],ans;

struct BIT
{
	int c[N];
	inline void add(int x,int v)
	{
		for(;x<=k;x+=lowbit(x))
			c[x]=max(c[x],v);
	}
	inline int query(int x)
	{
		int res=-1;
		for(;x;x-=lowbit(x))
			res=max(res,c[x]);
		return res;
	}
	inline void clear(int x)
	{
		for(;x<=k;x+=lowbit(x))
			c[x]=-1;
	}
}sum;

signed main()
{
	n=k=read();m=read()+2;
	for(int i=1;i<=n;++i)
		a[i]=read()-i,c[i]=a[i];
	c[++k]=-1e18;a[0]=-1e18;
	c[++k]=1e18;a[n+1]=1e18;
	sort(c+1,c+1+k);
	k=unique(c+1,c+1+k)-c-1;
	for(int i=0;i<=n+1;++i)
		d[i]=lower_bound(c+1,c+1+k,a[i])-c;
	b[1]=0;b[m]=n+1;
	for(int i=2;i<=m-1;++i)
	{
		b[i]=read();
		if(a[b[i-1]]>a[b[i]]||b[i]-b[i-1]>a[b[i]]+b[i]-a[b[i-1]]+b[i-1])
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=k;++i)
		sum.c[i]=-1;
	for(int i=2;i<=m;++i)
	{
		sum.add(d[b[i-1]],0);
		for(int j=b[i-1]+1;j<=b[i];++j)
		{
			int tmp=sum.query(d[j]);
			if(tmp!=-1)
			{
				dp[j]=tmp+1;
				sum.add(d[j],dp[j]);
			}
		}
		ans+=b[i]-b[i-1]-dp[b[i]];
		sum.clear(d[b[i-1]]);
		for(int j=b[i-1]+1;j<=b[i];++j)
			sum.clear(d[j]);
	}
	printf("%lld\n",ans);
	return 0;
}