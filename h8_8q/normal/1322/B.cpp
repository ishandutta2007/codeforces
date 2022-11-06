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

const int N=4e5+5;
int n,a[N],ans;

pair<int,int> b[N];

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=0;i<=24;++i)
	{
		for(int j=1;j<=n;++j)
			b[j]=mp(a[j]%(1<<(i+1)),j);
		sort(b+1,b+1+n);
		int l1=1,l2=1,r1=0,r2=0,sum=0;
		for(int j=n;j>=1;--j)
		{
			while(l1<=n&&b[l1].fi+b[j].fi<(1<<i)) ++l1;
			while(l2<=n&&b[l2].fi+b[j].fi<(1<<(i+1))+(1<<i)) ++l2;
			while(r1<n&&b[r1+1].fi+b[j].fi<=(1<<(i+1))-1) ++r1;
			while(r2<n&&b[r2+1].fi+b[j].fi<=(1<<(i+2))-1) ++r2;
			sum+=r1-l1+1+r2-l2+1-(l1<=j&&j<=r1)-(l2<=j&&j<=r2);
		}
		if((sum/2)&1) ans^=(1<<i);
	}
	printf("%lld\n",ans);
	return 0;
}