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
#define lc (x<<1)
#define rc (x<<1|1)
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

const int N=1e5+5;
int n,a[N];

inline int g(int x)
{
	if(!a[x])
	{
		printf("? %lld\n",x);
		fflush(stdout);a[x]=read();
	}
	return a[x];
}

signed main()
{
	n=read();
	printf("? %lld\n",1ll);
	fflush(stdout);
	a[1]=read();a[0]=1e18;a[n+1]=1e18;
	int l=1,r=n;
	while(r-l>2)
	{
		int mid=((l+r)>>1);
		if(g(mid)>g(mid-1)) r=mid-1;
		else l=mid;
	}
	for(int i=l;i<=r;++i)
		if(g(i)<min(g(i-1),g(i+1)))
		{
			printf("! %lld\n",i);
			fflush(stdout);return 0;
		}
	return 0;
}