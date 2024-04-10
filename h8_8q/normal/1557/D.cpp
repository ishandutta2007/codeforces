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

const int N=1e6+5;
int n,m,k,b[N],dp[N],pre[N],vis[N];

vector<pair<int,int> > hav[N/3];

struct Seg
{
	pair<int,int> val[N<<2],tag[N<<2];
	inline void pushup(int x)
	{
		val[x]=max(val[lc],val[rc]);
	}
	inline void pushdown(int x)
	{
		if(tag[x].se!=0)
		{
			val[lc]=max(val[lc],tag[x]);
			val[rc]=max(val[rc],tag[x]);
			tag[lc]=max(tag[lc],tag[x]);
			tag[rc]=max(tag[rc],tag[x]);
			tag[x].fi=tag[x].se=0;
		}
	}
	void update(int x,int l,int r,int L,int R,pair<int,int> v)
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
		pushup(x);
	}
	pair<int,int> query(int x,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return val[x];
		pair<int,int> res(0,0);pushdown(x);
		if(L<=mid) res=max(res,query(lc,l,mid,L,R));
		if(mid+1<=R) res=max(res,query(rc,mid+1,r,L,R));
		return res;
	}
}sum;

void work(int x)
{
	if(!x) return;
	vis[x]=1;
	work(pre[x]);
}

signed main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		int x=read(),l=read(),r=read();
		hav[x].push_back(mp(l,r));
		b[++k]=l;b[++k]=r;
	}
	sort(b+1,b+1+k);
	k=unique(b+1,b+1+k)-b-1;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<hav[i].size();++j)
		{
			int l=lower_bound(b+1,b+1+k,hav[i][j].fi)-b;
			int r=lower_bound(b+1,b+1+k,hav[i][j].se)-b;
			pair<int,int> tmp=sum.query(1,1,k,l,r);
			if(tmp.fi+1>dp[i]) dp[i]=tmp.fi+1,pre[i]=tmp.se;
		}
		for(int j=0;j<hav[i].size();++j)
		{
			int l=lower_bound(b+1,b+1+k,hav[i][j].fi)-b;
			int r=lower_bound(b+1,b+1+k,hav[i][j].se)-b;
			sum.update(1,1,k,l,r,mp(dp[i],i));
		}
	}
	pair<int,int> ans;
	for(int i=1;i<=n;++i)
		ans=max(ans,mp(dp[i],i));
	printf("%lld\n",n-ans.fi);
	work(ans.se);
	for(int i=1;i<=n;++i)
		if(!vis[i]) printf("%lld ",i);
	return 0;
}