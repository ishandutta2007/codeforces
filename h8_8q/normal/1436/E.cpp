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
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=1e5+5;
int n,a[N],las[N];

struct Seg
{
	int val[N*20],lc[N*20],rc[N*20],rt[N],cnt;
	void build(int &x,int l,int r)
	{
		if(!x) x=++cnt;
		val[x]=-1e18;
		if(l==r) return;
		build(lc[x],l,mid);
		build(rc[x],mid+1,r);
	}
	void update(int &x,int y,int l,int r,int p,int v)
	{
		x=++cnt;
		if(l==r)
		{
			val[x]=v;
			return;
		}
		if(p<=mid)
		{
			update(lc[x],lc[y],l,mid,p,v);
			rc[x]=rc[y];
		}
		else
		{
			update(rc[x],rc[y],mid+1,r,p,v);
			lc[x]=lc[y];
		}
		val[x]=min(val[lc[x]],val[rc[x]]);
	}
	int query(int x,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return val[x];
		int res=1e18;
		if(L<=mid) res=min(res,query(lc[x],l,mid,L,R));
		if(mid+1<=R) res=min(res,query(rc[x],mid+1,r,L,R));
		return res; 
	}
}sum;

vector<int> pos[N];

signed main()
{
	n=read();
	int fflag=1;
	for(int i=1;i<=n;++i)
		a[i]=read(),fflag&=(a[i]==1);
	if(fflag)
	{
		printf("1\n");
		return 0;
	}
	sum.build(sum.rt[0],1,n);
	for(int i=1;i<=n+2;++i)
		pos[i].push_back(0);
	for(int i=1;i<=n;++i)
	{
		sum.update(sum.rt[i],sum.rt[i-1],1,n+2,a[i],i);
		pos[a[i]].push_back(i);
	}
	for(int i=1;i<=n+2;++i)
		pos[i].push_back(n+1);
	for(int i=2;i<=n+2;++i)
	{
		int flag=1;
		for(int j=1;j<pos[i].size();++j)
		{
			if(pos[i][j]-1<pos[i][j-1]+1) continue;
			if(sum.query(sum.rt[pos[i][j]-1],1,n+2,1,i-1)>=pos[i][j-1]+1)
				flag=0;
		}
		if(flag)
		{
			printf("%lld\n",i);
			return 0;
		}
	}
	return 0;
}