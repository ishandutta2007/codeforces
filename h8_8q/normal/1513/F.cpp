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
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=4e5+5;
int n,m,a[N],b[N],c[N];
long long now;

vector<int> d[N];

struct Array
{
	int root[N],lc[N*20],rc[N*20],tot;
	long long val[N*20];
	void build(int &x,int l,int r)
	{
		x=++tot;val[x]=1e18;
		if(l==r) return;
		build(lc[x],l,mid);
		build(rc[x],mid+1,r);
	}
	void update(int pre,int &x,int l,int r,int p,long long v)
	{
		x=++tot;val[x]=1e18;
		if(l==r)
		{
			val[x]=min(val[x],v);
			return;
		}
		if(p<=mid)
		{
			rc[x]=rc[pre];
			update(lc[pre],lc[x],l,mid,p,v);
		}
		else
		{
			lc[x]=lc[pre];
			update(rc[pre],rc[x],mid+1,r,p,v);
		}
		val[x]=min(val[lc[x]],val[rc[x]]);
	}
	long long query(int x,int l,int r,int L,int R)
	{
		if(!x) return 1e18;
		if(L<=l&&r<=R) return val[x];
		long long res=1e18;
		if(L<=mid) res=min(res,query(lc[x],l,mid,L,R));
		if(mid+1<=R) res=min(res,query(rc[x],mid+1,r,L,R));
		return res;
	}
	inline void clear()
	{
		memset(lc,0,sizeof(lc));
		memset(rc,0,sizeof(rc));
		memset(root,0,sizeof(root));
		tot=0;
	}
}t1;

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read(),c[++m]=a[i];
	for(int i=1;i<=n;++i)
		b[i]=read(),c[++m]=b[i];
	for(int i=1;i<=n;++i)
		now+=abs(a[i]-b[i]);
	sort(c+1,c+1+m);
	m=unique(c+1,c+1+m)-c-1;
	for(int i=1;i<=n;++i)
	{
		a[i]=lower_bound(c+1,c+1+m,a[i])-c;
		b[i]=lower_bound(c+1,c+1+m,b[i])-c;
		d[b[i]].push_back(a[i]);
	}
	long long ans=now;
	
	t1.tot=0;t1.build(t1.root[0],1,m);
	for(int i=1;i<=m;++i)
	{
		if(d[i].size()==0) t1.root[i]=t1.root[i-1];
		for(int j=0;j<d[i].size();++j)
		{
			if(j==0) t1.update(t1.root[i-1],t1.root[i],1,m,d[i][j],-c[d[i][j]]-c[i]-abs(c[d[i][j]]-c[i]));
			else t1.update(t1.root[i],t1.root[i],1,m,d[i][j],-c[d[i][j]]-c[i]-abs(c[d[i][j]]-c[i]));
		}
	}
	for(int i=1;i<=n;++i)
		ans=min(ans,now+t1.query(t1.root[a[i]],1,m,1,b[i])+c[b[i]]+c[a[i]]-abs(c[a[i]]-c[b[i]]));
		
	t1.clear();t1.build(t1.root[m+1],1,m);
	for(int i=m;i>=1;--i)
	{
		if(d[i].size()==0) t1.root[i]=t1.root[i+1];
		for(int j=0;j<d[i].size();++j)
		{
			if(j==0) t1.update(t1.root[i+1],t1.root[i],1,m,d[i][j],-c[d[i][j]]+c[i]-abs(c[d[i][j]]-c[i]));
			else t1.update(t1.root[i],t1.root[i],1,m,d[i][j],-c[d[i][j]]+c[i]-abs(c[d[i][j]]-c[i]));
		}
	}
	for(int i=1;i<=n;++i)
		ans=min(ans,now+t1.query(t1.root[a[i]],1,m,1,b[i])+c[b[i]]-c[a[i]]-abs(c[a[i]]-c[b[i]]));
		
	t1.clear();t1.build(t1.root[0],1,m);
	for(int i=1;i<=m;++i)
	{
		if(d[i].size()==0) t1.root[i]=t1.root[i-1];
		for(int j=0;j<d[i].size();++j)
		{
			if(j==0) t1.update(t1.root[i-1],t1.root[i],1,m,d[i][j],c[d[i][j]]-c[i]-abs(c[d[i][j]]-c[i]));
			else t1.update(t1.root[i],t1.root[i],1,m,d[i][j],c[d[i][j]]-c[i]-abs(c[d[i][j]]-c[i]));
		}
	}
	for(int i=1;i<=n;++i)
		ans=min(ans,now+t1.query(t1.root[a[i]],1,m,b[i],m)-c[b[i]]+c[a[i]]-abs(c[a[i]]-c[b[i]]));
	
	t1.clear();t1.build(t1.root[m+1],1,m);
	for(int i=m;i>=1;--i)
	{
		if(d[i].size()==0) t1.root[i]=t1.root[i+1];
		for(int j=0;j<d[i].size();++j)
		{
			if(j==0) t1.update(t1.root[i+1],t1.root[i],1,m,d[i][j],c[d[i][j]]+c[i]-abs(c[d[i][j]]-c[i]));	
			else t1.update(t1.root[i],t1.root[i],1,m,d[i][j],c[d[i][j]]+c[i]-abs(c[d[i][j]]-c[i]));
		}
	}
	for(int i=1;i<=n;++i)
		ans=min(ans,now+t1.query(t1.root[a[i]],1,m,b[i],m)-c[b[i]]-c[a[i]]-abs(c[a[i]]-c[b[i]]));
	printf("%lld\n",ans);
	return 0;
}