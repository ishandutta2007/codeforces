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

const int N=1e5+5;
int n,m,a[N],vis[N],last[2],ans;

queue<int> qu[N];

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		qu[a[i]].push(i);
	}
	for(int i=1;i<=n;++i)
		qu[i].push(1e18);
	last[0]=-1;last[1]=-1;
	for(int i=1,j=0;i<=n;++i)
	{
		qu[a[i]].pop();
		if(a[i]!=last[0]&&a[i]!=last[1])
		{
			if(last[0]==-1) last[0]=a[i];
			else if(last[1]==-1) last[1]=a[i];
			else if(qu[last[0]].front()<qu[last[1]].front()) last[1]=a[i];
			else last[0]=a[i];
			ans++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}