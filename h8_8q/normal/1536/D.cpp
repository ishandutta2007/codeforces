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
#define lc (x<<1)
#define rc (x<<1|1)
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

const int N=2e5+5;
int t,n,m,a[N],b[N];

struct BIT
{
	int c[N];
	void add(int x,int v)
	{
		for(;x<=m;x+=lowbit(x))
			c[x]+=v;
	}
	int sum(int x)
	{
		int res=0;
		for(;x;x-=lowbit(x))
			res+=c[x];
		return res;
	}
	int query(int l,int r)
	{
		if(l>r) return 0;
		return sum(r)-sum(l-1);
	}
}sum;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=n;
		for(int i=1;i<=n;++i)
			a[i]=b[i]=read();
		sort(b+1,b+1+m);
		m=unique(b+1,b+1+m)-b-1;
		for(int i=1;i<=n;++i)
			a[i]=lower_bound(b+1,b+1+m,a[i])-b;
		int flag=0;
		for(int i=1;i<=n-1;++i)
		{
			int L=min(a[i],a[i+1]);
			int R=max(a[i],a[i+1]);
			if(sum.query(L+1,R-1)>=1) flag=1;
			sum.add(a[i],1);
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
		for(int i=1;i<=n-1;++i)
			sum.add(a[i],-1);
	}
	return 0;
}