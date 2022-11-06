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

const int N=2e7+5;
int t,c,d,n,m,ans,vis[N],sum[N],pri[N];

inline int work(int x);

signed main()
{
	for(int i=2;i<=20000000;++i)
	{
		if(!vis[i]) pri[++m]=i,sum[i]=1;
		for(int j=1;j<=m&&pri[j]*i<=20000000;++j)
		{
			vis[pri[j]*i]=1;
			if(i%pri[j]==0)
			{
				sum[pri[j]*i]=sum[i];
				break;
			}
			sum[pri[j]*i]=sum[i]+1;
			
		}
	}
	t=read();
	while(t--)
	{
		c=read();d=read();n=read();ans=0;
		for(int i=1;i*i<=n;++i)
			if(n%i==0)
			{
				ans+=work(i);
				if(n/i!=i) ans+=work(n/i);
			}
		printf("%lld\n",ans);
	}
	return 0;
}

inline int work(int x)
{
	if((d+x)%c!=0) return 0;
	int r=(d+x)/c;
	return 1ll<<sum[r];
}