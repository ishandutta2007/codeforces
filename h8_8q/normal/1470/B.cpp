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
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))

using namespace std;

inline long long read()
{
	long long ans=0,f=1;
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

const int N=3e6+5;
int t,n,q,a[N],b[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
		{
			int tmp=read();a[i]=1;
			for(int j=2;j*j<=tmp;++j)
				if(tmp%j==0)
				{
					int sum=0;
					while(tmp%j==0)
						tmp/=j,sum++;
					if(sum&1) a[i]*=j;
				}
			a[i]*=tmp;
		}
		int ans1=0,ans2=0;
		for(int i=1;i<=n;++i)
		{
			b[a[i]]++;
			ans1=max(ans1,b[a[i]]);
		}
		for(int i=1;i<=n;++i)
		{
			if(b[a[i]]%2==0)
				ans2+=b[a[i]],b[a[i]]=0;
			else if(a[i]==1)
				ans2+=b[a[i]],b[a[i]]=0;
		}
		q=read();
		while(q--)
		{
			long long x=read();
			if(x==0) printf("%d\n",ans1);
			else printf("%d\n",max(ans1,ans2));
		}
		for(int i=1;i<=n;++i)
			b[a[i]]=0;
	}
	return 0;
}