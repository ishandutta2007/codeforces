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

const int N=50005;
int t,n,m,vis[N],sum[N];

signed main()
{
	for(int i=2;i<=30000;++i)
		if(!vis[i])
		{
			sum[++m]=i;
			for(int j=i+i;j<=30000;j+=i)
				vis[j]=1;
		}
	t=read();
	while(t--)
	{
		n=read();
		int a1=sum[lower_bound(sum+1,sum+1+m,n+1)-sum];
		int a2=sum[lower_bound(sum+1,sum+1+m,a1+n)-sum];
		printf("%lld\n",a1*a2);
	}
	return 0;
}