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
#define INF 0x3f3f3f3f

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
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=2e5+5;
int n,m,a[N],siz[N],dp[N],pre[N];

vector<int> hav[N],ans;

inline int exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	int tmp=exgcd(b,a%b,y,x);
	y-=a/b*x;return tmp;
}

void print(int x)
{
	if(!x) return;
	print(pre[x]);
	for(int i=0;i<hav[x].size();++i)
		ans.push_back(hav[x][i]);
}

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
		a[read()]=1;
	for(int i=1;i<=m-1;++i)
		if(!a[i])
		{
			int u=__gcd(i,m);
			hav[u].push_back(i);
			siz[u]++;
		}
	for(int i=1;i<=m-1;++i)
	{
		dp[i]+=siz[i];
		for(int j=i+i;j<=m-1;j+=i)
			if(dp[j]<dp[i])
			{
				dp[j]=dp[i];
				pre[j]=i;
			}
	}
	int mx=0,ps=0;
	for(int i=1;i<=m-1;++i)
		if(dp[i]>mx)
		{
			mx=dp[i];
			ps=i;
		}
	print(ps);
	int now=1;
	for(int i=0;i<ans.size();++i)
	{
		int tmp=now;now=ans[i];
		int x,y,gcd=exgcd(tmp,m,x,y);
		x=(x*1ll*ans[i]/gcd%m+m)%m;
		ans[i]=x;
	}
	if(!a[0]) ans.push_back(0);
	write(ans.size());puts("");
	for(int i=0;i<ans.size();++i)
		write(ans[i]),putchar(' ');
	return 0;
}