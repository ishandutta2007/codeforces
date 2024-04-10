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
#define INF 0x3f3f3f3f3f3f3f3f

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

const int N=105;
int t,n,m,dp[N][N],hav[N][N],in[N];

struct Node
{
	int x,y,id;
	bool operator < (const Node &p)const
	{
		return y<p.y;
	}
}a[N];

vector<int> ans;

void print(int x,int y)
{
	if(!x) return;
	print(x-1,hav[x][y]?y-1:y);
	in[x]=hav[x][y];
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=n;++i)
			a[i].x=read(),a[i].y=read(),a[i].id=i;
		sort(a+1,a+1+n);
		memset(dp,-0x3f,sizeof(dp));
		dp[0][0]=0;
		for(int i=1;i<=n;++i)
		{
			dp[i][0]=dp[i-1][0]+(m-1)*a[i].y;
			for(int j=1;j<=m&&j<=i;++j)
			{
				int p1=dp[i-1][j]+(m-1)*a[i].y;
				int p2=dp[i-1][j-1]+a[i].x+(j-1)*a[i].y;
				if(p1<p2) dp[i][j]=p2,hav[i][j]=1;
				else dp[i][j]=p1,hav[i][j]=0;
			}
		}
			
		//printf("%lld\n",dp[n][m]);
		print(n,m);
		ans.clear();
		for(int i=1;i<=n;++i)
			if(in[i]) ans.push_back(a[i].id);
		int now=ans.size()-1;
		for(int i=1;i<=n;++i)
			if(!in[i])
			{
				ans.push_back(a[i].id);
				ans.push_back(-a[i].id);
			}
			else in[i]=0;
		write(ans.size());puts("");
		for(int i=0;i<now;++i)
			printf("%lld ",ans[i]);
		for(int i=now+1;i<ans.size();++i)
			printf("%lld ",ans[i]);
		printf("%lld\n",ans[now]);
	}
	return 0;
}