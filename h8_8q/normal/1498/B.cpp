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

const int N=1e5+5;
int t,n,m,sum[40];

inline bool check(int x);

signed main()
{
	t=read();
	while(t--)
	{
		memset(sum,0,sizeof(sum));
		n=read();m=read();
		for(int i=1;i<=n;++i)
		{
			int tmp=read(),num=0;
			while(tmp!=1)
			{
				tmp>>=1;
				num++;
			}
			sum[num]++;
		}
		int l=1,r=n,ans=1;
		while(l<=r)
		{
			if(check(mid))
				ans=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

inline bool check(int x)
{
	int now=0;
	for(int i=30;i>=0;--i)
	{
		if((m>>i)&1)
			now+=x;	
		now-=sum[i];
		if(now<0) return 0;
		now<<=1;
	}
		
	return 1;
}