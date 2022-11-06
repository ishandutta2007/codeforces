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

const int N=3e5+5;
int n,a[N],b[N],ll[N],rr[N],dp[N][22];

struct Seg
{
	int val[N*4],tag[N*4];
	void build(int x,int l,int r)
	{
		val[x]=tag[x]=-1e18;
		if(l==r) return;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	inline void pushdown(int x)
	{
		if(tag[x]!=-1e18)
		{
			val[lc]=max(val[lc],tag[x]);
			val[rc]=max(val[rc],tag[x]);
			tag[lc]=max(tag[lc],tag[x]);
			tag[rc]=max(tag[rc],tag[x]);
			tag[x]=-1e18;
		}
	}
	void update(int x,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{
			val[x]=max(val[x],v);
			tag[x]=max(tag[x],v);
			return;
		}
		pushdown(x);
		if(L<=mid) update(lc,l,mid,L,R,v);
		if(mid+1<=R) update(rc,mid+1,r,L,R,v);
		val[x]=max(val[lc],val[rc]);
	}
	int query(int x,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return val[x];
		pushdown(x);int res=-1e18;
		if(L<=mid) res=max(res,query(lc,l,mid,L,R));
		if(mid+1<=R) res=max(res,query(rc,mid+1,r,L,R));
		return res;
	}
}sum;

inline int query(int l,int r);

signed main()
{
	n=read();
	sum.build(1,0,n);
	for(int i=1;i<=n;++i)
		a[i]=read(),dp[i][0]=a[i];
	for(int j=1;j<=21;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=n;++i)
	{
		int l=1,r=i;
		while(l<=r)
		{
			if(query(mid,i)==a[i])
				ll[i]=mid,r=mid-1;
			else l=mid+1;
		}
		l=i,r=n;
		while(l<=r)
		{
			if(query(i,mid)==a[i])
				rr[i]=mid,l=mid+1;
			else r=mid-1;
		}
	}
	for(int i=1;i<=n;++i)
		b[i]=read();
	sum.update(1,0,n,0,0,0);
	for(int i=1;i<=n;++i)
		sum.update(1,0,n,i,rr[i],sum.query(1,0,n,ll[i]-1,i-1)+b[i]);
	printf("%lld\n",sum.query(1,0,n,n,n));
	return 0;
}

inline int query(int l,int r)
{
	int k=log2(r-l+1);
	return min(dp[l][k],dp[r-(1<<k)+1][k]);
}