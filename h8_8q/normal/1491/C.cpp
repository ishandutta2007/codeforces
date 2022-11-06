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

const int N=5005;
int t,n,a[N],ans;

struct BIT
{
	int c[N];
	inline void add(int x,int v)
	{
		for(;x<=n;x+=lowbit(x))
			c[x]+=v;
	}
	inline void update(int l,int r,int v)
	{
		if(l>r) return;
		add(l,v);add(r+1,-v);
	}
	inline int query(int x)
	{
		int res=0;
		for(;x;x-=lowbit(x))
			res+=c[x];
		return res;
	}
}sum;

signed main()
{
	t=read();
	while(t--)
	{
		memset(sum.c,0,sizeof(sum.c));
		n=read();ans=0;
		for(int i=1;i<=n;++i)
			a[i]=read();
		for(int i=1;i<=n;++i)
		{
			int tmp=sum.query(i);
			sum.update(i+max(a[i]-tmp,1)+1,min(i+a[i],n),1);
			sum.update(i+1,i+1,max(0,tmp-a[i]+1));
			if(a[i]-tmp>1)
			{
				int b=a[i]-tmp-1;ans+=b;
				sum.update(i+2,min(n,i+a[i]-tmp),1);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}