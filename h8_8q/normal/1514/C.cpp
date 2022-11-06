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
int n,m,a[N],vis[N];

signed main()
{
	n=read();
	int tmp=n;
	for(int j=2;j*j<=tmp;++j)
		if(tmp%j==0)
		{
			while(tmp%j==0) tmp/=j;
			for(int i=j;i<=n-1;i+=j)
				vis[i]=1;
		}
	if(tmp!=1)
	{
		for(int i=tmp;i<=n-1;i+=tmp)
			vis[i]=1;
	}
	int now=1;
	for(int i=1;i<=n-2;++i)
		if(!vis[i]) a[++m]=i,now=now*i%n;
	if(!vis[n-1]&&now*(n-1)%n==1)
		a[++m]=n-1;
	printf("%lld\n",m);
	for(int i=1;i<=m;++i)
		printf("%lld ",a[i]);
	return 0;
}