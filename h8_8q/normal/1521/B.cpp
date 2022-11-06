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
int t,n,a[N];

struct Node
{
	int a,b,c,d;
};

vector<Node> ans;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		ans.clear();
		int mn=1e18,ps=-1;
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			if(a[i]<mn)
				mn=a[i],ps=i;
		}
		for(int i=ps-1,j=1;i>=1;--i,++j)
		{
			if(j%2==1)
				ans.push_back((Node){i,ps,a[ps]+1,a[ps]});
			else ans.push_back((Node){i,ps,a[ps],a[ps]});
		}
		for(int i=ps+1,j=1;i<=n;++i,++j)
		{
			if(j%2==1)
				ans.push_back((Node){i,ps,a[ps]+1,a[ps]});
			else ans.push_back((Node){i,ps,a[ps],a[ps]});
		}
		printf("%d\n",ans.size());
		for(int i=1;i<=ans.size();++i)
			printf("%lld %lld %lld %lld\n",ans[i-1].a,ans[i-1].b,ans[i-1].c,ans[i-1].d);
	}
	return 0;
}