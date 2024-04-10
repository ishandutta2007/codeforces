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
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
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

const int N=1e5+5;
int n,a[N],d[N];

inline int gettop(int x);

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=2;i<=n-1;++i)
		if(gettop(a[i-1])==gettop(a[i])&&gettop(a[i])==gettop(a[i+1]))
		{
			printf("%lld\n",1);
			return 0;
		}
	int ans=1e18;
	for(int i=1;i<=n;++i)
	{
		int s1=0;
		for(int j=i;j>=1;--j)
		{
			s1^=a[j];
			int s2=0;
			for(int k=i+1;k<=n;++k)
			{
				s2^=a[k];
				if(s1>s2) ans=min(ans,k-j-1);
			}
		}
	}
	if(ans==1e18) ans=-1;
	printf("%lld\n",ans);
	return 0;
}

inline int gettop(int x)
{
	for(int i=32;i>=0;--i)
		if((x>>i)&1) return i;
}