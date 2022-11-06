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

const int N=1e5+5;
int t,n,a[N],ans,res,mn1,mn2;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();ans=0;mn1=mn2=1e18;
		res=1e18;
		for(int i=1;i<=n;++i)
			a[i]=read();
		mn1=a[1];mn2=a[2];
		res=n*a[1]+n*a[2];
		for(int i=3,j=1,k=1;i<=n;++i)
		{
			if(i%2==1) j++;
			else k++;
			if(i%2==1&&a[i]<mn1)
				ans+=mn1==1e18?0:mn1,mn1=a[i];
			else if(i%2==0&&a[i]<mn2)
				ans+=mn2==1e18?0:mn2,mn2=a[i];
			else ans+=a[i];
			res=min(res,ans+mn1*(n-j+1)+mn2*(n-k+1));
		}
		printf("%lld\n",res);
	}
	return 0;
}