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

const int N=2e5+5;
int n1,n2,n3,n4,m1,m2,m3,a[N],b[N],c[N],d[N],dp[N][5];

vector<int> bd1[N],bd2[N],bd3[N];

struct Seg
{
	int val[N*4];
	void build(int x,int l,int r)
	{
		val[x]=1e18;
		if(l==r) return;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	void update(int x,int l,int r,int p,int v)
	{
		if(l==r)
		{
			val[x]=v;
			return;
		}
		if(p<=mid) update(lc,l,mid,p,v);
		else update(rc,mid+1,r,p,v);
		val[x]=min(val[lc],val[rc]);
	}
	int query(int x,int l,int r,int L,int R)
	{
		if(L>R) return 1e18;
		if(L<=l&&r<=R) return val[x];
		int res=1e18;
		if(L<=mid) res=min(res,query(lc,l,mid,L,R));
		if(mid+1<=R) res=min(res,query(rc,mid+1,r,L,R));
		return res;
	}
}sum;

signed main()
{
	n1=read();n2=read();n3=read();n4=read();
	for(int i=1;i<=n1;++i) a[i]=read(),bd1[i].push_back(0),bd1[i].push_back(n2+1);
	for(int i=1;i<=n2;++i) b[i]=read(),bd2[i].push_back(0),bd2[i].push_back(n3+1);
	for(int i=1;i<=n3;++i) c[i]=read(),bd3[i].push_back(0),bd3[i].push_back(n4+1);
	for(int i=1;i<=n4;++i) d[i]=read();
	m1=read();
	for(int i=1;i<=m1;++i)
	{
		int u=read(),v=read();
		bd1[u].push_back(v);
	}
	m2=read();
	for(int i=1;i<=m2;++i)
	{
		int u=read(),v=read();
		bd2[u].push_back(v);
	}
	m3=read();
	for(int i=1;i<=m3;++i)
	{
		int u=read(),v=read();
		bd3[u].push_back(v);
	}
	sum.build(1,1,n4);
	for(int i=1;i<=n4;++i)
		sum.update(1,1,n4,i,d[i]);
	for(int i=1;i<=n3;++i)
	{
		sort(bd3[i].begin(),bd3[i].end());
		dp[i][3]=1e18;
		for(int j=1;j<bd3[i].size();++j)
			dp[i][3]=min(dp[i][3],sum.query(1,1,n4,bd3[i][j-1]+1,bd3[i][j]-1)+c[i]);
	}
	sum.build(1,1,n3);
	for(int i=1;i<=n3;++i)
		sum.update(1,1,n3,i,dp[i][3]);
	for(int i=1;i<=n2;++i)
	{
		sort(bd2[i].begin(),bd2[i].end());
		dp[i][2]=1e18;
		for(int j=1;j<bd2[i].size();++j)
			dp[i][2]=min(dp[i][2],sum.query(1,1,n3,bd2[i][j-1]+1,bd2[i][j]-1)+b[i]);
	}
	sum.build(1,1,n2);
	for(int i=1;i<=n2;++i)
		sum.update(1,1,n2,i,dp[i][2]);
	for(int i=1;i<=n1;++i)
	{
		sort(bd1[i].begin(),bd1[i].end());
		dp[i][1]=1e18;
		for(int j=1;j<bd1[i].size();++j)
			dp[i][1]=min(dp[i][1],sum.query(1,1,n2,bd1[i][j-1]+1,bd1[i][j]-1)+a[i]);
	}
	int ans=1e18;
	for(int i=1;i<=n1;++i)
		ans=min(ans,dp[i][1]);
	if(ans==1e18) printf("-1\n");
	else printf("%lld\n",ans);
	return 0;
}