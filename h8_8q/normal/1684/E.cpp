#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
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
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f

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

const int N=2e5+5;
int t,n,k,a[N],m,b[N],c[N],vis[N];

struct Seg
{
	int val[N<<2],val2[N<<2];
	void build(int x,int l,int r)
	{
		val[x]=0;val2[x]=0;
		if(l==r) return;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	void update(int x,int l,int r,int p,int v)
	{
		if(l==r)
		{
			val[x]+=l*v;
			val2[x]+=v;
			return;
		}
		if(p<=mid) update(lc,l,mid,p,v);
		else update(rc,mid+1,r,p,v);
		val[x]=val[lc]+val[rc];
		val2[x]=val2[lc]+val2[rc];
	}
	int query(int x,int l,int r,int k)
	{
		if(l==r) return min(val2[x],k/l);
		if(val[lc]<=k)
			return val2[lc]+query(rc,mid+1,r,k-val[lc]);
		else return query(lc,l,mid,k);
	}
	inline int Query(int k)
	{
		return val2[1]-query(1,1,n,k);
	}
}sum;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();
		for(int i=1;i<=n;++i)
			a[i]=b[i]=read();
		for(int i=0;i<=n;++i)
			vis[i]=0;
		sort(b+1,b+1+n);
		sum.build(1,1,n);
		m=unique(b+1,b+1+n)-b-1;
		for(int i=1;i<=m;++i)
			c[i]=0;
		for(int i=1;i<=n;++i)
			c[lower_bound(b+1,b+1+m,a[i])-b]++;
		for(int i=1;i<=m;++i)
			sum.update(1,1,n,c[i],1);
		int now=0,ans=1e9;
		for(int i=0,j=0;i<=n;++i)
		{
			while(j+1<=m&&b[j+1]<i)
			{
				++j,sum.update(1,1,n,c[j],-1);
				if(!vis[b[j]])
					vis[b[j]]=1,++now;
			}
			if(i-now>k) break;
			ans=min(ans,sum.Query(k));
		}
		write(ans);puts("");
	}
	return 0;
}