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

const int N=2e5+5,M=1e7+5;
int t,n,k,a[N],b[M];

inline bool check(int x);

signed main()
{
	//srand(time(0));
	t=read();
	while(t--)
	{
		n=read();k=read();
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			int res=1;
			for(int j=2;j*j<=a[i];++j)
				if(a[i]%j==0)
				{
					int tmp=0;
					while(a[i]%j==0)
						tmp++,a[i]/=j;
					if(tmp&1) res*=j;
				}
			if(a[i]!=1) res*=a[i];
			a[i]=res;
		}
			
		int le=1,ans=1;
		for(int i=1;i<=n;++i)
		{
			if(b[a[i]])
			{
				ans++;
				while(le<i)
					b[a[le]]--,le++;
			}
			b[a[i]]++;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;++i)
			b[a[i]]=0;
	}
	return 0;
}