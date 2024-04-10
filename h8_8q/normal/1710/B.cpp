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

const int N=5e5+5;
int t,n,m,k,B[N],a[N],b[N],s1[N],s2[N],h[N],l1[N],l2[N];

struct Seg
{
	int v1[N<<2],v2[N<<2];
	void build(int x,int l,int r)
	{
		if(l==r)
		{
			v1[x]=l1[l];
			v2[x]=l2[l];
			return;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		v1[x]=min(v1[lc],v1[rc]);
		v2[x]=min(v2[lc],v2[rc]);
	}
	int query1(int x,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return v1[x];
		int res=INF;
		if(L<=mid) res=min(res,query1(lc,l,mid,L,R));
		if(mid+1<=R) res=min(res,query1(rc,mid+1,r,L,R));
		return res;
	}
	int query2(int x,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return v2[x];
		int res=INF;
		if(L<=mid) res=min(res,query2(lc,l,mid,L,R));
		if(mid+1<=R) res=min(res,query2(rc,mid+1,r,L,R));
		return res;
	}
}sm;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();k=0;
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			b[i]=read();
			B[++k]=a[i];
		}
		sort(B+1,B+1+k);
		k=unique(B+1,B+1+k)-B-1;
		for(int i=1;i<=k;++i)
			s1[i]=s2[i]=h[i]=0;
		for(int i=1;i<=n;++i)
		{
			int u=lower_bound(B+1,B+1+k,a[i])-B;
			int l=lower_bound(B+1,B+1+k,a[i]-b[i]+1)-B;
			int r=upper_bound(B+1,B+1+k,a[i]+b[i]-1)-B-1;
			s1[l]+=b[i];s1[r+1]-=b[i];
			s1[l]-=a[i];s1[u]+=a[i];s2[l]++;s2[u]--;
			s1[u+1]+=a[i];s1[r+1]-=a[i];s2[u+1]--;s2[r+1]++;
		}
		for(int i=1;i<=k;++i)
		{
			s1[i]+=s1[i-1];
			s2[i]+=s2[i-1];
			h[i]=s1[i]+B[i]*s2[i];
		}
		int p1=n+1,p2=-1;
		for(int i=1;i<=k;++i)
			if(h[i]>m)
			{
				l1[i]=m+B[i]-h[i];
				l2[i]=m-B[i]-h[i];
				p1=min(p1,i);
				p2=max(p2,i);
			}
			else l1[i]=l2[i]=INF;
		sm.build(1,1,k);
		for(int i=1;i<=n;++i)
		{
			int u=lower_bound(B+1,B+1+k,a[i])-B;
			int l=lower_bound(B+1,B+1+k,a[i]-b[i]+1)-B;
			int r=upper_bound(B+1,B+1+k,a[i]+b[i]-1)-B-1;
			if(l<=p1&&p2<=r)
			{
				int t1=sm.query1(1,1,k,l,u);
				int t2=sm.query2(1,1,k,u,r);
				if(-b[i]+a[i]<=t1&&-a[i]-b[i]<=t2)
					putchar('1');
				else putchar('0');
			}
			else putchar('0');
		}
		puts("");
	}
	return 0;
}