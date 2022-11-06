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

#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
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
int t,n,m,a[N],b[N],ne[N],ne2[N],now[N],k,rt[N];

vector<int> hv[N],hv2[N];

struct Seg
{
	int val[N*33],lc[N*33],rc[N*33],cnt;
	void update(int &x,int l,int r,int p)
	{
		if(!x) x=++cnt;
		if(l==r) return val[x]=l,void();
		if(p<=mid) update(lc[x],l,mid,p);
		else update(rc[x],mid+1,r,p);
		val[x]=max(val[lc[x]],val[rc[x]]);
	}
	inline int query(int x,int l,int r,int L,int R)
	{
		if(!x||L>R) return 0;
		if(L<=l&&r<=R)
			return val[x];
		int res=0;
		if(L<=mid) res=max(res,query(lc[x],l,mid,L,R));
		if(mid+1<=R) res=max(res,query(rc[x],mid+1,r,L,R));
		return res; 
	}
	inline void clear()
	{
		for(int i=1;i<=cnt;++i)
			val[i]=lc[i]=rc[i]=0;
	}
}sum;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();k=0;
		for(int i=1;i<=n;++i)
			a[i]=b[i]=read();
		sort(b+1,b+1+n);
		k=unique(b+1,b+1+n)-b-1;
		for(int i=1;i<=n;++i)
			a[i]=lower_bound(b+1,b+1+k,a[i])-b;
		for(int i=1;i<=k;++i)
			rt[i]=0,now[i]=n+1;
		for(int i=n;i>=1;--i)
		{
			ne[i]=now[a[i]];
			now[a[i]]=i;
		}
		for(int i=1;i<=k;++i)
			now[i]=0;
		for(int i=1;i<=n;++i)
		{
			ne2[i]=now[a[i]];
			now[a[i]]=i;
		}
		for(int i=1;i<=n;++i)
			sum.update(rt[a[i]],1,n,i);
		for(int i=1;i<=m;++i)
		{
			int l=read(),r=read();
			if(l==r) continue;
			hv[l].push_back(r);
			hv2[r].push_back(l);
		}
		int mxr=1e9,lim=n,ans=1e9,now=0;
		for(int i=n;i>=1;--i)
		{
			for(int j=0;j<hv2[i].size();++j)
				mxr=min(mxr,hv2[i][j]);
			int tmp=ne2[i];
			if(tmp>=mxr) now=max(now,tmp);
		}
		ans=now;
		mxr=0;
		for(int i=1;i<=lim;++i)
		{
			for(int j=0;j<hv[i].size();++j)
				mxr=max(mxr,hv[i][j]);
			int tmp=sum.query(rt[a[i]],1,n,i+1,mxr);
			int tmp2=ne[i];
			if(tmp2<=mxr) lim=min(lim,tmp2-1);
			if(tmp!=0) now=max(now,tmp);
			ans=min(ans,max(0,now-i));
		}
		write(ans);puts("");
		for(int i=1;i<=n;++i)
			hv[i].clear(),hv2[i].clear();
		sum.clear();
	}
	return 0;
}