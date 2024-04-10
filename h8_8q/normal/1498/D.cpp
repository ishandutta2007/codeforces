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

const int N=205,M=1e5+5;
int n,m,dp[N][M],ans[M],tg[M],a[N],b[N],c[N],nub[M],id[M];

vector<int> qu[M];
int head[M],tail[M];

signed main()
{
	n=read();m=read();
	//a[1]=1;b[1]=100000;c[1]=1;
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		b[i]=read();
		c[i]=read();
	}
	for(int j=0;j<=m;++j)
		ans[j]=1e9;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
			dp[i][j]=1e9;
	dp[0][0]=0;
	memset(tail,-1,sizeof(tail));
	for(int i=0;i<=n-1;++i)
	{
		if(a[i+1]==1)
		{
			int tmp;
			if(b[i+1]%100000==0) tmp=b[i+1]/100000;
			else tmp=b[i+1]/100000+1;
			for(int j=0;j<=tmp-1;++j)
				if(!qu[j].empty())
					qu[j].clear(),head[j]=0,tail[j]=-1;
			for(int j=0;j<=m;++j)
			{
				int now=j%tmp;
				while(head[now]<=tail[now]&&qu[now][head[now]]<j-c[i+1]*tmp)
					head[now]++;
				if(head[now]<=tail[now])
					dp[i+1][j]=min(dp[i+1][j],dp[i][qu[now][head[now]]]+1);
				while(head[now]<=tail[now]&&dp[i][qu[now][tail[now]]]>=dp[i][j])
					tail[now]--,qu[now].pop_back();
				tail[now]++;qu[now].push_back(j);
			}
		}
		else
		{
			int k=0;
			for(int j=m;j>=0;--j)
			{
				int tmp;
				if(j*b[i+1]%100000==0) tmp=j*b[i+1]/100000;
				else tmp=j*b[i+1]/100000+1;
				if(tmp<=m) tg[j]=tg[tmp];
				else tg[j]=k++;
			}
			for(int j=0;j<=k-1;++j)
			{
				if(!qu[j].empty())
					qu[j].clear(),head[j]=0,tail[j]=-1;
				nub[j]=0;
			}
			for(int j=1;j<=m;++j)
				id[j]=++nub[tg[j]];
			for(int j=1;j<=m;++j)
			{
				int now=tg[j];
				while(head[now]<=tail[now]&&id[qu[now][head[now]]]<id[j]-c[i+1])
					head[now]++;
				if(head[now]<=tail[now])
					dp[i+1][j]=min(dp[i+1][j],dp[i][qu[now][head[now]]]+1);
				while(head[now]<=tail[now]&&dp[i][qu[now][tail[now]]]>=dp[i][j])
					tail[now]--,qu[now].pop_back();
				tail[now]++;qu[now].push_back(j);
			}
		}
		for(int j=0;j<=m;++j)
		{
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
			ans[j]=min(ans[j],dp[i+1][j]);
		}
			
	}
	for(int i=1;i<=m;++i)
		if(ans[i]==1e9) printf("-1 ");
		else printf("%lld ",ans[i]);
	return 0;
}